#ifndef STATICMORSEDICTIONARY_H
#define STATICMORSEDICTIONARY_H
#include "IMorseDictionary.h"

class StaticMorseDictionary : public IMorseDictionary
{
public:
    std::string_view encode(char c) const override;
    char decode(std::string_view input) const override;
};

#endif // STATICMORSEDICTIONARY_H
