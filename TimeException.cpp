#include "TimeException.h"

namespace planning {
    const int TimeException::INVALID_HOUR = 1;
    const int TimeException::INVALID_MINUTE = 2;
    const int TimeException::OVERFLOW = 3;

    TimeException::TimeException(const std::string& msg, int code) : Exception(msg), code(code) {}
    
    int TimeException::getCode() const { return code; }
}
