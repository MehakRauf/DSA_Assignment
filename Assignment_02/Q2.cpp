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
int count = 0;
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
        count++;
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
        count++;
    }
}
//function to print the elements of the elements of the linked list
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

// function to sort the elements of the linked list
void sort()
{
    // taking to pointers just to keep the track of the last sorted element
    struct node *curr2;
    struct node *curr1 = NULL;
    bool swapp;
    // bubble sort algorithm
    // this loop will run atleast once
    do
    {
        // making it false so that when all elements are sorted the loop will break
        swapp = false;
        curr2 = start;
        while (curr2->next != curr1)
        {
            // searching the elements consecutively
            if (curr2->num > curr2->next->num)
            {
                // if it is true than swap the values of the nodes
                int num = curr2->num;
                curr2->num = curr2->next->num;
                curr2->next->num = num;
                // make it true so that next terms will also be sorted
                swapp = true;
            }
            // moving the pointer one step forward
            curr2 = curr2->next;
        }
        curr1 = curr2;
    } while (swapp);
}
void median()
{
    float median;
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
    // when size of the linked list is even
    if (runner == NULL)
    {
        median = (prev->num + prev->next->num) / 2.0;
        cout << "The median is: " << median << endl;
    }
    // when size of the linked list is odd
    else
    {
        cout << "The median is: " << curr->num << endl;
    }
}
void READ()
{
    string filepath;
    // filepath input
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
        // constraint(3) Every individual number will always be greater than 0 and less than or
        // equal to 100.
        if (value < 0 || value > 100)
        {
            continue;
        }
        ADD(value);
        // sorting it after every insertion
        sort();
        // printing the median
        median();
    }
}

int main()
{
    READ();
}