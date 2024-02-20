#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int secretNumber, guess, numberOfGuesses = 0;

  // Seed the random number generator
  srand(time(0));

  // Generate a random number
  secretNumber = rand() % 100 + 1; // Adjust the range as needed

  cout << "I'm thinking of a number between 1 and 100 (or your chosen range). Can you guess it?" << endl;

  do {
    cout << "Enter your guess: ";
    cin >> guess;

    numberOfGuesses++;

    if (guess > secretNumber) {
      cout << "Too high!" << endl;
    } else if (guess < secretNumber) {
      cout << "Too low!" << endl;
    } else {
      cout << "Correct! You guessed the number in " << numberOfGuesses << " tries." << endl;
    }
  } while (guess != secretNumber);

  // Ask if the user wants to play again
  char answer;
  cout << "Play again? (y/n): ";
  cin >> answer;

  if (answer == 'y' || answer == 'Y') {
    // Reset variables and restart the game
    numberOfGuesses = 0;
    secretNumber = rand() % 100 + 1;
    main(); // Recursive call to start again
  }

  return 0;
}
