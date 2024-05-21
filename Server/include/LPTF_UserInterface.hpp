#pragma once

#include "../../Common/include/LPTF_Socket.hpp"


class LPTF_UserInterface
{
    public:
        LPTF_UserInterface();
        LPTF_UserInterface(const LPTF_UserInterface& other);
        ~LPTF_UserInterface();

        void test(LPTF_Socket socket);

        LPTF_UserInterface& operator=(const LPTF_UserInterface &other);
};