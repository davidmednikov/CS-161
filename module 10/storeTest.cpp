#include <iostream>
#include "Store.hpp"

using std::cout;
using std::endl;

int main()
{
   cout << "\n\ntesting Product class:\n";
   Product myProduct("aaa", "pet rock", "low maintenance pet, fully house-trained", 50, 2);
   cout << "ID code: " << myProduct.getIdCode() << endl;
   cout << "Title: " << myProduct.getTitle() << endl;
   cout << "Description: " << myProduct.getDescription() << endl;
   cout << "Price: $" << myProduct.getPrice() << endl;
   cout << "Quantity available: " << myProduct.getQuantityAvailable() << endl;
   myProduct.decreaseQuantity();
   cout << "Newly decreased quantity available: " << myProduct.getQuantityAvailable() << endl;

   cout << "\n\ntesting Customer class:\n";
   Customer myCustomer("Jenny", "8675309", true);
   cout << "Account ID: " << myCustomer.getAccountID() << endl;
   if (myCustomer.isPremiumMember())
      cout << "premium member = true\n";
   else
      cout << "premium member = false\n";
   myCustomer.addProductToCart("12345");
   std::vector<std::string> vec = myCustomer.getCart();
   cout << vec.at(0) << endl;
   myCustomer.emptyCart();
   vec = myCustomer.getCart();
   if (vec.empty())
      cout << "cart successfully emptied\n";
   else
      cout << "cart not successfully emptied\n";

   cout << "\n\ntesting Store class (with Customer and Product):\n";
   Product p1("123", "Red blender", "sturdy blender perfect for making smoothies and sauces", 350.0, 4);
   Product p2("234", "Fuzzy beanbag chair", "comfy chair for lounging about", 12.0, 1);
   Product p3("345", "Hot air balloon", "fly into the sky in your own balloon - comes in red, blue or chartreuse", 700.0, 2);
   Store myStore;
   myStore.addProduct(&p1);
   myStore.addProduct(&p2);
   myStore.addProduct(&p3);
   cout << "\nSearching store for \"red\":\n";
   myStore.productSearch("red");
   Customer c1("bob", "xyz", false);
   Customer c2("jill", "wxy", true);
   myStore.addMember(&c1);
   myStore.addMember(&c2);
   myStore.addProductToMemberCart("345", "xyz");
   myStore.addProductToMemberCart("345", "xyz");
   myStore.addProductToMemberCart("123", "xyz");
   myStore.addProductToMemberCart("345", "wxy");
   myStore.addProductToMemberCart("234", "wxy");

   cout << "\nChecking out jill:\n";
   myStore.checkOutMember(c2.getAccountID());

   cout << "\nTrying to purchase item that is now out of stock:\n";
   myStore.addProductToMemberCart("234", "xyz");

   cout << "\nChecking out bob:\n";
   myStore.checkOutMember(c1.getAccountID());
    
   return 0;
}

