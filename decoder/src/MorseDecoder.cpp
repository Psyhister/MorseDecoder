#include "MorseDecoder.h"

#include <numeric>
#include <algorithm>

MorseDecoder::MorseDecoder(std::unique_ptr<IMorseDictionary>&& dict)
    : m_dict(std::move(dict))
{
}

Result<std::string> MorseDecoder::encode(std::string_view input) const
{
    std::string encodedString;
    for (const auto& symbol : input)
    {
        if (symbol == '\n' || symbol == '\r')
        {
            if (encodedString.back() == ' ')
            {
                encodedString.pop_back();
            }
            encodedString.append(1, symbol);
        }
        else
        {
            auto encodingSymbolResult = m_dict->encode(symbol);
            if (encodingSymbolResult.status == Status::Error)
            {
                return Result<std::string>::makeError(encodingSymbolResult.errorMsg);
            }
            encodedString.append(encodingSymbolResult.value);
            encodedString.append(1, ' ');
        }
    }
    if (encodedString.back() == ' ')
    {
        encodedString.pop_back(); // easier to remove last space than rewriting the loop
    }
    return Result<std::string>::makeSuccess(encodedString);
}

Result<std::string> MorseDecoder::decode(std::string_view input) const
{
    std::string decodedString;

    size_t delimiterPosition = 0;
    while (delimiterPosition != std::string_view::npos)
    {
        delimiterPosition = input.find_first_of(" \n");
        auto chunk = input.substr(0, delimiterPosition);
        if (chunk.empty())
        {
            break;
        }

        std::string suffix;
        if (input[delimiterPosition] == '\n')
        {
            if (chunk.back() == '\r')
            {
                chunk.remove_suffix(1);
                suffix.push_back('\r');
            }
            suffix.push_back('\n');
        }
        auto decodingSymbolResult = m_dict->decode(chunk);
        if (decodingSymbolResult.status == Status::Error)
        {
            return Result<std::string>::makeError(decodingSymbolResult.errorMsg);
        }
        decodedString.append(1, decodingSymbolResult.value);
        decodedString.append(suffix);
        input.remove_prefix(delimiterPosition + 1);
    }

    return Result<std::string>::makeSuccess(decodedString);
}
