#include <iostream>
#include "Line.h"
#include <cstring>
#include <cctype>
using namespace std;

// constructor
Line::Line()
{
    front = nullptr;
    rear = nullptr;
}

// destructor
Line::~Line()
{
    myQueue* pointer = nullptr, * nextNode = nullptr;
    pointer = front;
    while (pointer != nullptr)
    {
        nextNode = pointer->next;
        delete pointer;
        pointer = nextNode;
    }
}

//***********************************************************************
// name:  addQueue
// called by: add
// passed: string name, int number
// returns: exit(EXIT_FAILURE)
// calls: isEmpty()
// The addQueue function takes a user input to check if it's > 0 & < 20.
//  If so, it assigns the name and raffle number in the line. The next
// time addQueue is called, the name will join the queue.
//************************************************************************

void Line::addQueue(string name, int number)
{
    if (name.length() > 0 && name.length() < 20)
    {
        myQueue* newNode = nullptr;
        newNode = new myQueue;
        newNode->value = name;
        newNode->raffle = number;
        newNode->next = nullptr;


        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;

        }

    }
    else
    {
        cout << "Invalid Entry";
        exit(EXIT_FAILURE);
    }
}

//***********************************************************************
// name: removeItem
// called by: order
// passed: string name
// returns: nothing
// calls: isEmpty()
// The removeItem function removes the name and raffle number in front of 
// the line.
//************************************************************************

void Line::removeItem(string name)
{
    myQueue* ptr = nullptr;
    if (isEmpty())
    {
        cout << "\nThe queue is currently empty.\n" << endl;

    }
    else
    {
        if (front == rear)
        {
            cout << endl << front->value << " you may now order!" << endl;
            delete front;
            front = NULL;
            rear = NULL;
        }
        else
        {
            name = front->value;
            ptr = front;
            cout << endl << front->value << " you may now order!" << endl;
            front = front->next;
            delete ptr;
        }


    }

}

//***********************************************************************
// name:  displayQueue
// called by:  main
// passed: nothing
// returns: nothing
// calls: isEmpty()
// The displayQueue function checks if the queue is empty, if not,
// it will display the position in line each person is in, their name, and raffle number.
// 
//************************************************************************

void Line::displayQueue()
{
    myQueue* pointer;
    pointer = front;
    int position = 0;
    cout << "Position:\t" << "Name:\t\t" << "Raffle Number:" << endl;
    cout << "---------------------------------------------" << endl;
    while (pointer)
    {
        cout << "(" << position << ")\t\t" << pointer->value << "\t\t" << pointer->raffle << endl;
        pointer = pointer->next;

        position++;
    }
    if (isEmpty())
    {
        cout << "\nThe queue is currently empty.\n" << endl;

    }


}

//***********************************************************************
// name: countLength
// called by: main
// passed: int num 
// returns: nothing
// calls: countValues
// The countLength sets a front of the queue and calls the function countValues
// 
//************************************************************************

void Line::countLength(int num)
{
    int number = num;
    myQueue* pointer;
    pointer = front;
    countValues(number, pointer);
}

//***********************************************************************
// name: countValues
// called by: countLength
// passed: int num, myQueue *pointer 
// returns: nothing
// calls: countValues(num+1, pointer)
// The countLength acts as a recursive method. Once called it checks to see if
// the current node is empty, if it isn't, it looks to the next node, and
// the method calls itself incrementing 1 to num. Once the pointer reaches 
// nullptr, the num variable is printed.
//************************************************************************

void Line::countValues(int num, myQueue* pointer)
{


    if (pointer == nullptr)
    {
        cout << "\nThere are currently this many people in Line: " << num << endl;
    }
    else
    {
        pointer = pointer->next;
        countValues(num + 1, pointer); // Recurrsive Call


    }
}

//***********************************************************************
// name:  isEmpty
// called by:  Line
// passed: nothing
// returns: status 
// calls: nothing
// The isEmpty function checks if the queue is empty by seeing if 
// front and rear are NULL.
//************************************************************************

bool Line::isEmpty() const
{
    bool status;

    if (front == NULL && rear == NULL)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}
