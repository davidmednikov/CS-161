#include "Box.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double h, w, len;
    int choice;
    
    cout << "Please select a box.\n1) Custom Box\n2) Default Box" << endl; 
    
    cin >> choice;
    
    while (choice != 1 && choice != 2)
    {
        cout << "That is an invalid choice. Please select a box.\n";
        cin >> choice;
    }
    
    if (choice == 1)
    {
        cout << "What is the height of the box?\n";
        cin >> h;
        
        cout << "What is the width of the box?\n";
        cin >> w;
        
        cout << "What is the length of the box?\n";
        cin >> len;
        
        Box customBox(h, w, len);
        
        cout << "The volume is: " << customBox.getVolume() << endl;
        cout << "The surface area is: " << customBox.getSurfaceArea() << endl;
    }
    else
    {
        Box defaultBox;
        
        cout << "The volume is: "<< defaultBox.getVolume() << endl;
        cout << "The surface area is: " << defaultBox.getSurfaceArea() << endl;
    }
    
    return 0;
}