#ifndef ITEMFACTORY__HPP
#define ITEMFACTORY__HPP

#include "Item.hpp"

/**
 * \brief Generates new item objects from the defaults that are available.
 *        
 *        Allows for the location files to define items by a code rather than listing all of their attributes.
 */
class ItemFactory {
    // Attributes
    private :
        List<Item> m_validItems;
        static std::set<std::string> m_validTypes;
    // Operations
    public :
        ItemFactory (std::string itemFile);
        /**
         * \brief dtor
         */
        ~ItemFactory ();
        /**
         * \brief gets an item by the code
         * \param code (???)
         * \return Item
         */
        Item byCode (ItemCode code);
        /**
         * \brief decides whether the type listed is valid.
         * \param name (???)
         * \return bool
         */
        bool validateType (std::string name);
};

#endif
