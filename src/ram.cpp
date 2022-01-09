// File: ram.cpp
// Author(s): Caleb Johnson-Cantrell

#include "ram.hpp"

namespace calebrjc::MOS6502 {
    const Byte RAM::handle_read(Word address) {
        if (address >= storage.size()) return 0x00;

        return storage[address];
    }

    void RAM::handle_write(Word address, Byte data) {
        if (address >= storage.size()) return;

        storage[address] = data;
    }
}  // namespace calebrjc::MOS6502
