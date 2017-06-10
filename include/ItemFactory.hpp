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
        std::vector<Item> m_validItems;
        static std::map<std::string,std::vector<std::string>> m_validTypes;

        void loadItem(std::string file);

        void loadValidItemTypes(std::string itemTypesFile);
    // Operations
    public :
        ItemFactory (std::string itemDir);

        /**
         * \brief decides whether the type listed is valid.
         * \param name (???)
         * \return bool
         */
        bool validateType (std::string type);


        void listItems (std::ostream& out);
};

#endif
