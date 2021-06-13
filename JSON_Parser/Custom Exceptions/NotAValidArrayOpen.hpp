#ifndef NO_OPEN_ARR_CUSTOM_EXCEPTION_H
#define NO_OPEN_ARR_CUSTOM_EXCEPTION_H

#include <stdexcept>

class NotAValidOpenArray : public std::exception {
public:
    const char *what() const throw()
    {
        return "Arrays start with \'[\' !";
    }
};


#endif