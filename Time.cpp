#include "Time.h"
#include <iostream>

using namespace std;

namespace planning {
    Time::Time() : hour(0), minute(0) {
        cout << "--- [Trace] Constructeur par defaut Time ---" << endl;
    }

    Time::Time(int h, int m) : hour(h), minute(m) {
        cout << "--- [Trace] Constructeur init (h,m) Time ---" << endl;
    }

    Time::Time(int m) : hour(m / 60), minute(m % 60) {
        cout << "--- [Trace] Constructeur init (m) Time ---" << endl;
    }

    Time::Time(const Time& t) : hour(t.hour), minute(t.minute) {
        cout << "--- [Trace] Constructeur de copie Time ---" << endl;
    }

    Time::~Time() {
        cout << "--- [Trace] Destructeur Time ---" << endl;
    }

    int Time::getHour() const { return hour; }
    int Time::getMinute() const { return minute; }
    void Time::setHour(int h) { hour = h; }
    void Time::setMinute(int m) { minute = m; }

    void Time::display() const {
        cout << hour << "h";
        if (minute < 10) cout << "0"; // Formatage XXhXX
        cout << minute;
    }
}
