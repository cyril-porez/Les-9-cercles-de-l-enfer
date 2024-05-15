#include "../../Common/include/LPTF_SOCKET.hpp"

int main()
{
  LPTF_SOCKET serverSocket;
  serverSocket.setUpService("0.0.0.0", 12345, true);

  if (serverSocket.bindLPTFSocket() != 0)
  {
    std::cerr << "Binding Failed. " << std::endl;
    return 1;
  }

  std::cout << "Binding check : " << std::endl;

  if (serverSocket.listenLPTFSocket() != 0)
  {
    std::cerr << "Listening Failed. " << std::endl;
    return 1;
  }

  std::cout << "Server is listening for incoming connections...." << std::endl;

  while (serverSocket.acceptLPTFSocket() == 0)
  {
    std::cerr << "Client Connected." << std::endl;

    char buffer[1024];
    if (serverSocket.recvLPTFSocket(buffer, sizeof(buffer), true) != 0)
    {
      std::cerr << "Failed to receive data." << std::endl;
    }
    else
    {
      std::cout << "Receive data: " << buffer << std::endl;
      std::string message = "Hello client!";
      if (serverSocket.sendLPTFSocket(message, true))
      {
        std::cerr << "Send Failed" << std::endl;
      }
    }

    serverSocket.closeLPTFSocket(true);
  }

  return 0;
}