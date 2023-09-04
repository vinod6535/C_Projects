#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to clear the screen
void clearScreen()
{
    printf("\033[H\033[J");
}

// Function to set cursor position
// void gotoxy(int x, int y)
// {
//     printf("\033[%d;%dH", y, x);
//     fflush(stdout);
// }

// Structure to store user data
struct UserData
{
    char username[50];
    char password[50];
    char fname[20];
    char lname[20];
    char bankname[50];
    char typeaccount[20];
    int date, month, year;
    char adharnum[12];
    char pnumber[12];
    long int money; // Added: Balance in the account
};

// Structure to keep track of money transfer
struct MoneyTransfer
{
    char usernameto[50];
    char userpersonfrom[50];
    long int money;
};

// Function to create a bank account
void createAccount()
{
    struct UserData user;
    FILE *fp;

    clearScreen();
    printf("===== CREATE A BANK ACCOUNT =====\n\n");

    printf("FIRST NAME: ");
    scanf("%s", user.fname);

    printf("\nLAST NAME: ");
    scanf("%s", user.lname);

    printf("\nBank Name: ");
    scanf("%s", user.bankname);

    printf("\nACCOUNT TYPE: ");
    scanf("%s", user.typeaccount);

    do
    {
        printf("\nDATE OF BIRTH (DD MM YYYY): ");
        scanf("%d %d %d", &user.date, &user.month, &user.year);

        if ((user.date < 1 || user.date > 31) || (user.month < 1 || user.month > 12) || (user.year < (2023 - user.year < 18)))
        {
            printf("Invalid date of birth. Please try again.\n");
        }
    } while ((user.date < 1 || user.date > 31) || (user.month < 1 || user.month > 12) || (user.year < (2023 - user.year < 18)));

    do
    {
        printf("\nADHAR NUMBER (10 digits): ");
        scanf("%s", user.adharnum);

        if (strlen(user.adharnum) != 10)
        {
            printf("Invalid Aadhar number. Please enter exactly 10 digits.\n");
        }
    } while (strlen(user.adharnum) != 10);

    do
    {
        printf("\nPHONE NUMBER (10 digits): ");
        scanf("%s", user.pnumber);

        if (strlen(user.pnumber) != 10)
        {
            printf("Invalid phone number. Please enter exactly 10 digits.\n");
        }
    } while (strlen(user.pnumber) != 10);

    printf("\nUSERNAME: ");
    scanf("%s", user.username);

    printf("\nPASSWORD: ");
    scanf("%s", user.password);

    user.money = 0; // Initialize the account balance to zero

    fp = fopen("userdata.txt", "ab");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fwrite(&user, sizeof(user), 1, fp);

    fclose(fp);

    printf("\nAccount created successfully!\n");
    sleep(2);
}

// Function to display user account information
void displayAccount(char username[])
{
    struct UserData user;
    FILE *fp;

    clearScreen();
    printf("===== ACCOUNT INFORMATION =====\n\n");

    fp = fopen("userdata.txt", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    while (fread(&user, sizeof(user), 1, fp))
    {
        if (strcmp(username, user.username) == 0)
        {
            printf("USERNAME: %s\n", user.username);
            printf("FIRST NAME: %s\n", user.fname);
            printf("LAST NAME: %s\n", user.lname);
            printf("BANK NAME: %s\n", user.bankname);
            printf("ACCOUNT TYPE: %s\n", user.typeaccount);
            printf("DATE OF BIRTH: %02d-%02d-%04d\n", user.date, user.month, user.year);
            printf("ADHAR NUMBER: %s\n", user.adharnum);
            printf("PHONE NUMBER: %s\n", user.pnumber);
            printf("BALANCE: %ld\n", user.money);
            break;
        }
    }

    fclose(fp);
    printf("\nPress Enter to return to the main menu.");
    getchar();
    getchar();
}

// Function to perform money transfer
void transferMoney(char sender[])
{
    struct MoneyTransfer transfer;
    FILE *fm;
    struct UserData user;

    clearScreen();
    printf("===== MONEY TRANSFER =====\n\n");

    printf("Enter recipient's username: ");
    scanf("%s", transfer.usernameto);

    printf("Enter amount to transfer: ");
    scanf("%ld", &transfer.money);

    // Check if the sender has sufficient balance
    FILE *fp = fopen("userdata.txt", "rb+");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    while (fread(&user, sizeof(user), 1, fp))
    {
        if (strcmp(sender, user.username) == 0)
        {
            if (transfer.money <= user.money)
            {
                // Deduct the transferred amount from the sender's balance
                user.money -= transfer.money;
                fseek(fp, -sizeof(user), SEEK_CUR);
                fwrite(&user, sizeof(user), 1, fp);
                fclose(fp);

                strcpy(transfer.userpersonfrom, sender);

                fm = fopen("moneytransfer.txt", "ab");
                if (fm == NULL)
                {
                    perror("Error opening file");
                    exit(1);
                }

                fwrite(&transfer, sizeof(transfer), 1, fm);

                fclose(fm);

                printf("\nAmount transferred successfully!\n");
                sleep(2);
                return;
            }
            else
            {
                fclose(fp);
                printf("\nInsufficient balance to perform the transfer.\n");
                sleep(2);
                return;
            }
        }
    }

    fclose(fp);
    printf("\nUser not found. Transfer failed.\n");
    sleep(2);
}

// Function to deposit money into the account
void depositMoney(char username[])
{
    long int depositAmount;
    FILE *fp;
    struct UserData user;

    clearScreen();
    printf("===== DEPOSIT MONEY =====\n\n");

    printf("Enter the amount to deposit: ");
    scanf("%ld", &depositAmount);

    if (depositAmount <= 0)
    {
        printf("Invalid deposit amount. Please enter a positive amount.\n");
        sleep(2);
        return;
    }

    // Open the user data file
    fp = fopen("userdata.txt", "rb+");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Find the user's account and update the balance
    while (fread(&user, sizeof(user), 1, fp))
    {
        if (strcmp(username, user.username) == 0)
        {
            user.money += depositAmount;
            fseek(fp, -sizeof(user), SEEK_CUR);
            fwrite(&user, sizeof(user), 1, fp);
            fclose(fp);
            printf("Deposit successful!\n");
            sleep(2);
            return;
        }
    }

    fclose(fp);

    printf("User not found. Deposit failed.\n");
    sleep(2);
}

// Function to display money transfer history
void showMoneyTransferHistory(char username[])
{
    struct MoneyTransfer transfer;
    FILE *fm;

    clearScreen();
    printf("===== MONEY TRANSFER HISTORY =====\n\n");

    int i = 1;

    fm = fopen("moneytransfer.txt", "rb");
    if (fm == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("S.No.\tRecipient\tAmount\n");
    while (fread(&transfer, sizeof(transfer), 1, fm))
    {
        if (strcmp(username, transfer.userpersonfrom) == 0)
        {
            printf("%d\t%s\t\t%ld\n", i, transfer.usernameto, transfer.money);
            i++;
        }
    }

    fclose(fm);

    printf("\nPress Enter to return to the main menu.");
    getchar();
    getchar();
}

// Function to check account balance
void checkBalance(char username[])
{
    struct UserData user;
    FILE *fp;

    clearScreen();
    printf("===== ACCOUNT BALANCE =====\n\n");

    fp = fopen("userdata.txt", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    while (fread(&user, sizeof(user), 1, fp))
    {
        if (strcmp(username, user.username) == 0)
        {
            printf("USERNAME: %s\n", user.username);
            printf("BALANCE: %ld\n", user.money);
            break;
        }
    }

    fclose(fp);
    printf("\nPress Enter to return to the main menu.");
    getchar();
    getchar();
}

// Function to log out
void logout()
{
    clearScreen();
    printf("Logging out...\n");
    sleep(2);
}

// Function to perform actions after successful login
void afterLogin(char username[])
{
    int choice;

    while (1)
    {
        clearScreen();
        printf("===== WELCOME, %s =====\n\n", username);
        printf("1. Display Account Information\n");
        printf("2. Transfer Money\n");
        printf("3. Check Account Balance\n");
        printf("4. Deposit Money\n");
        printf("5. Money Transfer History\n"); // Added option for money transfer history
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayAccount(username);
            break;

        case 2:
            transferMoney(username);
            break;

        case 3:
            checkBalance(username);
            break;

        case 4:
            depositMoney(username);
            break;

        case 5:
            showMoneyTransferHistory(username); // Added case for money transfer history
            break;

        case 6:
            logout();
            return;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to perform user login
void login()
{
    char username[50];
    char password[50];
    int loginAttempts = 3;

    clearScreen();
    printf("===== USER LOGIN =====\n\n");

    while (loginAttempts > 0)
    {
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        FILE *fp = fopen("userdata.txt", "rb");
        if (fp == NULL)
        {
            perror("Error opening file");
            exit(1);
        }

        int found = 0;
        struct UserData user;

        while (fread(&user, sizeof(user), 1, fp))
        {
            if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(fp);

        if (found)
        {
            printf("\nLogin successful!\n");
            sleep(2);
            afterLogin(username);
            return;
        }
        else
        {
            loginAttempts--;
            printf("\nInvalid username or password. %d attempts remaining.\n", loginAttempts);
        }
    }

    printf("\nToo many login attempts. Exiting...\n");
    sleep(2);
    exit(0);
}

int main()
{
    int choice;

    while (1)
    {
        clearScreen();
        printf("===== BANK ACCOUNT SYSTEM =====\n\n");
        printf("1. Create a Bank Account\n");
        printf("2. Already a User? Sign In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            login();
            break;

        case 3:
            clearScreen();
            printf("Exiting...\n");
            sleep(2);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
