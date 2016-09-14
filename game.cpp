/**
 * Guessing Game
 * 
 * INTERFACE
 * The computer will pick a random number between 0 and 100, inclusive. The user will guess a number,
 * and the computer will tell you if it is too high, too low, or correct. If it is correct, it will display how
 * many guesses it took you, and ask if you want to play again.
 * 
 * IMPLEMENTATION
 * Create a variable which will hold the random number and use rand() to create it. (5 points) Note that
 * you need to use srand() to set the random seed first. I would use time (so the line would be
 * “srand(time(NULL));”) Use cout to print things out to the command line. (5 points) Use cin to read
 * in a line (5 points):
 * 
 * Compare the input to the random number. (5 points) If the guess is correct, print out the number of
 * guesses (use a variable to keep track) and ask if they want to play again. (5 points) If so, restart the game. (5
 * points) (You can use y/n for the answer.)
 *
 * Comments! (10 points)
 * 
 * @author Harish Palani
 * @version 1.0
 */

#include <iostream>

using namespace std;

void playGame() {
    int r = 0;
    int guess = 0;
    int count = 0;
    
    srand(time(NULL)); // Seed random number generator
    r = rand() % 101; // Generate random number between 1 and 100
    
    cout << "\nWelcome to the Guessing Game!" << " / Please enter a guess between 0 and 100, inclusive: ";
    cin >> guess;
    
    while(!(guess >= 0 && guess <= 100)) {
        cout << "That was not between 0 and 100." << " / Please enter a guess between 0 and 100, inclusive: ";
        cin >> guess;
    }
    
    while (guess != r) {
        if (guess >= 0 && guess <= 100) {                                                                                                                                                                                                                                                           
            count++;
            if (guess < r) {
                cout << "Too low. Try again." << " / Please enter a guess between 0 and 100, inclusive: ";
                cin >> guess;
            } else if (guess > r) {
                cout << "Too high. Try again." << " / Please enter a guess between 0 and 100, inclusive: ";
                cin >> guess;
            } else {
                cout << "Try again." << " / Please enter a guess between 0 and 100, inclusive: ";
                cin >> guess;
            }
        } else {
            while (!(guess >= 0 && guess <= 100)) {
                cout << "That was not between 0 and 100." << " / Please enter a guess between 0 and 100, inclusive: ";
                cin >> guess;
            }
        }
    }
        
    if (guess == r) {
        int input = 0;
        count++;
        
        // Users can restart the game
        cout << "You got it! / Guesses required: " << count << "\n" << "Would you like to play again? (0 = no / 1 = yes): ";
        cin >> input;
        if (input == 1) {
            playGame();
        } else {
            cout << "Thank you for playing!";
        }
    }
}

int main() {
    playGame();
}