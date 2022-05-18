#include "bus.hpp"
#include "mos6502.hpp"
#include "ram.hpp"

int main(int argc, char *argv[]) {
    using namespace calebrjc::MOS6502;

    MOS6502 cpu;
    Bus bus;
    RAM ram(0x0000, 0xFFFF);

    bus.add_device(&ram);
    bus.set_controller(&cpu);

    return EXIT_SUCCESS;
}
