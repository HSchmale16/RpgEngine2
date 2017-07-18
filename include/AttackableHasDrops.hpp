#ifndef ATTACKABLE_HAS_DROPS
#define ATTACKABLE_HAS_DROPS

#include "Attackable.hpp"
#include "Item.hpp"
#include "Room.hpp"

/** Overrides the on death action, provides the ability for the
 */
class AttackableHasDrops : public Attackable {
private:
    std::vector<Item*> m_possibleDrops;
    std::vector<int>   m_dropChance;

    
public:
    ~AttackableHasDrops();
};

#endif // ATTACKABLE_HAS_DROPS