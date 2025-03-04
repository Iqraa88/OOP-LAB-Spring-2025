#include<iostream>
#define max_levels 10
using namespace std;

class Levels{

    int levelNum;
    string difficulty;

    public:
    
    Levels(int levelNum=0, string difficulty="Unknown"): levelNum(levelNum), difficulty(difficulty){}

    int getNum(){return levelNum;}
    string getDifficulty(){return difficulty;}
};

class VideoGame{

    string name;
    string genre;
    Levels *levels;
    int count;


    public:
    
    VideoGame(string name, string genre, int count=0): name(name), genre(genre), count(count){
        levels= new Levels[max_levels];
    }


    void addLevels(Levels &level){
        if(count< max_levels ){
            levels[count]= level;
            count++;
        }
        else{
            cout<<"No more levels can be added!"<< endl;
        }
    }

    void displayDetails(){
        cout<<"-----------------------------"<< endl;
        cout<<" Game Name: "<< name<< " "<< endl;
        cout<<" Game Genre: "<< genre<< " "<< endl;
        cout<<" Game Levels: "<< count<< " "<< endl;
        for(int i=0; i<count; i++){
            cout<< "Level Num: "<< levels[i].getNum()<< " "<< endl;  
            cout<< "Level Difficulty: "<< levels[i].getDifficulty()<< " "<< endl;  
           }
        cout<<"-----------------------------"<< endl;
    }

    ~ VideoGame(){
        delete[] levels;
    }

};

int main()
{
    Levels l1(1, "Easy");
    Levels l2(2, "Medium");
    Levels l3(3, "Hard");
    Levels l4(4, "Hardest");

    VideoGame v1("Candy Crush", "Fun");
    v1.addLevels(l1);
    v1.addLevels(l2);
    v1.addLevels(l3);
    v1.addLevels(l4);

    v1.displayDetails();


  

 return 0;
}