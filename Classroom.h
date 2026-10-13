#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Schedulable.h"
#include <string>

namespace planning {
    class Classroom : public Schedulable {
    private:
        std::string name;
        int seatingCapacity;

    public:
    	Classroom();
        Classroom(int id, std::string name, int seatingCapacity);

        std::string getName() const;
        int getSeatingCapacity() const;
        void setName(std::string name);
        void setSeatingCapacity(int seatingCapacity);

        std::string toString() const override;
        std::string tuple() const override;
    };
}
#endif
