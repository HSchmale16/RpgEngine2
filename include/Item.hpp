#ifndef ITEM__HPP
#define ITEM__HPP

#include "EntityBase.hpp"
#include <map>

class Item : public EntityBase {
    // Attributes
    private :
        std::string m_type;
        /// Price to buy from a store
        uint32_t m_buyPrice;
        /// Money returned for selling to store.
        uint32_t m_sellPrice;
    public:
        Item(json j);
        Item(const Item& itm);

        std::string getType();

        void printDetailed(std::ostream& out);
};


#endif
