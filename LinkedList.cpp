#include <limits>
#include <iostream>
#include <climits>

#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList()
{
   head = new Node(0,NULL);
}

LinkedList::LinkedList(int *array, int len)
{
    Node *ptr = new Node(array[0], nullptr);
    head = ptr;

    for (int i = 1; i < len; i++)
    {
        Node *temp = new Node(array[i], nullptr);
        ptr->setLink(temp);
        ptr = temp;
    }
    ptr->setLink(nullptr);
}

bool LinkedList::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

void LinkedList::insertFront(int newNum)
{
    Node *temp = new Node(newNum, head);
    head = temp;
}

void LinkedList::insertEnd(int newNum)
{
    Node *temp = new Node(newNum, nullptr);

    if (this->isEmpty())
    {
        head = temp;
        return;
    }

    Node *ptr = head;
    while (ptr->getLink() != nullptr)
    {
        ptr = ptr->getLink();
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    // made change here so user cant input more than int max
    if (newNum >= INT_MAX)
    {
        return;
    }
    
    if (this->isEmpty())
    {
        head = new Node(newNum, nullptr);
        return;
    }
    
    if (pos <= 1)
    {
        this->insertFront(newNum);
        return;
    }

    Node *add = nullptr;
    Node *ptr = head;

    int count = 0;

    while (ptr != nullptr && count <= pos)
    {
        count++;
        if (count == pos - 1)
        {
            add = ptr;
        }
        ptr = ptr->getLink();
    }

    if (add == nullptr)
    {
        this->insertEnd(newNum);
        return;
    }

    Node *temp = new Node(newNum, add->getLink());
    add->setLink(temp);
    return;
}

// search

int LinkedList::search(int target)
{
    int found = 0;

    int count = 1;
    
    Node *ptr = head;

    while(ptr != nullptr)
    {
        if (ptr->getData() == target)
        {
            found = count;
            break;
            // maybe here return count
        }
        else 
        {
            found = - 1;
        }
        ptr = ptr->getLink();
        count++;
    }
    return found;   
}

void LinkedList::deleteFront()
{
    if (this->isEmpty())
    {
        return;
    }

    Node *ptr = head;
    head = head->getLink();
    delete ptr;
    return;
}

void LinkedList::deleteEnd()
{
    if(this->isEmpty())
    {
        return;
    }

    Node *ptr = nullptr;
    Node *end = head;

    while(end->getLink() != nullptr)
    {
        ptr = end;
        end = end->getLink();
    }

    ptr->setLink(nullptr);
    delete end;
    return;
}

bool LinkedList::deletePosition(int pos)
{

    if(pos < 1)
    {
        return false;
    }
    // edited this to include more conditions 
    else
    {
        Node *temp = head->getLink();
        if(pos == 1)
        {
            temp = head->getLink();
            head = temp;
            return true;
        }
    }

    Node *del = nullptr;
    Node *ptr = head;
    int count = 0;

    while (ptr != nullptr && count <= pos)
    {
        count++;

        if (count == pos - 1)
        {
            del = ptr;
        }
        ptr = ptr->getLink();
    }
    
    if (del == nullptr || del->getLink() == nullptr)
    {
        return false;
    }
    
    Node *temp = del->getLink();
    del->setLink(temp->getLink());
    delete(temp);

    return true;
}

int LinkedList::get(int pos)
{
    int outofrange = std::numeric_limits < int >::max();

    if(pos < 1)
    {
        return outofrange;
    }

    Node *get = nullptr;
    Node *ptr = head;
    int count = 0;

    while(ptr != nullptr && count <= pos)
    {
        count++;
        if (count == pos)
            get = ptr;
        ptr = ptr->getLink();
    }
    // change made here to check more than int max
    if (get == nullptr || get->getLink() == nullptr || get->getData() >= INT_MAX)
    {
        return outofrange;
    }
    //return get->getData();
    return get->getData();
}

void LinkedList::printList()
{
    if(this->isEmpty())
    {
        return;
    }

    Node *ptr = head;

    std::cout << "[";

    while (ptr != nullptr)
    {
        std::cout << ptr->getData() << " ";
        ptr = ptr->getLink();
    }
    std::cout << "]" <<std::endl;
}

LinkedList::~LinkedList()
{
    Node *ptr = head;
    Node *temp;
    while(ptr != nullptr)
    {
        temp = ptr;
        ptr = ptr->getLink();
        delete temp;
    }
    // 
    head->~Node();
}
