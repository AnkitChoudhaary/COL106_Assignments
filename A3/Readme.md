# Bank Data Management System

This project implements a hashmap-based system for managing bank account information. It utilizes various collision resolution strategies to efficiently store and retrieve account data.

## Introduction

The project simulates a real-world scenario where a bank maintains a database of millions of customer accounts. To ensure efficient data access and retrieval, the system employs a hashmap, which maps account identifiers (IFSC code and account number) to their respective account information.

## Hashmap Implementation

The hashmap is implemented using a custom `BankData` class. The class provides methods for creating, accessing, and modifying bank accounts. It also implements various collision resolution strategies to handle situations where multiple accounts map to the same hash index.

## Collision Resolution Strategies

The project implements four collision resolution strategies:

1. **Chaining:** This strategy creates linked lists at each hash table index to store accounts that share the same hash code.

2. **Linear Probing:** This strategy probes subsequent hash table slots in a linear fashion until an empty slot is found.

3. **Quadratic Probing:** This strategy probes subsequent hash table slots using a quadratic function to distribute collisions more evenly.

4. **Cubic Probing:** This strategy probes subsequent hash table slots using a cubic function to further distribute collisions.

 #### Defining an ID for a bank account = <#11 digit IFSC Code>_<10 digit account No. > 


**This is implemented for a *hash table size of 10000* i.e. No. of unique account = 10000.**
# Function Descriptions

| Function                              | Description                                                                                                           |
| ------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| `createAccount(string id, int count)` | Creates a new account with the given `id` and initial `count` value. The `id` uniquely identifies the account.        |
| `getTopK(int k)`                      | Retrieves the top `k` balances values from the database. Returns a vector containing at most `k` balances values.    |
| `getBalance(string id)`               | Returns the current balance of the account identified by the provided `id`. In case the `id` is not present, return -1. |
| `addTransaction(string id, int count)`| Adds a transaction of `count` value to the account specified by the `id`. If the account is not present, create a new one and then add this transaction. Transactions can be positive or negative. |
| `doesExist(string id)`                 | Checks if an account with the given `id` exists in the database. Returns true if the account exists, and false otherwise. |
| `databaseSize()`                       | Returns the total number of accounts currently stored in the database.                                                 |
| `hash(string id)`                      | Computes the hash value for the given `id`. Use this hash function only in your strategies.                           |
| `delete(string id)`                    | Deletes the key stored in the database. Returns true after deletion. If the key was not present, returns false.         |

## Getting Started

To run the project, follow these steps:

1. Clone the project repository.

2. Compile the project using a C++ compiler.

3. Execute the compiled program.

## Code Structure

The project consists of the following files:

- `BankData.h`: Defines the `BankData` class and its methods.

- `BankData.cpp`: Implements the methods of the `BankData` class.

- `main.cpp`: Main entry point for the program.

