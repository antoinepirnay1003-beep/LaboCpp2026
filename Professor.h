#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Schedulable.h"
#include <string>

namespace planning {
    class Professor : public Schedulable {
    private:
        std::string lastName;
        std::string firstName;

    public:
    	Professor();
        Professor(int id, std::string lastName, std::string firstName);
        
        std::string getLastName() const;
        std::string getFirstName() const;
        void setLastName(std::string lastName);
        void setFirstName(std::string firstName);

        std::string toString() const override;
        std::string tuple() const override;
    };
}
#endif
