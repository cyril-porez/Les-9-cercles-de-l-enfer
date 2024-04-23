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

    int selectLPTFSocket(
      fd_set* readFds, fd_set* writeFds, fd_set* exceptFds,
      const timeval* timeout
    ) {
      int iResult = select(
        0, 
        readFds, writeFds, exceptFds, 
        timeout
      );
      if(iResult != 0) {
        std::cout << "selectLPTFSocket() failed: " << iResult << std::endl;
        return 1;
      }

      return 0;
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