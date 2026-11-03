#include "TimingException.h"

namespace planning {
    const int TimingException::INVALID_DAY = 1;
    const int TimingException::NO_TIMING = 2;

    TimingException::TimingException(const std::string& msg, int code) : Exception(msg), code(code) {}

    int TimingException::getCode() const { return code; }
}
