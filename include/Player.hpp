#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "Inventory.hpp"

class Player : public Inventory {
public:
    Player();
    virtual ~Player();
};

#endif // PLAYER_HPP