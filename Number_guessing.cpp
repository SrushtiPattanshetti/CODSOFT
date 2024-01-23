#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 10 + 1;
    int userGuess;

    std::cout << "Guess the number (between 1 and 10): ";

    do {
        // Read user's guess
        std::cin >> userGuess;

        // Provide feedback
        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again: ";
        }
    } while (userGuess != randomNumber);

    std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;

    return 0;
}