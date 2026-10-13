#include <cstring>
#include <iostream>
using namespace std;
 
class Event 
{

private:

  int code;
  char* title;

public:

  Event()             //constructeur par défaut
  {
    title = new char[20];
    code=1;
    strcpy(title, "default");

  }

  Event(int c, const char* t)   //constructeur d'initialisation 
  {
    title = new char[20];
    code = c;
    strcpy(title, t);

  }

  ~Event()
  {
    delete title;
    cout << "destructeur";
  }

  void setcode(int c)                 //c= variable temporaire qui va etre analysee
  {
    if (c<=0) return;
    code = c;
    
  }

  void setTitle(const char* t)
  {
    if (strlen(t) == 0) return;
    strcpy(title,t);
  }

  int getCode()
  {
    return code;
  }

  char* getTitle()
  {
    return title;
  }

  void display()
  {
    cout << "Code = " << code << endl;
    cout << "Title = " << title << endl;
  }
};

int main()
{
  Event e;
  e.display();

  e.setcode(6);
  e.setTitle("Labo CPP");
  e.display();

  Event e2(3, "Labo Linux"); 
  e2.display();

}