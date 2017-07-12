#ifndef RequirementENGINE__HPP
#define RequirementENGINE__HPP

#include <json.hpp>
#include "Inventory.hpp"

class RequirementItem {
private:
    static const std::map<string,uint32_t> RI_TYPES;

    uint32_t            m_type;
    string              m_name;
    AttributeInteger    m_min;  /// Lower bound
    AttributeInteger    m_max;  /// Upper bound

    /** Juggles the type to be a valid int
     */
    void setType(string type);

    bool testAttribute(const EntityBase& eb);
    bool testInventory(const Inventory& i);
public:
    RequirementItem(string type, string name, AttributeInteger min, 
                     AttributeInteger max);
    RequirementItem(string type, string name);
    ~RequirementItem();

    bool valid(const EntityBase& i);
    string toString();
};

class RequirementEngine {
private:
    class RequirementGroup {
    private:
        std::list<RequirementItem> m_requirements;

        void addRequirementItem(json js);
    public:
        RequirementGroup(json js);
        ~RequirementGroup();

        bool valid(const EntityBase& i);
        void print(std::ostream& out);
    };

    std::list<RequirementGroup> m_groups;

    void addGroup(json js);
public:
    RequirementEngine(json js);
    ~RequirementEngine();

    bool valid(const EntityBase& i);
    void printRequirements(std::ostream& out);
};

#endif // RequirementENGINE__HPP