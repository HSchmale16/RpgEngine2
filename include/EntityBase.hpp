#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

#include "../lib/json.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>

using json = nlohmann::json;

typedef std::vector<std::string> StringVector;
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
        StringVector m_lookTexts;

        // CTOR Are protected because this is an abstract class
        EntityBase (json j);
        EntityBase (const EntityBase& eb);
        EntityBase ();

        /**
         * \brief Loads from a json/
         * \param js (???) The json to load.
         */
        virtual void loadJson (json js);
    public :
        virtual ~EntityBase();
        virtual void printLookText (std::ostream& out);
        std::string getName () const;
        virtual void dump(std::ostream& out);
};

#endif
