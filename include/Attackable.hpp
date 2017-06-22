#ifndef ATTACKABLE__HPP
#define ATTACKABLE__HPP

#include <map>
#include <string>
#include <cstdint>

/** Interface to allow an entity to become attackable
 * \author Henry J Schmale
 */
class Attackable {
private:
    uint64_t m_currentHealth;
    uint64_t m_maxHealth;
protected:
    Attackable();

public:
    virtual ~Attackable();

    uint64_t getMaxHealth();
    uint64_t getCurrentHealth();
};


#endif // ATTACKABLE__HPP