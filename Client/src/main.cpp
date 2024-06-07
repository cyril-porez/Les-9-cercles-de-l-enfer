// Client/main.cpp
#include <winsock2.h>
#include <iostream>
#include <list>
#include <algorithm>
#include "../../Common/include/LPTF_Socket.hpp"
#include "../../Common/include/LPTF_Packet.hpp"

int main()
{
  LPTF_Socket clientSocket("127.0.0.1", 8080, false);

  if (clientSocket.connect() != 0)
  {
    std::cerr << "Connection failed." << std::endl;
    return 1;
  }

  std::cout << "Connected to server." << std::endl;

  fd_set read_set;
  FD_ZERO(&read_set);

  MyPacket packet(0, 0, "Hello from client");
  if (clientSocket.send(packet) != 0)
  {
    std::cerr << "send failed" << std::endl;
    return 1;
  }

  while (true)
  {
    FD_SET(clientSocket.getSocket(), &read_set);
    if (select(0, &read_set, nullptr, nullptr, nullptr) == SOCKET_ERROR)
    {
      std::cerr << "select failed with error: " << WSAGetLastError() << std::endl;
      return 1;
    }

    if (FD_ISSET(clientSocket.getSocket(), &read_set))
    {
      MyPacket recvPacket;
      int result = clientSocket.recv(recvPacket);
      std::cout << "Packet received:" << recvPacket.toString() << std::endl;
      if (result == 1)
      {
        std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
        break;
      }
      else if (result == 2)
      {
        std::cerr << "Connection closed by server." << std::endl;
        break;
      }
      else
      {
        // Mettre du code coté client
      }

    }
  }

  clientSocket.close();
  return 0;
}