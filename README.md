# CPP-Module-00
C++ Module 00 – 42 Abu Dhabi

![C++](https://img.shields.io/badge/C%2B%2B-98-blue)
![42](https://img.shields.io/badge/School-42-black)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Standard](https://img.shields.io/badge/Standard-C++98-orange)

---

## 📌 Overview

This repository contains my solutions for **C++ Module 00** from the 42 curriculum.

This module introduces the foundations of:

1. Object-Oriented Programming (OOP)
2. Classes & Member Functions
3. Static Members
4. const correctness
5. Initialization
6. Encapsulation
7. C++98 constraints

## Exercise 01 – My Awesome PhoneBook

Objective
Implement a simple phonebook using OOP principles.

Concepts Used:
  1. Class Design
  2. Encapsulation
  3. Circular Buffer
  4. Input Validation
  5. const correctness
  6. Formatted Output (std::setw)

Class Architecture

* Contact
* Stores:
* First Name
* Last Name
* Nickname
* Phone Number
* Darkest Secret

PhoneBook
* Holds up to 8 contacts
* Replaces oldest when full
* Displays formatted table
* Maintains circular ordering

Circular Buffer Design
When the phonebook is full (8 contacts), new entries overwrite the oldest one.

Core Logic
<pre>
contacts[nextIndex] = newContact;
nextIndex = (nextIndex + 1) % 8;
</pre>

Visual Diagram
<pre>
Index:   0   1   2   3   4   5   6   7
         ↓
After 8 inserts:

[ A ][ B ][ C ][ D ][ E ][ F ][ G ][ H ]

Add new contact → overwrites A

[ X ][ B ][ C ][ D ][ E ][ F ][ G ][ H ]
         ↑
     nextIndex moves circularly

</pre>

This ensures:
Constant memory usage
O(1) insertion
Correct ordering

## Exercise 02 – The Job Of Your Dreams
Objective
Rebuild Account.cpp using a provided header and output log.

Core Concept: Static vs Non-Static Members

Non-Static (Per Account)
Each account has:
<pre>
int _amount;
int _nbDeposits;
int _nbWithdrawals;
</pre>


These belong to each object individually.

Static (Shared Across All Accounts)
<pre>
static int _nbAccounts;
static int _totalAmount;
static int _totalNbDeposits;
static int _totalNbWithdrawals;
</pre>


These exist once in memory and are shared globally.

Memory Model Diagram
<pre>
Memory Layout

Account #0        Account #1        Account #2
------------      ------------      ------------
_amount            _amount           _amount
_nbDeposits        _nbDeposits       _nbDeposits
_nbWithdrawals     _nbWithdrawals    _nbWithdrawals


Shared Static Memory (Single Instance)
--------------------------------------
_nbAccounts
_totalAmount
_totalNbDeposits
_totalNbWithdrawals
</pre>

Deposit Logic
<pre>
_amount += deposit;
_totalAmount += deposit;
_nbDeposits++;
_totalNbDeposits++;
</pre>


Update individual account
Update global bank stats

Withdrawal Logic
<pre>
if (withdrawal > _amount)
    return false;

_amount -= withdrawal;
_totalAmount -= withdrawal;
_nbWithdrawals++;
_totalNbWithdrawals++;
</pre>

Timestamp Logging
Each action prints a formatted timestamp:
<pre>
[YYYYMMDD_HHMMSS]
</pre>

Generated using:
<pre>
std::time
std::localtime
std::strftime
</pre>


