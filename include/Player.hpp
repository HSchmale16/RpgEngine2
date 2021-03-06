#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "Inventory.hpp"
#include "Attackable.hpp"
#include "HasEquipment.hpp"

class Player : public Inventory, public Attackable, public HasEquipment {
public:
    Player();
    Player(json js);
    virtual ~Player();

    virtual void dump(std::ostream& out);
};

#endif // PLAYER_HPP