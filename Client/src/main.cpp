#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"

int main()
{
  LPTF_Socket clientSocket;
  clientSocket.setUpServiceClient("127.0.0.1", 12345, false);

  if (clientSocket.connect() != 0)
  {
    std::cerr << "Connection failed." << std::endl;
    return 1;
  }

  std::cout << "Connected to server." << std::endl;

  std::string message = "Hello server !";
  if (clientSocket.send(message, false) != 0)
  {
    std::cerr << "send failed" << std::endl;
    return 1;
  }

  std::cout << "Send succefully message : " << message << std::endl;

  char buffer[1024];
  // int nBytes = recv(clientSocket.getSocket(), buffer, sizeof(buffer), 0);
  int nBytes = clientSocket.recv(buffer, sizeof(buffer), false);
  if (nBytes < 0)
  {
    std::cerr << "recv failed" << WSAGetLastError() << std::endl;
    clientSocket.close(false);
    WSACleanup();
    return 1;
  }
  else if (nBytes == 0)
  {
    std::cerr << "Server closed the connection" << std::endl;
    clientSocket.close(false);
    WSACleanup();
    return 0;
  }

  buffer[nBytes] = '\0';
  std::cout << "Received from server: " << buffer << std::endl;

  clientSocket.close(false);
  WSACleanup();
  return 0;
}