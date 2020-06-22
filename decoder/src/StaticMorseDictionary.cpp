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

std::string_view StaticMorseDictionary::encode(char c) const
{
    return c == ' ' ? SPACE : LETTER_TO_MORSE[c - 'A'];
}

char StaticMorseDictionary::decode(std::string_view input) const
{
    if (input == SPACE)
        return ' ';

    auto it = std::find(LETTER_TO_MORSE.cbegin(), LETTER_TO_MORSE.cend(), input);
    return 'A' + std::distance(LETTER_TO_MORSE.cbegin(), it);
}
