#include <iostream>
#include <string.h>
#include <winsock2.h>

class LPTF_SOCKET
{
  private:
    int sockfd;
    sockaddr_in addr;
    struct  sockaddr_in server;    
  
  public:
    LPTF_SOCKET() {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd == INVALID_SOCKET)
      {
        std::cerr << "Fail to create socket: " << WSAGetLastError()<< std::endl;
      }
    }

    void accept()
    {

    }

    void bind()
    {

    }

    int connectLPTFSocket()
    {
      if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
      {
        std::cerr << "Connection fail : " << WSAGetLastError << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
      }
      return 0;
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