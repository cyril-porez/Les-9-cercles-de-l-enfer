#pragma once

#include <iostream>
#include <string>
#include <winsock2.h>

class LPTF_Socket
{
private:
  SOCKET sockfd, clientSock;
  struct sockaddr_in addr;
  std::string sendbuf;

  void setUpService(const std::string &ip, int port, bool isServer = false);

public:
  LPTF_Socket();
  LPTF_Socket(const std::string &ip, int port, bool isServer);
  LPTF_Socket(const LPTF_Socket &other);
  ~LPTF_Socket();

  int accept();
  int bind();
  int connect();
  int listen();
  int select(
      fd_set *readFds, fd_set *writeFds,
      fd_set *execptFds, const timeval *timeout);
  int recv(char *buffer, int bufferSize, bool isServer);
  int send(const std::string &message, bool isServer);
  int close(bool isServer);
  SOCKET getSocket();

  LPTF_Socket &operator=(const LPTF_Socket &other);
};
