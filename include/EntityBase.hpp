#ifndef ENTITYBASE__HPP
#define ENTITYBASE__HPP

class EntityBase {
    // Attributes
    protected :
        /// the name of the entity.
        std::string m_name;
        /// Information that can be found by looking at it.
        std::vector<std::string> m_lookTexts;
    // Operations
        /**
         * \brief default ctor
         */
        Entity ();
    public :
        virtual void printLookText (std::ostream out) = 0;
        std::string getName ();
        /**
         * \brief Loads from a json/
         * \param js (???) The json to load.
         * \return bool
         */
        bool loadJson (json js);
};

#endif
