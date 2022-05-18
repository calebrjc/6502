#ifndef CALEBRJC_6502_BUS_HPP_
#define CALEBRJC_6502_BUS_HPP_

#include <memory>
#include <vector>

#include "address_range.hpp"
#include "common.hpp"

namespace calebrjc::MOS6502 {
    // Represents the mechanism by which data is transferred between IO devices and the processing
    // unit that controls them
    class Bus {
      public:
        // Represents an entity that can initiate reads and writes on the bus at will.
        class Controller {
          public:
            // This allows the bus to connect itself to this controller when `Bus::set_controller()`
            // is called
            friend class Bus;

            // Reads a byte from the specified address on the bus that this controller controls
            const Byte read(Word address) { return bus->read(address); }

            // Writes a byte to the specified address on the bus that this controller controls
            void write(Word address, Byte data) { return bus->write(address, data); }

          private:
            // The bus that this controller controls
            Bus *bus;
        };

        // Represents an entity that is responsible for responding to read and write requests given
        // to it by the bus
        class Device {
          public:
            // This allows the bus to instruct devices to handle reads and writes without exposing
            // explicit read and write functionality to anything else
            friend class Bus;

            // Constructs a bus device
            Device(AddressRange<Word> range) : address_range(range) {}

            // Represents the range of addresses that this device is sensitive to
            AddressRange<Word> address_range;

          private:
            // Handles a read request to this device at the specified address
            virtual const Byte handle_read(Word address) = 0;

            // Handles a write request to this device at the specified address
            virtual void handle_write(Word address, Byte data) = 0;
        };

        // Sets the inputted controller (most likely some processing unit) as the controller for the
        // bus
        void set_controller(Bus::Controller *controller);

        // Returns true if the inputted device was successfully added to the bus
        bool add_device(Bus::Device *device);

      private:
        // The current controller of the bus
        Bus::Controller *controller;

        // A container that holds all of the devices connected to the bus
        std::vector<Bus::Device *> devices;

        // Returns the byte read from the specified address
        const Byte read(Word address);

        // Writes the specified data to the specified address
        void write(Word address, Byte data);

        // Convienienvce function that returns a pointer to the device that is sensitive to the
        // inputted address, or `std::nullptr` otherwise
        Bus::Device *get_sensitive_device(Word address);

        // Convenience function that returns true if the inputted device is a viable candidate to be
        // added to the bus
        bool is_viable_candidate(Device *device);
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_6502_BUS_HPP_
