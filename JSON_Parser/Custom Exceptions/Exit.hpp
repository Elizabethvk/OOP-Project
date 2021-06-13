
#ifndef EXIT_PROGRAM_H
#define EXIT_PROGRAM_H

#include <stdexcept>

class Exit_Program : public std::exception {
public:
    const char* what() const throw()
    {
        return "Exiting the program! Goodbye ! :^)\n";
    }
};


#endif