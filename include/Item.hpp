#ifndef ITEM__HPP
#define ITEM__HPP

#include "EntityBase.hpp"

class Item : public EntityBase {
    // Attributes
    private :
        String m_type;
        std::map<std::string,int> m_attributes;
        /// Price to buy from a store
        int m_buyPrice;
        /// Money returned for selling to store.
        int m_sellPrice;
        ItemFactory* m_factory;
};

#endif
