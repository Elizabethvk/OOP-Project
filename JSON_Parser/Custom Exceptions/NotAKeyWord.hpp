#ifndef KEYWORD_CUSTOM_EXCEPTION_H
#define KEYWORD_CUSTOM_EXCEPTION_H

#include <stdexcept>

class NotAKeyWord : public std::exception {
public:
    const char *what() const throw()
    {
        return "The value should have been \"true\", \"false\" or \"null\"!";
    }
};


#endif