/***************************************************************************
** Author: David Mednikov
** Date: 10/24/2016
** Description: This BankAccount implementation file defines the getCustomerName,
** getCustomerID, getCustomerBalance, withdraw, and deposit methods.
***************************************************************************/

// BankAccount.cpp is the BankAccount class implementation file
#include "BankAccount.hpp"

using std::string;

// Constructor with 3 prototypes
BankAccount::BankAccount(string name, string ID, double balance) 
    {
        customerName = name;
        customerID = ID;
        customerBalance = balance;
    }
    
string BankAccount::getCustomerName() // Get Customer's name
{
    return customerName;
}

string BankAccount::getCustomerID() // Get Customer's ID
{
    return customerID;
}

double BankAccount::getCustomerBalance() // Get Customer's Current Balance
{
    return customerBalance;
}

void BankAccount::withdraw(double amount) // Subtract withdrawal amount from balance
{
    customerBalance -= amount;
}

void BankAccount::deposit(double amount) // Add deposit amount to balance
{
    customerBalance += amount;
}

