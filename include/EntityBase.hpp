#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

#include "../lib/json.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <hunspell/hunspell.hxx>

using json = nlohmann::json;

typedef std::vector<std::string> StringVector;
/** This is an abstract base class for all entities
 */
class EntityBase {
    private :
        static uint64_t m_nextSerial;
        uint64_t m_serialNumber;

        /// the name broken up into keywords
        StringVector m_keywords;

        void loadLookTexts(json ltexts);

        void setName(std::string name);

        void setSerial();
    // Attributes
    protected :
        /// the name of the entity.
        std::string m_name;
        /// Information that can be found by looking at it.
        StringVector m_lookTexts;

        // CTOR Are protected because this is an abstract class
        EntityBase (json j);
        EntityBase (const EntityBase& eb);

        /** Default CTOR to allow one to call up the json load overloads on
         * their own terms.
         */
        EntityBase ();

        /**
         * \brief Loads from a json/
         * \param js (???) The json to load.
         */
        virtual void loadJson (json js);
    public :
        virtual ~EntityBase();


        virtual void printLookText (std::ostream& out);
        virtual void printBasicLookText (std::ostream& out);

        std::string getName () const;
        virtual void dump(std::ostream& out);
        uint64_t getSerialNumber();

        uint64_t getSearchScore(const StringVector& kws);
};

#endif
