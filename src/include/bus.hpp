// File: include/bus.hpp
// Author(s): Caleb Johnson-Cantrell

#ifndef CALEBRJC_MOS6502_BUS_HPP_
#define CALEBRJC_MOS6502_BUS_HPP_

#include <vector>

#include "common.hpp"

namespace calebrjc::MOS6502 {
    class Bus {
      public:
        // Constructs a new bus
        Bus();

        // Destructs a bus
        ~Bus();

        class Controller {
          public:
            friend class Bus;

            // Read a byte from the specified address on the bus that this controller controls
            Byte read(Word address) { return bus->read(address); }

            // Writes a byte to the specified address on the bus that this controller controls
            void write(Word address, Byte data) { return bus->write(address, data); }

          private:
            // The bus that this controller controls
            Bus *bus;
        };

        class Device {
          public:
            friend class Bus;

            // Handles a read request to this device at the specified address
            Byte handle_read(Word address);

            // Handles a write request to this device at the specified address
            void handle_write(Word address, Byte data);

          private:
            // The bus that this controller controls
            Bus *bus;
        };

        // Sets the inputted device as the controller for the bus (most likely some processing unit)
        void set_controller(Bus::Controller controller);

        // Returns true if the inputted device was successfully added to the bus
        bool add_device(Bus::Device device);

      private:
        // The current controller of the bus
        Bus::Controller controller;

        // A container that holds all of the devices connected to the bus
        std::vector<Bus::Device> devices;

        // Returns the byte read from the specified address
        Byte read(Word address);

        // Writes the specified data to the specified address
        void write(Word address, Byte data);
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_MOS6502_BUS_HPP_
