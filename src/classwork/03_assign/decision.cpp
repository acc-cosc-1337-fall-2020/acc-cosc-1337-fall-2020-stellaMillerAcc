//cpp
#include<string>
#include "decision.h"

using std::string;

string get_letter_grade_using_if(int numericGrade) {
    if (numericGrade >= 90) {
        return "A";
    }
    else if(numericGrade >= 80) {
        return "B";
    }
    else if(numericGrade >= 70) {
        return "C";
    }
    else if(numericGrade >= 60) {
        return "D";
    }
    else {
        return "F";
    }
}

string get_letter_grade_using_switch(int numericGrade) {

    int converted = numericGrade/10;

    switch (converted)
    {
    case 10: case 9:
        return "A";
        break;

    case 8:
        return "B";
        break;

    case 7:
        return "C";
        break;

    case 6:
        return "D";
        break;

    default:
        return "F";
        break;
    }
}
