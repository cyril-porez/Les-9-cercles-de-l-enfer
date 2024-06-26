#pragma once

#include <iostream>
#include <string>
#include <winsock2.h>
#include <vector>
#include "LPTF_Packet.hpp"

class LPTF_Socket
{
private:
  SOCKET sockfd;
  std::vector<SOCKET> clientSockets;
  struct sockaddr_in addr;
  std::string sendbuf;

  void setUpService(const std::string &ip, int port, bool isServer = false);

public:
  LPTF_Socket();
  LPTF_Socket(const std::string &ip, int port, bool isServer);
  LPTF_Socket(const LPTF_Socket &other);
  ~LPTF_Socket();

  LPTF_Socket *accept();
  int bind();
  int connect();
  int listen();
  int select(
      fd_set *readFds, fd_set *writeFds,
      fd_set *execptFds, const timeval *timeout);

  int recv(SOCKET clientSock, Message &message);
  // int recv(char *buffer, int bufferSize);

  int send(SOCKET clientSock, const Message &message);
  // int send(const std::string &message);

  int close();

  // int handleMultipleClients();
  // void handleClientSockets(std::vector<SOCKET> clientSockets, fd_set fdList);

  // GETTERS
  SOCKET getSocket();
  std::vector<SOCKET> getClientSockets();
  sockaddr_in getAddr();
  std::string getBuffer();

  // SETTERS
  void setSocket(SOCKET);
  void setClientSockets(std::vector<SOCKET>);
  void setAddr(sockaddr_in);
  void setBuffer(std::string);

  LPTF_Socket &operator=(const LPTF_Socket &other);
};
