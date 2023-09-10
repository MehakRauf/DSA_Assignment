#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//single linked list
struct node
{
    int num;
    struct node *next;
};
struct node *start = NULL;
// to keep the track of the end of the linked list
struct node *END = start;

// function to return the mid values of the linked list
void GetTrump()
{
    // this will move one step forward
    struct node *curr = start;
    // this will move two steps forward
    struct node *runner = start;
    // if the size of linked list is even so, this will keep track off the previous element
    struct node *prev = NULL;
    // the loop will run when both the conditions are true
    while (runner != NULL && runner->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        runner = runner->next->next;
    }
    // when the size of linked list is even
    if (runner == NULL)
    {
        cout << "The middle values are: " << endl;
        cout << prev->num << " " << prev->next->num << endl;
    }
    // when the size of the linked list is odd
    else
    {
        cout << "The middle element is: " << endl;
        cout << curr->num;
    }
}

// function to add the value at the end of the linked list
void ADD(int value)
{
    struct node *curr1;
    // memory allocation
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // assigning the value
    temp->num = value;
    temp->next = NULL;
    // when the list is empty
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        // will start traversing from start
        curr1 = start;
        // traversing to reach the end of linked list
        while (curr1->next != NULL)
        {
            curr1 = curr1->next;
        }
        // adding the node
        curr1->next = temp;
    }
}

// function to delete a node at the end of the linked list
void DELETE()
{
    // when start is empty means there is no node in the linked list
    if (start == NULL)
    {
        cout << "No elements to be deleted." << endl;
    }
    // when there is only one node in the linked list
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct node *curr = start;
        struct node *prev = NULL;
        // traversing till the end
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        // making the next of second last node as null
        prev->next = NULL;
        free(curr);
    }
}
// function to read the .txt file
void READ()
{
    string filepath;
    // taking the file path as input
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return;
    }

    string command;
    int value;
    // loop will run until unless there will be some command in the input file
    while (inputFile >> command)
    {
        // if command is add then ADD(value) will be called
        if (command == "ADD")
        {
            if (inputFile >> value)
            {
                ADD(value);
            }
        }
        // if command is DELETE then DELETE() will be called
        else if (command == "DELETE")
        {
            DELETE();
        }
        // if the command is END so this will be executed which will indicate the end of the linked list
        else if(command=="END")
        {
            struct node *curr = start;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            END = curr;           
        }
        else{
            cout<<"The command is invalid"<<endl;
        }
    }
    inputFile.close();
}
// function to print the elemnt of the linked list
void PRINT()
{
    if (start == NULL)
    {
        cout << "List is empty.";
    }
    struct node *curr = start;
    while (curr != NULL)
    {
        cout << curr->num << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    READ();
    PRINT();
    GetTrump();
}
