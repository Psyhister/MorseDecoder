#ifndef MORSEDECODER_H
#define MORSEDECODER_H

#include <string>
#include <string_view>
#include <memory>
#include "IMorseDictionary.h"

class MorseDecoder
{
public:
    MorseDecoder(std::unique_ptr<IMorseDictionary> dict);
    std::string encode(std::string_view input) const;
    std::string decode(std::string_view input) const;

    MorseDecoder(const MorseDecoder&) = delete;
    MorseDecoder& operator=(const MorseDecoder&) = delete;

private:
    std::unique_ptr<IMorseDictionary> m_dict;
};

#endif // MORSEDECODER_H
