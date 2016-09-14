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