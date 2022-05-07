#include "dom_math.hpp"

#define ALPHABET_SIZE   (uint_64(256))
#define HASH_STR_MODULE (uint_64(1e14))

uint_64 
dom::Math::getHash(std_const_ref aStr)
{
    uint_64 result = 0;
    for(auto& i : aStr)
    {
        result += i * ALPHABET_SIZE;
        result %= HASH_STR_MODULE;
    }
    return result;
}