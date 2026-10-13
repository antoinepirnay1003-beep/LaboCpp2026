#include "Event.h"
#include <iostream>
#include <cstring>

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
		return Timing(); 
	    }
	    return *timing; // On retourne l'objet pointé
	}

	void Event::setTiming(const Timing& t) {
	    if (timing != nullptr) {
		delete timing; // Libérer l'ancien timing s'il y en avait déjà un
	    }
	    timing = new Timing(t); // Allocation d'un nouveau Timing par copie
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
}
