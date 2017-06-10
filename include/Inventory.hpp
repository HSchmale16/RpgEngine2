#ifndef INVENTORY__HPP
#define INVENTORY__HPP

#include "Item.hpp"
#include "Entity.hpp"

/**
 * \brief Provides base class for something that has an inventory.
 *        
 *        All things that can be taken from must inherit from this.
 */
class Inventory : public Entity {
    // Attributes
    protected :
        std::vector<Item> m_items;
    public :
        int m_money = 0;
    // Operations
    protected :
        Inventory ();
    public :
        Item takeItem (std::string name);

        /**
         * \brief tests whether this inventory contains an item like itm.
         * \param itm (???)
         * \return bool
         */
        bool contains (Item& itm);
        /**
         * \brief Returns the current value of money and sets it to 0.
         * \return int
         */
        int takeMoney ();

        int getMoney ();
};

#endif
