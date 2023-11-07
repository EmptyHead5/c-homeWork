#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int count;
} Player;

// Function to get a valid guess from the user
int GetGuess() {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {
            if (num < 10 || num > 100) {
                printf("Guess is out of range (10-100). Try again.\n");
            } else {
                return num;
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }
    }
}

// Function to sort leaders by count in ascending order
void SortLeaders(Player players[], int numLeaders) {
    for (int i = 0; i < numLeaders - 1; i++) {
        for (int j = 0; j < numLeaders - i - 1; j++) {
            if (players[j].count > players[j + 1].count) {
                // Swap players[j] and players[j + 1]
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

// Function to play the guessing game
void PlayGuessingGame(char name[], Player players[], int* numLeaders) {
    int target = rand() % 91 + 10;
    double sqrt_target = sqrt(target);
    int num;
    int count = 0;
    printf("%.8lf is the square root of what number? Guess a value between 10 and 100: ", sqrt_target);
    do {
        num = GetGuess();
        if (num < target) {
            printf("Too low, guess again: ");
            count++;
        } else if (num > target) {
            printf("Too high, guess again: ");
            count++;
        } else {
            count++;
            printf("You got it, baby!\n");
        }
    } while (num != target);
    printf("You made %d guesses.\n", count);
    if (*numLeaders < 5) {
        strcpy(players[*numLeaders].name, name);
        players[*numLeaders].count = count;
        (*numLeaders)++;
    } else {
        // Find the index of the highest score
        int highestIndex = 0;
        for (int i = 1; i < 5; i++) {
            if (players[i].count > players[highestIndex].count) {
                highestIndex = i;
            }
        }
        // Replace the highest score with the new score if it's better
        if (count < players[highestIndex].count) {
            strcpy(players[highestIndex].name, name);
            players[highestIndex].count = count;
        }
    }
    // Sort the leaders array after adding a new player
    SortLeaders(players, *numLeaders);
}

// Function to save the leaders to a file
void SaveLeadersToFile(Player players[], int numLeaders) {
    FILE *file = fopen("leaders.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < numLeaders; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].count);
    }
    fclose(file);
}

// Function to read the leaders from a file
void ReadLeadersFromFile(Player players[], int *numLeaders) {
    FILE *file = fopen("leaders.txt", "r");
    if (file == NULL) {
        return;
    }
    *numLeaders = 0;
    while (*numLeaders < 5 && fscanf(file, "%s %d", players[*numLeaders].name, &players[*numLeaders].count) == 2) {
        (*numLeaders)++;
    }
    fclose(file);
}

int main() {
    Player players[5];
    int numLeaders = 0;

    ReadLeadersFromFile(players, &numLeaders);

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    while (1) {
        char input[100];
        scanf("%s", input);
        if (input[0] == 'q') {
            SaveLeadersToFile(players, numLeaders);
            printf("Bye Bye!\n");
            return 0;
        } else {
            char name[MAX_NAME_LENGTH];
            printf("Please enter your name to start: ");
            scanf("%s", name);

            PlayGuessingGame(name, players, &numLeaders);
            printf("Here are the current leaders:\n");
            for (int i = 0; i < numLeaders; i++) {
                printf("%s made %d guesses\n", players[i].name, players[i].count);
            }
            printf("Press 'q' to quit or any other key to continue:\n");
        }
    }
    return 0;
}
