//
// Created by zaser on 2/13/2021.
//

#ifndef NEXT_DATE_DATEEXCEPTION_H
#define NEXT_DATE_DATEEXCEPTION_H


#include <exception>

class DateException : public std::exception{
public:
    const char* what() const throw() {
        return "Invalid Date Exception Occurred";
    }
};


#endif //NEXT_DATE_DATEEXCEPTION_H
