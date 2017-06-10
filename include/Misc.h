#ifndef MISC_H_INC
#define MISC_H_INC

#include <algorithm>
#include <climits>
#include <cstdlib>

#define JSON_ATTEMPT_READ_STR(var, jsonObj, keyname) \
    if(jsonObj.find(keyname) != jsonObj.end() && j[keyname].is_string()) \
        var = jsonObj[keyname]; \
    else \
        throw keyname " Must be a string or is not available";

#define JSON_ATTEMPT_READ_NUM(var, jsonObj, keyname) \
    if(jsonObj.find(keyname) != jsonObj.end() && j[keyname].is_number()) \
        var = jsonObj[keyname]; \
    else \
        throw keyname " Must be a string or is not available";

template <typename I>
I random_element(I begin, I end)
{
    const unsigned long n = std::distance(begin, end);
    const unsigned long divisor = ((long)RAND_MAX + 1) / n;

    unsigned long k;
    do { k = std::rand() / divisor; } while (k >= n);

    std::advance(begin, k);
    return begin;
}

#endif // MISC_H_INC