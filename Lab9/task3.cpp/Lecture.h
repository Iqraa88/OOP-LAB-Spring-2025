#pragma once
#include"Course.h"

class LectureCourse: public Course{

    public:
    LectureCourse(string courseCode, int credits);
    void calculateGrade();
    void displayInfo()const;


};