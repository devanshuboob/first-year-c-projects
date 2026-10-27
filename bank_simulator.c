
#include <stdio.h>

void deposit(double *balance) {
    double amount;

    printf("Enter deposit amount: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
    } else {
        *balance += amount;
        printf("Deposit successful.\n");
    }
}

void withdraw(double *balance) {
    double amount;

    printf("Enter withdrawal amount: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
    } else if (amount > *balance) {
        printf("Insufficient balance.\n");
    } else {
        *balance -= amount;
        printf("Withdrawal successful.\n");
    }
}

int main(void) {
    double balance = 1000.00;
    int choice;

    do {
        printf("\n=== Bank Account Simulator ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                deposit(&balance);
                break;

            case 3:
                withdraw(&balance);
                break;

            case 4:
                printf("Thank you for using the simulator.\n");
                break;

            default:
                printf("Invalid choice. Select 1-4.\n");
        }

    } while (choice != 4);

    return 0;
}
