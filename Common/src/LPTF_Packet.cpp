#include "../include/LPTF_Packet.hpp"

#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#ifdef UNICODE
#include <locale>
#include <codecvt>
#endif

// uint64_t htonll(uint64_t value) {
//     if (htonl(1) != 1) {
//         uint32_t hi = htonl((uint32_t)(value >> 32));
//         uint32_t lo = htonl((uint32_t)(value & 0xFFFFFFFFLL));
//         return ((uint64_t) lo << 32) | hi;
//     } else {
//         return value;
//     }
// }

// uint64_t ntohll(uint64_t value) {
//     if (ntohl(1) != 1) {
//         uint32_t hi = ntohl((uint32_t)(value >> 32));
//         uint32_t lo = ntohl((uint32_t)(value & 0xFFFFFFFFLL));
//         return ((uint64_t) lo << 32) | hi;
//     } else {
//         return value;
//     }
// }

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