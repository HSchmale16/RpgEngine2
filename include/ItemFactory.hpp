#ifndef ITEMFACTORY__HPP
#define ITEMFACTORY__HPP

#include "Item.hpp"

/**
 * \brief Generates new item objects from the defaults that are available.
 *        
 *        Allows for the location files to define items by a code or string
 *        rather than listing all of their attributes. Also better validation
 *        is added by restricting the items to being defined in a directory.
 */
class ItemFactory {
    private:
        static std::vector<Item> m_validItems;
        static std::map<string,std::vector<string>> m_validTypes;

        static void loadItem(string file);
    public:
        static void init(string itemDir, string typeFile);

        static void loadValidItemTypes(string itemTypesFile);

        static void loadDirectory(string itemDir);

        /**
         * \brief decides whether the type listed is valid.
         * \param name (???)
         * \return bool
         */
        static bool validateType (string type, const AttributeMap& attribs);

        /**\return copy of item requested, null if not found.
         */
        static Item* getByName (string name);

        static void listItems (std::ostream& out);
};

#endif
