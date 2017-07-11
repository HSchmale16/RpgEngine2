#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

#include "json.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>

using json = nlohmann::json;
using string = std::string;

typedef int32_t AttributeInteger;
typedef std::vector<string> StringVector;
typedef std::pair<StringVector,StringVector> StringVectorPair;
typedef std::map<string,AttributeInteger> AttributeMap;

struct CompareBySize {
    bool operator()(const StringVector& a, const StringVector& b) {
        return a.size() < b.size();
    }
    bool operator()(const AttributeMap& a, const AttributeMap& b) {
        return a.size() < b.size();
    }
};

/** This is an abstract base class for all entities
 */
class EntityBase {
    private :
        static uint64_t m_nextSerial;
        uint64_t m_serialNumber;

        /// the name broken up into keywords
        StringVector m_keywords;

        /// the name of the entity.
        std::string m_name;

        void loadLookTexts(json looktexts);

        void setName(std::string name);

        void setSerial();
    protected :
        
        /// Information that can be found by looking at it.
        StringVector m_lookTexts;
        AttributeMap m_attributes;

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

        /**
         * Loads attributes from json
         */
        void loadAttributes(json js);
    public :
        virtual ~EntityBase();


        virtual void printLookText (std::ostream& out);
        virtual void printBasicLookText (std::ostream& out);
        virtual void dump(std::ostream& out);

        std::string getName () const;
        uint64_t getSerialNumber() const;

        /**
         * \brief Gets the value of a given attribute
         * \return the value of given attribute, otherwise defValue
         * \param defValue default return value if not found
         * \param attrib name of attribute to request
         */
        AttributeInteger getAttribute(string attrib,
                                      AttributeInteger defValue = 0) const;
        /** 
         *  \brief Calculate name similarity to kws,
         *  \return 0 if a perfect match for given keywords, otherwise a
         *  higher value as it gets worse
         */
        uint64_t getSearchScore(const StringVector& kws);
};

#endif
