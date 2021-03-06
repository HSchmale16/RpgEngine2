#ifndef HASEQUIPMENT__HPP
#define HASEQUIPMENT__HPP

#include "Inventory.hpp"

/** A container that holds a single item with a type restriction allowing
 * only that item to be placed in it at any given type.
 */
class ItemSlot {
private:
    Item* m_item;
    string m_restrictedType;
public:
    ItemSlot(string restricted);
    ~ItemSlot();

    /** sets the type restriction
     */
    void setRestrictedType(string type);
    void moveItem(Inventory* inventory, Item* item);
    AttributeMap getAttributes() const;
};

typedef std::map<string,ItemSlot> SlotMap;

/** Provides ability to have items
 */
class HasEquipment {  
    SlotMap m_slots;
protected:
    HasEquipment();

    void equipItem(Inventory* inv, Item* itm);
public:
    virtual ~HasEquipment();
    bool hasSlot(string name);
    
    AttributeMap getAttributeAdjustment() const;
};

#endif // HASEQUIPMENT__HPP