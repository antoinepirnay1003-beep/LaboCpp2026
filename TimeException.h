#ifndef TIMEEXCEPTION_H
#define TIMEEXCEPTION_H
#include "Exception.h"
#include <string>

namespace planning {
    class TimeException : public Exception {
    private:
        int code;
    public:
        static const int INVALID_HOUR;
        static const int INVALID_MINUTE;
        static const int OVERFLOW;

        TimeException(const std::string& msg, int code);
        int getCode() const;
    };
}
#endif
