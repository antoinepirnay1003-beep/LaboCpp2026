#include "Exception.h"

using namespace std;

Exception::Exception(const string& msg) : message(msg) {}

string Exception::getMessage() const { return message; }
