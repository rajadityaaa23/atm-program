# ATM Banking System in C

A console-based ATM simulator written in C featuring PIN authentication, account balance tracking, and transaction limits.

## Features
- **PIN Authentication:** Verifies user PIN (`4821`) with a maximum of 3 attempts before blocking the card.
- **Check Balance:** Displays the current account balance (starts at `Rs. 12500.00`).
- **Withdraw & Deposit:** Supports cash withdrawals and deposits with validation.
- **Session Transaction Limit:** Allows up to 5 transactions per login session.

## How to Run
Compile and run the program using GCC:

```bash
gcc main.c -o atm
./atm
