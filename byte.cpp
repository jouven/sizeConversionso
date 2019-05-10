#include "byte.hpp"

#include <vector>
#include <cmath>
#include <cstdlib>
#ifdef __ANDROID__
#include <sstream>
#endif

#ifdef __ANDROID__

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}
#endif

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
    //in theory android NDKr15c supports c++14, but it does not have std::to_string and std::lldiv... (which are c++11) WTF!?
    //search for BIONIC android STL for more "explanations", bravo google...
#ifdef __ANDROID__
    auto resultDivision(lldiv(value_par, magnitude));
#else
    std::lldiv_t resultDivision(std::lldiv(value_par, magnitude));
#endif
    int afterComma(0);
    if (shortNameIndex > 0 and resultDivision.rem > 0)
    {
#ifdef __ANDROID__
        auto resultDivisionAfter(lldiv(resultDivision.rem, magnitude / 1024));
#else
        std::lldiv_t resultDivisionAfter(std::lldiv(resultDivision.rem, magnitude / 1024));
#endif
        afterComma = resultDivisionAfter.quot;
    }
#ifdef __ANDROID__
    std::string resultStr(to_string(resultDivision.quot));
#else
    std::string resultStr(std::to_string(resultDivision.quot));
#endif
    if (afterComma > 0)
    {
#ifdef __ANDROID__
        std::string afterCommaNumberStr(to_string(afterComma));
#else
        std::string afterCommaNumberStr(std::to_string(afterComma));
#endif
        afterCommaNumberStr.resize(afterCommaSize);
        resultStr.append("." + afterCommaNumberStr);
    }
    resultStr.append(" ").append(byteSizeShortNames[shortNameIndex]);
    return resultStr;
}

