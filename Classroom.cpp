#include "Classroom.h"

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
}
