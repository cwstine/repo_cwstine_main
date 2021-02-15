#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "include/SimpleDate.h"
#include "include/DateException.h"

using namespace std;


void validateInput(SimpleDate *d8){
    if (d8->getMonth() > 12 || d8->getMonth() < 1){
        throw DateException();
    }
    if (d8->getDay() > 31 || d8->getDay() < 1){
        throw DateException();
    }
    if (d8->getYear() > 2030 || d8->getYear() < 1812){
        throw DateException();
    }
    if ( d8->getDay() == 31 && (d8->getMonth() != 1 || d8->getMonth() != 3 || d8->getMonth() != 5
                                || d8->getMonth() != 7 || d8->getMonth() != 8 || d8->getMonth() != 10 || d8->getMonth() != 12)){
        throw DateException();
    }

    if (((d8->getMonth() == 2 && d8->getDay() > 28) && d8->getYear() % 4 != 0) || d8->getDay() > 29){
        throw DateException();
    }

    if ((d8->getMonth() == 2 && d8->getDay() > 28) && d8->getYear() % 100 == 0 && d8->getYear() % 400 != 0){
        throw DateException();
    }
}

int main(int argc, char *argv[]) {
    cout << "You have entered " << argc
         << " arguments:" << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";


    //std::string oDate = argv[1];
    std::string oDate = "02/30/2004";
    std::string month = oDate.substr(0,2);
    std::string day = oDate.substr(3,5);;
    std::string year = oDate.substr(6,10);;
    int mon,da,yea;

    stringstream sm;
    sm << month;
    sm >> mon;

    stringstream sd;
    sd << day;
    sd >> da;

    stringstream sy;
    sy << year;
    sy >> yea;

    SimpleDate *guy = new SimpleDate(mon,da,yea);
    validateInput(guy);

    std::cout << guy->toString() << std::endl;

    *guy = guy->nextDate();
    std::cout << guy->toString() << std::endl;

    return 0;
}



