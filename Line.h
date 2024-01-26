#ifndef LINE_H
#define LINE_H
#include <string>
using namespace std;



class Line
{
private:

    struct myQueue
    {
        string value;
        int raffle;
        myQueue* next;
    };
    myQueue* front;
    myQueue* rear;

public:
    // constructor
    Line();
    // destructor
    ~Line();

    void countValues(int, myQueue*);
    void countLength(int num);
    void addQueue(string, int);
    void removeItem(string);
    void displayQueue();
    bool isEmpty() const;



};
#endif