
#include <stdio.h>

int main(void) {
    float marks[5];
    float total = 0, percentage;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter marks for subject %d (0-100): ", i + 1);

        if (scanf("%f", &marks[i]) != 1 ||
            marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks. Enter a value from 0 to 100.\n");
            return 1;
        }

        total += marks[i];
    }

    percentage = total / 5.0f;

    printf("\nTotal Marks = %.2f / 500\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    if (percentage >= 90) {
        printf("Grade: A+\n");
    } else if (percentage >= 80) {
        printf("Grade: A\n");
    } else if (percentage >= 70) {
        printf("Grade: B\n");
    } else if (percentage >= 60) {
        printf("Grade: C\n");
    } else if (percentage >= 40) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F (Fail)\n");
    }

    return 0;
}
