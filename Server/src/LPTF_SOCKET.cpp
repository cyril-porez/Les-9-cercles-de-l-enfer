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

    /**
     * @param socket Un socket lié (bound) et non-connecté
     * @param backlog La taille maximum de la queue pour les connexions en attente
    */
    void listenLPTFSocket(SOCKET socket, int backlog) {
        if(listen(socket, backlog) == SOCKET_ERROR) 
            printf("listenLPTFSocket() function failed with error %d\n", WSAGetLastError());
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