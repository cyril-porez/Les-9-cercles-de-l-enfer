#pragma once

#include <cstdint>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <winsock2.h>

struct MyPacket {
    uint8_t command;
    uint8_t status_code;
    uint16_t payload_length;
    uint64_t timestamp;
    char payload[256];

    MyPacket() {}
 
    MyPacket(uint8_t cmd, uint8_t status, const std::string& data) {
        command = cmd;
        status_code = status;
        payload_length = htons(data.size());
        timestamp = htonl(time(nullptr));
        memcpy(payload, data.c_str(), data.size());
    }

    char* toString() {
      char* res =
        "command:\t%d\n" \
        "status:\t%d\n" \
        "length:\t\%d\n" \
        "timestamp:\t%d\n" \
        "payload:\n%s\n";
      sprintf(
        res, res,
        this->command, this->status_code, this->payload_length,
        this->timestamp, this->payload
      );

      return res;
    }
};

// struct MyPacket {
//     unsigned short cmd;         // 2 bytes | Contient la commande associée
//     unsigned short status;      // 2 bytes | Contient le code de statut
//     unsigned int payloadLength; // 4 bytes | Contient la taille du payload
    
//     unsigned long timestamp;    // 8 bytes | Contient le timestamp Unix
//     unsigned long payload;      // 8 bytes | Contient les données envoyées
// };

enum STATUS_CODE {
    SUCCESS = 0,
    CMD_NOT_FOUND = 1,
    TIMEOUT = 2,
    SERVER_ERR = 3,
    CLIENT_ERR = 4
};

// enum CMD {
//     GET_INFO = 0x01,
//     TOGGLE_KEYLOG = 0x02,
//     GET_PROC_LIST = 0x03,
//     EXEC_SYS_CMD = 0x04
// };


class LPTF_Packet
{
public:
    // Constructors
    LPTF_Packet();
    LPTF_Packet(const LPTF_Packet& other);
    ~LPTF_Packet();

    // Builders
    unsigned short getCMD();
    unsigned short getStatus();
    unsigned int getPayloadLength(unsigned long &payload);
    unsigned long getTimestamp();
    unsigned long getPayload();

    void getClientData();

    LPTF_Packet& operator=(const LPTF_Packet &other);
};
