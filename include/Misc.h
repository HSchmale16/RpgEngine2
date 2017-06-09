#ifndef MISC_H_INC
#define MISC_H_INC

#include <algorithm>
#include <climits>
#include <cstdlib>

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