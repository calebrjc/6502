// File: emulator.cpp
// Author(s): Caleb Johnson-Cantrell

#include <cstdlib>
#include <iostream>
#include <memory>

#include "bus.hpp"
#include "mos6502.hpp"
#include "ram.hpp"
#include "rom_loader.hpp"

int main(int argc, char *argv[]) {
    using namespace calebrjc::MOS6502;

    MOS6502 cpu;
    Bus bus;
    RAM ram(0x0000, 0xFFFF);
    ROMLoader loader;


    bus.add_device(&ram);
    bus.set_controller(&loader);
    loader.load_rom("test_roms/nestest.nes");
    std::cout << std::hex << ((int)loader.read(0x4000) & 0x000000FF) << "\n";
    bus.set_controller(&cpu);

    return EXIT_SUCCESS;
}
