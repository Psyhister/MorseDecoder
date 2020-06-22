#include "MorseDecoder.h"
#include <numeric>
#include <algorithm>

MorseDecoder::MorseDecoder(std::unique_ptr<IMorseDictionary> dict)
    : m_dict(std::move(dict))
{
}

std::string MorseDecoder::encode(std::string_view input) const
{
    auto fold = [this](std::string a, char c) {
        return a.append(" ").append(m_dict->encode(c));
    };
    return std::accumulate(std::next(input.cbegin()), input.cend(), std::string(m_dict->encode(input.front())), fold);
}

std::string MorseDecoder::decode(std::string_view input) const
{
    std::string res;

    size_t end = 0;
    while (end != std::string_view::npos)
    {
        end = input.find(' ');
        res.append(1, m_dict->decode(input.substr(0, end)));
        input.remove_prefix(end + 1);
    }

    return res;
}
