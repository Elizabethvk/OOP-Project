#ifndef VALUE_CUSTOM_EXCEPTION_H
#define VALUE_CUSTOM_EXCEPTION_H

#include <stdexcept>

class UnknownValue : public std::exception {
public:
    const char *what() const throw()
    {
        return "Unknown symbol in a number!";
    }
};


#endif