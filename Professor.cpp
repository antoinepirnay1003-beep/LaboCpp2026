#include "Professor.h"

using namespace std;

namespace planning {
	Professor::Professor() : Schedulable(0), lastName(""), firstName("") {}
    Professor::Professor(int id, string lastName, string firstName) 
        : Schedulable(id), lastName(lastName), firstName(firstName) {}

    string Professor::getLastName() const { return lastName; }
    string Professor::getFirstName() const { return firstName; }
    void Professor::setLastName(string lastName) { this->lastName = lastName; }
    void Professor::setFirstName(string firstName) { this->firstName = firstName; }

    string Professor::toString() const {
        return lastName + " " + firstName;
    }

    string Professor::tuple() const {
        return to_string(id) + ";" + lastName + ";" + firstName;
    }
}
