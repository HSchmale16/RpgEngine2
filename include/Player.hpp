#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "Inventory.hpp"
#include "Attackable.hpp"

class Player : public Inventory, public Attackable {
public:
    Player();
    Player(json js);
    virtual ~Player();
};

#endif // PLAYER_HPP