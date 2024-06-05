// Server/main.cpp
#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"
#include "../../Common/include/LPTF_Packet.hpp"
#include "../include/LPTF_UserInterface.hpp"

int main()
{
  WSADATA wsaData;
  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0)
  {
    std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
    return 1;
  }

  LPTF_Socket serverSocket("127.0.0.1", 8080, true);
  std::cout << "Server initialized\n";

  if (serverSocket.bind() != 0)
  {
    std::cerr << "Error: Server cannot bind\n";
    return 1;
  }

  if (serverSocket.listen() != 0)
  {
    std::cerr << "Error: Server cannot listen\n";
    return 1;
  }

  fd_set master_set, read_set;
  FD_ZERO(&master_set);
  FD_ZERO(&read_set);
  FD_SET(serverSocket.getSocket(), &master_set);

  std::vector<SOCKET> clientSockets;

  while (true)
  {
    read_set = master_set;
    if (select(0, &read_set, nullptr, nullptr, nullptr) == SOCKET_ERROR)
    {
      std::cerr << "select failed with error: " << WSAGetLastError() << std::endl;
      return 1;
    }

    serverSocket.handleClientSockets(clientSockets, read_set);

    if (FD_ISSET(serverSocket.getSocket(), &read_set))
    {
      LPTF_Socket *clientSocket = serverSocket.accept();
      if (clientSocket != nullptr)
      {
        SOCKET clientSock = clientSocket->getSocket();
        clientSockets.push_back(clientSock);
        FD_SET(clientSock, &master_set);
      }
    }
  }

  WSACleanup();
  return 0;
}