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

    for (SOCKET s : clientSockets)
    {
      if (FD_ISSET(s, &read_set))
      {
        MyPacket packet(0, 0, "Hello from server");
        int result = serverSocket.recv(s, packet);
        if (result == 1)
        {
          std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
        }
        else if (result == 2)
        {
          std::cout << "Connection closed by peer.\n";
          closesocket(s);
          FD_CLR(s, &master_set);
          clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), s), clientSockets.end());
        }
        else
        {
          std::string input;
          while (true)
          {
            std::cout << "Entrez une commande : ";
            std::cin >> input;

            MyPacket query;

            if (input == "getInfo")
              query = LPTF_Packet::getClientData();
            if (input == "quit")
              break;
            else
              printf("Commande inconnue\n");

            if (serverSocket.send(s, query) != 0)
            {
              std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
            }
          }
        }
      }
    }

    if (FD_ISSET(serverSocket.getSocket(), &read_set))
    {
      LPTF_Socket *clientSocket = serverSocket.accept();
      if (clientSocket != nullptr)
      {
        clientSockets.push_back(clientSocket->getSocket());
        FD_SET(clientSocket->getSocket(), &master_set);
      }
    }
  }

  return 0;
}