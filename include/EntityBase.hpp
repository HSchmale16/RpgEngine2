#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

#include "../lib/json.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>

using json = nlohmann::json;


/** This is an abstract base class for all entities
 */
class EntityBase {
    private :
        static uint64_t m_nextSerial;
        uint64_t m_serialNumber;
        void loadLookTexts(json ltexts);

    // Attributes
    protected :
        /// the name of the entity.
        std::string m_name;
        /// Information that can be found by looking at it.
        std::vector<std::string> m_lookTexts;

        // CTOR Are protected because this is an abstract class
        EntityBase (json j);
        EntityBase (const EntityBase& eb);
        EntityBase ();
        virtual ~EntityBase();

        /**
         * \brief Loads from a json/
         * \param js (???) The json to load.
         * \return bool
         */
        virtual bool loadJson (json js);
    public :
        virtual void printLookText (std::ostream& out);
        std::string getName () const;
        virtual void dump(std::ostream& out);
};

#endif
