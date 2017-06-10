#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

#include "../lib/json.hpp"
#include <string>
#include <vector>
#include <cstdlib>

using json = nlohmann::json;

class EntityBase {
    private :
        void loadLookTexts(json ltexts);

    // Attributes
    protected :
        /// the name of the entity.
        std::string m_name;
        /// Information that can be found by looking at it.
        std::vector<std::string> m_lookTexts;
    // Operations
        EntityBase (json j);
        EntityBase ();


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
