#include <iostream>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

class LPTF_SOCKET
{
private:
    int sockfd;
    sockaddr_in addr;
    struct  sockaddr_in server;    
  
  public:

public:
    LPTF_SOCKET() {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd == INVALID_SOCKET) {
        std::cerr << "Fail to create socket: " << WSAGetLastError() <<std::endl;
      }
    }

    int acceptLptfSocket()
    {

      int adressLen = sizeof(addr);

      SOCKET clientSocket = accept(sockfd, reinterpret_cast<sockaddr*>
      (&addr), &adressLen);

      if (clientSocket == INVALID_SOCKET)
      {
        std::cerr << "accept failed with error: " 
                  << WSAGetLastError()
                  << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
      }
      else
      {
        wprintf(L"Client connected.\n");
        closesocket(sockfd);
        WSACleanup();
        return 0;
      }
      
      

    }

    void bind()
    {
    }

    int connectLPTFSocket()
    {
      if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
      {
        std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
      }
      return 0;
    }

    /**
     * @param socket Un socket lié par la méthode ```bound()``` et non-connecté
     * @param backlog La taille maximum de la queue pour les connexions en attente
     */
    int listenLPTFSocket() {
      // On essaye d'écouter avec le socket de la classe et la taille 
      // de file d'attente maximum
      if (listen(this->sockfd, SOMAXCONN) == SOCKET_ERROR)
      {
        std::cerr << "Listen failed : " << WSAGetLastError() << std::endl;
        return 1;
      }
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