#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"

int main()
{
    LPTF_Socket serverSocket("0.0.0.0", 12345, true);

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

    while (true)
    {
        // Accepter une nouvelle connexion
        LPTF_Socket clientSocket = serverSocket.accept();
        if (clientSocket.getSocket() == INVALID_SOCKET)
        {
            std::cerr << "Accept failed." << std::endl;
            WSACleanup();
            return 1;
        }

        std::cout << "Client connected." << std::endl;

        // Communication avec le client
        char buffer[1024];
        int bytesReceived = clientSocket.recv(buffer, sizeof(buffer));
        if (bytesReceived < 0)
        {
            std::cerr << "recv failed." << std::endl;
            clientSocket.close(false);
            continue;
        }
        else if (bytesReceived == 0)
        {
            std::cerr << "Client closed the connection." << std::endl;
            clientSocket.close(false);
            continue;
        }

        buffer[bytesReceived] = '\0';
        std::cout << "Received from client: " << buffer << std::endl;

        std::string message = "Hello client!";
        if (clientSocket.send(message) != 0)
        {
            std::cerr << "Send failed." << std::endl;
            clientSocket.close(false);
            continue;
        }

        std::cout << "Sent to client: " << message << std::endl;

        // Fermer la connexion avec le client
        clientSocket.close(false);
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
