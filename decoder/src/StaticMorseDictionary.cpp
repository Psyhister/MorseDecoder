#include "StaticMorseDictionary.h"
#include <array>
#include <algorithm>

constexpr std::array<std::string_view, 26> LETTER_TO_MORSE {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
};

constexpr std::string_view SPACE = ".......";

Result<std::string_view> StaticMorseDictionary::encode(char c) const
{
    if (c == ' ')
    {
        return Result<std::string_view>::makeSuccess(SPACE);
    }
    else
    {
        int idx = c - 'A';
        if (idx < 0 || idx >= static_cast<int>(LETTER_TO_MORSE.size()))
        {
            return Result<std::string_view>::makeError("Unsupported character");
        }
        return Result<std::string_view>::makeSuccess(LETTER_TO_MORSE[idx]);
    }
}

Result<char> StaticMorseDictionary::decode(std::string_view input) const
{
    if (input == SPACE)
        return Result<char>::makeSuccess(' ');

    auto it = std::find(LETTER_TO_MORSE.cbegin(), LETTER_TO_MORSE.cend(), input);
    if (it == LETTER_TO_MORSE.cend())
    {
        return Result<char>::makeError("Unsupported morse code sequence");
    }
    return Result<char>::makeSuccess('A' + std::distance(LETTER_TO_MORSE.cbegin(), it));
}
