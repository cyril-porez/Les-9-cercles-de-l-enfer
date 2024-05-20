#include "../include/LPTF_Packet.hpp"

LPTF_Packet::LPTF_Packet() {

}

LPTF_Packet::LPTF_Packet(const LPTF_Packet& other) {
    this->packet = other.packet;
}

LPTF_Packet::~LPTF_Packet() {

}



LPTF_Packet& LPTF_Packet::operator=(const LPTF_Packet& other) {
    this->packet = other.packet;

    return *this;
}