#include "../include/LPTF_Socket.hpp"
#include "../include/LPTF_Packet.hpp"
#include <string>

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
  // int adressLen = sizeof(addr);
  SOCKET clientSock = ::accept(sockfd, nullptr, nullptr);

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
    return 1;
  }
  std::cerr << "bind returned success" << std::endl;
  return 0;
}

int LPTF_Socket::connect()
{
  if (::connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
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
    return 1;
  }
  else
  {
    printf("Listening of socket...\n");
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

int LPTF_Socket::recv(MyPacket &packetRecv)
{
  int iResult = ::recv(sockfd, reinterpret_cast<char *>(&packetRecv), sizeof(MyPacket), 0);
  std::cout << "Packet received:\n" << packetRecv.toString() << std::endl;
  if (iResult < 0)
  {
    return 1; // Erreur de réception
  }
  else if (iResult == 0)
  {
    return 2; // Connexion fermée par le client
  }
  return 0; // Réception réussie
}

int LPTF_Socket::recv(SOCKET clientSock, MyPacket &packetRecv)
{
  int iResult = ::recv(clientSock, reinterpret_cast<char *>(&packetRecv), sizeof(MyPacket), 0);
  std::cout << "Packet received:\n" << packetRecv.toString() << std::endl;
  if (iResult < 0)
  {
    return 1; // Erreur de réception
  }
  else if (iResult == 0)
  {
    return 2; // Connexion fermée par le client
  }
  return 0; // Réception réussie
}

int LPTF_Socket::send(MyPacket &packetSend)
{
  std::cout << "Sent packet:\n" << packetSend.toString() << std::endl;
  int iResult = ::send(sockfd, reinterpret_cast<const char*>(&packetSend), sizeof(MyPacket), 0);
  if (iResult == SOCKET_ERROR)
  {
    return 1; // Erreur d'envoi
  }
  return 0; // Envoi réussi
}

int LPTF_Socket::send(SOCKET clientSock, MyPacket &packetSend)
{
  std::cout << "Sent packet:\n" << packetSend.toString() << std::endl;
  int iResult = ::send(clientSock, reinterpret_cast<const char *>(&packetSend), sizeof(MyPacket), 0);
  if (iResult == SOCKET_ERROR)
  {
    return 1; // Erreur d'envoi
  }
  return 0; // Envoi réussi
}

int LPTF_Socket::close()
{
  closesocket(sockfd);
  std::cout << "Socket " << sockfd << " closed\n";
  return 0;
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
  fd_set readfds; // liste de file descriptors

  while (true)
  {
    FD_ZERO(&readfds);        // initialise tous les fd à 0 bits
    FD_SET(sockfd, &readfds); // initialise un fd pour qu'il prenne la valeur du fd principal
    std::cout << clientSockets.size() << std::endl;
    for (SOCKET s : clientSockets)
    {
      FD_SET(s, &readfds);
    }

    if (FD_ISSET(sockfd, &readfds))
    {
      // Accept new connection
      accept();
    }

    handleClientSockets(clientSockets, readfds);
  }

  return 0;
}

void LPTF_Socket::handleClientSockets(std::vector<SOCKET> clientSockets, fd_set fdList) 
{
    std::cout << "handling client sockets..." << std::endl;
    for (size_t i = 0; i < clientSockets.size(); ++i)
    {
      if (FD_ISSET(clientSockets[i], &fdList))
      {
        MyPacket packetRecv;
        int result = recv(clientSockets[i], packetRecv);
        if (result != 0)
        {
          closesocket(clientSockets[i]);
          clientSockets.erase(clientSockets.begin() + i);
          std::cout << "error receiving" << std::endl;
          --i; // Adjust index to account for the removed socket
        }
        else
        {
          // Handle the received data, e.g., echo back to client
          std::cout << "buffer: " << packetRecv.toString() << std::endl;
          send(clientSockets[i], packetRecv);
        }
      }
    }
}

LPTF_Socket &LPTF_Socket::operator=(const LPTF_Socket &other)
{
  this->addr = other.addr;
  this->sendbuf = other.sendbuf;
  this->sockfd = other.sockfd;

  return *this;
}

/**
 * GETTERS
 */

SOCKET LPTF_Socket::getSocket()
{
  return this->sockfd;
}

std::vector<SOCKET> LPTF_Socket::getClientSockets()
{
  return this->clientSockets;
}

sockaddr_in LPTF_Socket::getAddr()
{
  return this->addr;
}

std::string LPTF_Socket::getBuffer()
{
  return this->sendbuf;
}

/**
 * SETTERS
 */

void LPTF_Socket::setSocket(SOCKET socket)
{
  this->sockfd = socket;
}

void LPTF_Socket::setClientSockets(std::vector<SOCKET> clientSockets)
{
  this->clientSockets = clientSockets;
}

void LPTF_Socket::setAddr(sockaddr_in addr)
{
  this->addr = addr;
}

void LPTF_Socket::setBuffer(std::string buffer)
{
  this->sendbuf = buffer;
}