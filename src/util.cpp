// File: util.cpp
// Author(s): Caleb Johnson-Cantrell

#include "util.hpp"

int byte_to_int(Byte byte) { return ((int)byte & 0x000000FF); }

int word_to_int(Word word) { return ((int)word & 0x0000FFFF); }
