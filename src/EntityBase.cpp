#include "../include/EntityBase.hpp"
#include "../include/Misc.h"

void EntityBase::printLookText(std::ostream& out) {
    if(m_lookTexts.size() == 0)
        out << "Nothing distinct about this.";
    else if(m_lookTexts.size() == 1)
        out << m_lookTexts[0];
    else
        out << *random_element(m_lookTexts.begin(), m_lookTexts.end());
    out << std::endl;
}

std::string EntityBase::getName() {
    return m_name;
}

bool EntityBase::loadJson(json js) {
    
}