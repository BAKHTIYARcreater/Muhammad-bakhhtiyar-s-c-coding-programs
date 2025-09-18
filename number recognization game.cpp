
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>  // For Beep() in Windows
#else
#include <unistd.h>  // For sleep() in Linux/macOS
#endif

void welcomeMessage();
int getPlayerGuess();
int checkGuess(int guess, int number);
void displayGameStats(int guesses);
void playSuccessSound();
void playFailureSound();
void platformSpecificSleep(int seconds);

int main() {
  
  234
  2344
    srand(time(NULL)); // Seed the random number generator

    int number = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guesses = 0; // Counter for number of guesses
    int guess;
    char playAgain;
    int maxAttempts = 5;

    welcomeMessage();

    // Game loop
    do {
        for (int i = 0; i < maxAttempts; i++) {
            guess = getPlayerGuess();
            guesses++;

            // Check the player's guess
            int result = checkGuess(guess, number);

            if (result == 0) {
                printf("Congratulations! You guessed the right number: %d\n", number);
                playSuccessSound();
                displayGameStats(guesses);
                break;
            } else if (result == 1) {
                printf("Your guess is too high. Try again.\n");
                playFailureSound();
            } else if (result == -1) {
                printf("Your guess is too low. Try again.\n");
                playFailureSound();
            }

            // If no more attempts are left
            if (i == maxAttempts - 1) {
                printf("Sorry, you've used all your attempts. The correct number was %d.\n", number);
            }

            platformSpecificSleep(1);  // Sleep for 1 second between guesses (for better UX)
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain == 'y' || playAgain == 'Y') {
            number = rand() % 100 + 1;  // Generate a new random number
            guesses = 0;  // Reset the guess counter
        }

    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing!\n");
    return 0;
}

// Function to display a welcome message
void welcomeMessage() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have 5 attempts to guess the correct number.\n");
}

// Function to get player's guess
int getPlayerGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to check if the player's guess is correct, too high, or too low
int checkGuess(int guess, int number) {
    if (guess == number) {
        return 0;  // Correct guess
    } else if (guess > number) {
        return 1;  // Guess is too high
    } else {
        return -1;  // Guess is too low
    }
}

// Function to display the stats of the game (number of guesses)
void displayGameStats(int guesses) {
    printf("It took you %d guesses to find the correct number.\n", guesses);
}

// Function to play a sound when the guess is correct
void playSuccessSound() {
#ifdef _WIN32
    Beep(1000, 500);  // Frequency 1000 Hz, duration 500ms (success sound)
#else
    // On Linux/macOS, we can use system call to play sound (you need to have a sound file)
    system("aplay /usr/share/sounds/alsa/Front_Center.wav &"); // Linux sound (you can use a different sound file)
    // or use "afplay" on macOS
#endif
}

// Function to play a sound when the guess is wrong
void playFailureSound() {
#ifdef _WIN32
    Beep(500, 500);  // Frequency 500 Hz, duration 500ms (failure sound)
#else
    // Play a different sound for failure
    system("aplay /usr/share/sounds/alsa/Side_Right.wav &");  // You can change the sound file as desired
    // Or use "afplay" on macOS
#endif
}

// Function to pause execution for a given number of seconds (platform-specific)
void platformSpecificSleep(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000); // Windows Sleep() takes milliseconds
#else
    sleep(seconds); // Linux/macOS sleep() takes seconds
#endif
}

