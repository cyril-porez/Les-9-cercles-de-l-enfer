#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"

int main()
{
  LPTF_Socket clientSocket("127.0.0.1", 8080, false);

  if (clientSocket.connect() != 0)
  {
    return 1;
  }

  std::string message = "Hello from client";
  clientSocket.send(message);

  char buffer[1024];
  std::cout << "1\n";
  clientSocket.recv(buffer, sizeof(buffer));
  std::cout << "2\n";
  std::cout << "Received from server: " << buffer << std::endl;
  std::cout << "3\n";

  clientSocket.close();
  return 0;
}