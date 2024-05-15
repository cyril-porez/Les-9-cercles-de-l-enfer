#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"

int main()
{
  LPTF_Socket serverSocket;
  serverSocket.setUpServiceServer("0.0.0.0", 12345, true);

  if (serverSocket.bind() != 0)
  {
    std::cerr << "Binding Failed. " << std::endl;
    return 1;
  }

  std::cout << "Binding check : " << std::endl;

  if (serverSocket.listen() != 0)
  {
    std::cerr << "Listening Failed. " << std::endl;
    return 1;
  }

  while (serverSocket.accept() == 0)
  {
    std::cerr << "Client Connected." << std::endl;

    char buffer[1024];
    if (serverSocket.recv(buffer, sizeof(buffer), true) != 0)
    {
      std::cerr << "Failed to receive data." << std::endl;
    }
    else
    {
      std::cout << "Receive data: " << buffer << std::endl;
      std::string message = "Hello client!";
      if (serverSocket.send(message, true))
      {
        std::cerr << "Send Failed" << std::endl;
      }
    }

    serverSocket.close(true);
  }
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