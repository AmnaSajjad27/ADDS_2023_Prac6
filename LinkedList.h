#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

class LinkedList
{
    private:
    Node *head;

    public:
    LinkedList();
    LinkedList(int * array, int len);
    ~LinkedList();

    // IsEmpty function so we can use it in other functions
    bool isEmpty();

    // pos of one or less inserts node at the start of the list 
    // pos that exceeds the size of the list adds the node to the end of the list
    void insertPosition(int pos, int newNum);

    // helper functions for insertPosition
    void insertFront(int newNum);
    void insertEnd(int newNum);

    // removes the node at pos and deletes it
    bool deletePosition(int pos); 

    // helper functions
    void deleteFront();
    void deleteEnd();

    // returns the pos Node's member variable 
    // if out of bounds, return std::numeric_limits < int >::max()
    int get(int pos);

    // searches the list for first occurance of target 
    // returns index of target or -1 if it does not exist 
    int search(int target);

    // prints the list enscapsulated by '[' and ']'
    void printList();
};

#endif