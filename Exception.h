#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class Exception {
protected:
    std::string message;
public:
    Exception(const std::string& msg);
    virtual ~Exception() = default;
    std::string getMessage() const;
};
#endif
