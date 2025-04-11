#include <iostream>
using namespace std;

class Character {
protected:
    int id;
    string characterName;
    int level;
    float healthPoints;
    

public:
    Character(int id, string characterName, int level, float healthPoints): id(id), characterName(characterName), level(level), healthPoints(healthPoints) {}

    virtual void attack() {
        cout<<"-----------------------------"<< endl;
        cout << characterName << " performs a basic attack!" << endl;
    }

    virtual void defend() {
        cout<<"-----------------------"<<endl;
        cout << characterName << " takes a defensive stance!" << endl;
    }

    virtual void showStats() {
        cout<< "-------------------"<< endl;
        cout<< " ID: "<< id<< " "<< endl;
        cout<< " Name: "<< characterName<< " "<< endl;
        cout<< " Level: "<< level<< " "<< endl;
        cout<< " Health Points: "<< healthPoints<< " "<< endl;
    }

    
};

class Warrior : public Character {
    int armorRating;
    int meleeDamage;

public:
    Warrior(int id, string name, int level, float health, int armor, int damage)  : Character(id, name, level, health), armorRating(armor), meleeDamage(damage) {}

    void attack() override {
        cout << characterName << "  causing " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int mana;
    int magicPower;

public:
    Mage(int id, string name, int level, float health, int mana, int power) : Character(id, name, level, health), mana(mana), magicPower(power) {}

    void defend() override {
        cout << characterName << " uses magic shield to absorb damage.." << endl;
    }
};

class Archer : public Character {
    int arrowsLeft;
    int accuracyRate;

public:
    Archer(int id, string name, int level, float health, int arrows, int accuracy)  : Character(id, name, level, health), arrowsLeft(arrows), accuracyRate(accuracy) {}

    void attack() override {
        cout << characterName << " releases an arrow with " << accuracyRate << "% accuracy!" << endl;
    }
};

class Rogue : public Character {
    int stealth;
    int speed;

public:
    Rogue(int id, string name, int level, float health, int stealth, int speed) : Character(id, name, level, health), stealth(stealth), speed(speed) {}

    void showStats() override {
        Character::showStats();
        cout << " Stealth Rating: " << stealth << endl;
         cout << " Agility: " << speed << endl;
    }
};

int main() {
    Character* ptr;

    Warrior w1(1001, "Grimblade", 55, 980, 350, 120);

    Mage m1(1002, "Zyra", 48, 560, 900, 75);
    Archer a1(1003, "Sylvan", 40, 600, 30, 88);
    Rogue r1(1004, "Shadow", 60, 750, 95, 110);

    ptr = &w1;
    cout<<"-----------------------------"<< endl;
    ptr->attack();

    ptr = &m1;
    cout<<"-----------------------------"<< endl;

    ptr->defend();

    ptr = &a1;
    cout<<"-----------------------------"<< endl;

    
    ptr->attack();

    ptr = &r1;
    ptr->showStats();

    return 0;
}

