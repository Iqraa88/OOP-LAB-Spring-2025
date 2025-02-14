#include<iostream>
using namespace std;

class fitnessTracker{

string userName;
int dailyStepGoal;
int stepsTaken;
int caloriesBurned;

public:

fitnessTracker(){};

void setDailyStepGoal(int goal){
    dailyStepGoal= goal;
}

int getDailyStepGoal(){
    return dailyStepGoal;
}

void logSteps(){
    int s;
    cout<< "How many steps have you taken? "<< endl;
    cin>> s;
    stepsTaken= s;
}

void setCaloriesBurned(){
    caloriesBurned= stepsTaken * 0.05;
}


void displayProgress(){
    cout<< "| Goal: "<< dailyStepGoal<< " |" << endl;
    cout<< "| Steps Taken: "<< stepsTaken << " |"<<  endl;
    cout<< "| Calories Burned: "<< caloriesBurned<< " |"<< endl;
    if(stepsTaken>= dailyStepGoal){
       cout<< "Yayyy! You Acheived your goal for today."<< endl;
    }
    else{
        cout<< "Keep going! you need "<< dailyStepGoal-stepsTaken<< " more steps!"<< endl;
        
    }
}




};
int main(){

fitnessTracker Laiba;
Laiba.setDailyStepGoal(6000);
cout<< "Your Step Goal is: "<< Laiba.getDailyStepGoal()<< endl;
Laiba.logSteps();
Laiba.setCaloriesBurned();
Laiba.displayProgress();

    return 0;
}
