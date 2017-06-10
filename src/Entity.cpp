#include "../include/Entity.hpp"

void Entity::use(const Item& itm) {
    
}

void Entity::dump(std::ostream& out) {
    out << this->getName() << std::endl;
}