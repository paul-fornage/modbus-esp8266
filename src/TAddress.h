//
// Created by paulw on 6/10/2025.
//

#ifndef TADDRESS_H
#define TADDRESS_H
#include <cstdint>


struct TAddress {
    enum RegType {COIL, ISTS, IREG, HREG, NONE = 0xFF};
    RegType type;
    uint16_t address;
    bool operator==(const TAddress &obj) const { // TAddress == TAddress
        return type == obj.type && address == obj.address;
    }
    bool operator!=(const TAddress &obj) const { // TAddress != TAddress
        return type != obj.type || address != obj.address;
    }
    TAddress& operator++() {     // ++TAddress
        address++;
        return *this;
    }
    TAddress  operator++(int) {  // TAddress++
        const TAddress result(*this);
        ++(*this);
        return result;
    }
    TAddress& operator+=(const int& inc) {  // TAddress += integer
        address += inc;
        return *this;
    }

    TAddress operator+(const int &inc) const {    // TAddress + integer
        TAddress result(*this);
        result.address += inc;
        return result;
    }
    bool isCoil() const {
        return type == COIL;
    }
    bool isIsts() const {
        return type == ISTS;
    }
    bool isIreg() const {
        return type == IREG;
    }
    bool isHreg() const {
        return type == HREG;
    }
};


#endif //TADDRESS_H
