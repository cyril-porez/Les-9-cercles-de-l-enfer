#include "../include/LPTF_Socket.hpp"

LPTF_Socket::LPTF_Socket()
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
    exit(1);
  }
}

LPTF_Socket::LPTF_Socket(const LPTF_Socket &other)
{
  WSAData wsaData;
  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0)
  {
    std::cerr << "WSAStartup failed: " << iResult << std::endl;
    exit(1);
  }

  sockfd = other.sockfd;
  if (sockfd == INVALID_SOCKET)
  {
    std::cerr << "Fail to create socket: " << WSAGetLastError() << std::endl;
    exit(1);
  }
}

LPTF_Socket::LPTF_Socket(const std::string &ip, int port, bool isServer)
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
    exit(1);
  }

  this->setUpService(ip, port, isServer);
}

LPTF_Socket::~LPTF_Socket()
{
  closesocket(sockfd);
  WSACleanup();
}

void printSockAddrIn(const sockaddr_in &addr)
{
  // Récupérer l'adresse IP sous forme d'entier
  unsigned int ip = ntohl(addr.sin_addr.s_addr);
  // Extraire les octets de l'adresse IP
  unsigned char octet1 = (ip >> 24) & 0xFF;
  unsigned char octet2 = (ip >> 16) & 0xFF;
  unsigned char octet3 = (ip >> 8) & 0xFF;
  unsigned char octet4 = ip & 0xFF;

  // Récupérer le port
  unsigned short port = ntohs(addr.sin_port);

  // Affichage de l'adresse IP et du port
  std::cout << "IP: " << (int)octet1 << '.' << (int)octet2 << '.' << (int)octet3 << '.' << (int)octet4 << ", Port: " << port << std::endl;
}

LPTF_Socket *LPTF_Socket::accept()
{
  printSockAddrIn(addr);
  int adressLen = sizeof(addr);
  SOCKET clientSock = ::accept(sockfd, reinterpret_cast<sockaddr *>(&addr), &adressLen);

  if (clientSock == INVALID_SOCKET)
  {
    std::cerr << "accept failed with error: "
              << WSAGetLastError()
              << std::endl;
    return nullptr;
  }
  else
  {
    LPTF_Socket *clientSocket = new LPTF_Socket();
    clientSocket->sockfd = clientSock;
    clientSocket->addr = addr;
    std::cout << "Client #" << clientSocket->sockfd << " connected" << std::endl;
    return clientSocket;
  }
}

int LPTF_Socket::bind()
{
  if (::bind(sockfd, (SOCKADDR *)&addr, sizeof(addr)) == SOCKET_ERROR)
  {
    std::cerr << "Bind failed : " << WSAGetLastError() << std::endl;
    closesocket(sockfd);
    return 1;
  }
  std::cerr << "bind returned success" << std::endl;
  return 0;
}

int LPTF_Socket::connect()
{
  if (::connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
    std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
    closesocket(sockfd);
    WSACleanup();
    return 1;
  }
  std::cerr << "connect returned success" << std::endl;
  return 0;
}

int LPTF_Socket::listen()
{
  // On essaye d'écouter avec le socket de la classe et la taille
  // de file d'attente maximum
  if (::listen(this->sockfd, SOMAXCONN) == SOCKET_ERROR)
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

int LPTF_Socket::select(
    fd_set *readFds, fd_set *writeFds, fd_set *exceptFds,
    const timeval *timeout)
{
  int iResult = ::select(
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

int LPTF_Socket::recv(char *buffer, int bufferSize)
{
  int iResult = ::recv(sockfd, buffer, bufferSize, 0);
  if (iResult < 0)
  {
    std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    return 1;
  }
  else if (iResult == 0)
  {
    std::cerr << "Connection closed by peer." << std::endl;
    return 1;
  }

  buffer[iResult] = '\0';
  std::cout << "Data successfully received" << std::endl;
  return 0;
}

int LPTF_Socket::recv(SOCKET clientSock, char *buffer, int bufferSize)
{
  int iResult = ::recv(clientSock, buffer, bufferSize, 0);
  if (iResult < 0)
  {
    std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    return 1;
  }
  else if (iResult == 0)
  {
    std::cerr << "Connection closed by peer." << std::endl;
    return 1;
  }

  buffer[iResult] = '\0';
  std::cout << "Data successfully received: " << buffer << std::endl;
  return 0;
}

int LPTF_Socket::send(const std::string &message)
{
  if (::send(sockfd, message.c_str(), static_cast<int>(message.length()), 0) == SOCKET_ERROR)
  {
    std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
    return 1;
  }
  std::cout << "Message sent successfully" << std::endl;
  return 0;
}

int LPTF_Socket::send(SOCKET clientSock, const std::string &message)
{
  if (::send(clientSock, message.c_str(), static_cast<int>(message.length()), 0) == SOCKET_ERROR)
  {
    std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
    return 1;
  }
  std::cout << "Message sent successfully: "  << message << std::endl;
  return 0;
}

int LPTF_Socket::close()
{
  if (sockfd != INVALID_SOCKET)
  {
    int result = closesocket(sockfd);
    if (result == SOCKET_ERROR)
    {
      std::cerr << "Failed to close client socket: " << WSAGetLastError() << std::endl;
      return 1;
    }
    sockfd = INVALID_SOCKET;
    std::cout << "Client socket closed successfully." << std::endl;
  }
  return 0;
}

SOCKET LPTF_Socket::getSocket()
{
  return this->sockfd;
}

void LPTF_Socket::setUpService(const std::string &ip, int port, bool isServer)
{
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);

  if (isServer)
  {
    addr.sin_addr.s_addr = INADDR_ANY;
  }
  else
  {
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
  }
  memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
}

int LPTF_Socket::handleMultipleClients()
{
  fd_set readfds;
  timeval timeout = {0, 500000}; // 0.5 seconds

  while (true)
  {
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    for (SOCKET s : clientSockets)
    {
      FD_SET(s, &readfds);
    }

    int activity = ::select(0, &readfds, NULL, NULL, &timeout);

    if (activity == SOCKET_ERROR)
    {
      std::cerr << "select call failed with error: " << WSAGetLastError() << std::endl;
      return 1;
    }

    if (FD_ISSET(sockfd, &readfds))
    {
      // Accept new connection
      accept();
    }

    for (size_t i = 0; i < clientSockets.size(); ++i)
    {
      if (FD_ISSET(clientSockets[i], &readfds))
      {
        char buffer[1024];
        int result = recv(clientSockets[i], buffer, sizeof(buffer) - 1);
        if (result != 0)
        {
          closesocket(clientSockets[i]);
          clientSockets.erase(clientSockets.begin() + i);
          --i; // Adjust index to account for the removed socket
        }
        else
        {
          // Handle the received data, e.g., echo back to client
          std::cout << std::string(buffer) << std::endl;
          send(clientSockets[i], std::string(buffer));
        }
      }
    }
  }

  return 0;
}

LPTF_Socket &LPTF_Socket::operator=(const LPTF_Socket &other)
{
  this->addr = other.addr;
  // this->clientSock = other.clientSock;
  this->sendbuf = other.sendbuf;
  this->sockfd = other.sockfd;

  return *this;
}
