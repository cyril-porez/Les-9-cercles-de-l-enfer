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
    std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
    WSACleanup();
  }

  std::string message = "Hello from client";
  if(clientSocket.send(message) != 0) {
    std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
  };

  char buffer[1024];
  switch(clientSocket.recv(buffer, sizeof(buffer))) {
    case 1:
      std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
      break;
    
    case 2:
      std::cerr << "Connection closed by peer." << std::endl;
      break;
  }
  std::string bufferStr = std::string(buffer);
  std::string displayMsg = bufferStr.empty() ? "NULL" : buffer;
  std::cout << "Received from server: " << displayMsg << std::endl;

  clientSocket.close();
  return 0;
}