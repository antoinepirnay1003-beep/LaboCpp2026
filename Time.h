#ifndef TIME_H
#define TIME_H

namespace planning {
    class Time {
    private:
        int hour;
        int minute;

    public:
        // Constructeurs et destructeur
        Time();
        Time(int h, int m); // À vérifier avec Test2.cpp
        Time(int m);        // À vérifier avec Test2.cpp (ex: durée en minutes)
        Time(const Time& t);
        ~Time();

        // Accesseurs
        int getHour() const;
        int getMinute() const;
        void setHour(int h);
        void setMinute(int m);

        // Affichage
        void display() const;
    };
}

#endif
