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

    if (clientSocket.connect() != 0)
    {
        std::cerr << "Connection failed." << std::endl;
        return 1;
    }

    std::cout << "Connected to server." << std::endl;

    fd_set read_set;
    FD_ZERO(&read_set);

    std::string message = "Hello server!";
    if (clientSocket.send(message) != 0)
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
            char buffer[1024];
            int result = clientSocket.recv(buffer, sizeof(buffer) - 1);
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
                std::cout << "Received from server: " << buffer << std::endl;
            }

            if (strcmp(buffer, "getInfo") == 0)
            {
                LPTF_Packet p = LPTF_Packet();
                // p.getClientData();
            }
            else
            {
                std::string mess = "Commande non reconnu";
                clientSocket.send(mess);
            }
        }
    }

    clientSocket.close();
    return 0;
}
