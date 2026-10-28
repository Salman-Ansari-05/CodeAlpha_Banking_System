# 🏦 Bank Account Management System in C

A simple **Bank Account Management System** developed using the C programming language. This mini-project demonstrates the use of functions, structures, and file handling to perform basic banking operations.

## 📌 Project Overview

The Banking System allows users to create bank accounts, deposit money, withdraw money, and check their account balance. Account information is stored in a binary file so that the data remains available after the program closes.

## ✨ Features

- 🆕 **Create Account** — Create a bank account with an account number, account holder name, and initial deposit.
- 💰 **Deposit Money** — Deposit money into an existing account.
- 💸 **Withdraw Money** — Withdraw money if sufficient balance is available.
- 📊 **Balance Enquiry** — View account details and the current balance.
- 💾 **File Handling** — Store and retrieve account information using a binary file.
- 🔄 **Menu-Driven Interface** — Perform multiple operations until choosing to exit.
- ⚠️ **Basic Validation** — Handle invalid menu choices, missing accounts, negative deposits, and insufficient balances.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Concepts:** Functions, Structures, Pointers, File Handling, Conditional Statements, Loops, and Switch Statements
- **Compiler:** GCC
- **Storage:** Binary file (`bank.dat`)

## 📂 Project Structure

```text
Banking-System/
│
├── banking.c       # Main source code
├── bank.dat        # Account data file (created automatically)
└── README.md       # Project documentation
```

**Note:** The `bank.dat` file is generated automatically when the first account is created.

## ⚙️ Installation and Setup

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the Project Directory

```bash
cd Banking-System
```

### 3. Compile the Program

Make sure GCC is installed on your system.

```bash
gcc banking.c -o banking
```

### 4. Run the Program

**Windows:**

```bash
banking.exe
```

**Linux/macOS:**

```bash
./banking
```

## 🖥️ Sample Output

```text
=================================
     BANK ACCOUNT MANAGEMENT
=================================

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Balance Enquiry
5. Exit

Enter your choice: 1

Enter account number: 101
Enter account holder name: Aditya Jadhav
Enter initial deposit: 5000

Account created successfully!
```

### Deposit Example

```text
Enter your choice: 2

Enter account number: 101
Enter amount to deposit: 2000

Deposit successful!
Updated balance: 7000.00
```

### Withdrawal Example

```text
Enter your choice: 3

Enter account number: 101
Enter amount to withdraw: 1000

Withdrawal successful!
Remaining balance: 6000.00
```

## 📚 Concepts Learned

This project demonstrates practical applications of the following C programming concepts:

- **Functions:** Organizing code into reusable blocks.
- **Structures:** Grouping account details into a single data type.
- **File Handling:** Reading and
