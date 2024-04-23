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
      if (sockfd < 0)
      {
        printf("Echec cde la création du socket");
        exit(EXIT_FAILURE);
      }
    }

    void accept()
    {

    }

    void bind()
    {

    }

    void connect()
    {

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