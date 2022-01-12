// File: rom_loader.cpp
// Author(s): Caleb Johnson-Cantrell

#include <fstream>
#include <iomanip>
#include <iostream>

#include "rom_loader.hpp"
#include "util.hpp"

namespace calebrjc::MOS6502 {
    void ROMLoader::load_rom(std::string filename) {
        // Load the file into memory
        std::ifstream rom_file(filename, std::ifstream::binary | std::ifstream::in);

        // Get header data
        std::vector<Byte> header_data;
        header_data.resize(0x10);
        rom_file.read((char*)header_data.data(), header_data.size());

        std::vector<Byte> program_memory;
        program_memory.resize(0x4000);
        rom_file.read((char*)program_memory.data(), program_memory.size());

        for (size_t i = 0x0000; i < program_memory.size(); i++) {
            write(i + 0x8000, program_memory[i]);
            write(i + 0xC000, program_memory[i]);
        }
        
        /*
        Word current_line = 0x8000 - 16;
        for (size_t i = 0x8000; i <= 0xFFFF; i++) {
            // Discard header
            if (i < 16) continue;
            if (i % 16 == 0) {
                std::cout << "\n";
                current_line += 16;
                std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex
                          << word_to_int(current_line) << ": ";
            }
            std::cout << "0x" << std::setfill('0') << std::setw(2) << std::hex
                      << byte_to_int(read(i)) << " ";
        }
        std::cout << "\n";
        */
    }  // namespace calebrjc::MOS6502
}  // namespace calebrjc::MOS6502
