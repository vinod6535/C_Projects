Bank Management System
===================

This is a simple C program for managing bank accounts. Users can create accounts, log in, perform various banking operations like transferring money, checking balances, and viewing account information.

How to Use
----------

1.  Compile the Code: Before running the program, make sure you have a C compiler installed (e.g., GCC). Compile the code using the following command:

    `gcc -o bank_system bank_system.c`

2.  Run the Program: Execute the compiled program:

    `./bank_system`

Main Menu:

-   Create a Bank Account
-   Already a User? Sign In
-   Exit

Steps
----------

Here are some test cases to verify the functionality of the Bank Account System:

### Step 1: Creating an Account

1.  Choose option 1 from the main menu.
2.  Enter valid user information.
3.  Check if the account is created successfully.

### Step 2: Logging In

1.  Choose option 2 from the main menu.
2.  Enter a valid username and password.
3.  Check if the login is successful.

### Step 3: Transferring Money

1.  After logging in, choose option 2 to transfer money.
2.  Enter a recipient's username.
3.  Enter an amount to transfer.
4.  Check if the transfer is successful.

### Step 4: Checking Account Balance

1.  After logging in, choose option 3 to check the account balance.
2.  Verify that the account balance is displayed correctly.

### Step 5: Depositing Money

1.  After logging in, choose option 4 to deposit money.
2.  Enter a valid deposit amount.
3.  Check if the deposit is successful.

### Step 6: Money Transfer History

1.  After logging in, choose option 5 to view money transfer history.
2.  Verify that the transfer history is displayed correctly.

### Step 7: Invalid Login

1.  Enter an invalid username and password three times.
2.  Verify that the program exits after too many login attempts.

Important Notes
---------------

-   The program uses text files (`userdata.txt` and `moneytransfer.txt`) to store user data and money transfer records. Make sure these files are created in the same directory as the program.
-   This code is a simple demonstration and may require additional error handling and security measures for real-world use.
-   Be cautious when handling financial data and ensure compliance with data protection regulations in your jurisdiction.
