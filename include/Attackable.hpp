#ifndef ATTACKABLE__HPP
#define ATTACKABLE__HPP

#include <map>
#include <string>
#include <cstdint>
#include "EntityBase.hpp"

/** Interface to allow an entity to become attackable
 * \author Henry J Schmale
 */
class Attackable : public virtual EntityBase {
private:
    
protected:
    Attackable();
    Attackable(AttributeInteger defHealth);
    Attackable(AttributeInteger defHealth, AttributeInteger baseAttack);

public:
    virtual ~Attackable();

    AttributeInteger getMaxHealth();
    AttributeInteger getCurrentHealth();
    void restoreHealth();

    static const AttributeInteger DEFAULT_HEALTH;
    static const AttributeInteger DEFAULT_BASE_ATTACK;
    static const AttributeInteger DEFAULT_BASE_DEFENSE;
};


#endif // ATTACKABLE__HPP