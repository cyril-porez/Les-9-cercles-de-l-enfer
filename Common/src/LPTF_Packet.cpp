#include "../include/LPTF_Packet.hpp"

#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#ifdef UNICODE
#include <locale>
#include <codecvt>
#endif

LPTF_Packet::LPTF_Packet()
{
}

LPTF_Packet::LPTF_Packet(const LPTF_Packet &other)
{
    this->message = other.message;
}

LPTF_Packet::~LPTF_Packet()
{
}

// unsigned short LPTF_Packet::getCMD()
// {
// }

// unsigned short LPTF_Packet::getStatus()
// {
// }

// unsigned int LPTF_Packet::getPayloadLength(unsigned long &payload)
// {
// }

// unsigned long LPTF_Packet::getTimestamp()
// {
//     return std::time(nullptr);
// }

// unsigned long LPTF_Packet::getPayload()
// {
// }

// void LPTF_Packet::getClientData()
// {
//     this->.cmd = GET_INFO; // On sait quelle commande le serveur à envoyé

//     TCHAR infoBuf[15000];
//     DWORD bufCharCount = 15000;

//     if (!GetComputerName(infoBuf, &bufCharCount))
//     {
//         this->packet.status = CLIENT_ERR; // Erreur client
//     }
//     std::cout << "Computer name: " << infoBuf << std::endl;

//     if (!GetUserName(infoBuf, &bufCharCount))
//     {
//         this->packet.status = CLIENT_ERR; // Erreur client
//     }
//     std::cout << "User name: " << infoBuf << std::endl;

//     OSVERSIONINFO osvi;
//     ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
//     osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

//     std::time_t time = std::time(nullptr);
//     this->packet.timestamp = time;

//     if (GetVersionEx(&osvi))
//     {
//         std::cout << "OS: Windows " << std::to_string(osvi.dwMajorVersion) << "." << std::to_string(osvi.dwMinorVersion) << std::endl;
//         std::cout << "Timestamp: " << getTimestamp() << std::endl;
//     }

//     this->packet.status = SUCCESS;
// }

// LPTF_Packet &LPTF_Packet::operator=(const LPTF_Packet &other)
// {
//     this->packet = other.packet;

//     return *this;
// }

uint64_t htonll(uint64_t value)
{
    if (htonl(1) != 1)
    {
        uint32_t high_part = htonl(static_cast<uint32_t>(value >> 32));
        uint32_t low_part = htonl(static_cast<uint32_t>(value & 0xFFFFFFFF));
        return (static_cast<uint64_t>(low_part) << 32) | high_part;
    }
    else
    {
        return value;
    }
}

uint64_t ntohll(uint64_t value)
{
    if (htonl(1) != 1)
    {
        uint32_t high_part = ntohl(static_cast<uint32_t>(value >> 32));
        uint32_t low_part = ntohl(static_cast<uint32_t>(value & 0xFFFFFFFFLL));
        return (static_cast<uint64_t>(low_part) << 32) | high_part;
    }
    else
    {
        return value;
    }
}

Message::Message(uint8_t cmd, uint8_t status, const std::string &data)
{
    command = cmd;
    status_code = status;
    payload_length = htons(static_cast<uint16_t>(data.size()));
    timestamp = htonll(static_cast<uint64_t>(time(nullptr)));
    memcpy(payload, data.c_str(), data.size());

    if (data.size() < 256)
    {
        memset(payload + data.size(), 0, 256 - data.size());
    }
}

std::vector<uint8_t> LPTF_Packet::serializeMessage(const Message &msg)
{
    size_t total_size = sizeof(msg.command) + sizeof(msg.status_code) +
                        sizeof(msg.payload_length) + sizeof(msg.timestamp) +
                        sizeof(msg.payload);

    std::vector<uint8_t> buffer(total_size);
    uint8_t *ptr = buffer.data();

    memcpy(ptr, &msg.command, sizeof(msg.command));
    ptr += sizeof(msg.command);

    memcpy(ptr, &msg.status_code, sizeof(msg.status_code));
    ptr += sizeof(msg.status_code);

    memcpy(ptr, &msg.payload_length, sizeof(msg.payload_length));
    ptr += sizeof(msg.payload_length);

    memcpy(ptr, &msg.timestamp, sizeof(msg.timestamp));
    ptr += sizeof(msg.timestamp);

    memcpy(ptr, &msg.payload, sizeof(msg.payload));
    return buffer;
}

Message LPTF_Packet::deserializeMessage(const std::vector<uint8_t> &buffer)
{
    Message msg;
    const uint8_t *ptr = buffer.data();

    memcpy(&msg.command, ptr, sizeof(msg.command));
    ptr += sizeof(msg.command);

    memcpy(&msg.status_code, ptr, sizeof(msg.status_code));
    ptr += sizeof(msg.status_code);

    memcpy(&msg.payload_length, ptr, sizeof(msg.payload_length));
    ptr += sizeof(msg.payload_length);

    memcpy(&msg.timestamp, ptr, sizeof(msg.timestamp));
    ptr += sizeof(msg.timestamp);

    memcpy(&msg.payload, ptr, sizeof(msg.payload));

    msg.payload_length = ntohs(msg.payload_length);
    msg.timestamp = ntohll(msg.timestamp);

    return msg;
}