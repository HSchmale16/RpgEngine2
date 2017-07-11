#ifndef RequirementENGINE__HPP
#define RequirementENGINE__HPP

#include <json.hpp>
#include "Inventory.hpp"

class RequirementItem {
private:
    static const std::map<string,uint32_t> RI_TYPES;

    uint32_t            m_type;
    string              m_name;
    AttributeInteger    m_min;
    AttributeInteger    m_max;

    void setType(string type);

    bool testAttribute(const EntityBase& eb);
    bool testInventory(const Inventory& i);
public:
    RequirementItem(string type, string name, AttributeInteger min, 
                     AttributeInteger max);
    RequirementItem(string type, string name);
    ~RequirementItem();

    bool valid(const Inventory& i);
    bool valid(const EntityBase& i);
};

class RequirementEngine {
private:
    class RequirementGroup {
    private:
        std::vector<RequirementItem> m_Requirement;
    public:
        RequirementGroup(json js);
        ~RequirementGroup();

        bool valid(const Inventory& i);
        bool valid(const EntityBase& i);
    };

    std::vector<RequirementGroup> m_groups;
public:
    RequirementEngine(json js);
    ~RequirementEngine();

    bool valid(const Inventory& i);
    bool valid(const EntityBase& i);
};

#endif // RequirementENGINE__HPP