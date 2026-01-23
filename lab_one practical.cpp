#include <iostream>
#include <iomanip> // For setprecision
using namespace std;

class Student {
public:
    void calculateMarks() {
        int roll;
        float marks[5], total = 0, percentage;

        cout << "Enter Roll Number: ";
        cin >> roll;

        for (int i = 0; i < 5; i++) {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }

        percentage = total / 5;
        cout << fixed << setprecision(2);
        cout << "Total Marks = " << total << endl;
        cout << "Percentage = " << percentage << "%" << endl;
    }
};

class Swapper {
public:
    void swapThree() {
        int a, b, c;
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;

        int temp = a;
        a = b;
        b = c;
        c = temp;

        cout << "After swapping:" << endl;
        cout << "a = " << a << " b = " << b << " c = " << c << endl;
    }
};

class Temperature {
public:
    void convert() {
        float f, c;
        cout << "Enter temperature in Fahrenheit: ";
        cin >> f;

        c = (f - 32) / 1.8;
        cout << fixed << setprecision(2);
        cout << "Temperature in Celsius = " << c << "°C" << endl;
    }
};

class Matrix {
public:
    void matrixOperations() {
        int a[3][3], b[3][3], sum[3][3], mul[3][3];

        cout << "Enter first 3x3 matrix:" << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];

        cout << "Enter second 3x3 matrix:" << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> b[i][j];

        cout << "Matrix Addition:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum[i][j] = a[i][j] + b[i][j];
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matrix Multiplication:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    mul[i][j] += a[i][k] * b[k][j];
                cout << mul[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Sphere {
public:
    void calculate() {
        float r;
        cout << "Enter radius of sphere: ";
        cin >> r;

        float surfaceArea = 4 * 3.14159f * r * r;
        float volume = (4.0f / 3.0f) * 3.14159f * r * r * r;

        cout << fixed << setprecision(2);
        cout << "Surface Area = " << surfaceArea << endl;
        cout << "Volume = " << volume << endl;
    }
};

class Bank {
protected:
    float balance;

public:
    Bank() {
        balance = 200000;
    }
};

class Savings : public Bank {
public:
    void withdraw(float amount) {
        if (amount > 100000) {
            cout << "Cannot withdraw more than 100000" << endl;
            return;
        }

        float fee = 0.02f * amount;
        balance -= (amount + fee);

        if (amount > 50000)
            balance -= balance * 0.05f;

        cout << fixed << setprecision(2);
        cout << "Remaining Balance = " << balance << endl;
    }
};

class Current : public Bank {
public:
    void withdraw(float amount) {
        if (amount > 100000) {
            cout << "Cannot withdraw more than 100000" << endl;
            return;
        }

        balance -= (amount + 100);

        if (amount > 50000)
            balance -= balance * 0.05f;

        cout << fixed << setprecision(2);
        cout << "Remaining Balance = " << balance << endl;
    }
};

int main() {
    int choice;

    do {
        cout << endl;
        cout << "1. Student Marks & Percentage" << endl;
        cout << "2. Swap Three Numbers" << endl;
        cout << "3. Fahrenheit to Celsius" << endl;
        cout << "4. Matrix Operations" << endl;
        cout << "5. Sphere Surface Area & Volume" << endl;
        cout << "6. Bank Withdrawal System" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Student s;
            s.calculateMarks();
            break;
        }
        case 2: {
            Swapper sw;
            sw.swapThree();
            break;
        }
        case 3: {
            Temperature t;
            t.convert();
            break;
        }
        case 4: {
            Matrix m;
            m.matrixOperations();
            break;
        }
        case 5: {
            Sphere sp;
            sp.calculate();
            break;
        }
        case 6: {
            char type;
            float amount;
            cout << "Enter account type (S/C): ";
            cin >> type;
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (type == 'S' || type == 's') {
                Savings s;
                s.withdraw(amount);
            } else if (type == 'C' || type == 'c') {
                Current c;
                c.withdraw(amount);
            } else {
                cout << "Invalid account type" << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}

