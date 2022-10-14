// Zohaib Ahmad
// 11/10/2022
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *perv;
};
Node *head;
//---------------------------------------------------------------------------------------------------
Node *Get_New_Node(int value)
{ // Function to make a new Node.
    Node *new_node;
    new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;
    new_node->perv = NULL;
    return new_node;
}

void InsertAtHead(int value)
{ // Will insert a new Node at head
    Node *new_Node = Get_New_Node(value);
    if (head == NULL)
    {
        head = new_Node;
    }
    else
    {
        new_Node->next = head;
        head->perv = new_Node;
        head = new_Node;
    }
}

void InserAtEnd(int value)
{ // Will insert a new Node at the end of the linkedlist
    Node *new_node = Get_New_Node(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->perv = temp;
    }
}

void deletion_by_value(int value){
    Node *temp = head;
    if(head->value == value){
        temp = head;
        head = head->next;
    }
    else{
        Node *temp2;
        while(temp->next != NULL){
            if(temp->next->value == value){
                temp2 = temp->next;
                if(temp2->next != NULL){
                    temp->next = temp2->next;
                    temp2->next->perv = temp->perv;
                    return;
                }
                else{
                    temp->next = NULL;
                    delete temp2;

                }
                //temp->next = temp2->next;
                //temp2->next->perv = temp->perv;
                delete temp2;
                return;
            }
            temp = temp->next;
            
        }
        cout<<"Data not found";

    }

    
}

void print()
{ // Function to print values of linkedlist
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    cout << "NULL<-->";
    while (temp != NULL)
    {
        cout << temp->value << "<-->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

void print_Reverse()
{ // Will print the linkedlist in reverse order
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "NULL<-->";
    while (temp != NULL)
    {
        cout << temp->value << "<-->";
        temp = temp->perv;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{

    head = NULL;

    InsertAtHead(3);
    InsertAtHead(2);
    InsertAtHead(1);
    InserAtEnd(4);
    InserAtEnd(5);
    InserAtEnd(6);
    deletion_by_value(6);
    print();
   // print_Reverse();

    return 0;
}