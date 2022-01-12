// File: bus.cpp
// Author(s): Caleb Johnson-Cantrell

#include <algorithm>

#include "bus.hpp"

namespace calebrjc::MOS6502 {
    bool Bus::add_device(Bus::Device *device) {
        // See if the device is a viable candidate to be added to the bus
        bool viable = is_viable_candidate(device);

        // If the device is not a viable candidate, do not add the device
        if (!viable) return false;

        // Otherwise, add the device to the bus
        this->devices.push_back(device);
        return true;
    }

    void Bus::set_controller(Bus::Controller *controller) {
        // Allowed because Bus is a friend class of Bus::Controller
        controller->bus = this;

        this->controller = controller;
    }

    const Byte Bus::read(Word address) {
        // Find the device that is sensitive to the read
        Device *sensitive_device = get_sensitive_device(address);

        // Have that device execute the read
        Byte data = (sensitive_device) ? sensitive_device->handle_read(address) : 0x00;

        return data;
    }

    void Bus::write(Word address, Byte data) {
        // Find the device that is sensitive to the read
        Device *sensitive_device = get_sensitive_device(address);

        // Have that device execute the read
        if (sensitive_device) sensitive_device->handle_write(address, data);
    }

    Bus::Device *Bus::get_sensitive_device(Word address) {
        for (Device *device : devices) {
            if (device->address_range.contains(address)) {
                return device;
            }
        }

        return nullptr;
    }

    bool Bus::is_viable_candidate(Device *device) {
        for (Device *d : devices) {
            if (d->address_range.intersects(device->address_range)) {
                return false;
            }
        }

        return true;
    }
}  // namespace calebrjc::MOS6502
