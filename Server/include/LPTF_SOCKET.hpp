#ifndef LPTF_SOCKET_H
#define LPTF_SOCKET_H

#include <iostream>
#include <string>
#include <winsock2.h>

class LPTF_SOCKET
{
private:
  SOCKET sockfd, clientSock;
  struct sockaddr_in service, server, addr;
  std::string sendbuf;

public:
  LPTF_SOCKET();
  ~LPTF_SOCKET();
  void setUpServiceClient(const std::string &ip, int port, bool isServer = false);
  void setUpServiceServer(const std::string &ip, int port, bool isServer = false);
  int acceptLPTFSocket();
  int bindLPTFSocket();
  int connectLPTFSocket();
  int listenLPTFSocket();
  int selectLPTFSocket(
      fd_set *readFds, fd_set *writeFds,
      fd_set *execptFds, const timeval *timeout);
  int recvLPTFSocket(char *buffer, int bufferSize, bool isServer);
  int sendLPTFSocket(const std::string &message, bool isServer);
  int closeLPTFSocket(bool isServer);
  SOCKET getSocket();
};

#endif