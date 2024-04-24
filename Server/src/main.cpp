#include "LPTF_SOCKET.cpp"
#include <iostream>

int main()
{
  LPTF_SOCKET serverSocket;

  serverSocket.setUpService(12345);

  if (serverSocket.bindLPTFSocket() != 0)
  {
    std::cerr << "Binding Failed. " << std::endl;
    return 1;
  }

  if (serverSocket.listenLPTFSocket() != 0)
  {
    std::cerr << "Listening Failed. " << std::endl;
    return 1;
  }

  if (serverSocket.acceptLPTFSocket() != 0)
  {
    std::cerr << "Accepting Failed." << std::endl;
    return 1;
  }
}