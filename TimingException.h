#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H
#include "Exception.h"
#include <string>

namespace planning {
    class TimingException : public Exception {
    private:
        int code;
    public:
        static const int INVALID_DAY;
        static const int NO_TIMING;

        TimingException(const std::string& msg, int code);
        int getCode() const;
    };
}
#endif
