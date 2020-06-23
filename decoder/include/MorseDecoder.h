#ifndef MORSEDECODER_H
#define MORSEDECODER_H

#include <string>
#include <string_view>
#include <memory>
#include "IMorseDictionary.h"
#include "Result.h"

class MorseDecoder
{
public:
    MorseDecoder(std::unique_ptr<IMorseDictionary>&& dict);
    MorseDecoder(MorseDecoder&&) = default;
    MorseDecoder& operator=(MorseDecoder&&) = default;

    Result<std::string> encode(std::string_view input) const;
    Result<std::string> decode(std::string_view input) const;

    MorseDecoder(const MorseDecoder&) = delete;
    MorseDecoder& operator=(const MorseDecoder&) = delete;

private:
    std::unique_ptr<IMorseDictionary> m_dict;
};

#endif // MORSEDECODER_H
