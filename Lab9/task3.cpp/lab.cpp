#include"lab.h"
#include<iostream>

using namespace std;

LabCourse::LabCourse(string courseCode, int credits): Course(courseCode,credits){}

void LabCourse::calculateGrade(){
    cout<<"-------------------------------"<< endl;
    cout<<" Calculating Grade for your LabCourse ( "<< courseCode<< " ) ..."<< endl;
}


void LabCourse::displayInfo()const{
cout<<"-------------------------------"<< endl;
cout<< "LabCourse Code: "<< courseCode<< " "<< endl;
cout<< "LabCourse Credits: "<< credits<< " "<< endl;
}

