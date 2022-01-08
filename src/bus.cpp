// File: bus.cpp
// Author(s): Caleb Johnson-Cantrell

#include "bus.hpp"

namespace calebrjc::MOS6502 {
    Bus::Bus() {}

    Bus::~Bus() {}

    bool Bus::add_device(Bus::Device device) {
        device.bus = this;
        this->devices.push_back(device);
        return true;
    }

    void Bus::set_controller(Bus::Controller controller) {
        controller.bus   = this;
        this->controller = controller;
    }

    Byte Bus::read(Word address) { return 0x00; }

    void Bus::write(Word address, Byte data) {}
}  // namespace calebrjc::MOS6502
