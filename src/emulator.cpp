// File: emulator.cpp
// Author(s): Caleb Johnson-Cantrell

#include <cstdlib>
#include <iostream>
#include <memory>

#include "bus.hpp"
#include "mos6502.hpp"
#include "ram.hpp"

int main(int argc, char *argv[]) {
    using namespace calebrjc::MOS6502;
    MOS6502 cpu;
    Bus bus;
    RAM ram(0x0000, 0xFFFF);

    bus.set_controller(&cpu);
    bus.add_device(&ram);

    cpu.write(0x0002, 0xEA);
    cpu.write(0x0001, 0xEB);
    std::cout << std::hex << (int)cpu.read(0x0002) << "\n";
    std::cout << std::hex << (int)cpu.read(0x0001) << "\n";
    std::cout << std::hex << (int)cpu.read(0x0002) << "\n";

    return EXIT_SUCCESS;
}
