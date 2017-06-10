#include "../include/Item.hpp"
#include "../include/Misc.h"

Item::Item(json j) : EntityBase(j) {
    JSON_ATTEMPT_READ_STR(m_type, j, "type");
    JSON_ATTEMPT_READ_NUM(m_sellPrice, j, "sellPrice");
    JSON_ATTEMPT_READ_NUM(m_buyPrice, j, "buyPrice");
}

std::string Item::getType() {
    return m_type;
}