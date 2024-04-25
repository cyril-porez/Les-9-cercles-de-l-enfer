#ifndef LPTF_SOCKET_H
#define LPTF_SOCKET_H

#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

class LPTF_SOCKET
{
private:
  SOCKET sockfd;
  struct sockaddr_in service, server, addr;
  std::string sendbuf;

public:
  LPTF_SOCKET();
  ~LPTF_SOCKET();
  void setUpService(const std::string &ip, int port, bool isServer = false);
  int acceptLPTFSocket();
  int bindLPTFSocket();
  int connectLPTFSocket();
  int listenLPTFSocket();
  int selectLPTFSocket(
      fd_set *readFds, fd_set *writeFds,
      fd_set *execptFds, const timeval *timeout);
  int recvLPTFSocket(SOCKET socket, char *buffer);
  int sendLPTFSocket(const std::string &message);
  SOCKET getSocket();
};

void LPTF_SOCKET::setUpService(const std::string &ip, int port, bool isServer)
{
  service.sin_family = AF_INET;
  service.sin_port = htons(port);

  if (isServer)
  {
    service.sin_addr.s_addr = INADDR_ANY;
  }
  else
  {
    service.sin_addr.s_addr = inet_addr(ip.c_str());
  }
  memset(service.sin_zero, 0, sizeof(service.sin_zero));
}

#endif