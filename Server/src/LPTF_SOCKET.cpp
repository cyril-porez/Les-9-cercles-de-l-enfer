#include "LPTF_SOCKET.hpp"

LPTF_SOCKET::LPTF_SOCKET()
{
  WSAData wsaData;
  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0)
  {
    std::cerr << "WSAStartup failed: " << iResult << std::endl;
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == INVALID_SOCKET)
  {
    std::cerr << "Fail to create socket: " << WSAGetLastError() << std::endl;
    WSACleanup();
    exit(1);
  }
}

LPTF_SOCKET::~LPTF_SOCKET()
{
  closesocket(sockfd);
  WSACleanup();
}

int LPTF_SOCKET::acceptLPTFSocket()
{

  int adressLen = sizeof(addr);

  SOCKET clientSocket = accept(sockfd, reinterpret_cast<sockaddr *>(&addr), &adressLen);

  if (clientSocket == INVALID_SOCKET)
  {
    std::cerr << "accept failed with error: "
              << WSAGetLastError()
              << std::endl;
    closesocket(sockfd);
    WSACleanup();
    return 1;
  }
  else
  {
    wprintf(L"Client connected.\n");
    return 0;
  }
}

int LPTF_SOCKET::bindLPTFSocket()
{
  if (bind(sockfd, (SOCKADDR *)&service, sizeof(service)) == SOCKET_ERROR)
  {
    std::cerr << "Bind failed : " << WSAGetLastError() << std::endl;
    closesocket(sockfd);
    return 1;
  }
  std::cerr << "bind returned success" << std::endl;
  return 0;
}

int LPTF_SOCKET::connectLPTFSocket()
{
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
  {
    std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
    closesocket(sockfd);
    WSACleanup();
    return 1;
  }
  std::cerr << "connect returned success" << std::endl;
  return 0;
}

int LPTF_SOCKET::listenLPTFSocket()
{
  // On essaye d'écouter avec le socket de la classe et la taille
  // de file d'attente maximum
  if (listen(this->sockfd, SOMAXCONN) == SOCKET_ERROR)
  {
    std::cerr << "Listen failed : " << WSAGetLastError() << std::endl;
    return 1;
  }
  else
  {
    printf("Listening of socket...");
    return 0;
  }
}

int LPTF_SOCKET::selectLPTFSocket(
    fd_set *readFds, fd_set *writeFds, fd_set *exceptFds,
    const timeval *timeout)
{
  int iResult = select(
      0, // paramètre ignoré
      readFds, writeFds, exceptFds,
      timeout);
  if (iResult != 0)
  {
    std::cout << "selectLPTFSocket() failed: " << iResult << std::endl;
    return 1;
  }

  return 0;
}

/**
 * @param socket Le socket connecté
 * @param buffer Le buffer de données
 */
int LPTF_SOCKET::recvLPTFSocket(SOCKET socket, char *buffer)
{
  int iResult = recv(socket, buffer, sizeof(buffer), MSG_PEEK);
  if (iResult != 0)
  {
    std::cout << "recvLPTFSocket() failed: " << WSAGetLastError() << std::endl;

    return 1;
  }

  std::cout << "Data successfully received" << std::endl;
  return 0;
}

int LPTF_SOCKET::sendLPTFSocket(const std::string &message)
{
  if (send(sockfd, sendbuf.c_str(), static_cast<int>(sendbuf.length()), 0) == SOCKET_ERROR)
  {
    std::cerr << "Send failed : " << WSAGetLastError() << std::endl;
    closesocket(sockfd);
    WSACleanup();
    closesocket(sockfd);
    return 1;
  }
  std::cout << "send Successfully" << std::endl;
  return 0;
}

int LPTF_SOCKET::closeLPTFSocket(SOCKET socket)
{
  int iResult = closesocket(socket);
  if (iResult == SOCKET_ERROR)
  {
    std::cout << "closesocket failed with error: "
              << WSAGetLastError()
              << std::endl;
    return 1;
  }
  else
  {
    std::cout << "closesocket Successfully" << std::endl;
    return 0;
  }
}

SOCKET LPTF_SOCKET::getSocket()
{
  return this->sockfd;
}

void LPTF_SOCKET::setUpService(const std::string &ip, int port, bool isServer)
{
  service.sin_family = AF_INET;
  service.sin_port = htons(port);

  if (isServer)
  {
    service.sin_addr.s_addr = INADDR_ANY;
  }
  else
  {
    service.sin_addr.s_addr = inet_addr(ip.c_str());
  }
  memset(service.sin_zero, 0, sizeof(service.sin_zero));
}
