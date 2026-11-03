#include "Time.h"
#include <iostream>
#include "TimeException.h"

using namespace std;

namespace planning {
    Time::Time() : hour(0), minute(0) { cout << "--- [Trace] Constructeur par defaut Time ---" << endl; }
    
    Time::Time(int h, int m) { 
        setHour(h); 
        setMinute(m); 
        cout << "--- [Trace] Constructeur init (h,m) Time ---" << endl; 
    }
    
    Time::Time(int m) { 
        setHour(m / 60); 
        setMinute(m % 60); 
        cout << "--- [Trace] Constructeur init (m) Time ---" << endl; 
    }
    
    Time::Time(const Time& t) : hour(t.hour), minute(t.minute) { cout << "--- [Trace] Constructeur de copie Time ---" << endl; }
    Time::~Time() { cout << "--- [Trace] Destructeur Time ---" << endl; }
    
    int Time::getHour() const { return hour; }
    int Time::getMinute() const { return minute; }
    void Time::setHour(int h) { 
   	 if (h < 0 || h > 23) throw TimeException("Heure invalide", TimeException::INVALID_HOUR);
   	 	hour = h; 
    }

    void Time::setMinute(int m) { 
    	if (m < 0 || m > 59) throw TimeException("Minute invalide", TimeException::INVALID_MINUTE);
    	minute = m; 
    }

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
        if (total_mins < 0 || total_mins > 1439) throw TimeException("Debordement", TimeException::OVERFLOW);
        return Time(total_mins / 60, total_mins % 60);
    }

    Time operator+(int m, const Time& t) {
        return t + m;
    }

    Time Time::operator+(const Time& t) const {
        int total_mins = hour * 60 + minute + t.hour * 60 + t.minute;
        if (total_mins < 0 || total_mins > 1439) throw TimeException("Debordement", TimeException::OVERFLOW);
        return Time(total_mins / 60, total_mins % 60);
    }

    Time Time::operator-(int m) const {
        int total_mins = hour * 60 + minute - m;
        if (total_mins < 0 || total_mins > 1439) throw TimeException("Debordement", TimeException::OVERFLOW);
        return Time(total_mins / 60, total_mins % 60);
    }

    Time Time::operator-(const Time& t) const {
        int total_mins = (hour * 60 + minute) - (t.hour * 60 + t.minute);
        if (total_mins < 0 || total_mins > 1439) throw TimeException("Debordement", TimeException::OVERFLOW);
        return Time(total_mins / 60, total_mins % 60);
    }
    
    Time operator-(int m, const Time& t) {
        int total_mins = m - (t.hour * 60 + t.minute);
        if (total_mins < 0 || total_mins > 1439) throw TimeException("Debordement", TimeException::OVERFLOW);
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


    // C. Operateurs de flux (pour la serialisation XML)
    ostream& operator<<(ostream& os, const Time& t) {
        os << "<Time>" << endl;
        os << "<hour>" << endl;
        os << t.getHour() << endl;
        os << "</hour>" << endl;
        os << "<minute>" << endl;
        os << t.getMinute() << endl;
        os << "</minute>" << endl;
        os << "</Time>" << endl;
        return os;
    }

    istream& operator>>(istream& is, Time& t) {
        string ligne;
        // L'opérateur >> fait appel 8 fois à la fonction getline pour lire les 8 lignes[cite: 26]
        getline(is, ligne); // lit <Time>
        
        getline(is, ligne); // lit <hour>
        getline(is, ligne); // lit la valeur de l'heure
        t.setHour(stoi(ligne)); // stoi convertit le texte en int
        getline(is, ligne); // lit </hour>
        
        getline(is, ligne); // lit <minute>
        getline(is, ligne); // lit la valeur des minutes
        t.setMinute(stoi(ligne)); // stoi convertit le texte en int
        getline(is, ligne); // lit </minute>
        
        getline(is, ligne); // lit </Time>
        return is;
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
}
