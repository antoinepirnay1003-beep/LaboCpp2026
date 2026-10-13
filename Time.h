#ifndef TIME_H
#define TIME_H
#include <iostream>

namespace planning {
    class Time {
    private:
        int hour;
        int minute;

    public:
        Time();
        Time(int h, int m);
        Time(int m);
        Time(const Time& t);
        ~Time();

        int getHour() const;
        int getMinute() const;
        void setHour(int h);
        void setMinute(int m);
        void display() const;

        // A. Operateurs arithmetiques
        Time& operator=(const Time& t);
        Time operator+(int m) const;
        friend Time operator+(int m, const Time& t);
        Time operator+(const Time& t) const;
        Time operator-(int m) const;
        friend Time operator-(int m, const Time& t); // <--- AJOUTE CETTE LIGNE
        Time operator-(const Time& t) const;	

        // B. Operateurs de comparaison
        bool operator>(const Time& t) const;
        bool operator<(const Time& t) const;
        bool operator==(const Time& t) const;

        // D. Operateurs d'incrementation (+/- 30 min)
        Time& operator++();    // Pre-incrementation
        Time operator++(int);  // Post-incrementation
        Time& operator--();    // Pre-decrementation
        Time operator--(int);  // Post-decrementation
    };

    // C. Operateurs de flux (externes a la classe)
    std::ostream& operator<<(std::ostream& os, const Time& t);
    std::istream& operator>>(std::istream& is, Time& t);
}
#endif
