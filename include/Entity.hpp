#ifndef ENTITY__HPP
#define ENTITY__HPP

#include "Item.hpp"
#include "EntityBase.hpp"

class Entity : public EntityBase {
    // Operations
    public:
        /**
         * \brief Uses a given item on this instance.
         * \param itm (???)
         * \return void
         */
        virtual void use (const Item& itm);

        virtual void dump(std::ostream& out);
};

#endif
