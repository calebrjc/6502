#ifndef CALEBRJC_6502_ADDRESSRANGE_HPP_
#define CALEBRJC_6502_ADDRESSRANGE_HPP_

#include "common.hpp"

namespace calebrjc::MOS6502 {
    // Represents a range of addresses
    template<typename T>
    class AddressRange {
      public:
        // Convenience constructor for an address range
        AddressRange(T min, T max) : min(min), max(max) {};

        // Returns true if the inputted address is contained within this address range
        bool contains(T address) { return (min <= address && address <= max); }

        // Returns true if this address range intersects with the inputted address range
        bool intersects(AddressRange<T> other_range) {
            return (this->min <= other_range.max && other_range.min <= this->max);
        }

      private:
        // The lowest address that this device will be sensitive to
        T min;

        // The highest address that this device will be sensitive to
        T max;
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_6502_ADDRESSRANGE_HPP_
