#include "Classroom.h"
#include <iostream>

using namespace std;

namespace planning {
	Classroom::Classroom() : Schedulable(0), name(""), seatingCapacity(0) {}
    Classroom::Classroom(int id, string name, int seatingCapacity)
        : Schedulable(id), name(name), seatingCapacity(seatingCapacity) {}

    string Classroom::getName() const { return name; }
    int Classroom::getSeatingCapacity() const { return seatingCapacity; }
    void Classroom::setName(string name) { this->name = name; }
    void Classroom::setSeatingCapacity(int seatingCapacity) { this->seatingCapacity = seatingCapacity; }

    string Classroom::toString() const {
        return name + " (" + to_string(seatingCapacity) + ")";
    }

    string Classroom::tuple() const {
        return to_string(id) + ";" + name + " (" + to_string(seatingCapacity) + ")";
    }
    ostream& operator<<(ostream& os, const Classroom& c) {
        os << "<Classroom>" << endl;
        os << "<id>" << endl;
        os << c.getId() << endl;
        os << "</id>" << endl;
        os << "<name>" << endl;
        os << c.getName() << endl;
        os << "</name>" << endl;
        os << "<seatingCapacity>" << endl;
        os << c.getSeatingCapacity() << endl;
        os << "</seatingCapacity>" << endl;
        os << "</Classroom>" << endl;
        return os;
    }

    istream& operator>>(istream& is, Classroom& c) {
        string ligne;
        getline(is, ligne); // <Classroom>
        
        getline(is, ligne); // <id>
        getline(is, ligne); // valeur de l'id
        c.setId(stoi(ligne));
        getline(is, ligne); // </id>
        
        getline(is, ligne); // <name>
        getline(is, ligne); // valeur du nom
        c.setName(ligne);
        getline(is, ligne); // </name>
        
        getline(is, ligne); // <seatingCapacity>
        getline(is, ligne); // valeur de la capacite
        c.setSeatingCapacity(stoi(ligne));
        getline(is, ligne); // </seatingCapacity>
        
        getline(is, ligne); // </Classroom>
        return is;
    }
}

