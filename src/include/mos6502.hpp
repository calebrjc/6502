// File: include/mos6502.hpp
// Author(s): Caleb Johnson-Cantrell

#ifndef CALEBRJC_MOS6502_MOS6502_HPP_
#define CALEBRJC_MOS6502_MOS6502_HPP_

#include "common.hpp"
#include "bus.hpp"

namespace calebrjc::MOS6502 {
    class MOS6502 : public Bus::Controller {
      public:
        // Constructs an instance of a MOS6502 emulation
        MOS6502();

        // Destructs an instance of a MOS6502 emulation
        ~MOS6502();

        // General-purpose registers
        Byte accumulator = 0x00;
        Byte index_X     = 0x00;
        Byte index_Y     = 0x00;

        // System registers
        Word program_counter = 0x0000;
        Byte stack_pointer   = 0x00;
        Byte status          = 0x00;

        // Processor status flags
        enum StatusFlags {
            CARRY     = (1 << 0),
            ZERO      = (1 << 1),
            INTERRUPT = (1 << 2),
            DECIMAL   = (1 << 3),
            BREAK     = (1 << 4),
            UNUSED    = (1 << 5),
            OVERFLOW  = (1 << 6),
            NEGATIVE  = (1 << 7),
        };

        // Resets the microprocessor to a known state
        void reset();

        // Emulates an interrupt request pulse
        void irq();

        // Emulates a non-maskable interrupt pulse
        void nmi();

        // Emulates the next clock cycle
        void clock();

        // Returns true if the 6502 is in the middle of executing an instruction
        bool is_busy();

      private:
        // Emulates the addressing modes of the 6502
        Byte implied();
        Byte immediate();
        Byte zero_page();
        Byte zero_page_indexed_x();
        Byte zero_page_indexed_y();
        Byte relative();
        Byte absolute();
        Byte absolute_indexed_x();
        Byte absolute_indexed_y();
        Byte indirect();
        Byte indexed_indirect();
        Byte indirect_indexed();

        // Emulates the 6502's legal mnemonics
        Byte ADC();  // Add with carry
        Byte AND();  // And (with accumulator)
        Byte ASL();  // Arithmetic shift left
        Byte BCC();  // Branch if carry clear
        Byte BCS();  // Branch if carry set
        Byte BEQ();  // Branch if equal (Z set)
        Byte BIT();  // Bit test
        Byte BMI();  // Branch if minus (N set)
        Byte BNE();  // Branch if not equal (Z clear)
        Byte BPL();  // Branch if plus (N clear)
        Byte BRK();  // Break/interrupt
        Byte BVC();  // Branch if overflow clear
        Byte BVS();  // Branch if overflow set
        Byte CLC();  // Clear carry bit
        Byte CLD();  // Clear decimal bit
        Byte CLI();  // Clear interrupt disable bit
        Byte CLV();  // Clear overflow bit
        Byte CMP();  // Compare (with accumulator)
        Byte CPX();  // Compare with X
        Byte CPY();  // Compare with Y
        Byte DEC();  // Decrement (memory byte)
        Byte DEX();  // Decrement X
        Byte DEY();  // Decrement Y
        Byte EOR();  // Exclusive or (with accumulator)
        Byte INC();  // Increment (memory byte)
        Byte INX();  // Increment X
        Byte INY();  // Increment Y
        Byte JMP();  // Jump
        Byte JSR();  // Jump to subroutine
        Byte LDA();  // Load accumulator
        Byte LDX();  // Load X
        Byte LDY();  // Load Y
        Byte LSR();  // Logical shift right
        Byte NOP();  // No operation
        Byte ORA();  // Or with accumulator
        Byte PHA();  // Push accumulator
        Byte PHP();  // Push processor status (status register)
        Byte PLA();  // Pull accumulator
        Byte PLP();  // Pull processor status (status register)
        Byte ROL();  // Rotate left (accumulator or memory)
        Byte ROR();  // Rotate right (accumulator or memory)
        Byte RTI();  // Return from interrupt
        Byte RTS();  // Return from subroutine
        Byte SBC();  // Subtract with carry
        Byte SEC();  // Set carry bit
        Byte SED();  // Set decimal bit
        Byte SEI();  // Set interrupt disable bit
        Byte STA();  // Store accumulator
        Byte STX();  // Store X
        Byte STY();  // Store Y
        Byte TAX();  // Transfer accumulator to X
        Byte TAY();  // Transfer accumularot to Y
        Byte TSX();  // Transfer stack pointer to X
        Byte TXA();  // Transfer X to accumulator
        Byte TXS();  // Transfer X to stack pointer
        Byte TYA();  // Transfer Y to accumulator

        // Captures illegal opcodes
        Byte XXX();
        
        // Allows processor status flags to be read from and written to conveniently
        Byte get_status_flag(StatusFlags flag);
        Byte set_status_flag(StatusFlags flag, bool value);
    };
}  // namespace calebrjc::MOS6502

#endif  // CALEBRJC_MOS6502_MOS6502_HPP_
