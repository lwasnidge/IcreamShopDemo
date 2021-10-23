/* Program Name: FinalApp.cpp
 Author: Logan Wasnidge
Date Updated: 12/17/2020
Purpose: Program that allows people to order icecream */

#include <iostream>
#include <set>
#include <string>
#include <list>
#include <queue>
#include <map>
#include "IceCream.h"

using namespace std;

int ID = 0;

void printList(list<IceCream*> lis) { //Print items from an order
    double x = 0;  


    cout << "Number of items: " << lis.size() << endl;
    for (list<IceCream*>::iterator it = lis.begin(); it != lis.end(); it++) {      //iterates through a list of icecream and displays the decriptions 
        (*it)->description();
        cout << endl;
    }

    for (list<IceCream*>::iterator i = lis.begin(); i != lis.end(); i++) {  //goes through the price of each item
        x += (*i)->getPrice();  //adds up prices
    }

    cout << "Your total is $";

    x *= 1.07;      //adds tax

    if (x < 10) {       //Used 2 or 3 decimal points depending on size of the dollar value
        cout << setprecision(3) << x << endl;
    }
    else {
        cout << setprecision(4) << x << endl;
    }
}
void findOrder(map<queue<list<IceCream*>>,int> que){ //Will find an order with the matching ID number
    int x;

    if (que.empty()) {      //If the queue is empty, then there are no orders
        cout << "No orders!" << endl;
        return;
    }
    cout << "Please enter your order ID number" << endl;
    cin >> x;

    for (map<queue<list<IceCream*>>, int>::iterator it = que.begin(); it != que.end(); ++it) {  //Goes through each order in the queue

        if (it->second == x) {      //When the correct order is found, displays the info
            cout << "Order with ID number " << x << ":" << endl;
            printList(it->first.front());
            cout << endl;
        }
        if(it->second!=x ) {  //checks to see if the number given is a correct ID
            cout << "No order with that ID number" << endl;
        }
    }
}
void makeOrder(queue<list<IceCream*>>& que, map<queue<list<IceCream*>>, int>& qID) {
    
    list<IceCream*> cream;  //Creates the list for the entire order
    int ord;  //Which Item is being ordered
    int flavor;  // Flavor
    //int spec;  for specialty, unused
    string size;  //Size
    string exit;  // exit conditions

    do {

        cout << "What would you like to order?" << endl;
        
        cout << "1. Soft Serve Ice Cream" << endl;
        cout << "2. Home Made Ice Cream" << endl;
        cout << "3. Sundae " << endl;
        cout << "4. Milk Shake" << endl;

        cin >> ord;

        try { // exception handling
            if (ord > 4 || ord < 1 || !cin) {
                string a = "You must choose a number from 1 to 4";
                throw invalid_argument(a);
            }
        }
        catch (invalid_argument & a) {
            while (ord > 4 || ord < 1 || !cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << a.what() << endl;
                cin >> ord;
            }
        }

        switch (ord) {		//Switch statement based on type of item ordered
        case 1: 
            cout << "What kind of soft serve ice cream would you like?" << endl;
               
            for (map<SoftServe::softFlavors, string>::iterator it = SoftServe::softFlavorMap.begin(); it != SoftServe::softFlavorMap.end(); it++) {  //iterates through list of soft serve flavors
                cout << "\t" << it->first << ": " << it->second << endl;  
            }

            cin >> flavor;
            try { // exception handling
                if (flavor > SoftServe::softFlavorMap.size() || flavor < 1 || !cin) {
                    string a = "Quantity must be > 0 and less than " + to_string(SoftServe::softFlavorMap.size() + 1);
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (flavor > SoftServe::softFlavorMap.size() || flavor < 1 || !cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> flavor;
                }
            }

            cout << "What size would you like?" << endl;

           
            for (map<string, double>::iterator it = SoftServe::softServeSizePrice.begin(); it != SoftServe::softServeSizePrice.end(); it++) { //iterates through sizes and their prices
                cout << "\t" << it->first << " for " << it->second << endl;
            }  

            cin >> size;

            try { // exception handling
                if (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    string a = "Size must be either small, medium, or large";
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> size;
                }
            }

           cream.push_back(new SoftServe(SoftServe::softFlavors(flavor), size)); //adds item to order
        

            break;
        case 2: 
            cout << "What kind of homemade ice cream would you like?" << endl;

            for (map<HomeMade::hardFlavors, string>::iterator it = HomeMade::hardFlavorMap.begin(); it != HomeMade::hardFlavorMap.end(); it++) {  //iterates through list of homemade flavors
                cout << "\t" << it->first << ": " << it->second << endl;
            }

            cin >> flavor;
            try { // exception handling
                if (flavor > HomeMade::hardFlavorMap.size() || flavor < 1 || !cin) {
                    string a = "Quantity must be > 0 and less than " + to_string(HomeMade::hardFlavorMap.size() + 1);
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (flavor > HomeMade::hardFlavorMap.size() || flavor < 1 || !cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> flavor;
                }
            }

            cout << "What size would you like?" << endl;

            for (map<string, double>::iterator it = HomeMade::hardSizePrice.begin(); it != HomeMade::hardSizePrice.end(); it++) {       //iterates through sizes and prices
                cout << "\t" << it->first << " for " << it->second << endl;
            }

            cin >> size;


            try { // exception handling
                if (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    string a = "Size must be either small, medium, or large";
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> size;
                }
            }

            cream.push_back(new HomeMade(HomeMade::hardFlavors(flavor), size));  //adds homemade flavor and size to the list
            
            break;
        case 3: 
            cout << "What kind of sundae would you like?" << endl;
           /* cout << "1.) Normal" << endl;     //Attempt at adding specialty to the order.  Didn't work out, decided to leave it in, jsut quoted out
            cout << "2.) Specialty" << endl;

            int spec;
            
            cin >> spec;

            try { // exception handling
                if (spec != 1 && spec !=2) {
                    string a = "Must be 1 or 2";
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (spec !=1 && spec !=2) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> size;
                }
            }

            if (spec == 1) {*/
                for (map<Sundae::sundaeFlavors, string>::iterator it = Sundae::sundaeFlavorMap.begin(); it != Sundae::sundaeFlavorMap.end(); it++) {  //Displays sundae flavors
                    cout << "\t" << it->first << ": " << it->second << endl;
                }

                cin >> flavor;
                try { // exception handling
                    if (flavor > Sundae::sundaeFlavorMap.size() || flavor < 1 || !cin) {
                        string a = "Quantity must be > 0 and less than " + to_string(Sundae::sundaeFlavorMap.size() + 1);
                        throw invalid_argument(a);
                    }
                }
                catch (invalid_argument & a) {
                    while (flavor > Sundae::sundaeFlavorMap.size() || flavor < 1 || !cin) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << a.what() << endl;
                        cin >> flavor;
                    }
                }
           /* }
            else {
                for (map<set<Sundae::sundaeFlavors>, string >::iterator it = Sundae::specialtymap.begin(); it != Sundae::specialtymap.end(); it++) {
                    cout << "\t" << it->second << endl;
                    for(set<Sundae::sundaeFlavors>::iterator i = it->first.begin(); i != it->first.end(); it++)
                        cout << "\t\t" << *i << endl;
                    
                }

                cin >> flavor;
                try { // exception handling
                    if (flavor > Sundae::specialtymap.size() || flavor < 1 || !cin) {
                        string a = "Quantity must be > 0 and less than " + to_string(Sundae::sundaeFlavorMap.size() + 1);
                        throw invalid_argument(a);
                    }
                }
                catch (invalid_argument & a) {
                    while (flavor > Sundae::specialtymap.size() || flavor < 1 || !cin) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << a.what() << endl;
                        cin >> flavor;
                    }
                }
            }
            */
            cout << "What size would you like?" << endl;

            for (map<string, double>::iterator it = Sundae::sundaeSizePrice.begin(); it != Sundae::sundaeSizePrice.end(); it++) {  //Sizes and prices
                cout << "\t" << it->first << " for " << it->second << endl;
            }

            cin >> size;


            try { // exception handling
                if (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    string a = "Size must be either small, medium, or large";
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> size;
                }
            }

            cream.push_back(new Sundae(Sundae::sundaeFlavors(flavor), size));  //adds to order

            break;
        case 4:
            cout << "What kind of milk shake would you like?" << endl;

            for (map<MilkShake::shakeFlavors, string>::iterator it = MilkShake::shakeFlavorMap.begin(); it != MilkShake::shakeFlavorMap.end(); it++) {  //Milkshake flavors
                cout << "\t" << it->first << ": " << it->second << endl;
            }


            cin >> flavor;

            try { // exception handling
                if (flavor > MilkShake::shakeFlavorMap.size() || flavor < 1 || !cin) {
                    string a = "Quantity must be > 0 and less than " + to_string(MilkShake::shakeFlavorMap.size() + 1);
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (flavor > MilkShake::shakeFlavorMap.size() || flavor < 1 || !cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> flavor;
                }
            }

            cout << "What size would you like?" << endl;

            for (map<string, double>::iterator it = MilkShake::shakeSizePrice.begin(); it != MilkShake::shakeSizePrice.end(); it++) {  //Size and price
                cout << "\t" << it->first << " for " << it->second << endl;
            }

            cin >> size;


            try { // exception handling
                if (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    string a = "Size must be either small, medium, or large";
                    throw invalid_argument(a);
                }
            }
            catch (invalid_argument & a) {
                while (size != "Small" && size != "small" && size != "Medium" && size != "medium" && size != "Large" && size != "large") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << a.what() << endl;
                    cin >> size;
                }
            }
            cream.push_back(new MilkShake(MilkShake::shakeFlavors(flavor), size));  //adds to order

            break;
        default:		//In case user does not choose number, it defaults to invalid choice
            cout << "Invalid choice." << endl;
        }


        cout << "Do you wish to continue with your order?(Y for yes, otherwise exit) ";
        cin >> exit;



    } while (exit == "Y" || exit == "y");

    cout << "Your order ID is " << ID << endl;  //Displays users order ID
    cout << "Your total is $";

    double x = 0;

    for (list<IceCream*>::iterator it = cream.begin(); it != cream.end(); it++) {       //Iterates through order
        x +=  (*it)->getPrice();  //counting total of final price
    }
    x *= 1.07;      //Tax added
    if (x < 10){  //Decided how many decimal places are needed
        cout << setprecision(3) << x << endl;
    }
    else {
        cout << setprecision(4) << x << endl;
    }
    que.push(cream);
    qID.insert(pair<queue<list<IceCream*>>, int>(que, ID));
    ID++;
}


int main()
{

   

    int select;
    string exit;
    ID = 1;
    queue<list<IceCream*>> orderQueue; //Queue of orders
    map<queue<list<IceCream*>>, int> orderQueueID; //queue of orders with ID assigned to each


    cout << "Welcome to my ice cream shop! \n" << endl;
  

    

    do {

        cout << "What would you like to do? " << endl;
        cout << "1. Make an order." << endl;
        cout << "2. View an existing order." << endl;
        cin >> select;

        switch (select) {
        case 1:makeOrder(orderQueue, orderQueueID);  //Allows user to start an order
            break;
        case 2:findOrder(orderQueueID);     //allows user to view orders based on ID
            break;
        default: 
            cout << "Invalid Choice" << endl;
        }

        cout << "Do you wish to continue in the applicaton?(Y for yes, otherwise exit) ";
        cin >> exit;

    } while (exit == "Y" || exit == "y");
    
  


   
    return 0;
}

