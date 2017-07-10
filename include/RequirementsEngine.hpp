#ifndef REQUIREMENTSENGINE__HPP
#define REQUIREMENTSENGINE__HPP

#include <json.hpp>
#include "EntityBase.hpp"

class RequirementsItem {
private:
    static const std::map<string,int8_t> RI_TYPES;
    int8_t              m_type;
    string              m_name;
    AttributeInteger    m_min;
    AttributeInteger    m_max;

    void setType(string type);
public:
    RequirementsItem(string type, string name, AttributeInteger min = 0, 
                     AttributeInteger max = 0);
    ~RequirementsItem();
};

class RequirementsEngine {
private:
    class RequirementsGroup {
    private:
    };
};

#endif // REQUIREMENTSENGINE__HPP