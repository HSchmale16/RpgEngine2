#include "HasEquipment.hpp"
#include "ItemFactory.hpp"

#define CREATE_SLOT(name) {name, ItemSlot(name)}

ItemSlot::ItemSlot(string type) {
    m_item = nullptr;
    setRestrictedType(type);
}

ItemSlot::~ItemSlot() {

}

void ItemSlot::setRestrictedType(string type) {
    if(!ItemFactory::validateType(type))
        throw "ItemSlot requested an invalid type restriction";
    m_restrictedType = type;
}

void ItemSlot::moveItem(Inventory* inv, Item* item) {

}

AttributeMap ItemSlot::getAttributes() const {
    return m_item ? m_item->getAttributes() : AttributeMap();
}

/////////////////////////////////////////////////
// Implementation of has Equipables

HasEquipment::HasEquipment() {
    m_slots = {
        CREATE_SLOT("ring"),
        CREATE_SLOT("belt"),
        CREATE_SLOT("gloves"),
        CREATE_SLOT("sword"),
        CREATE_SLOT("shield"),
        CREATE_SLOT("chestplate"),
        CREATE_SLOT("greaves"),
        CREATE_SLOT("helmet")
    };
}

HasEquipment::~HasEquipment() {}

bool HasEquipment::hasSlot(string name) {
    return m_slots.count(name);
}

void HasEquipment::equipItem(Inventory* inv, Item* itm) {

}

AttributeMap HasEquipment::getAttributeAdjustment() const {
    AttributeMap tmp;
    return tmp;
}