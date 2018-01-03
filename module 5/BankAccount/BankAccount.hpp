/***************************************************************************
** Author: David Mednikov
** Date: 10/24/2016
** Description: This BankAccount class specification contains two strings 
** (customerName and customerID) and a double (customerBalance). The class
** has a constructor that takes 2 strings and 1 double as parameters. The
** constructor sets the values of the BankAccount object without using set
** methods. The class also has a get method for each member variable, as 
** well as withdraw and deposit methods that recalculate customerBalance.
***************************************************************************/
// BankAccount.hpp is the BankAccount class specification file
#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

class BankAccount // Declare BankAccount class
{
    private:
    std::string customerName; // Private member variables
    std::string customerID;
    double customerBalance;
    
    public:
        
    // Constructor prototype
    BankAccount(std::string name, std::string ID, double balance);
        
    std::string getCustomerName(); // Get method prototypes
    std::string getCustomerID();
    double getCustomerBalance();
    
    void withdraw(double amount); // Withdraw and deposit method prototypes
    void deposit(double amount);
    
};
#endif