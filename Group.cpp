#include "Group.h"

using namespace std;

namespace planning {
	Group::Group() : Schedulable(0), name("") {}
    Group::Group(int id, string name) : Schedulable(id), name(name) {}

    string Group::getName() const { return name; }
    void Group::setName(string name) { this->name = name; }

    string Group::toString() const {
        return name;
    }

    string Group::tuple() const {
        return to_string(id) + ";" + name;
    }
}
