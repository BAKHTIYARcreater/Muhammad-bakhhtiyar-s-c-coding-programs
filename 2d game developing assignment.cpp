#include <iostream>
using namespace std;

// Base class
class Character {
public:
    virtual void attack() {
        cout << "Character attacks!" << endl;
    }
    virtual void power() {
        cout << "Character uses power!" << endl;
    }
    virtual ~Character() {} // Virtual destructor for safe polymorphism
};

// Derived class: Warrior
class Warrior : public Character {
public:
    void attack() override {
        cout << "Warrior swings sword!" << endl;
    }
    void power() override {
        cout << "Warrior uses Berserk!" << endl;
    }
};

// Derived class: Mage
class Mage : public Character {
public:
    void attack() override {
        cout << "Mage casts fireball!" << endl;
    }
    void power() override {
        cout << "Mage uses Arcane Blast!" << endl;
    }
};

// DamageCalculator class demonstrating function overloading
class DamageCalculator {
public:
    // Basic attack damage
    int calculateDamage(int base) {
        return base;
    }

    // Special attack damage (base + bonus)
    int calculateDamage(int base, int bonus) {
        return base + bonus;
    }
};

// Position class with operator overloading
class Position {
public:
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload + operator to combine positions
    Position operator+(const Position& other) {
        return Position(x + other.x, y + other.y);
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Using base class pointer for polymorphism
    Character* character1 = new Warrior();
    Character* character2 = new Mage();

    cout << "Polymorphism demonstration:" << endl;
    character1->attack();
    character1->power();
    character2->attack();
    character2->power();
    cout << endl;

    // Function overloading demonstration
    DamageCalculator dc;
    cout << "Function overloading demonstration:" << endl;
    cout << "Basic attack damage: " << dc.calculateDamage(50) << endl;
    cout << "Special attack damage: " << dc.calculateDamage(50, 30) << endl;
    cout << endl;

    // Operator overloading demonstration
    Position p1(5, 10);
    Position p2(3, 7);
    Position p3 = p1 + p2;

    cout << "Operator overloading demonstration:" << endl;
    cout << "Position 1: "; p1.display();
    cout << "Position 2: "; p2.display();
    cout << "Combined Position: "; p3.display();
    cout << endl;

    // Cleanup
    delete character1;
    delete character2;

    return 0;
}
