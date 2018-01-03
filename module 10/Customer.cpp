/*********************************************************************
** Author: David Mednikov
** Date: 11/29/2016
** Description: This Customer class implementation file defines the 
** constructor, which takes 3 parameters (2 strings and a bool) and 
** creates a new customer object. It defines 2 get methods, which 
** return the customer's account ID and cart. It defines a
** method that adds a product to the customer's cart. It also defines a
** method that returns a bool that tells the system if the customer
** is a premium member. Last, it defines a method that empties the
** customer's cart.
*********************************************************************/
// Customer.cpp is the Customer class implementation file

#include "Customer.hpp" // Include Customer header file
#include <string> // Needed for strings

using std::string; // Clean up code
using std::vector;

// 3 Parameter constructor that sets the customer's name, account ID, and premium member bool
Customer::Customer(string n, string a, bool pm)
{
    name = n;
    accountID = a;
    premiumMember = pm;
}

// Method that returns the customer's account ID
string Customer::getAccountID()
{
    return accountID;
}

// Method that returns the customer's cart
vector<string> Customer::getCart()
{
    return cart;
}

// Method that takes a product ID and adds it to the customer's cart
void Customer::addProductToCart(string productID)
{
    cart.push_back(productID);
}

// Method that returns whether or not the customer is a premium member
bool Customer::isPremiumMember()
{
    return premiumMember;
}

// Method that empties the customer's cart
void Customer::emptyCart()
{
    cart.clear();
}