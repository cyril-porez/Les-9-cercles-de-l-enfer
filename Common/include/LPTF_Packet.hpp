#pragma once

struct MyPacket {
    unsigned short cmd;         // 2 bytes | Contient la commande associée
    unsigned short status;      // 2 bytes | Contient le code de statut
    unsigned int payloadLength; // 4 bytes | Contient la taille du payload
    
    unsigned long timestamp;    // 8 bytes | Contient le timestamp Unix
    unsigned long payload;      // 8 bytes | Contient les données envoyées
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


    LPTF_Packet& operator=(const LPTF_Packet &other);
};
