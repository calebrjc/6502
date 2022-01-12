// File: include/rom_loader.hpp
// Author(s): Caleb Johnson-Cantrell

#ifndef CALEBRJC_MOS6502_ROMLOADER_HPP_
#define CALEBRJC_MOS6502_ROMLOADER_HPP_

#include <string>

#include "bus.hpp"
#include "common.hpp"

namespace calebrjc::MOS6502 {
    class ROMLoader : public Bus::Controller {
      public:
        // Loads the ROM from the file `filename` into the emulator, starting at the address
        // specified by `starting_address`. Also sets FFFC/FFFD to the starting address so that
        // execution begins where the ROM begins
        void load_rom(std::string filename);
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_MOS6502_ROMLOADER_HPP_
