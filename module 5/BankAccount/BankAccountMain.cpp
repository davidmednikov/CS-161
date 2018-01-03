#include "BankAccount.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    
    string name;
    string ID;
    double balance;
    double dep;
    double withd;
    int choice;
    bool stillRunning = true;
    
    cout << "Welcome to the Big Bank of Dave.\nWe see that this is your first time here,\n";
    cout << "so we'd like to invite you to open an account with us." << endl;
    
    cout << "Please enter the customer's name: ";
    getline(cin, name);
    
    cout << "Please enter the customer's ID: ";
    cin >> ID;
    
    cout << "Please enter the current balance: ";
    cin >> balance;
    
    BankAccount newAccount(name, ID, balance);
    
    while(stillRunning)
    {
        
        cout << "\nDave Bank Member's Menu\n\n";
        
        cout << "1) Retrieve Customer's Name\n";
        cout << "2) Retrieve Customer's ID\n";
        cout << "3) Retrieve Current Balance\n";
        cout << "4) Make a Withdrawal\n";
        cout << "5) Make a Deposit\n";
        
        cout << "\nWhat would you like to do? Enter -1 to quit.\n";
        cin >> choice;
            
        if (choice == -1)
        {
            stillRunning = false;
        }
            
        while (choice < -1 || choice == 0 || choice > 5)
        {
            cout << "That is not a valid option. Please select one of the 5 options\n";
            cin >> choice;
        }
        
        switch(choice)
        {
            case 1: cout << "\n" << newAccount.getCustomerName() << endl;
                    break;
            case 2: cout << "\n"  << newAccount.getCustomerID() << endl;
                    break;
            case 3: cout << "\n"  << newAccount.getCustomerBalance() << endl;
                    break;
            case 4: cout << "How much would you like to withdraw?\n";
                    cin >> withd;
                    newAccount.withdraw(withd);
                    break;     
            case 5: cout << "How much would you like to deposit?\n";
                    cin >> dep;
                    newAccount.deposit(dep);
                    break;
        }
    }
    
    return 0;
    
}
        