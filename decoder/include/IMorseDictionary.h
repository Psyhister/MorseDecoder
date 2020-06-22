#ifndef IMORSEDICTIONARY_H
#define IMORSEDICTIONARY_H

#include <string>
#include <string_view>

class IMorseDictionary
{
public:
    virtual std::string_view encode(char c) const = 0;
    virtual char decode(std::string_view input) const = 0;
    virtual ~IMorseDictionary() = default;
};

#endif // IMORSEDICTIONARY_H
