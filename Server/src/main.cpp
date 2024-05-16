#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"

int main()
{
  LPTF_Socket serverSocket("127.0.0.1", 8080, true);
  std::cout << "Server initialized\n";

  if (serverSocket.bind() != 0)
  {
    std::cout << "Error: Cannot bind server\n";
    return 1;
  }

  if (serverSocket.listen() != 0)
  {
    std::cout << "Error: Server cannot listen\n";
    return 1;
  }

  serverSocket.handleMultipleClients();

  return 0;
}

//  std::list<SOCKET> clientSockets;
//   fd_set readfs;
//   SOCKET maxSocket = serverSocket.getSocket();

//   std::cout << "Server is listening for incoming connections...." << std::endl;

//   while (true)
//   {
//     FD_ZERO(&readfs);
//     FD_SET(serverSocket.getSocket(), &readfs);

//     for (SOCKET sock : clientSockets)
//     {
//       FD_SET(sock, &readfs);
//     }

//     int activity = select(maxSocket + 1, &readfs, NULL, NULL, NULL);
//     if ((activity < 0) && (WSAGetLastError() != WSAEINTR))
//     {
//       std::cerr << "Select error.\n";
//       continue;
//     }

//     if (FD_ISSET(serverSocket.getSocket(), &readfs))
//     {
//       SOCKET newSocket = serverSocket.acceptLPTFSocket();
//       if (newSocket != INVALID_SOCKET)
//       {
//         clientSockets.push_back(newSocket);
//         std::cout << "New connection accepted.\n";
//       }
//     }

//     for (auto it = clientSockets.begin(); it != clientSockets.end();)
//     {
//       SOCKET sock = *it;
//       if (FD_ISSET(sock, &readfs))
//       {
//         char buffer[1024];
//         int bytesRead = recv(sock, buffer, 1024, 0);
//         if (bytesRead == 0)
//         { // Client disconnected
//           closesocket(sock);
//           it = clientSockets.erase(it);
//           std::cout << "Client disconnected.\n";
//         }
//         else if (bytesRead > 0)
//         {
//           buffer[bytesRead] = '\0';
//           std::cout << "Received: " << buffer << std::endl;
//           send(sock, buffer, bytesRead, 0);
//           ++it;
//         }
//         else
//         {
//           ++it;
//         }
//       }
//       else
//       {
//         ++it;
//       }
//     }

//     WSACleanup();

//     return 0;
//   }
