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
        std::vector<Item*> m_items;
        uint64_t m_money = 0;

        virtual void loadJson(json js);
    public :
        /** Allows an inventory to be filled using a json array
         */
        Inventory(json js);
        
        /** Constructs an empty inventory
         */
        Inventory();
        virtual ~Inventory();

        /** Adds an item using it's name string
         */
        void addItem(std::string name);

        /** removes item from inventory and returns a copy
         */
        Item* takeItem (std::string name);

        /**
         * \brief tests whether this inventory contains an item like itm.
         * \param itm (???)
         * \return bool
         */
        bool contains (Item& itm);

        /**\brief tests whether it contains an item of name
         * \return true if so.
         */
        bool contains (std::string name);
        /**
         * \brief Returns the current value of money and sets it to 0.
         * \return int
         */
        uint64_t takeMoney ();

        uint64_t getMoney ();

        void addMoney(uint64_t amount);

        virtual void dump(std::ostream& out);
};

#endif
