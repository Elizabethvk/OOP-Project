#ifndef NO_CLOSE_ARR_CUSTOM_EXCEPTION_H
#define NO_CLOSE_ARR_CUSTOM_EXCEPTION_H

#include <stdexcept>

class NotAValidCloseArray : public std::exception {
public:
    const char *what() const throw()
    {
        return "The array should be closed with \']\' !";
    }
};


#endif