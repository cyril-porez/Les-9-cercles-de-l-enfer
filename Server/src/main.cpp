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
        std::cerr << "Error: Server cannot bind\n";
        return 1;
    }

    if (serverSocket.listen() != 0)
    {
        std::cerr << "Error: Server cannot listen\n";
        return 1;
    }

    std::cout << "Server ready to go!\n";
    serverSocket.handleMultipleClients();

    return 0;
}
