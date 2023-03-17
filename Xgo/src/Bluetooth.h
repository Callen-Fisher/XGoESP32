#pragma once

#include "util/enum/BluetoothStatus.h"
#include "util/func/send.h"

class Bluetooth {
  public:
    //Bluetooth();
    
    /*0x10*/ BluetoothStatus::BluetoothStatus getStatus();
    /*0x11*/ int getBaudRate();
    
    /*0x12*/ int getPassword();
    /*0x12*/ void setPassword(int password) {
      send(0x12, password);
    }
    
    /*0x13*/ String getName();
    /*0x13*/ void setName(String name);
};
