
#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int roll;
    char name[NAME_LENGTH];
    float marks;
};

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, i, searchRoll, found;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Student record limit reached.\n");
                    break;
                }

                printf("Enter roll number: ");
                if (scanf("%d", &students[count].roll) != 1) {
                    printf("Invalid roll number.\n");
                    return 1;
                }

                printf("Enter name (one word): ");
                if (scanf("%49s", students[count].name) != 1) {
                    printf("Invalid name.\n");
                    return 1;
                }

                printf("Enter marks (0-100): ");
                if (scanf("%f", &students[count].marks) != 1 ||
                    students[count].marks < 0 ||
                    students[count].marks > 100) {
                    printf("Invalid marks.\n");
                    return 1;
                }

                count++;
                printf("Student added successfully.\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No student records available.\n");
                    break;
                }

                printf("\nRoll No.   Name                 Marks\n");
                for (i = 0; i < count; i++) {
                    printf("%-10d %-20s %.2f\n",
                           students[i].roll,
                           students[i].name,
                           students[i].marks);
                }
                break;

            case 3:
                printf("Enter roll number to search: ");
                if (scanf("%d", &searchRoll) != 1) {
                    printf("Invalid roll number.\n");
                    return 1;
                }

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].roll == searchRoll) {
                        printf("Student found!\n");
                        printf("Roll: %d\n", students[i].roll);
                        printf("Name: %s\n", students[i].name);
                        printf("Marks: %.2f\n", students[i].marks);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found.\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Select 1-4.\n");
        }

    } while (choice != 4);

    return 0;
}
