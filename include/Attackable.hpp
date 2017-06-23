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
    uint16_t m_currentHealth;
    uint16_t m_maxHealth;
protected:
    Attackable();

public:
    virtual ~Attackable();

    uint16_t getMaxHealth();
    uint16_t getCurrentHealth();
};


#endif // ATTACKABLE__HPP