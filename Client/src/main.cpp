#include <iostream>
#include "../../Server/include/LPTF_SOCKET.hpp"

int main()
{
  LPTF_SOCKET clientSocket;
  clientSocket.setUpService("127.0.0.1", 12345, false);

  if (clientSocket.connectLPTFSocket() != 0)
  {
    std::cerr << "Connection failed." << std::endl;
    return 1;
  }

  std::cout << "Connected to server." << std::endl;

  std::string message = "Hello server !";
  if (clientSocket.sendLPTFSocket(message) != 0)
  {
    std::cerr << "send failed" << std::endl;
    return 1;
  }

  char buffer[1024];
  int nBytes = recv(clientSocket.getSocket(), buffer, sizeof(buffer), 0);
  if (nBytes < 0)
  {
    std::cerr << "recv failed" << std::endl;
    return 1;
  }
  else if (nBytes == 0)
  {
    std::cerr << "Server closed the connection" << std::endl;
    return 0;
  }

  std::cout << "Received from server: " << std::endl;

  clientSocket.closeLPTFSocket(clientSocket.getSocket());
  return 0;
}