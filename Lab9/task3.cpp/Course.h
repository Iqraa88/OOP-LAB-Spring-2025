#pragma once
#include<iostream>
using namespace std;
class Course{

protected:
    string courseCode;
    int credits;

public:
    Course(string courseCode, int credits): courseCode(courseCode), credits(credits){}
    virtual void calculateGrade()=0;
    virtual void displayInfo()const=0;

};