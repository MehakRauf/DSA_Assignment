#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// doubly linked list
struct node
{
    int id;
    struct node *next = NULL;
    struct node *prev = NULL;
};
struct node *start = NULL;

// function to add values int the linked list
void insertion(int value)
{
    // memory allocation
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = value;
    temp->next = NULL;
    struct node *curr = start;
    // if start is empty
    if (start == NULL)
    {
        start = temp;
    }
    // otherwise add it at the end of the linked list
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

// function to print the linked list
void print()
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr = start;
    while (curr != NULL)
    {
        cout << curr->id << " ";
        curr = curr->next;
    }
    cout << endl;
}

// function to reverse the elements and return the third last of the linked list
int reverse()
{
    int i = 1;
    // traversing the linked list
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
        // counting the number of elements
        i++;
    }
    // if the no. of elements is less than 3 then it will return(-1)
    if (i < 3)
    {
        return -1;
    }
    // if greater than three
    else
    {
        int j = 1;
        // this time current will be at the last node
        while (curr != NULL)
        {
            // checking if we have reached our desired position if yes then return the value
            if (j == 3)
            {
                return curr->id;
                break;
            }
            // going in reverse order
            curr = curr->prev;
            j++;
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
    int value;
    while (inputFile >> value)
    {
        insertion(value);
    }
}
int main()
{
    READ();
    // storing the value in an integer
    int val = reverse();
    // if (-1) means the size of linked list is less than 3
    if (val == -1)
    {
        cout << "The size of list is less than three " << endl;
    }
    // otherwise it will print the third last element
    else
    {
        cout << "The third last value is: " << val;
    }
}