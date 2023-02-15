//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

// ====================================================
//Your name: Elian Renteria
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node* current = NULL;//place holder to track while I traverse linkedlist
    current = front; // start at front
    while(current != NULL)//traverse array loop until not Nodes left
    {
        current = front;
        while(current->next != NULL)//nested loop to find last item
        {
            current = current->next;
        }
        delete current;//delete last node
        if(this->length()==0)//if no nodes left quit loop
        {
            current = NULL;
        }
        else//else continue
        {
            current = front;
        }
    }
    delete this;//delete linked list
    //TODO: Add code here. Make sure memory is released properly.
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if(front == nullptr)//checks if there is initial node at front return true if empty
        return true;
    else
    {
        return false;
    }// else retruns false since linked list has at least one node
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    if (front == NULL)//checks if we have a head node to see is linked list empty
    {
        return 0;
    }
    else//since front exists we proceed to count how many nodes there are
    {
        int count = 1;
        Node* current = front;
        while(current->next != NULL)//traverses linked list until end of reached when last node pointer doesn't point to another node
        {
            count++;
            current = current->next;
        }
        return count;
    }
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != NULL) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;//display linked list as string
}


void LinkedList::addRear(T val) {
    if(front == NULL)//check if linked list empty
    {
        front = new Node(val);
        rear = front;
    }
    else
    {
        Node* current = NULL;//create node ptr to traverse linked list
        current = front;//start at front
        while(current->next != NULL)//traverse linkedlist until reach end
        {
            current = current->next;
        }
        current->next = new Node(val);//set end next from null to equal our new node with val
        rear = current->next;//set linkedlist rear as current next
    }
    // consider the two cases of whether the list was empty
}

void LinkedList::addFront(T val) {
    if(this->isEmpty()== true)//check if list empty is so set front to new node
    {
        front = new Node(val);
        rear = front;
    }
    else
    {
        Node* oldFront = NULL;//else placehold old front
        oldFront = front;
        front = new Node(val);//set front to new node
        front->next = oldFront;//link front pointer to previous front node location
    }
    // consider the two cases of whether the list was empty
} 


bool LinkedList::deleteFront(T &OldNum) {
    OldNum = front->val;
    if(this->isEmpty()==true)//check is list empty if so return false
    {
        return false;
    }
    else
    {
        if(this->length()==1)//if list only has one item set front to null and delete &oldnum
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;//otherwise set front to next node and delete &oldnum
        }
        return true;
    }
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 


bool LinkedList::deleteRear(T &OldNum) {
    OldNum = rear->val;
    if(this->isEmpty()==true)//check is list empty if so return false
    {
        return false;
    }
    else
    {
        if(this->length()==1)//if list only has one item set front to null and delete &oldnum
        {
            delete rear;
            front = NULL;
            rear = NULL;
        }
        else
        {
            Node* prev = NULL;//saving locaton of previous node to rear
            Node* current = front;
            while(current->next != NULL )//traverse array
            {
                prev = current;
                current = current->next;
            }
            prev->next = NULL;//make prev ptr null
            rear = prev;//set prev node to new rear
            delete current;//delete old rear
            if(this->length()==1)//if list only has one item set front to null and delete &oldnum
            {
                front = rear;
            }
        }
        return true;
    }
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
bool LinkedList::deleteAt(int pos, T &val) {
    if((pos < 0)||(pos >= this->length()))//index out of range return false
    {
        return false;
    }
    else
    {
        Node* prev = NULL;//placeholder for previous node of current
        Node* current = front;//placeholder for traversing linked list
        int count = 0;
        while(count != pos)//traverse array till reach pos
        {
            count++;
            prev = current;
            current = current->next;
        }
        val = current->val;//set new val equal to that position
        if(count == 0)//if pos is front
        {
            if(this->length()==1)//linked list will be empty if we delete only element so reset rear and front
            {
                rear = NULL;
                front = NULL;
                delete current;
            }
            else if(this->length()==2)//if length 2 then left over item will be new rear and front
            {
                front = current->next;
                rear = front;
                delete current;
            }
            else// just remove front
            {
                front = current->next;
                delete current;
            }
        }
        else if(count == this->length()-1)//if pos is rear
        {
            rear = prev;//remove rear from list and set rear to prev
            prev->next = NULL;
            delete current;
        }
        else//for everything in between front and rear
        {
            prev->next = current->next;
            delete current;
        }
        return true;
    }
    //TODO: Add code here
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value. ?????????
}

/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
    if((pos < 0)||(pos > this->length()))//index out of range return false
    {
        return false;
    }
    else
    {
        int count = 0;//count current position
        Node* prev = NULL;//placeholder for previous node of current
        Node* current = front;//placeholder for current pos while traversing linkdlist
        while (count != pos)//traverse linked list until pos is reached
        {
            count++;
            prev = current;
            current = current->next;
        }
        if(count == 0)//if pos is front
        {
            prev = current;//save current front
            front = new Node(val);//create new node and set to front
            front->next = prev;//set fronts next ptr to prev front
        }
        else if(count == this->length())//if pos is rear
        {
            prev->next = new Node(val);
        }
        else//everything in between
        {
            prev->next = new Node(val);//make previous node point to new node
            prev = prev->next;//make point to prev new node
            prev->next = current;
        }
    }
    return true;
    //TODO: Add code here
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = NULL;//create empty placeholders for linked list
    rear = NULL;
    count = 0;//counter
    if(other.isEmpty()==true)//if linked list empty do nothing, since nothing to copy
    {
        return;
    }
    else
    {
        Node* current = other.front;//placeholder for traversal
        front = new Node(current->val);//create copy start by setting front of copy
        Node* copyCurrent = front;//copy traversal placeholder
        while(current->next != NULL)//traverse other and copy each element to copy
        {
            current = current->next;//go next node other
            copyCurrent->next = new Node(current->val);//add new node to copy if doesnt exist
            copyCurrent = copyCurrent->next;//go next node copy
        }
        rear = copyCurrent;//once last element from other copied set same element in our copy to rear since it is the end of the linked list
    }
    return;
    // TODO: Add code here. Interate through the other list and add a new node to this list
    // for each node in the other list. The new node should have the same value as the other node.
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
    if(this != &other) { // check if the same object
        // Delete all nodes in this list
        int x = 0;//variable needed for calling delete rear
        while(this->length()!=0)//loop through each node until there is none left
        {
            this->deleteRear(x);//delete rear node
        }
        // TODO: Add code here
        // Interate through the other list and add a new node to this list
        // Be sure to set the front and rear pointers to the correct values
        // Be sure to set the count to the correct value
        Node* current = NULL;//placeholder
        current = other.front;//start at front ot other linked list we will be copying
        front = new Node(current->val);//set local linked list front to other front
        while(current->next != NULL)//loop through other
        {
            current = current->next;//for each element in other add new node to this linkedlist
            this->addRear(current->val);
        }
        // TODO: Add code here
    }
    return *this;
}

