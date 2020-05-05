#ifndef SIZECONVERSIONSO_BYTE_HPP
#define SIZECONVERSIONSO_BYTE_HPP

#include "crossPlatformMacros.hpp"

#include <string>

//afterCommaSize from 0 to 4 (0-1024 range)
EXPIMP_SIZECONVERSIONSO std::string formatByteSizeValue_f(const uint_fast64_t value_par, const int afterCommaSize = 1);


#endif // SIZECONVERSIONSO_BYTE_HPP
