/*********************************************************************
** Author: David Mednikov
** Date: 11/29/2016
** Description: This Store class implementation file defines the
** addProduct() method, the addMember() method, the getProductFromID()
** method, the getMemberFromID() method, the productSearch() method,
** the addProductToMemberCart() method, and the checkOutMember() method.
*********************************************************************/
// Store.cpp is the Store class implementation file

#include "Store.hpp" // Include store header file
#include <string> // Needed to use strings
#include <iostream> // Needed  to print text to the terminal
#include <iomanip> // Needed to format how prices are printed ($x.xx)
#include <vector> // Needed to use vectors

using std::string; // Clean up code
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::vector;

// Method that takes a pointer to a Product and adds the product to the inventory
void Store::addProduct(Product* p)
{
    inventory.push_back(p);
}

// Method that takes a pointer to a Customer and adds the Customer to the member registry
void Store::addMember(Customer* c)
{
    members.push_back(c);
}

/*****************************************************************************
This function takes a product ID, loops through the inventory to find a
product that has a matching product ID, and returns a pointer to the 
matching product. If there is no matching product, the function returns NULL.
*****************************************************************************/
Product* Store::getProductFromID(string prodId)
{
    // Loop through inventory to find product that matches product ID
    for (int i = 0; i < inventory.size(); i++)
    {
        // Create product object from current position in product vector
        Product currentProduct = *(inventory.at(i));
        
        // Store current product's ID code in a local string
        string idCode = currentProduct.getIdCode();
        
        /* Compare the current product's ID code to the product ID supplied to the method.
        If the two ID code strings match, the method will return a pointer to the current product*/
        if (idCode == prodId)
            return inventory.at(i);
    }
    
    // If no product is matched, return NULL
    return NULL;
        
}

/*****************************************************************************
This function takes a customer's account ID, loops through the membership vector
to find a member that has a matching account ID, and returns a pointer to the 
matching member. If there is no matching member, the function returns NULL.
*****************************************************************************/
Customer* Store::getMemberFromID(string memberId)
{
    // Loop through members to find customer that matches account ID
    for (int i = 0; i < members.size(); i++)
    {
        // Create customer object from current position in customer vector
        Customer currentCustomer = *(members.at(i));
        
        // Store current member's account ID in a local string
        string mId = currentCustomer.getAccountID();
        
        /* Compare the current member's account ID to the ID supplied to the method. If the
        two account ID's match, the method will return a pointer to the current member */
        if (mId == memberId)
            return members.at(i);
    }
    
    // If there is no customer that matches, return NULL
    return NULL;
}

/*****************************************************************************
This function takes a search term and the current product being searched for a
match, compares the search term to the current product's title and description,
and prints out details about items that match the search query. If the search
term is not found in the current product's title or description, nothing is printed.
*****************************************************************************/
void printSearchResults(Product currentProduct, string searchTerm)
{
    // Store product's title in a local string
    string title = currentProduct.getTitle();
    // Store product's description in a local string
    string desc = currentProduct.getDescription();
    
    // If the search query string is found in the product's title (the position of the matching string is not null)
    if (title.find(searchTerm) != string::npos)
    {
        // Print out the title, ID code, price, remaining quanity, and description
        cout << endl << currentProduct.getTitle() << endl;
        cout << "ID code: " << currentProduct.getIdCode() << endl;
        cout << "Price: $" << currentProduct.getPrice() << endl;
        // cout << "Remaining Units: " << currentProduct.getQuantityAvailable() << endl;      Commenting this line out to follow instructions
        cout << currentProduct.getDescription() << endl;
    }
    // OR,
    // If the search query string is found in the product's description (the position of the matching string is not null)
    else if (desc.find(searchTerm) != string::npos)
    {
        // Print out the title, ID code, price, remaining quanity, and description
        cout << endl << currentProduct.getTitle() << endl;
        cout << "ID code: " << currentProduct.getIdCode() << endl;
        cout << "Price: $" << currentProduct.getPrice() << endl;
        // cout << "Remaining Units: " << currentProduct.getQuantityAvailable() << endl;       Commenting this line out to follow instructions
        cout << currentProduct.getDescription() << endl;
    }
    
    // If there is no match in the title or the description, do not print anything
}

/*****************************************************************************
This function takes a search term and sends it to the printSearchResults() method 
(defined above) which prints matching products to the terminal. The search is 
case-insensitive for the 1st letter.
*****************************************************************************/
void Store::productSearch(string searchTerm)
{
    // Loop through the product inventory to search each product's title and description
    for (int i = 0; i < inventory.size(); i++)
    {
        // Create local product to send to printSearchResults() method
        Product currentProduct = *(inventory.at(i));
        
        // Make first letter of search query uppercase and send to printSearchResults() method
        searchTerm[0] = toupper(searchTerm[0]);
        printSearchResults(currentProduct, searchTerm);
        
        // Make first letter of search query lowercase and send to printSearchResults() method. This ensures that the first letter of the search is case-insensitive
        searchTerm[0] = tolower(searchTerm[0]);   
        printSearchResults(currentProduct, searchTerm);
    }
}

/*****************************************************************************
This function takes a product ID and a member ID and adds the product to the 
member's cart. It tells the user if the product or account ID could not be matched
to existing products or customers. If the product and member are both real, and
the quantity of the product is greater than 1, the function adds the product
to the customer's cart. If the quantity, is 0, the function prints out that
the product is currently out of stock.
*****************************************************************************/
void Store::addProductToMemberCart(string prodId, string memberId)
{
    // Create pointer to product that matches the product ID
    Product* addedProduct = getProductFromID(prodId);
    // Create pointer to customer that matches the account ID
    Customer* buyingCustomer = getMemberFromID(memberId);
    
    // If there is no matching product, print out "product not found"
    if (!addedProduct)
        cout << "\nProduct #" << prodId << " not found.\n";
    // If there is no matching member, print out "member not found"
    if (!buyingCustomer)
        cout << "\nMember #" << memberId << " not found.\n";  
    
    // If the product ID and account ID both match to a product and customer:
    if (addedProduct && buyingCustomer)
    {
        // If quantity is >0, add product to customer's cart
         if ((*addedProduct).getQuantityAvailable() > 0)
            (*buyingCustomer).addProductToCart(prodId);
        // If quantity is 0, print out that the item is currently out of stock
        else
            cout << "\nSorry, product #" << prodId << " is currently out of stock.\n";
    }
}

/*****************************************************************************
This function takes a member ID and checks out the items in the member's cart.
It prints out each item in the cart, along with its price, and displays the
subtotal, shipping cost, and the total. It then decreases the remaining quantity
of the products purchased from the store and clears out the customer's cart.
*****************************************************************************/
void Store::checkOutMember(string memberId)
{
    // Create pointer to Customer that matches the supplied account ID
    Customer* buyingCustomer = getMemberFromID(memberId);
    
    // Create variables to store running total and total of purchase
    double runningTotal = 0;
    double total;
    
    // If there is no customer that matched the supplied account ID, print out "member not found"
    if (buyingCustomer == NULL)
        cout << "\nMember #" << memberId << " not found.\n";
    // If there is a customer that matches
    else
    {
        // Find how many items are in the cart
        int cartSize = ((*buyingCustomer).getCart()).size();
        
        // If the cart is empty, print out "no items in the cart"
        if (cartSize == 0)
            cout << "\nThere are no items in the cart.\n" ;
        // If the cart has items in it
        else
        {
            // Format how doubles are printed to the terminal ($x.xx) and clear the output buffer
            cout << std::fixed << endl;
            
            // Loop through each item in cart
            for (int i; i < cartSize; i++)
            {
                // store current product's ID in a local string
                string currentProductId = ((*buyingCustomer).getCart()).at(i);
                // store the current product in a local Product object
                Product currentProduct = *(getProductFromID(currentProductId));
                
                /* If the remaining quantity of the current product is greater than 0,
                print out the product title and cost, decrease the remaining quantity by 1, and add the price to the running total */
                if (currentProduct.getQuantityAvailable() > 0)
                {
                    // Print out price (formatted to look like $x.xx)
                    cout << currentProduct.getTitle() << " - $" << setprecision(2) << currentProduct.getPrice() << endl;
                    // Decrease the remaining quantity by 1
                    (*(getProductFromID(currentProductId))).decreaseQuantity();
                    // Add the price of the product to the running total
                    runningTotal += currentProduct.getPrice();
                }
                // If the product has a quantity of 0, print out "no longer available"
                else
                    cout << "Sorry, product #" << currentProduct.getIdCode() << ", \"" << currentProduct.getTitle() << "\", is no longer available.\n";
            }
            // Print out the subtotal
            cout << "\nCart Subtotal: $" << setprecision(2) << runningTotal << endl;
            
            // If the customer is a premium member, shipping is free. The total is the same as the subtotal
            if ((*buyingCustomer).isPremiumMember())
            {
                cout << "\n     Shipping: $0\n";
                total = runningTotal;
            }
            /* If the customer is not a premium member, shipping costs an additional 7% of the subtotal.
            Calculate shipping and add to the subtotal to find the total. */
            else
            {
                // Calculate shipping
                double shipping = runningTotal*0.07;
                // Print shipping cost to terminal
                cout << "\n     Shipping: $" << setprecision(2) << shipping << endl;
                // Add shipping to subtotal to calculate total
                total = runningTotal + shipping;
            }
            
            // Print out total (including shipping)
            cout << "\n        Total: $" << setprecision(2) << total << endl;
            
            // Empty the customer's cart
            (*buyingCustomer).emptyCart();
        }
    }
}

// Comment out the rest

string Customer::getName()
{
    return name;
}

vector<Product*> Store::getInventory()
{
    return inventory;
}

vector<Customer*> Store::getMembers()
{
    return members;
}

int main()
{
    
    Store store;
    
    Product* redBlender = new Product("123", "red blender", "sturdy blender perfect for making smoothies and sauces", 350, 20);
    Product* hotAirBalloon = new Product("345", "hot air balloon", "fly into the sky in your own balloon - comes in red, blue or chartreuse", 700, 2);
    Product* bestBuds = new Product("420", "best buds", "they stick together", 35, 16);
    Product* championshipRing = new Product("16", "Championship Ring", "Only for the Great Ones", 12500, 16);
    
    store.addProduct(redBlender);
    store.addProduct(hotAirBalloon);
    store.addProduct(bestBuds);
    store.addProduct(championshipRing);
    
    Customer* kobe = new Customer("Kobe Bryant", "8245", true);
    Customer* trump = new Customer("Donnie Boy", "2016", false);
    Customer* rosen = new Customer("Josh Rosen", "2015", true);
    Customer* adams = new Customer("Davante Adams", "51303", true);

    store.addMember(kobe);
    store.addMember(trump);
    store.addMember(rosen);
    store.addMember(adams);
    
    cout << "----------------------------------------------------------\n\n" 
        << "                  Welcome to my Store\n\n" << "----------------------------------------------------------\n\n";
    
    bool sessionOpen = true;
    
    while(sessionOpen)
    {
    
        int menuChoice;
        bool validInput = false;
        
        cout << "\nStore Menu\n\n";
        
        cout << "Please select from one of the following options:\n\n";
        cout << "1. Search Our Products\n";
        cout << "2. Add Product to Inventory\n";
        cout << "3. Add Member\n";
        cout << "4. Add Item to Cart\n";
        cout << "5. View Cart\n";
        cout << "6. Check Out\n";
        cout << "7. Print Inventory\n";
        cout << "8. Print Members\n";
        cout << "9. Quit\n\n";
        
        while (!validInput)
        {
            if (cin >> menuChoice)
            {
                while (menuChoice < 1 || menuChoice > 9)
                {
                    cout << "That is not a valid choice. Please enter a number between 1 and 9: ";
                    cin >> menuChoice;
                }
                
                validInput = true;
            }
            else
            {
                cout << "That is not a valid choice. Please enter a number between 1 and 5: ";
                continue;
            }
        }
        
        cout << endl;
        
        switch(menuChoice)
        {
            case 1 :{cout << "Search Inventory\n\n";
                     string searchTerm;
                     cout << "What are you looking for: ";
                     cin >> searchTerm;
                     store.productSearch(searchTerm);
                     break;}       
            case 2 : {cout << "Add Product\n\n";
                     string title, prodId, desc;
                     int quantity;
                     double price;
                     cout << "What are you adding: ";
                     cin.ignore();
                     getline(cin, title);
                     cout << "What is the product ID: ";
                     cin >> prodId;
                     cout << "How much does it cost: $";
                     cin >> price;
                     cout << "Descripton: ";
                     cin.ignore();
                     getline(cin, desc);
                     cout << "How many are there: ";
                     cin >> quantity;
                     Product* p = new Product(prodId, title, desc, price, quantity);
                     store.addProduct(p);
                     cout << "\nProduct added successfully.\n";
                     break;}
            case 3 : {cout << "Add Member\n\n";
                     string name, account, premMem;
                     bool premium, validInput = false;
                     cout << "What is the customer's name: ";
                     cin.ignore();
                     getline(cin, name);
                     cout << "What is the account ID: ";
                     cin >> account;
                     cout << "Premium Member: ";
                     cin >> premMem;
                     while (!validInput)
                     {
                         if (premMem == "y" || premMem == "Y")
                         {  
                            premium = true;
                            validInput = true; 
                         }
                         else if (premMem == "n" || premMem == "N")
                         { 
                            premium = false;
                            validInput = true;
                         }
                         else
                         {
                             cout << "Enter Y or N: ";
                             cin >> premMem;
                         }
                     }
                     Customer* c = new Customer(name, account, premium);
                     store.addMember(c);
                     cout << "Member added successfully.\n";
                     break;}
            case 4 : {cout << "Add To Cart\n\n";
                     string accountId, productId;
                     cout << "Please enter the account ID of the customer: ";
                     cin >> accountId;
                     cout << "\nPlease enter the product ID: ";
                     cin >> productId;
                     store.addProductToMemberCart(productId, accountId);
                     cout << "\nProduct added successfully.\n";
                     break;}
            case 5 : {cout << "View Cart \n\n";
                     string accountId;
                     cout << "Please enter the account ID of the customer: ";
                     cin >> accountId;
                     cout << endl;
                     Customer* currentMember = store.getMemberFromID(accountId);
                     if (currentMember != NULL)
                     {
                         vector<string>tempCart = (*currentMember).getCart();
                         for (int i = 0; i < tempCart.size(); i++)
                         {
                             string prodId = tempCart.at(i);
                             Product currentProduct = *(store.getProductFromID(prodId));
                             cout << currentProduct.getTitle() << endl;
                             cout << "ID code: " << currentProduct.getIdCode() << endl;
                             cout << "Price: $" << currentProduct.getPrice() << endl;
                             cout << currentProduct.getDescription() << endl << endl;
                         }
                     }
                     else
                         cout << "Member #" << accountId << " not found." << endl << endl;
                    break;}
            case 6 : {cout << "Check Out\n\n";
                     string accountId;
                     cout << "Please enter the account ID of the customer: ";
                     cin >> accountId;
                     store.checkOutMember(accountId);
                     break;}
            case 7 : {cout << "Print Inventory\n\n";
                     for (int i = 0; i < store.getInventory().size(); i++)
                     {
                         Product currentProduct = *(store.getInventory().at(i));
                         cout << currentProduct.getTitle() << endl;
                         cout << "ID code: " << currentProduct.getIdCode() << endl;
                         cout << "Price: $" << currentProduct.getPrice() << endl;
                         cout << currentProduct.getDescription() << endl;
                         cout << "Remaining inventory: " << currentProduct.getQuantityAvailable() << endl << endl;
                     }
                     break;}
            case 8 : {cout << "Print Members\n\n";
                     string premium;
                     for (int i = 0; i < store.getMembers().size(); i++)
                     {
                         Customer currentMember = *(store.getMembers().at(i));
                         
                         if (currentMember.isPremiumMember())
                             premium = "Yes";
                         else
                             premium = "No";
                         
                         cout << currentMember.getName() << endl;
                         cout << "Account ID: " << currentMember.getAccountID() << endl;
                         cout << "Premium: " << premium << endl << endl;
                     }         
                     break;}    
            case 9 : {cout << "Thank you for shopping with us! Have a great day!\n\n";
                     sessionOpen = false;;
                     break;}           
                         
                           
        }
        
    } 
    
    return 0;
    
}