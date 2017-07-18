#include "AttackableHasDrops.hpp"
#include "ItemFactory.hpp"
#include <random>

/**AttackableHasDrops.cpp
 *  
 */

AttackableHasDrops::~AttackableHasDrops() {
    for(auto item : m_possibleDrops)
        delete item;
}