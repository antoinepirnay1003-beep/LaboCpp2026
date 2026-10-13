#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <string>
#include <iostream>

namespace planning {
    class Schedulable {
    protected:
        int id; // Identifiant unique

    public:
    	Schedulable();
        Schedulable(int id);
        virtual ~Schedulable() = default; // Destructeur virtuel essentiel pour l'héritage

        int getId() const;
        void setId(int id);

        // Méthodes virtuelles pures (rendent la classe abstraite)
        virtual std::string toString() const = 0;
        virtual std::string tuple() const = 0;
    };

    // Surcharge de l'opérateur d'affichage pour toutes les entités
    std::ostream& operator<<(std::ostream& os, const Schedulable& s);
}
#endif
