#include <stdio.h>
#include <string.h>

// Recursive function to find possible score combinations
void findScoreCombinations(int targetScore, int scoringValues[], char *scoringNames[], int currentCombination[], int allCombinations[][5], int *comboCount, int startIndex) {
    if (targetScore == 0) {
        // Store the current combination if the score is exactly 0
        for (int i = 0; i < 5; i++) {
            allCombinations[*comboCount][i] = currentCombination[i];
        }
        (*comboCount)++;
        return;
    }
    if (targetScore < 0) return;  // Stop if the score goes negative

    // Try all scoring possibilities starting from the current index
    for (int i = startIndex; i < 5; i++) {
        currentCombination[i]++;

        // Recurse with reduced score
        findScoreCombinations(targetScore - scoringValues[i], scoringValues, scoringNames, currentCombination, allCombinations, comboCount, i);

        currentCombination[i]--;  // Backtrack
    }
}

int main() {
    int stopFlag = -1;
    int targetScore;

    // Array of scoring play names
    char *scoringPlayNames[5] = {
        "TD + 2PT", // Touchdown + 2-point conversion
        "TD + PAT", // Touchdown + 1-point conversion
        "TD",   // Touchdown
        "FG",   // Field Goal
        "ST"    // Safety
    };

    // Array of scoring values corresponding to the plays
    int scoringValues[5] = {
        8,  // TD2P
        7,  // TD1P
        6,  // TD
        3,  // FG
        2   // ST
    };

    while (stopFlag != 0 && stopFlag != 1) {
        printf("Enter the NFL Score: ");
        scanf("%d", &targetScore);

        // Initialize arrays to track current combinations and all possible combinations
        int currentCombination[5];
        memset(currentCombination, 0, sizeof(currentCombination));
        int allCombinations[1000][5];
        memset(allCombinations, 0, sizeof(allCombinations));
        int comboCount = 0;

        // Find all score combinations
        findScoreCombinations(targetScore, scoringValues, scoringPlayNames, currentCombination, allCombinations, &comboCount, 0);

        // Output the result
        printf("Number of combinations for a %d point game: %d\n\n", targetScore, comboCount);
        for (int i = 0; i < comboCount; i++) {
            printf("Combination %d:\n", i + 1);
            int totalPoints = 0;
            for (int j = 0; j < 5; j++) {
                if (allCombinations[i][j] > 0) {
                    printf(" %d x %s\n", allCombinations[i][j], scoringPlayNames[j]);
                    totalPoints += allCombinations[i][j] * scoringValues[j];
                }
            }
            printf(" Total Points: %d\n\n", totalPoints);
        }

        // Prompt the user to stop or continue
        printf("Enter 0 or 1 to STOP: ");
        scanf("%d", &stopFlag);
    }

    return 0;
}

