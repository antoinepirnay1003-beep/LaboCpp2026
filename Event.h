#ifndef EVENT_H
#define EVENT_H

#include "Timing.h"

namespace planning {
    class Event {
    private:
        int code;
        char* title;
        Timing* timing;

    public:
        static int currentCode;

        Event();
        Event(int c, const char* t);
        Event(const Event& e);
        ~Event();

        int getCode() const;
        const char* getTitle() const;
        // Remplace les anciennes déclarations par celles-ci :
	Timing getTiming() const;
	void setTiming(const Timing& t);
        void setCode(int c);
        void setTitle(const char* t);


        void display() const;
    };
}

#endif
