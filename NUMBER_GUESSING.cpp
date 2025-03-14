#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
 
    do {
        std::cout << "Please enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number " 
                      << randomNumber << " in " << attempts << " attempts." << std::endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
