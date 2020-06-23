#include <iostream>
#include <iterator>
#include <utility>

#include "MorseDecoder.h"
#include "StaticMorseDictionary.h"

static MorseDecoder decoder(std::make_unique<StaticMorseDictionary>());

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    std::string s(reinterpret_cast<const char*>(Data), Size);
    auto decodeRes = decoder.decode(s);
    if (decodeRes.status == Status::Ok)
    {
        std::cout << decodeRes.value << std::endl;
    }
    else
    {
        std::cout << decodeRes.errorMsg << std::endl;
    }
    auto encodeRes = decoder.encode(s);
    if (encodeRes.status == Status::Ok)
    {
        std::cout << encodeRes.value << std::endl;
    }
    else
    {
        std::cout << encodeRes.errorMsg << std::endl;
    }
    return 0;
}
