#pragma once
#include"Course.h"

class LabCourse: public Course{

    public:
    LabCourse(string courseCode, int credits);
    void calculateGrade();
    void displayInfo()const;


};