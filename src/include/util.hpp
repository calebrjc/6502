// File: include/util.hpp
// Author(s): Caleb Johnson-Cantrell

#ifndef CALEBRJC_MOS6502_UTIL_HPP_
#define CALEBRJC_MOS6502_UTIL_HPP_

#include "common.hpp"

int byte_to_int(Byte byte) { return ((int)byte & 0x000000FF); }

int word_to_int(Word word) { return ((int)word & 0x0000FFFF); }

#endif  // CALEBRJC_MOS6502_UTIL_HPP_
