#include <iostream>
#include <string.h>
#include <winsock2.h>

class LPTF_SOCKET
{
  private:
    int sockfd;
    sockaddr_in addr;
  
  public:
    LPTF_SOCKET() {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd == INVALID_SOCKET)
      {
        std::cerr << "Fail to create socket: " << WSAGetLastError()<< std::endl;
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

    void connect()
    {
      connect();
    }

    void listen()
    {

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
};