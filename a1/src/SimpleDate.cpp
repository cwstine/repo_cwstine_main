//
// Created by zaser on 2/13/2021.
//

#include "SimpleDate.h"
#include <iomanip>
#include <iostream>

SimpleDate::SimpleDate(int month, int day, int year){
    initialize(month, day, year);
}

void SimpleDate::initialize(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
}

SimpleDate SimpleDate::nextDate(){
    // 1 3 5 7 8 10 12 have 31
    // 2 has 28 or 29 on leap days
    // 4, 6, 9, 11 have 30
    bool incrementMonth = false;
    int month2 = this->month;
    int day2 = this->day;
    int year2 = this->year;
    bool incrementYear = false;
    //USE "this->" if get this class to work.
    if (day2 < 28) {
        day2++;
    } else if (day2 == 28 && month2 == 2 && (year2 % 4 != 0 || (year2 % 100 == 0 && year2 != 2000))){
        incrementMonth = true;
        day2 = 01;
    } else if (day2 == 29 && month2 == 2){
        incrementMonth = true;
        day2 = 01;
    } else if (day2 == 30 && month2 != 1 || month2 != 3 || month2 != 5 || month2 != 7 || month2 != 8 || month2 != 10 || month2 != 12){
        incrementMonth = true;
        day2 = 01;
    } else if (day2 == 31){
        incrementMonth = true;
        day2 = 01;
    } else {
        day++;
    }


    if( incrementMonth ){
        if( month2 == 12){
            month2 = 01;
            year2++;
        } else {
            month2++;
        }
    }

    return SimpleDate(month2, day2, year2);


}

/*
 * Get methods so that validateInput can be used in Main class
 */
int SimpleDate::getMonth(){
    return month;
}
int SimpleDate::getDay() {
    return day;
}
int SimpleDate::getYear(){
    return year;
}

/*
 * Returns Sting of date in MM/DD/YYYY format.
 */
std::string SimpleDate::toString(){
    std::string dayS = std::to_string(day);
    dayS.insert(dayS.begin(), 2-dayS.length(), '0');
    std::string monthS = std::to_string(month);
    monthS.insert(monthS.begin(), 2-monthS.length(), '0');

    return monthS + "/" + dayS + "/" + std::to_string(year);
}