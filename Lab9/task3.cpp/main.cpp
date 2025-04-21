#include<iostream>
#include"Course.h"
#include"Lecture.h"
#include"lab.h"
using namespace std;
int main()
{
  
    Course *temp;
    temp= new LectureCourse("MT1009", 3);
    temp->calculateGrade();
    temp->displayInfo();
    delete temp;

    temp= new LabCourse("EE1024", 2);
    temp->calculateGrade();
    temp->displayInfo();
    delete temp;

 return 0;
}
