#include <stdio.h>

int main() {
    int pin = 4821, enteredPin, attempts = 3;
    int choice, transactions = 0, success = 0;
    double balance = 12500.00, amount;

    while (attempts > 0) {
        printf("Enter PIN: ");
        if (scanf("%d", &enteredPin) != 1)
            return 0;

        if (enteredPin == pin) {
            success = 1;
            break;
        } else {
            attempts--;

            if (attempts > 0) {
                printf("Incorrect PIN. %d attempt%s remaining.\n",
                       attempts, attempts == 1 ? "" : "s");
            } else {
                printf("Incorrect PIN. Your card has been blocked. Please visit your nearest branch.\n");
            }
        }
    }

    if (!success)
        return 0;

    printf("\n===== Welcome =====\n");
    printf("Balance: Rs. %.2f\n", balance);

    while (transactions < 5) {
        printf("\n-------------------\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Exit\n");
        printf("===================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 0;

        switch (choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("Enter withdrawal amount: Rs. ");
                if (scanf("%lf", &amount) != 1)
                    return 0;

                if (amount <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else if (amount > balance) {
                    printf("Insufficient balance.\n");
                } else if ((long long)amount % 100 != 0 ||
                           amount != (long long)amount) {
                    printf("Amount must be a multiple of 100.\n");
                } else {
                    balance -= amount;
                    transactions++;
                    printf("\nTransaction: Withdrawal\n");
                    printf("Amount: Rs. %.2f\n", amount);
                    printf("Balance: Rs. %.2f\n", balance);
                    printf("Txn No.: %d\n", transactions);
                }
                break;

            case 3:
                printf("Enter deposit amount: Rs. ");
                if (scanf("%lf", &amount) != 1)
                    return 0;

                if (amount <= 0) {
                    printf("Invalid deposit amount.\n");
                } else {
                    balance += amount;
                    transactions++;
                    printf("\nTransaction: Deposit\n");
                    printf("Amount: Rs. %.2f\n", amount);
                    printf("Balance: Rs. %.2f\n", balance);
                    printf("Txn No.: %d\n", transactions);
                }
                break;

            case 4:
                printf("Final Balance: Rs. %.2f\n", balance);
                printf("Thank you for using our ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (transactions == 5) {
            printf("\nTransaction limit reached. Please re-login.\n");
            printf("Final Balance: Rs. %.2f\n", balance);
            break;
        }
    }

    return 0;
}