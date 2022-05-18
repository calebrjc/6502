#ifndef CALEBRJC_6502_RAM_HPP_
#define CALEBRJC_6502_RAM_HPP_

#include <array>

#include "bus.hpp"

namespace calebrjc::MOS6502 {
    // Represents a random access memory unit
    class RAM : public Bus::Device {
      public:
        // Constructs a RAM that is sensitive to the range bounded by the inputted lower and upper
        // address bounds (inclusive)
        RAM(Word lowest_address, Word highest_address) :
            Bus::Device(AddressRange<Word>(lowest_address, highest_address)) {}

      private:
        // Returns the data being held at the specified address
        const Byte handle_read(Word address) override;

        // Writes the specified data to the specified address
        void handle_write(Word address, Byte data) override;

        // The container to be used as this ram's storage
        std::array<Byte, 0x10000> storage;
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_6502_RAM_HPP_
