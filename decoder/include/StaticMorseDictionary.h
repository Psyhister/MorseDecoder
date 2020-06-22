#ifndef STATICMORSEDICTIONARY_H
#define STATICMORSEDICTIONARY_H
#include "IMorseDictionary.h"

class StaticMorseDictionary : public IMorseDictionary
{
public:
    Result<std::string_view> encode(char c) const override;
    Result<char> decode(std::string_view input) const override;
};

#endif // STATICMORSEDICTIONARY_H
