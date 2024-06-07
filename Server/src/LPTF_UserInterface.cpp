#include "../include/LPTF_UserInterface.hpp"
#include "../../Common/include/LPTF_Socket.hpp"

#include <iostream>
#include <string>

LPTF_UserInterface::LPTF_UserInterface()
{
}

LPTF_UserInterface::LPTF_UserInterface(const LPTF_UserInterface &other)
{
}

LPTF_UserInterface::~LPTF_UserInterface()
{
}

void LPTF_UserInterface::test(LPTF_Socket socket)
{
  // std::string input;
  // while (input != "quit")
  // {
  //   std::cout << "Entrez une commande : ";
  //   std::cin >> input;

  //   MyPacket query(0, -1, input);

  //   if (input == "getInfo")
  //     query.command = GET_INFO;
  //   else
  //     query.command = 0;

  //   if (socket.send(socket.getSocket(), query) != 0)
  //   {
  //     std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
  //   }
  // }
}

LPTF_UserInterface &LPTF_UserInterface::operator=(const LPTF_UserInterface &other)
{
}