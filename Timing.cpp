#include "Timing.h"
#include "TimingException.h"
#include <iostream>

using namespace std;

namespace planning {
    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    Timing::Timing() : day(MONDAY) { cout << "--- [Trace] Constructeur par defaut Timing ---" << endl; }
    Timing::Timing(string d, const Time& s, const Time& dur) : start(s), duration(dur) { 
    setDay(d);
    cout << "--- [Trace] Constructeur init Timing ---" << endl; 
}
    Timing::Timing(const Timing& t) : day(t.day), start(t.start), duration(t.duration) { cout << "--- [Trace] Constructeur de copie Timing ---" << endl; }
    Timing::~Timing() { cout << "--- [Trace] Destructeur Timing ---" << endl; }

    string Timing::getDay() const { return day; }
    Time Timing::getStart() const { return start; }
    Time Timing::getDuration() const { return duration; }

    void Timing::setDay(string d) {
    if (d != MONDAY && d != TUESDAY && d != WEDNESDAY && d != THURSDAY &&
        d != FRIDAY && d != SATURDAY && d != SUNDAY) {
        throw TimingException("Jour invalide", TimingException::INVALID_DAY);
    }
    day = d;
}
    void Timing::setStart(const Time& s) { start = s; }
    void Timing::setDuration(const Time& dur) { duration = dur; }

    void Timing::display() const {
        cout << day << " de ";
        start.display();
        cout << " (";
        duration.display();
        cout << ")";
    }

    // Fonction interne pour transformer le jour en chiffre pour le tri chronologique
    int getDayIndex(const string& day) {
        if (day == Timing::MONDAY) return 1;
        if (day == Timing::TUESDAY) return 2;
        if (day == Timing::WEDNESDAY) return 3;
        if (day == Timing::THURSDAY) return 4;
        if (day == Timing::FRIDAY) return 5;
        if (day == Timing::SATURDAY) return 6;
        if (day == Timing::SUNDAY) return 7;
        return 8; 
    }

    bool Timing::operator>(const Timing& t) const {
        int d1 = getDayIndex(day);
        int d2 = getDayIndex(t.day);
        
        if (d1 > d2) return true;
        if (d1 == d2) {
            if (start > t.start) return true;
            if (start == t.start && duration > t.duration) return true;
        }
        return false;
    }

    bool Timing::operator<(const Timing& t) const {
        int d1 = getDayIndex(day);
        int d2 = getDayIndex(t.day);
        
        if (d1 < d2) return true;
        if (d1 == d2) {
            if (start < t.start) return true;
            if (start == t.start && duration < t.duration) return true;
        }
        return false;
    }

    bool Timing::operator==(const Timing& t) const {
        return (day == t.day && start == t.start && duration == t.duration);
    }
    ostream& operator<<(ostream& os, const Timing& t) {
        os << "<Timing>" << endl;
        os << "<day>" << endl;
        os << t.getDay() << endl;
        os << "</day>" << endl;
        
        os << "<start>" << endl;
        os << t.getStart(); // Appelle automatiquement l'opérateur << de Time !
        os << "</start>" << endl;
        
        os << "<duration>" << endl;
        os << t.getDuration(); // Appelle automatiquement l'opérateur << de Time !
        os << "</duration>" << endl;
        
        os << "</Timing>" << endl;
        return os;
    }

    istream& operator>>(istream& is, Timing& t) {
        string ligne;
        getline(is, ligne); // <Timing>
        
        getline(is, ligne); // <day>
        getline(is, ligne); // valeur du jour
        t.setDay(ligne);
        getline(is, ligne); // </day>
        
        getline(is, ligne); // <start>
        Time start;
        is >> start; // Appelle automatiquement l'opérateur >> de Time !
        t.setStart(start);
        getline(is, ligne); // </start>
        
        getline(is, ligne); // <duration>
        Time duration;
        is >> duration; // Appelle automatiquement l'opérateur >> de Time !
        t.setDuration(duration);
        getline(is, ligne); // </duration>
        
        getline(is, ligne); // </Timing>
        return is;
    }
}
