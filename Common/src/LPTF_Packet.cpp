#include "../include/LPTF_Packet.hpp"

#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#ifdef UNICODE
#include <locale>
#include <codecvt>
#endif


// Helper function to convert 64-bit integers to network byte order
uint64_t htonll(uint64_t value) {
    if (htonl(1) != 1) {
        // If system is little-endian
        return (((uint64_t)htonl(value)) << 32) | htonl(value >> 32);
    } else {
        return value;
    }
}

// Helper function to convert 64-bit integers to host byte order
uint64_t ntohll(uint64_t value) {
    if (ntohl(1) != 1) {
        // If system is little-endian
        return (((uint64_t)ntohl(value)) << 32) | ntohl(value >> 32);
    } else {
        return value;
    }
}

void serializeMessage(const Message& msg, char* buffer) {
    size_t offset = 0;

    // Copy command
    memcpy(buffer + offset, &msg.command, sizeof(msg.command));
    offset += sizeof(msg.command);

    // Copy status_code
    memcpy(buffer + offset, &msg.status_code, sizeof(msg.status_code));
    offset += sizeof(msg.status_code);

    // Copy payload_length
    memcpy(buffer + offset, &msg.payload_length, sizeof(msg.payload_length));
    offset += sizeof(msg.payload_length);

    // Copy timestamp
    uint64_t network_timestamp = htonll(msg.timestamp);
    memcpy(buffer + offset, &network_timestamp, sizeof(network_timestamp));
    offset += sizeof(network_timestamp);

    // Copy payload
    memcpy(buffer + offset, msg.payload, sizeof(msg.payload));
    offset += sizeof(msg.payload);
}

void deserializeMessage(const char* buffer, Message& msg) {
    size_t offset = 0;

    // Copy command
    memcpy(&msg.command, buffer + offset, sizeof(msg.command));
    offset += sizeof(msg.command);

    // Copy status_code
    memcpy(&msg.status_code, buffer + offset, sizeof(msg.status_code));
    offset += sizeof(msg.status_code);

    // Copy payload_length
    memcpy(&msg.payload_length, buffer + offset, sizeof(msg.payload_length));
    offset += sizeof(msg.payload_length);
    msg.payload_length = ntohs(msg.payload_length);

    // Copy timestamp
    uint64_t network_timestamp;
    memcpy(&network_timestamp, buffer + offset, sizeof(network_timestamp));
    msg.timestamp = ntohll(network_timestamp);
    offset += sizeof(network_timestamp);

    // Copy payload
    memcpy(msg.payload, buffer + offset, sizeof(msg.payload));
    offset += sizeof(msg.payload);
}

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
    TCHAR infoBuf[15000];
    DWORD bufCharCount = 15000;

    std::cout << "Computer name: " << infoBuf << std::endl;
    std::cout << "User name: " << infoBuf << std::endl;

    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (GetVersionEx(&osvi))
    {
        std::cout << "OS: Windows " << std::to_string(osvi.dwMajorVersion) << "." << std::to_string(osvi.dwMinorVersion) << std::endl;
        std::cout << "Timestamp: " << getTimestamp() << std::endl;
    }
}

LPTF_Packet &LPTF_Packet::operator=(const LPTF_Packet &other)
{
    return *this;
}