#include <stdio.h>
#include <stdlib.h>

struct BankAccount
{
    int accountNumber;
    char name[50];
    float balance;
};

// Function declarations
void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();

int main()
{
    int choice;

    printf("\n=================================\n");
    printf("     BANK ACCOUNT MANAGEMENT\n");
    printf("=================================\n");

    while (1)
    {
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balanceEnquiry();
                break;

            case 5:
                printf("\nThank you for using our banking system!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createAccount()
{
    struct BankAccount account;
    FILE *fp;

    printf("\nEnter account number: ");
    scanf("%d", &account.accountNumber);

    printf("Enter account holder name: ");
    scanf(" %49[^\n]", account.name);

    printf("Enter initial deposit: ");
    scanf("%f", &account.balance);

    if (account.balance < 0)
    {
        printf("Initial deposit cannot be negative!\n");
        return;
    }

    fp = fopen("bank.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&account, sizeof(account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully!\n");
}

void deposit()
{
    struct BankAccount account;
    FILE *fp;
    int accountNumber, found = 0;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    fp = fopen("bank.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found. Please create an account first.\n");
        return;
    }

    while (fread(&account, sizeof(account), 1, fp) == 1)
    {
        if (account.accountNumber == accountNumber)
        {
            found = 1;

            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Amount must be greater than zero!\n");
            }
            else
            {
                account.balance += amount;

                fseek(fp, -(long)sizeof(account), SEEK_CUR);
                fwrite(&account, sizeof(account), 1, fp);

                printf("Deposit successful!\n");
                printf("Updated balance: %.2f\n", account.balance);
            }

            break;
        }
    }

    if (!found)
    {
        printf("Account not found!\n");
    }

    fclose(fp);
}

void withdraw()
{
    struct BankAccount account;
    FILE *fp;
    int accountNumber, found = 0;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    fp = fopen("bank.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found. Please create an account first.\n");
        return;
    }

    while (fread(&account, sizeof(account), 1, fp) == 1)
    {
        if (account.accountNumber == accountNumber)
        {
            found = 1;

            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Amount must be greater than zero!\n");
            }
            else if (amount > account.balance)
            {
                printf("Insufficient balance!\n");
            }
            else
            {
                account.balance -= amount;

                fseek(fp, -(long)sizeof(account), SEEK_CUR);
                fwrite(&account, sizeof(account), 1, fp);

                printf("Withdrawal successful!\n");
                printf("Remaining balance: %.2f\n", account.balance);
            }

            break;
        }
    }

    if (!found)
    {
        printf("Account not found!\n");
    }

    fclose(fp);
}

void balanceEnquiry()
{
    struct BankAccount account;
    FILE *fp;
    int accountNumber, found = 0;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    fp = fopen("bank.dat", "rb");

    if (fp == NULL)
    {
        printf("No accounts found. Please create an account first.\n");
        return;
    }

    while (fread(&account, sizeof(account), 1, fp) == 1)
    {
        if (account.accountNumber == accountNumber)
        {
            found = 1;

            printf("\n----- Account Details -----\n");
            printf("Account Number: %d\n", account.accountNumber);
            printf("Account Holder: %s\n", account.name);
            printf("Current Balance: %.2f\n", account.balance);

            break;
        }
    }

    if (!found)
    {
        printf("Account not found!\n");
    }

    fclose(fp);
}
