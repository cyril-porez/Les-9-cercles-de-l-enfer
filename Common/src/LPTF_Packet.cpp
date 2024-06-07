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

MyPacket LPTF_Packet::getClientData()
{
  int command = GET_INFO;
  int status_code = PENDING;
  int timestamp = 0;
  char buf[256];
  std::string payload;

  TCHAR infoBuf[15000];
  DWORD bufCharCount = 15000;

  if (!GetComputerName(infoBuf, &bufCharCount))
  {
      status_code = CLIENT_ERR; // Erreur client
  }
  sprintf(buf, "Computer name: %s\n", infoBuf);
  payload.append(buf);

  if (!GetUserName(infoBuf, &bufCharCount))
  {
      status_code = CLIENT_ERR; // Erreur client
  }
  sprintf(buf, "User name: %s\n", infoBuf);
  payload.append(buf);

  OSVERSIONINFO osvi;
  ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

  std::time_t time = std::time(nullptr);
  timestamp = time;

  if (GetVersionEx(&osvi))
  {
    sprintf(buf, "OS: Windows %s.%s\n", std::to_string(osvi.dwMajorVersion), std::to_string(osvi.dwMinorVersion));
    payload.append(buf);
  }

  status_code = SUCCESS;
  MyPacket packet(command, status_code, payload);
  return packet;
}

LPTF_Packet &LPTF_Packet::operator=(const LPTF_Packet &other)
{
    return *this;
}