#include "../include/ItemFactory.hpp"
#include "../lib/tinydir.h"
#include <fstream>

ItemFactory::ItemFactory (std::string itemDir) {
    this->loadValidItemTypes("config/itemtypes.json");

    // load valid items
    tinydir_dir dir;
    tinydir_open(&dir, itemDir.c_str());
    while(dir.has_next) {
        tinydir_file file;
        tinydir_readfile(&dir, &file);
        if(file.is_reg) {
            this->loadItem(file.path);
        }
        tinydir_next(&dir);
    }
    tinydir_close(&dir);
}

void ItemFactory::loadItem(std::string file) {
    std::ifstream def(file);
    if(!def)
        throw "Can't access file";
    json j;
    def >> j;
    def.close();
    
    Item itm(j);
    m_validItems.push_back(itm);
    //TODO: Item validation
    
}

void ItemFactory::listItems(std::ostream& out) {
    for(auto& itm : m_validItems)
        out << itm.getName() << " - " << itm.getType();
}

void ItemFactory::loadValidItemTypes(std::string itemTypesFile) {

}