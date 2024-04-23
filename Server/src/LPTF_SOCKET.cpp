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
    sockaddr_in service;  
  
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
        return 0;
      }
    }

    int bindLPTFSOCKET()
    {
      if(bind(sockfd, (SOCKADDR *)&service, sizeof(service)) == SOCKET_ERROR)
      {
        std::cerr << "Bind failed : " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        return 1;
      }
      std::cerr << "bind returned success" << std::endl;
      return 0;
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
      std::cerr << "connect returned success" << std::endl;
      return 0;
    }

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

    /**
     * @param socket Le socket connecté
     * @param buffer Le buffer de données
    */
    int recvLPTFSocket(SOCKET socket, char* buffer) {
      int iResult = recv(socket, buffer, sizeof(buffer), MSG_PEEK);
      if(iResult != 0) {
        std::cout << "recvLPTFSocket() failed: " << WSAGetLastError() <<
        std::endl;

        return 1;
      }

      std::cout << "Data successfully received" << std::endl;
      return 0;
    }

    void send()
    {
    }

    SOCKET getSocket()
    {
        return this->sockfd;
    }
};