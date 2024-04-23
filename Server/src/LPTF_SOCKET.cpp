#include <iostream>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

class LPTF_SOCKET
{
private:
    int sockfd;
    sockaddr_in addr;

public:
    LPTF_SOCKET() {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == INVALID_SOCKET) {
            std::cerr << "Fail to create socket: " << WSAGetLastError() << std::endl;
        }
    }

    void accept()
    {
    }

    void bind()
    {
    }

    void connect() {
        connect();
    }

    /**
     * @param socket Un socket lié par la méthode ```bound()``` et non-connecté
     * @param backlog La taille maximum de la queue pour les connexions en attente
     */
    int listenLPTFSocket() {
        // On essaye d'écouter avec le socket de la classe et la taille 
        // de file d'attente maximum
        if (listen(this->sockfd, SOMAXCONN) == SOCKET_ERROR)
            printf("listenLPTFSocket() function failed with error %d\n", WSAGetLastError());
        else {
            printf("Listening of socket...");
            return 0;
        }
    }

    void select()
    {
    }

    void read()
    {
    }

    void recv()
    {
    }

    void send()
    {
    }

    SOCKET getSocket()
    {
        return this->sockfd;
    }
};