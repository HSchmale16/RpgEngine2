#include "../include/Inventory.hpp"

Inventory::Inventory(json js) {

}

Item Inventory::takeItem(std::string name) {

}

bool Inventory::contains(Item& itm) {
    return false;
}

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
    for(auto& itm : m_items)
        itm.dump(out);
}

bool Inventory::loadJson(json js) {
    Entity::loadJson(js);
}