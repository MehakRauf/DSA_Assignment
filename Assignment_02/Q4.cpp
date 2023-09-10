#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// doubly linked list
struct node
{
    int id;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *cursor = start;

// function to add a value at a specific index
void insertAtpos(int steps, int value)
{
    // memory allocation
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = value;
    // to add at start location
    if (steps == 0)
    {
        temp->prev = NULL;
        temp->next = start;
        // checking if there is already a node as start
        if (start != NULL)
        {
            start->prev = temp;
        }
        start = temp;
    }
    else
    {
        struct node *temp1 = start;
        // iterating till the steps mentioned
        for (int i = 1; i <= steps; i++)
        {
            // during iteration if we reach the end of the list then return hence there is no value left
            if (temp1 == NULL)
            {
                return;
            }
            // moving it one step forward
            temp1 = temp1->next;
        }
        // adjusting the links
        temp->prev = temp1;
        temp->next = temp1->next;
        // checking if it is not the last element
        if (temp1->next != NULL)
        {
            // adjusting the links
            temp1->next->prev = temp;
        }
        temp1->next = temp;
    }
    // for printing the list
    // means there is no list
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr1 = start;
    while (curr1 != NULL)
    {
        cout << curr1->id << " ";
        curr1 = curr1->next;
    }
    cout << endl;
}
void insertion(int value)
{
    // memory allocation
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = value;
    temp->next = NULL;
    struct node *curr = start;
    // if list is not initialized means start is NULL
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        // addidng the element at the end of the list
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        // adjusting the links
        curr->next = temp;
        temp->prev = curr;
    }
    // for printing the list
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr1 = start;
    while (curr1 != NULL)
    {
        cout << curr1->id << " ";
        curr1 = curr1->next;
    }
    cout << endl;
}

// function to print the value present at the cursor
void print()
{
    if (cursor != NULL)
    {
        cout << cursor->id << endl;
    }
    // as I have not appliedthe undo part so it can be null
    else
    {
        cout << "NULL" << endl;
    }
}
// function to move the cursor forward
void MoveForward_steps(int steps)
{
    cursor = start;
    struct node *curr = start;
    for (int i = 0; i <= steps; i++)
    {
        // if the desired steps are reached
        // changing the cursor position
        if (i == steps)
        {
            break;
        }
        // moving in forward direction
        curr = curr->next;
    }
    cout << "Moved the cursor by " << steps << " steps." << endl;
}
// function to move the curosr in backward direction
void Backward_steps(int steps)
{
    for (int i = 0; i <= steps; i++)
    {
        if (i == steps)
        {
            break;
        }
        // moving in backward deirection
        cursor = cursor->prev;
    }
    cout << "Moved the cursor by " << steps << " steps." << endl;
}

// function to add the value right after the cursor position
void AddImmediate_number(int val)
{
    if (cursor != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->id = val;
        temp->next = NULL;
        temp->prev = cursor;
        temp->next = cursor->next;

        // if it is in between the node
        if (cursor->next != NULL)
        {
            cursor->next->prev = temp;
        }
        // if it is the last node
        cursor->next = temp;
        cursor = temp;
    }
}
// function to delete a node at the end of the linked list
void Deletion()
{
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    // adjusting the links
    curr->prev->next->next = NULL;
    free(curr);
}
// function to delete a node at specific index
void deleteAtIndex(int index)
{
    // if want to delete the start node
    if (index == 0)
    {
        // if the list not even initialized
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        // if there is no node after start(only one node)
        else if (start->next == NULL)
        {
            free(start);
            start = NULL;
        }
        // if there is a node after start
        else
        {
            struct node *temp = start;
            start = start->next;
            start->prev = NULL;
            free(temp);
        }
    }
    else
    {
        struct node *temp = start;
        // iterating through the list
        for (int i = 1; i <= index; i++)
        {
            temp = temp->next;
        }
        // adjusting the links
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
// function to delete the index where the cursor is presented.
void DeleteImmediate()
{
    struct node *temp = cursor;
    if (cursor != NULL)
    {
        // means cursor is at start
        if (cursor->prev == NULL)
        {
            start = start->next;
            free(temp);
        }
        // when list not initialized
        else if (start == NULL)
        {
            cout << "List is empty." << endl;
        }
        // means the last element
        else if (cursor->next == NULL)
        {
            cursor->prev->next = NULL;
            free(temp);
        }
        // if it is in between two nodes
        else
        {
            cursor->next = cursor->next->next;
            cursor->next->prev = cursor;
        }
    }
}
// function to update the data at the specific index by the
// number.
void Update_index_number(int pos, int val)
{
    struct node *temp = start;
    // from 0th index to the required position
    for (int i = 0; i <= pos; i++)
    {
        // if before reaching the required position if it becomes null
        // so no need for further iteration
        if (temp == NULL)
        {
            return;
        }
        // moving the pointer forward
        temp = temp->next;
    }
    // if it is not null then update the value
    if (temp != NULL)
    {
        temp->id = val;
    }
}
// function to Update the data at which the cursor is
// pointing to.
void UpdateImmediate_number(int num)
{
    // checking if cursor is null
    if (cursor != NULL)
    {
        cursor->id = num;
    }
}
// function to Shift the current data of cursor with the data of the index
// specified
void Shift_index(int index)
{
    if (cursor != NULL)
    {
        struct node *temp = start;
        // to reach the desired position
        for (int i = 0; i <= index; i++)
        {
            // before reaching the requored position
            // if it is null so no need for further iteration
            if (temp == NULL)
            {
                return;
            }
            // moving the cursor forward
            temp = temp->next;
        }
        // checking if there is any node
        if (temp != NULL)
        {
            // swapping the values
            int temp1 = temp->id;
            temp->id = cursor->id;
            cursor->id = temp1;
        }
    }
}
// function to read the .txt file
void READ()
{
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return;
    }
    int pos_val;
    string command;
    int value;
    while (inputFile >> command)
    {
        if (command == "Add")
        {
            if (inputFile >> value)
            {
                //if add at index
                if (inputFile >> pos_val)
                {
                    insertAtpos(value, pos_val);
                }                
            }
            else{
                insertion(value);
            }
        }
        else if (command == "Shift")
        {
            int ind;
            inputFile >> ind;
            Shift_index(ind);
        }
        else if (command == "Print")
        {
            print();
        }
        else if (command == "MoveForward")
        {
            int steps;
            inputFile >> steps;
            MoveForward_steps(steps);
        }
        else if (command == "AddImmediate")
        {
            int val;
            inputFile >> val;
            AddImmediate_number(val);
        }
        else if (command == "DeleteImmediate")
        {
            DeleteImmediate();
        }
        else if (command == "Update")
        {
            int pos, val;
            inputFile >> pos;
            inputFile >> val;
            Update_index_number(pos, val);
        }
        else if (command == "Delete")
        {
            int val;
            // if there will be a value means that is a specific index
            if (inputFile >> val)
            {
                deleteAtIndex(val);
            }
            else
            {
                Deletion();
            }
        }
        else if (command == "MoveBackward")
        {
            int steps;
            // reading the steps
            inputFile >> steps;
            Backward_steps(steps);
        }
        // failed to implement this part that's why just wrote undo
        else if (command == "Undo")
        {
            cout << "Undo" << endl;
        }
        else if (command == "UpdateImmediate")
        {
            int val;
            inputFile >> val;
            UpdateImmediate_number(val);
        }
        else
        {
            cout << "Invalid opeartaion." << endl;
        }
    }
    inputFile.close();
}
int main()
{
    READ();
}