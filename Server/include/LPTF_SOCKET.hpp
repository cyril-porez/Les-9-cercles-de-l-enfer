#ifndef LPTF_SOCKET_H
#define LPTF_SOCKET_H

#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

class LPTF_SOCKET {
  private:
    SOCKET sockfd;
    struct sockaddr_in service, server, addr;
    std::string sendbuf;

  public:
    LPTF_SOCKET();
    ~LPTF_SOCKET();

    int acceptLPTFSocket(); 
    int bindLPTFSocket();
    int connectLPTFSocket();
    int listenLPTFSocket();
    int selectLPTFSocket(
      fd_set* readFds, fd_set* writeFds, 
      fd_set* execptFds, const timeval* timeout
    );
    int recvLPTFSocket(SOCKET socket, char* buffer);
    int sendLPTFSocket();
    int closeLPTFSocket(SOCKET socket);
    SOCKET getSocket();
};

#endif