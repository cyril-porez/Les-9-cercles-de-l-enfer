// Server/main.cpp
#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"
#include "../../Common/include/LPTF_Packet.hpp"

int main()
{
    LPTF_Packet LPTFPacket;
    Message msg(1, 200, "Test payload");

    std::vector<uint8_t> serializedMsg = LPTFPacket.serializeMessage(msg);
    Message deserialized_msg = LPTFPacket.deserializeMessage(serializedMsg);

    std::cout << "Command: " << static_cast<int>(deserialized_msg.command) << std::endl;
    std::cout << "Status Code: " << static_cast<int>(deserialized_msg.status_code) << std::endl;
    std::cout << "Payload: " << deserialized_msg.payload << std::endl;

    std::cout << "-------Fint test serialization-------" << std::endl;

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
        if (serverSocket.select(&read_set, nullptr, nullptr, nullptr) == 1)
        {
            std::cerr << "select failed\n";
            return 1;
        }

        for (SOCKET s : clientSockets)
        {
            if (FD_ISSET(s, &read_set))
            {
                char buffer[1024];
                Message receiveMessage;
                int result = serverSocket.recv(s, receiveMessage);
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
                    std::cout << "Received from client: " << buffer << std::endl;
                    std::cout << "Entrez votre commande : ";
                    std::string message;
                    std::cin >> message;
                    Message msg(1, 200, message);
                    if (serverSocket.send(s, msg) != 0)
                    {
                        std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
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