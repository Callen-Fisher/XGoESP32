#pragma once

#include "util/func/send.h"

class Steering {
    public:
        //Steering();

        void unmount();

        void reset() {
            send(0x00, 0x21, 0x01);
        }
};