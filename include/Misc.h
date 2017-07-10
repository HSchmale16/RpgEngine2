#ifndef MISC_H_INC
#define MISC_H_INC

/**\file Misc.h
 * \author Henry J Schmale
 * Contains random and useful functions for various things. Think of it as 
 * this and that.
 */

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
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
        throw keyname " must be a number"; \
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

#define JSON_ATTEMPT_FUNC_EX(jsonObj, key, action) \
    do { \
        auto tmp = jsonObj.find(key); \
        if(tmp == jsonObj.end()) \
            throw "Failed to find requested key for DO FUNC JSON"; \
        action(*tmp); \
    } while(0);


template <typename I>
I random_element(I begin, I end) {
    const unsigned long n = std::distance(begin, end);
    const unsigned long divisor = ((long)RAND_MAX + 1) / n;

    unsigned long k;
    do { k = std::rand() / divisor; } while (k >= n);

    std::advance(begin, k);
    return begin;
}

template<typename T>
T* searchEntitiesByName(std::vector<T*>& ents, std::string name) {
    static_assert(std::is_base_of<EntityBase, T>::value);

    auto it = std::find_if(ents.begin(), ents.end(), [&name](EntityBase const* ent) {
        return name == ent->getName();
    });
    if(it == ents.end())
        return nullptr;
    return *it;
}

template<typename T>
std::pair<uint64_t,T*> searchEntitiesByKeywords(std::vector<T*>& ents, const StringVector& kws) {
    static_assert(std::is_base_of<EntityBase, T>::value);

    std::map<uint64_t,T*> scores;
    for(auto* ent : ents) {
        scores.insert(std::make_pair(ent->getSearchScore(kws), ent));
    }
    return *scores.begin();
}

inline void splitOnWords(const std::string& str, StringVector& sv) {
    sv.clear();
    std::stringstream sstr(str);
    std::string tmp;
    while(sstr >> tmp)
        sv.push_back(tmp);
}

/** Returns true for the affirmative
 */
inline bool promptYesNo(std::string q, std::ostream& out, std::istream& in) {
    std::string answer;
    do {
        out << q;
        getline(in, answer);
        out << answer << std::endl;
    } while (answer[0] != 'y' && answer[0] != 'n');
    return answer[0] == 'y';
}

inline void lower_str(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

/** from: https://stackoverflow.com/a/16388610
 */
constexpr unsigned int str2int(const char* str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

#endif // MISC_H_INC