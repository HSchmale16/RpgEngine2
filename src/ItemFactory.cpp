#include "../include/ItemFactory.hpp"
#include "../lib/tinydir.h"
#include "../include/Misc.h"
#include <algorithm>
#include <fstream>

std::map<std::string,std::vector<std::string>> ItemFactory::m_validTypes = {};

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
    json j;
    JSON_FROM_FILE(j, file);
    
    Item itm(j, this);
    m_validItems.push_back(itm);
    
}

bool ItemFactory::validateType(std::string type) {
    return m_validTypes.count(type);
}

void ItemFactory::listItems(std::ostream& out) {
    for(auto& itm : m_validItems)
        out << itm.getName() << " - " << itm.getType() << std::endl;
}

void ItemFactory::loadValidItemTypes(std::string itemTypesFile) {
    json j;
    JSON_FROM_FILE(j, itemTypesFile);
    if(!j.is_object())
        throw "ItemTypesFile must contain a json object";
    for(json::iterator it = j.begin(); it != j.end(); ++it) {
        std::vector<std::string> v;
        //TODO: add loading of valid attributes for each type
        m_validTypes.insert(std::make_pair((std::string)it.key(), v));
    }
}

Item ItemFactory::getByName(std::string name) {
    auto it = std::find_if(m_validItems.begin(), m_validItems.end(),
        [&name](Item const& item) {
            return item.getName() == name;
        });
}