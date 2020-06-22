#ifndef IMORSEDICTIONARY_H
#define IMORSEDICTIONARY_H

#include <string>
#include <string_view>
#include "Result.h"

class IMorseDictionary
{
public:
    virtual Result<std::string_view> encode(char c) const = 0;
    virtual Result<char> decode(std::string_view input) const = 0;
    virtual ~IMorseDictionary() = default;
};

#endif // IMORSEDICTIONARY_H
