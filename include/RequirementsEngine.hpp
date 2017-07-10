#ifndef REQUIREMENTSENGINE__HPP
#define REQUIREMENTSENGINE__HPP

#include <json.hpp>
#include "Inventory.hpp"

class RequirementsItem {
private:
    static const std::map<string,int8_t> RI_TYPES;

    int8_t              m_type;
    string              m_name;
    AttributeInteger    m_min;
    AttributeInteger    m_max;

    void setType(string type);

    bool testAttribute(const EntityBase& eb);
    bool testInventory(const Inventory& i);
public:
    RequirementsItem(string type, string name, AttributeInteger min = 0, 
                     AttributeInteger max = 0);
    ~RequirementsItem();

    bool valid(const Inventory& i);
    bool valid(const EntityBase& i);
};

class RequirementsEngine {
private:
    class RequirementsGroup {
    private:
        std::vector<RequirementsItem> m_requirements;
    public:
        RequirementsGroup(json js);
        ~RequirementsGroup();

        bool valid(const Inventory& i);
        bool valid(const EntityBase& i);
    };

    std::vector<RequirementsGroup> m_groups;
public:
    RequirementsEngine(json js);
    ~RequirementsEngine();

    bool valid(const Inventory& i);
    bool valid(const EntityBase& i);
};

#endif // REQUIREMENTSENGINE__HPP