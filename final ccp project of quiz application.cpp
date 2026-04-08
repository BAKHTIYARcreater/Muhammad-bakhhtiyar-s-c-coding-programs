#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    int correctAnswer;

public:
    Question(string q, vector<string> opt, int ans) {
        questionText = q;
        options = opt;
        correctAnswer = ans;
    }

    void display() {
        cout << "\n" << questionText << endl;
        for (int i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int userAnswer) {
        return userAnswer == correctAnswer;
    }

    int getCorrectAnswer() {
        return correctAnswer;
    }

    string getCorrectOption() {
        return options[correctAnswer - 1];
    }

    string getQuestion() {
        return questionText;
    }
};

int main() {
    srand(time(0));

    vector<Question> allQuestions;

    // Adding questions
    allQuestions.push_back(Question("Capital of Pakistan?", {"Lahore","Islamabad","Karachi","Peshawar"}, 2));
    allQuestions.push_back(Question("2 + 2 = ?", {"3","4","5","6"}, 2));
    allQuestions.push_back(Question("OOP stands for?", {"Object Oriented Programming","Only One Program","Object One Process","None"}, 1));
    allQuestions.push_back(Question("Largest planet?", {"Earth","Mars","Jupiter","Venus"}, 3));
    allQuestions.push_back(Question("C++ is?", {"Language","Game","OS","Browser"}, 1));
    allQuestions.push_back(Question("Sun is a?", {"Planet","Star","Galaxy","Asteroid"}, 2));
    allQuestions.push_back(Question("5 * 3 = ?", {"10","15","20","25"}, 2));

    int totalQuestions = 5;
    int score = 0;

    vector<int> askedIndexes;

    for (int i = 0; i < totalQuestions; i++) {
        int index;

        // ensure unique random questions
        while (true) {
            index = rand() % allQuestions.size();
            bool alreadyAsked = false;

            for (int j = 0; j < askedIndexes.size(); j++) {
                if (askedIndexes[j] == index) {
                    alreadyAsked = true;
                    break;
                }
            }

            if (!alreadyAsked) {
                askedIndexes.push_back(index);
                break;
            }
        }

        int answer;
        allQuestions[index].display();
        cout << "Enter your answer: ";
        cin >> answer;

        if (allQuestions[index].checkAnswer(answer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong!\n";
        }
    }

    // Final Score
    cout << "\nFinal Score: " << score << "/" << totalQuestions << endl;

    // Show correct answers at end
    cout << "\n--- Correct Answers ---\n";
    for (int i = 0; i < askedIndexes.size(); i++) {
        int idx = askedIndexes[i];
        cout << allQuestions[idx].getQuestion() << endl;
        cout << "Correct Answer: "
             << allQuestions[idx].getCorrectAnswer()
             << ". " << allQuestions[idx].getCorrectOption() << "\n\n";
    }

    return 0;
}
