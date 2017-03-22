// Singly Linked list
// add nodes

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

int main()
{
    Node *headPtr = nullptr;
    Node *tailPtr = nullptr;
    Node *temp;
    
    headPtr = new Node;
    tailPtr = headPtr;
    
    for (int i = 99; i >= 77; i = i - 11)
    {
        if (i == 99) //Our first node
        {
            headPtr = new Node;
            headPtr->data = i;
            headPtr->link = nullptr;
            tailPtr = headPtr;
        }
        else //Other new nodes to be linked
        {
            tailPtr->link = new Node;
            tailPtr = tailPtr->link;
            tailPtr->data = i;
            tailPtr->link = nullptr;
        }
    }
    
    // put a dummy head pointer in front
    Node * dummyHead = new Node;
    dummyHead->data = NULL;
    dummyHead->link = headPtr;
    
    //Add a new node, value = 100 at the front
    temp = new Node;
    temp->data = 100;
    temp->link = dummyHead->link;
    dummyHead->link = temp;
    
    
    //Add a new node, value = 1 at the end
    temp = new Node;
    temp->data = 1;
    temp->link = nullptr;
    tailPtr->link = temp; // because tailPtr was already at the end from the construction for loop
    
    //Add a new node, value 80, between 77 and 88
    temp = new Node;
    temp->data = 80;
    temp->link = nullptr;
    
    // send moving pointer to location in linked list
    // where to perform the insert
    cout << "Moving right along...\n";
    Node * movPtr = dummyHead->link; // start at dummy head's link
    while (movPtr->link->data >= 80) {
        cout << movPtr->data << ' ';
        movPtr = movPtr->link;
    }
    
    // link temp (new node 80) to same as movPtr link (pointing at 77)
    temp->link = movPtr->link;
    // link moving pointer link to temp
    movPtr->link = temp;
    // all is linked, yes?
    
    cout << endl;
    
    cout << "Moving pointer data: " << movPtr->data << ' ';
    
    cout << endl;
    
    //Display the list
    cout << "Its the final countdown...\n";
    temp = dummyHead;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->link;
    }
    
    cout << endl;
    return 0;
}
