#ifndef NOT_VALUE_CUSTOM_EXCEPTION_H
#define NOT_VALUE_CUSTOM_EXCEPTION_H

#include <stdexcept>

class InvalidValue : public std::exception {
public:
    const char *what() const throw()
    {
        return "Unexpected value!";
    }
};


#endif