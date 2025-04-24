/******************************************************************************

DATA STRUCTURE: LINKED LIST

IMPLEMENTATION  AS DISCUSSED
*******************************************************************************/

#include <iostream>
using namespace std;

class Node
{
public:

    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
class SLList {

    Node* first;

public:

    SLList()
    {
        first = nullptr;
    }

    bool isEmpty()
    {
        if (first == nullptr)
            return true;

        return false;
    }

    //Linked list can never be full so no isFull() required

    void addItemAtLast(int value)
    {
        Node* ptr = new Node(value);

        if (isEmpty())
            first = ptr;
        else
        {
            Node* curr = first;
            //traverse to the last Node
            while (curr->next != nullptr)
                curr = curr->next;

            curr->next = ptr;
        }
    }

    void addAtFront(int value)
    {
        Node* ptr = new Node(value);

        if (isEmpty())
            first = ptr;

        else
        {
            ptr->next = first;
            first = ptr;
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            Node* curr = first;
            //traverse to the end of list , stop after the last Node

            while (curr != nullptr)
            {
                cout << curr->data << "  ";
                curr = curr->next;
            }

            cout << endl;
        }
        else
            cout << "List is Empty\n";
    }

    //after can be the node number , or can be the value after which you want to add so choose any 
    void addAfter(int value, int after) // try to write its definition as discussed in class
    {
        Node* ptr = new Node(value);
        Node* curr = first;
        while (curr->data != after)
        {
            curr = curr->next;
        }
        Node* NextOFAfter = curr->next;
        curr->next = ptr;
        ptr->next = NextOFAfter->next;
    }


    void addBefore(int value, int before) //// try to write its definition as discussed in class
    {
        Node* ptr = new Node(value);
        Node* curr = first;
        Node* beforeCurr = first;
        while (curr->data != before)
        {
            if(curr == first)
            curr = curr->next;
            else
            {
                beforeCurr = beforeCurr->next;
                curr = curr->next;
            }
        }
        beforeCurr->next = ptr;
        ptr->next = curr;
    }
    void addAtAny(int value) // try to write its definition as discussed in class
    {
        cout << "\nEnter the position you want to insert\n";
        int position;
        cin >> position;
        Node* ptr = new Node(value);
        Node* curr = first;
        while (position > 0)
        {
            curr = curr->next;
            position--;
        }
        ptr->next = curr;
    }
    int countNodes()
    {
        if (first == nullptr)
            return 0;
        Node* ptr = first;
        int count = 1;
        while (ptr != nullptr) {
            ptr = ptr->next;
            count++;
        }

    }
    bool searchItem(int value)  // will return true if value found else false
    {
        
        Node* check = first;
        while (check != nullptr)
        {
            if (check->data == value)
                return 1;
            check = check->next;
        }
        return 0;
    }
    Node* searchItem2(int value)  // will return the node with value if found else nullptr
    {
        Node* check = first;
        while (check != nullptr)
        {
            if (check->data == value)
                return check;
            check = check->next;
        }
        return nullptr;
    }
    // this function will help in removing item    
    Node* searchItem3(int value, Node*& prev) //will return the node with value , and also update prev with the prev of the node searched else return nullptr
    {
        if (isEmpty())
            return nullptr;
        Node* check = first;
        if (check->data = value)
        {
            prev = nullptr;
            return check;
        }
        else
        {
            Node* before = check;
            check = check->next;
            while (check != nullptr)
            {
                if (check->data == value)
                {
                    prev = before;
                    return check;
                }
                before = check;
                check = check->next;
            }
            return nullptr;
        }
    }
    void removeItemFromFront(int value)
    {
        if (first->data = value)
        {
            Node* curr = first->next;
            delete[] first;
            first = curr;
        }
    }

    void removeItemBeforeAnyNode(int value)
    {
        Node* ptr = new Node(value);
        Node* curr = first;
        Node* beforeCurr = first;
        while (curr->data != value)
        {
            if (curr == first)
                curr = curr->next;
            else
            {
                beforeCurr = curr->next;
                curr = curr->next;
            }
        }
        beforeCurr->next = ptr;
        ptr->next = curr;
    }

    void removeItemAfterAnyNode(int value);

    void removeAnyItem(int value);

    void removeNthNode(int n);

};
int main()
{
    SLList l1;

    l1.addItemAtLast(2);
    l1.addItemAtLast(19);
    l1.addItemAtLast(87);

    l1.print();


    return 0;
}  