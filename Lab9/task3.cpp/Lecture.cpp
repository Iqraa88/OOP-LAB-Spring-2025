#include"Lecture.h"
#include<iostream>

using namespace std;

LectureCourse::LectureCourse(string courseCode, int credits): Course(courseCode,credits){}

void LectureCourse::calculateGrade(){
    cout<<"-------------------------------"<< endl;
cout<<" Calculating Grade for your LectureCourse ( "<< courseCode<< " ) ..."<< endl;
}


void LectureCourse::displayInfo()const{
cout<<"-------------------------------"<< endl;
cout<< "LectureCourse Code: "<< courseCode<< " "<< endl;
cout<< "LectureCourse Credits: "<< credits<< " "<< endl;
}

