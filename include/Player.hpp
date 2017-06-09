#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "Inventory.hpp"

class Player : public Inventory {
    // Attributes
    private :
        /// Contains player attributes like STR ATK DEX
        std::map<std::string,int> m_stats;
        unsigned int m_curHealth;
    public :
        // Operations
        Player ();

        
};

#endif
