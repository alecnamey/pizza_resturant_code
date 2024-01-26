/******************************************************************************

Alec Namey

Chapter 20 Programming Assignment

November 10, 2022

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Line.h"
#include <cstdlib>
#include <string>
using namespace std;

// function prototypes
void exitProgram();
void displayMenu();
void add(Line&, int);
void order(Line&);

// global constants
const int MENUOPTIONS = 5; // five menu options




int main()
{
    Line queue;
    int num = 10; // variable for raffle number
    int choice = 0;

    int value = 0;
    while (choice != MENUOPTIONS)
    {

        if (num == 500) // caps out at 500 and resets back to 10
        {
            num = 10;
        }
        displayMenu();
        cout << "Please choose a menu option: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            add(queue, num);
            num += 10;
            break;
        case 2:
            order(queue);
            break;
        case 3:
            queue.countLength(value);
            break;
        case 4:
            queue.displayQueue();
            break;
        case 5:
            exitProgram();
            break;

        default:
            cout << "\nError that number is not on the menu" << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
//***********************************************************************
// name:  add
// called by:  main
// passed: Line &queue, int num 
// returns: nothing
// calls: addQueue
// The add function takes a user input and assigns a raffle number. 
// 
//************************************************************************
void add(Line& queue, int num)
{
    int number = num;

    string name = "";
    cout << "Enter you Name: ";
    getline(cin, name);
    if (name.length() > 0 && name.length() < 20)
    {
        cout << "Welcome to Alec's Pizza! Your raffle number is " << number << endl;
        queue.addQueue(name, number);

    }
    else
    {
        cout << "\nInvalid Entry: Name must be greater than 0, and less than 20 characters long.\n\n";
        add(queue, num);
    }

}

//***********************************************************************
// name:  order
// called by:  main
// passed: Line &queue
// returns: nothing
// calls: removeItem
// The order function calls removeItem to remove the person from the front 
// of the line.
//************************************************************************

void order(Line& queue)
{
    string name;
    queue.removeItem(name);
}


//***********************************************************************
// name:    displayMenu
// called by:  main
// passed: nothing
// returns: nothing
// calls: nobody
// The displayMenu function when called from main will show
// to the user each and every option of the menu.
//************************************************************************


void displayMenu()
{
    cout << "\n1. Add a Name\n" << endl;
    cout << "2. Place an Order\n" << endl;
    cout << "3. Count Names in Line\n" << endl;
    cout << "4. Display the Line\n" << endl;
    cout << "5. Exit\n" << endl;

    cout << endl;

}

//******************************************************************************************
// name:  exitProgram
// called by:  main
// passed: nothing
// returns: nothing
// calls: nobody
// The exitProgram option in the menu exits the while loop in main, stopping the program.
//*******************************************************************************************

void exitProgram()
{
    cout << "\nThanks for visiting Alec's Pizza!" << endl;
}




