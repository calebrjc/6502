// File: emulator.cpp
// Author(s): Caleb Johnson-Cantrell

#include "mos6502.hpp"
#include "bus.hpp"

int main(int argc, char *argv[]) {
    calebrjc::MOS6502::MOS6502 cpu;
    calebrjc::MOS6502::Bus bus;

    bus.set_controller(cpu);
    Word addr = 0xFFFF;
    cpu.read(addr);
    Byte value = 0xEA;
    cpu.write(addr, value);

    return 0;
}
