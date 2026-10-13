#ifndef GROUP_H
#define GROUP_H
#include "Schedulable.h"
#include <string>

namespace planning {
    class Group : public Schedulable {
    private:
        std::string name;

    public:
    	Group();
        Group(int id, std::string name);

        std::string getName() const;
        void setName(std::string name);

        std::string toString() const override;
        std::string tuple() const override;
    };
}
#endif
