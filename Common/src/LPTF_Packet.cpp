#include "../include/LPTF_Packet.hpp"

#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#ifdef UNICODE
#include <locale>
#include <codecvt>
#endif

LPTF_Packet::LPTF_Packet()
{
}

LPTF_Packet::LPTF_Packet(const LPTF_Packet &other)
{
}

LPTF_Packet::~LPTF_Packet()
{
}

unsigned short LPTF_Packet::getCMD()
{
}

unsigned short LPTF_Packet::getStatus()
{
}

unsigned int LPTF_Packet::getPayloadLength(unsigned long &payload)
{
}

unsigned long LPTF_Packet::getTimestamp()
{
  return std::time(nullptr);
}

unsigned long LPTF_Packet::getPayload()
{
}

void LPTF_Packet::getClientData()
{
  // this->packet.cmd = GET_INFO; // On sait quelle commande le serveur à envoyé

  // TCHAR infoBuf[15000];
  // DWORD bufCharCount = 15000;

  // if (!GetComputerName(infoBuf, &bufCharCount))
  // {
  //     this->packet.status = CLIENT_ERR; // Erreur client
  // }
  // std::cout << "Computer name: " << infoBuf << std::endl;

  // if (!GetUserName(infoBuf, &bufCharCount))
  // {
  //     this->packet.status = CLIENT_ERR; // Erreur client
  // }
  // std::cout << "User name: " << infoBuf << std::endl;

  // OSVERSIONINFO osvi;
  // ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
  // osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

  // std::time_t time = std::time(nullptr);
  // this->packet.timestamp = time;

  // if (GetVersionEx(&osvi))
  // {
  //     std::cout << "OS: Windows " << std::to_string(osvi.dwMajorVersion) << "." << std::to_string(osvi.dwMinorVersion) << std::endl;
  //     std::cout << "Timestamp: " << getTimestamp() << std::endl;
  // }

  // this->packet.status = SUCCESS;
}

LPTF_Packet &LPTF_Packet::operator=(const LPTF_Packet &other)
{
    return *this;
}