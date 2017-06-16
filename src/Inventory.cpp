#include "../include/Inventory.hpp"

Inventory::Inventory(json js) {
    loadJson(js);
}


Inventory::~Inventory() {
    // clean up allocated items
    for(Item* itm : m_items) {
        delete itm;
    }
}

/// TODO: Implement
Item Inventory::takeItem(std::string name) {

}

/// TODO: Implement
bool Inventory::contains(Item& itm) {
    return false;
}

/// TODO: Implement
bool Inventory::contains(std::string name) {
    return false;
}

int Inventory::takeMoney() {
    int m = m_money;
    m_money = 0;
    return m;
}

int Inventory::getMoney() {
    return m_money;
}

void Inventory::dump(std::ostream& out) {
    Entity::dump(out);
    for(auto& itm : m_items)
        itm->dump(out);
}

void Inventory::addItem(std::string name) {
    ItemFactory ifact;
    Item* item = ifact.getByName(name);
    m_items.push_back(item);
}

bool Inventory::loadJson(json js) {
    Entity::loadJson(js);
    auto it = js.find("items");
    if(it == js.end())
        return false;
    if(!it->is_array())
        throw "Items must be listed in an array";
    for(json& itmName : *it) {
        if(!itmName.is_string())
            throw "All items listed must be a string";
        this->addItem(itmName);
    }
}