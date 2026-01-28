//lab_3 excercise 2?
#include <iostream>
using namespace std;

/*
  Class: Character
  Purpose: Represents a game character in Epic Clash
           Demonstrates encapsulation, dynamic memory,
           and constructor overloading
*/
class Character {
private:
    // Private data members (encapsulation)
    int* health;
    int* attackPower;
    int* defense;

public:
    /*
      Default Constructor
      Initializes character with standard values
    */
    Character() {
        health = new int(100);
        attackPower = new int(50);
        defense = new int(30);
    }

    /*
      Parameterized Constructor
      Allows custom values at object creation
    */
    Character(int h, int a, int d) {
        health = new int(h);
        attackPower = new int(a);
        defense = new int(d);
    }

    /*
      Copy Constructor
      Creates a new character by copying another
      Performs deep copy
    */
    Character(const Character& c) {
        health = new int(*(c.health));
        attackPower = new int(*(c.attackPower));
        defense = new int(*(c.defense));
    }

    /*
      Getter functions
      Provide controlled access to data
    */
    int getHealth() {
        return *health;
    }

    int getAttackPower() {
        return *attackPower;
    }

    int getDefense() {
        return *defense;
    }

    /*
      Setter functions
      Allow controlled modification of data
    */
    void setHealth(int h) {
        *health = h;
    }

    void setAttackPower(int a) {
        *attackPower = a;
    }

    void setDefense(int d) {
        *defense = d;
    }

    /*
      Destructor
      Releases dynamically allocated memory
    */
    ~Character() {
        delete health;
        delete attackPower;
        delete defense;
    }
};

int main() {
    // Default character
    Character player1;

    // Parameterized character
    Character player2(150, 70, 40);

    // Copy character
    Character player3 = player2;

    cout << "Player 1 Health: " << player1.getHealth() << endl;
    cout << "Player 2 Attack: " << player2.getAttackPower() << endl;
    cout << "Player 3 Defense: " << player3.getDefense() << endl;

    return 0;
}

