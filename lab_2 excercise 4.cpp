#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class HittingGame
{
private:
    int players;
    int yourHits;
    int enemyHits;

public:
    // Constructor
    HittingGame()
    {
        srand(time(0));
        players = rand() % 5 + 1;   // Random number of players (1 to 5)
        yourHits = 0;
        enemyHits = 0;
    }

    // Function to play the game
    void playGame()
    {
        cout << "Number of players in your team: " << players << endl << endl;

        for (int i = 1; i <= players; i++)
        {
            int num1 = rand() % 10;
            int num2 = rand() % 10;

            if (num1 == num2)
            {
                cout << "Round " << i << ": Enemy got hit by your team." << endl;
                yourHits++;
            }
            else
            {
                cout << "Round " << i << ": Your team got hit by the enemy." << endl;
                enemyHits++;
            }
        }
    }

    // Function to display result
    void showResult()
    {
        cout << "\nFinal Result" << endl;
        cout << "Your Team Hits: " << yourHits << endl;
        cout << "Enemy Team Hits: " << enemyHits << endl;

        if (yourHits > enemyHits)
            cout << "Your Team Wins!" << endl;
        else if (enemyHits > yourHits)
            cout << "Enemy Team Wins!" << endl;
        else
            cout << "Match Draw!" << endl;
    }
};

int main()
{
    HittingGame game;
    game.playGame();
    game.showResult();

    return 0;
}

