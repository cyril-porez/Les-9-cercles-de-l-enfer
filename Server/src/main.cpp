#include "LPTF_SOCKET.cpp"

int main() {

    /**
     * INITIALISATION
    */
    WSAData wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    // FAIRE LES TESTS ICI

    // On ferme et nettoie WSA
    WSACleanup();
}