#include "Event.h"
#include <iostream>
#include <cstring>
#include <string>
#include "TimingException.h"

using namespace std;

namespace planning {
    // Initialisation de la variable statique
    int Event::currentCode = 1;

    Event::Event() {
        code = currentCode++;
        title = nullptr;
        timing = nullptr;
        cout << "--- [Trace] Constructeur par defaut Event appele ---" << endl;
    }

    Event::Event(int c, const char* t) {
        code = currentCode++; // Incrémentation automatique
        timing = nullptr;
        if (t != nullptr) {
            title = new char[strlen(t) + 1];
            strcpy(title, t);
        } else {
            title = nullptr;
        }
        cout << "--- [Trace] Constructeur d'initialisation Event appele ---" << endl;
    }
	Event::Event(const Event& e) {
	    code = e.code;
	    
	    // Copie profonde du titre
	    if (e.title != nullptr) {
		title = new char[strlen(e.title) + 1];
		strcpy(title, e.title);
	    } else {
		title = nullptr;
	    }
	    
	    // Copie profonde du timing
	    if (e.timing != nullptr) {
		timing = new Timing(*(e.timing));
	    } else {
		timing = nullptr;
	    }
	    cout << "--- [Trace] Constructeur de copie Event appele ---" << endl;
	}

	    Event::~Event() {
	    if (title != nullptr) {
		delete[] title;
	    }
	    if (timing != nullptr) {
		delete timing;
	    }
	    cout << "--- [Trace] Destructeur Event appele ---" << endl;
	}

    int Event::getCode() const { return code; }
    const char* Event::getTitle() const { return title; }
	Timing Event::getTiming() const {
        if (timing == nullptr) {
            throw TimingException("Aucun timing planifie", TimingException::NO_TIMING);
        }
        return *timing; // On retourne l'objet pointé
    }

	void Event::setTiming(const Timing& t) {
	    if (timing != nullptr) {
		delete timing; // Libérer l'ancien timing s'il y en avait déjà un
	    }
	    timing = new Timing(t); // Allocation d'un nouveau Timing par copie
	}
	
	void Event::clearTiming() {
        if (timing != nullptr) {
            delete timing;
            timing = nullptr;
        }
    }

    void Event::setCode(int c) { code = c; }
    
    void Event::setTitle(const char* t) {
        if (title != nullptr) {
            delete[] title;
        }
        if (t != nullptr) {
            title = new char[strlen(t) + 1];
            strcpy(title, t);
        } else {
            title = nullptr;
        }
    }


    void Event::display() const {
        cout << "Event [code=" << code << "] : " << (title ? title : "Sans titre") << endl;
        if (timing != nullptr) {
            cout << "  -> Timing : ";
            timing->display();
            cout << endl;
        }
    }
    ostream& operator<<(ostream& os, const Event& e) {
        os << "<Event>" << endl;
        os << "<code>" << endl;
        os << e.getCode() << endl;
        os << "</code>" << endl;
        os << "<title>" << endl;
        os << e.getTitle() << endl;
        os << "</title>" << endl;
        
        // Gestion du Timing optionnel
        try {
            Timing t = e.getTiming(); // Va lancer une exception NO_TIMING si nullptr
            os << "<timing>" << endl;
            os << t; // Appelle l'opérateur << de Timing
            os << "</timing>" << endl;
        } catch (const TimingException& ex) {
            // Aucun timing planifié, on n'écrit pas les balises <timing>
        }
        
        os << "</Event>" << endl;
        return os;
    }

    istream& operator>>(istream& is, Event& e) {
        string ligne;
        getline(is, ligne); // <Event>
        
        getline(is, ligne); // <code>
        getline(is, ligne); // valeur du code
        e.setCode(stoi(ligne));
        getline(is, ligne); // </code>
        
        getline(is, ligne); // <title>
        getline(is, ligne); // valeur du titre
        e.setTitle(ligne.c_str()); // .c_str() permet la conversion propre vers char* (Etape 1)
        getline(is, ligne); // </title>
        
       getline(is, ligne); // Lit la balise suivante apres le titre
        if (ligne == "<timing>") {
            Timing t;
            is >> t; // Appelle l'opérateur >> de Timing
            e.setTiming(t);
            getline(is, ligne); // lit </timing>
            getline(is, ligne); // lit </Event> (qui traine)
        } else if (ligne == "</Event>") {
            e.clearTiming();
            }
        
        return is;
    }
}
