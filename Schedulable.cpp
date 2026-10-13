#include "Schedulable.h"

using namespace std;

namespace planning {
	Schedulable::Schedulable() : id(0) {}
    Schedulable::Schedulable(int id) : id(id) {}

    int Schedulable::getId() const { return id; }
    void Schedulable::setId(int id) { this->id = id; }

    // Appelle la méthode toString() de l'objet réel (Professor, Group ou Classroom)
    ostream& operator<<(ostream& os, const Schedulable& s) {
        os << s.toString();
        return os;
    }
}
