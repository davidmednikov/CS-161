/*********************************************************************
** Author: David Mednikov
** Date: 11/29/2016
** Description: This Product class implementation file defines the 
** constructor, which takes 5 parameters (3 strings, a double, and
** an int) and creates a new product object. It also defines 5 get 
** methods, which return the product ID code, title, description, 
** price, and remaining quantity. It also defines a method which 
** decreases the quantity of the product by one.
*********************************************************************/
// Product.cpp is the Product class implementation file

#include "Product.hpp" // Include Product header file
#include <string> // Necessary for using strings

using std::string; // Reduce clutter in code

// 5 Parameter constructor that sets the product ID, title, descriptio, price, and quantity
Product::Product(string id, string t, string d, double p, int qa)
{
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
}

// Method to get product's ID Code
string Product::getIdCode()
{
    return idCode;
}

// Method to get product's title
string Product::getTitle()
{
    return title;
}

// Method to get product's description
string Product::getDescription() 
{
    return description;
}

// Method to get product's price
double Product::getPrice()
{
    return price;
}

// Method to get quantity of product
int Product::getQuantityAvailable()
{
    return quantityAvailable;
}

// Method to decrease quantity by 1
void Product::decreaseQuantity()
{
    quantityAvailable--;
}