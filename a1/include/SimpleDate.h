//
// Created by zaser on 2/13/2021.
//

#ifndef NEXT_DATE_SIMPLEDATE_H
#define NEXT_DATE_SIMPLEDATE_H
#include <iostream>

using namespace std;

class SimpleDate {
private:
    int month;
    int day;
    int year;
public:
    void initialize(int month, int day, int year);
    SimpleDate nextDate();
    std::string toString();
    SimpleDate(int i, int i1, int i2);
    SimpleDate();

    int getMonth();
    int getDay();
    int getYear();
};


#endif //NEXT_DATE_SIMPLEDATE_H
