#include<iostream>
using namespace std;

class Character{
    protected:
    string ID;
    string name;
    int level;
    int healthPoints;

    public:

    Character(string ID, string name, int level, int healthPoints): ID(ID), name(name), level(level), healthPoints(healthPoints){}

    virtual void attack(){
        cout<< "Attacking!!!"<< endl;
    }
    virtual void defend(){
        cout<< "Defending!!!"<< endl;
    }

    virtual void displayStats(){
        cout<< "-------------------"<< endl;
        cout<< " ID: "<< ID<< " "<< endl;
        cout<< " Name: "<< name<< " "<< endl;
        cout<< " Level: "<< level<< " "<< endl;
        cout<< " Health Points: "<< healthPoints<< " "<< endl;
    }


};

class Warriors: public Character{

    int armorStrength;
    int meleeDamage;
    
};

class Mages: public Character{};

class Archers: public Character{};

class Rouges: public Character{};


int main()
{
  
 return 0;
}