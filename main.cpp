//# Project-D---Problem-13.5---Heily-Cabrera

// Turn the linked list implementation into a circular list: Have the previous pointer of the first node point to the last node, and the next pointer of the last node point to the first node. Then remove the last pointer in the List class because the value can now be obtained as first->previous. Reimplement the member functions so that they have the same effect as before. // 

//Programmer: Heily Cabrera
//Tester: Audrey Tapia 

// Group Project C //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;

    Node(int value) 
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularList 
{
private:
    Node* first;

public:
    CircularList() 
    {
        first = nullptr;
    }

    
    void append(int value) 
        {
        Node* newNode = new Node(value);

        if (first == nullptr) 
        {
            
            first = newNode;
            first->next = first;
            first->prev = first;
        } 
        else 
        {
            Node* last = first->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = first;
            first->prev = newNode;
        }
    }

    
    void displayForward() 
    {
        if (first == nullptr) 
        {
            cout << "Empty." << endl;
            return;
        }

        Node* temp = first;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first);
        cout << endl;
    }

    
    void displayBackward() 
{
        if (first == nullptr) {
            cout << "Empty." << endl;
            return;
        }

        Node* last = first->prev;
        Node* temp = last;
        do 
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        while (temp != last);
        cout << endl;
    }

    void deleteFirst() 
{
        if (first == nullptr) return;

        if (first->next == first) 
        {
            delete first;
            first = nullptr;
        } 
        else 
        {
            Node* last = first->prev;
            Node* second = first->next;

            last->next = second;
            second->prev = last;

            delete first;
            first = second;
        }
    }

    // Delete the last node
    void deleteLast() 
{
        if (first == nullptr) return;

        Node* last = first->prev;
        if (last == first) 
        {
            delete last;
            first = nullptr;
        } 
        else 
        {
            Node* newLast = last->prev;
            newLast->next = first;
            first->prev = newLast;

            delete last;
        }
    }

    
    ~CircularList() 
{
        while (first != nullptr) 
        {
            deleteFirst();
        }
    }
};

int main() 
{
    CircularList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "List forward: ";
    list.displayForward();

    cout << "List backward: ";
    list.displayBackward();

    list.deleteFirst();
    cout << "After deleting first: ";
    list.displayForward();

    list.deleteLast();
    cout << "After deleting last: ";
    list.displayForward();

    return 0;
}

