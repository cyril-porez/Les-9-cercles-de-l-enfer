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

    void acceptLptfSocket(SOCKET socket, sockaddr_in socketAdress)
    {
     int socketAdressLen = sizeof(socketAdress);
     SOCKET acceptedSocket = accept(socket, reinterpret_cast<sockaddr*>(&     socketAdress), &socketAdressLen);
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