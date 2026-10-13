#include "Time.h"
#include <iostream>

using namespace std;

namespace planning {
    Time::Time() : hour(0), minute(0) { cout << "--- [Trace] Constructeur par defaut Time ---" << endl; }
    Time::Time(int h, int m) : hour(h), minute(m) { cout << "--- [Trace] Constructeur init (h,m) Time ---" << endl; }
    Time::Time(int m) : hour(m / 60), minute(m % 60) { cout << "--- [Trace] Constructeur init (m) Time ---" << endl; }
    Time::Time(const Time& t) : hour(t.hour), minute(t.minute) { cout << "--- [Trace] Constructeur de copie Time ---" << endl; }
    Time::~Time() { cout << "--- [Trace] Destructeur Time ---" << endl; }

    int Time::getHour() const { return hour; }
    int Time::getMinute() const { return minute; }
    void Time::setHour(int h) { hour = h; }
    void Time::setMinute(int m) { minute = m; }

    void Time::display() const {
        cout << hour << "h";
        if (minute < 10) cout << "0";
        cout << minute;
    }

    // A. Operateurs arithmetiques
    Time& Time::operator=(const Time& t) {
        hour = t.hour;
        minute = t.minute;
        return *this;
    }

    Time Time::operator+(int m) const {
        int total_mins = hour * 60 + minute + m;
        return Time(total_mins / 60, total_mins % 60);
    }

    Time operator+(int m, const Time& t) {
        return t + m;
    }

    Time Time::operator+(const Time& t) const {
        int total_mins = hour * 60 + minute + t.hour * 60 + t.minute;
        return Time(total_mins / 60, total_mins % 60);
    }

    Time Time::operator-(int m) const {
        int total_mins = hour * 60 + minute - m;
        return Time(total_mins / 60, total_mins % 60);
    }

    Time Time::operator-(const Time& t) const {
        int total_mins = (hour * 60 + minute) - (t.hour * 60 + t.minute);
        return Time(total_mins / 60, total_mins % 60);
    }
	Time operator-(int m, const Time& t) {
	int total_mins = m - (t.hour * 60 + t.minute);
	return Time(total_mins / 60, total_mins % 60);
	}
	
	
    // B. Operateurs de comparaison
    bool Time::operator>(const Time& t) const {
        if (hour > t.hour) return true;
        if (hour == t.hour && minute > t.minute) return true;
        return false;
    }

    bool Time::operator<(const Time& t) const {
        if (hour < t.hour) return true;
        if (hour == t.hour && minute < t.minute) return true;
        return false;
    }

    bool Time::operator==(const Time& t) const {
        return (hour == t.hour && minute == t.minute);
    }

    // D. Operateurs d'incrementation (++ et -- ajoutent/retirent 30 mins)
    Time& Time::operator++() {
        *this = *this + 30;
        return *this;
    }

    Time Time::operator++(int) {
        Time temp = *this;
        *this = *this + 30;
        return temp;
    }

    Time& Time::operator--() {
        *this = *this - 30;
        return *this;
    }

    Time Time::operator--(int) {
        Time temp = *this;
        *this = *this - 30;
        return temp;
    }

    // C. Operateurs de flux
    ostream& operator<<(ostream& os, const Time& t) {
        os << t.getHour() << "h";
        if (t.getMinute() < 10) os << "0";
        os << t.getMinute();
        return os;
    }

    istream& operator>>(istream& is, Time& t) {
        int h, m;
        char h_char; // Pour absorber le 'h' tapé par l'utilisateur
        is >> h >> h_char >> m;
        t.setHour(h);
        t.setMinute(m);
        return is;
    }
}
