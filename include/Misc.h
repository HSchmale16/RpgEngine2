#ifndef MISC_H_INC
#define MISC_H_INC

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include "EntityBase.hpp"

#define JSON_ATTEMPT_READ_STR(var, jsonObj, keyname) \
    { \
    auto it = jsonObj.find(keyname); \
    if(it != jsonObj.end() && it->is_string()) \
        var = *it; \
    else \
        throw keyname " Must be a string or is not available"; \
    }

#define JSON_ATTEMPT_READ_NUM(var, jsonObj, keyname) \
    { \
    auto it = jsonObj.find(keyname); \
    if(it != jsonObj.end() && it->is_number()) \
        var = *it; \
    else \
        throw keyname " Must be a string or is not available"; \
    }

#define JSON_FROM_FILE(jsonObj, file) \
    {   std::ifstream def(file); \
        if(!def) \
            throw "Can't access json file"; \
        def >> jsonObj; \
        def.close(); }

#define JSON_GET_ITER_EXCEPT(jsonObj, var, key) \
    auto var = jsonObj.find(key); \
    if(var == jsonObj.end()) \
        throw "Can't find " key " in object";

/** Runs a function using the returned json from a key lookup if the key
 * exists in the jsonObj
 *
 * If the key does not exist it does nothing.
 */
#define JSON_ATTEMPT_FUNC_OPT(jsonObj, key, action) \
    do { \
        auto tmp = jsonObj.find(key); \
        if(tmp == jsonObj.end()) \
            break; \
        action(*tmp); \
    } while(0);


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

template<typename T>
T* searchEntitiesByName(std::vector<T*>& ents, std::string name) {
    //static_assert(std::is_base_of<T, EntityBase>::value);
    auto it = std::find_if(ents.begin(), ents.end(), [&name](EntityBase const* ent) {
        return name == ent->getName();
    });
    if(it == ents.end())
        return nullptr;
    return *it;
}
#endif // MISC_H_INC