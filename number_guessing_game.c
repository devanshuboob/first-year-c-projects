
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secret, guess;
    int attempts = 0;

    srand((unsigned int)time(NULL));
    secret = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please guess within the range 1-100.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! You guessed the number.\n");
            printf("Attempts: %d\n", attempts);
        }

    } while (guess != secret);

    return 0;
}
