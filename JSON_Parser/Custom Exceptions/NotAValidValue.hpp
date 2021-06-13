/**
 * \brief A custom exception class throwing when encounter unexpected value
 * \author Elizabet Velikova
 */


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