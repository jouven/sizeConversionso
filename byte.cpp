#include "byte.hpp"

#include <vector>
#include <cmath>

namespace eines
{

std::string formatByteSizeValue_f(const uint_fast64_t value_par, const int afterCommaSize)
{
    //a 64bit integer can only fit up to exabytes
    //18446744073709551616 max 64bit value
    //1000000000000000000 bytes = 1 exabyte
    //1000000000000000000000 bytes = 1 zetabyte
    const std::vector<std::string> byteSizeShortNames {{"B"}, {"KB"}, {"MB"}, {"GB"}, {"TB"}, {"PB"}, {"EB"}};
    //double iteratedValue(value_par_con);
    uint_fast64_t magnitude(1);
    unsigned int shortNameIndex(0);
    while (((magnitude * 1024) - 1) < value_par)
    {
        shortNameIndex = shortNameIndex + 1;
        magnitude = magnitude * 1024;
        //someday? (the day c++ gets the next native value after 64bit)
//        if (acronymIndex == (byteSizeAcronyms.size() - 1))
//        {
//            break;
//        }
    }
    std::lldiv_t resultDivision(std::lldiv(value_par, magnitude));
    int afterComma(0);
    if (shortNameIndex > 0 and resultDivision.rem > 0)
    {
        std::lldiv_t resultDivisionAfter(std::lldiv(resultDivision.rem, magnitude / 1024));
        afterComma = resultDivisionAfter.quot;
    }
    std::string resultStr(std::to_string(resultDivision.quot));
    if (afterComma > 0)
    {
        std::string afterCommaNumberStr(std::to_string(afterComma));
        afterCommaNumberStr.resize(afterCommaSize);
        resultStr.append("." + afterCommaNumberStr);
    }
    resultStr.append(" ").append(byteSizeShortNames[shortNameIndex]);
    return resultStr;
}

}
