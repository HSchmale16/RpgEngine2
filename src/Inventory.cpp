#include "../include/Inventory.hpp"
#include "../lib/rang.hpp"

Inventory::Inventory(json js) {
    loadJson(js);
}

Inventory::Inventory() { }

Inventory::~Inventory() {
    // clean up allocated items
    for(Item* itm : m_items)
        delete itm;
}

/// TODO: Implement
bool Inventory::contains(std::string name) {
    return false;
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



// ////////////////////////////////////////////
// MONEY MANAGEMENT STUFF
// ////////////////////////////////////////////

uint64_t Inventory::takeMoney() {
    int m = m_money;
    m_money = 0;
    return m;
}

uint64_t Inventory::getMoney() {
    return m_money;
}

void Inventory::addMoney(uint64_t amount) {
    m_money += amount;
}

void Inventory::loadJson(json js) {
    Entity::loadJson(js);
    auto it = js.find("items");
    if(it == js.end())
        return;
    if(!it->is_array())
        throw "Items must be listed in an array";
    for(json& itmName : *it) {
        if(itmName.is_string())
            this->addItem(itmName);
        else if(itmName.is_number())
            this->addMoney(itmName);
    }
}

void Inventory::printLookText(std::ostream& out) {
    using namespace rang;
    Entity::printLookText(out);
    for(auto* i : m_items) {
        out << style::bold << i->getName() << style::reset << " - ";
        i->printLookText(out);
    }
}