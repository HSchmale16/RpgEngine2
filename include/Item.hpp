#ifndef ITEM__HPP
#define ITEM__HPP

#include "EntityBase.hpp"
#include <map>

class ItemFactory;

class Item : public virtual EntityBase {
    // Attributes
    private :
        std::string m_type;
        /// Price to buy from a store
        uint32_t m_buyPrice;
        /// Money returned for selling to store.
        uint32_t m_sellPrice;
    public:
        Item(json j, ItemFactory* factory);
        Item(const Item& itm);

        std::string getType();

        void printDetailed(std::ostream& out);
};

#include "ItemFactory.hpp"

#endif
