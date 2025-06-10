//
// Created by paulw on 6/10/2025.
//

#pragma once
#include <cstdint>
#include "TAddress.h"


#define MODBUS_MAX_COILS 256
#define MODBUS_MAX_ISTS 4
#define MODBUS_MAX_IREGS 4
#define MODBUS_MAX_HREGS 360

// Arrays to store register values





// Structure to directly access registers by index
class StaticRegisterArray {
public:

    uint16_t coilRegisters[MODBUS_MAX_COILS]{};
    uint16_t istsRegisters[MODBUS_MAX_ISTS]{};
    uint16_t iregRegisters[MODBUS_MAX_IREGS]{};
    uint16_t hregRegisters[MODBUS_MAX_HREGS]{};


    uint16_t get(const TAddress address) const {
        switch (address.type) {
            case TAddress::COIL:
                if (address.address < MODBUS_MAX_COILS) {
                    return coilRegisters[address.address];
                }
                break;
            case TAddress::ISTS:
                if (address.address < MODBUS_MAX_ISTS) {
                    return istsRegisters[address.address];
                }
                break;
            case TAddress::IREG:
                if (address.address < MODBUS_MAX_IREGS) {
                    return iregRegisters[address.address];
                }
                break;
            case TAddress::HREG:
                if (address.address < MODBUS_MAX_HREGS) {
                    return hregRegisters[address.address];
                }
                break;
            default: ;
        }
        return 0;
    }

    bool set(const TAddress address, const uint16_t value) {
        switch (address.type) {
            case TAddress::COIL:
                if (address.address < MODBUS_MAX_COILS) {
                    coilRegisters[address.address] = value;
                    return true;
                }
                break;
            case TAddress::ISTS:
                if (address.address < MODBUS_MAX_ISTS) {
                    istsRegisters[address.address] = value;
                    return true;
                }
                break;
            case TAddress::IREG:
                if (address.address < MODBUS_MAX_IREGS) {
                    iregRegisters[address.address] = value;
                    return true;
                }
                break;
            case TAddress::HREG:
                if (address.address < MODBUS_MAX_HREGS) {
                    hregRegisters[address.address] = value;
                    return true;
                }
                break;
            default: ;
        }
        return false;
    }
};
