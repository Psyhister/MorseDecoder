#include "MorseDecoder.h"
#include <numeric>
#include <algorithm>

MorseDecoder::MorseDecoder(std::unique_ptr<IMorseDictionary> dict)
    : m_dict(std::move(dict))
{
}

Result<std::string> MorseDecoder::encode(std::string_view input) const
{
    std::string encodedString;
    for (const auto& symbol : input)
    {
        auto encodingSymbolResult = m_dict->encode(symbol);
        if (encodingSymbolResult.status == Status::Error)
        {
            return Result<std::string>::makeError(encodingSymbolResult.errorMsg);
        }
        encodedString.append(encodingSymbolResult.value);
        encodedString.append(1, ' ');
    }
    return Result<std::string>::makeSuccess(encodedString);
}

Result<std::string> MorseDecoder::decode(std::string_view input) const
{
    std::string decodedString;

    size_t spacePosition = 0;
    while (spacePosition != std::string_view::npos)
    {
        spacePosition = input.find(' ');
        auto decodingSymbolResult = m_dict->decode(input.substr(0, spacePosition));
        if (decodingSymbolResult.status == Status::Error)
        {
            return Result<std::string>::makeError(decodingSymbolResult.errorMsg);
        }
        decodedString.append(1, decodingSymbolResult.value);
        input.remove_prefix(spacePosition + 1);
    }

    return Result<std::string>::makeSuccess(decodedString);
}
