// Client/main.cpp
#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"
#include "../../Common/include/LPTF_Packet.hpp"

int main()
{
    LPTF_Socket clientSocket("127.0.0.1", 8080, false);
    LPTF_Packet packet;

    if (clientSocket.connect() != 0)
    {
        std::cerr << "Connection failed." << std::endl;
        return 1;
    }

    std::cout << "Connected to server." << std::endl;

    fd_set read_set;
    FD_ZERO(&read_set);

    Message message(1, 200, "Hello server!");
    if (clientSocket.send(clientSocket.getSocket(), message) != 0)
    {
        std::cerr << "send failed" << std::endl;
        return 1;
    }

    while (true)
    {
        FD_SET(clientSocket.getSocket(), &read_set);
        if (select(0, &read_set, nullptr, nullptr, nullptr) == SOCKET_ERROR)
        {
            std::cerr << "select failed with error: " << WSAGetLastError() << std::endl;
            return 1;
        }

        if (FD_ISSET(clientSocket.getSocket(), &read_set))
        {
            // char buffer[1024];
            Message receiveMessage;
            int result = clientSocket.recv(clientSocket.getSocket(), receiveMessage);
            if (result == 1)
            {
                std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
                break;
            }
            else if (result == 2)
            {
                std::cerr << "Connection closed by server." << std::endl;
                break;
            }
            else
            {
                std::cout << "Received from server:" << std::endl;
                std::cout << "Command: " << static_cast<int>(receiveMessage.command) << std::endl;
                std::cout << "Status Code: " << static_cast<int>(receiveMessage.status_code) << std::endl;
                std::cout << "Payload Length: " << receiveMessage.payload_length << std::endl;
                std::cout << "Timestamp: " << receiveMessage.timestamp << std::endl;
                std::cout << "Payload: " << receiveMessage.payload << std::endl;
            }

            if (static_cast<int>(receiveMessage.command) == 1)
            {
                std::string dataClient = packet.getClientData();

                Message message(0, 200, dataClient);
                if (clientSocket.send(clientSocket.getSocket(), message) != 0)
                {
                    std::cerr << "send failed" << std::endl;
                    return 1;
                }
            }
            else
            {
                Message responseMess(1, 005, "Commande non reconnu");
                clientSocket.send(clientSocket.getSocket(), responseMess);
            }
        }
    }

    clientSocket.close();
    return 0;
}
