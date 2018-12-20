#ifndef SIZECONVERSIONSO_BYTE_HPP
#define SIZECONVERSIONSO_BYTE_HPP

#include "crossPlatformMacros.hpp"

#include <string>

namespace eines
{
//afterCommaSize from 0 to 4 (0-1024 range)
std::string EXPIMP_SIZECONVERSIONSO formatByteSizeValue_f(const uint_fast64_t value_par, const int afterCommaSize = 1);

}

#endif // SIZECONVERSIONSO_BYTE_HPP
