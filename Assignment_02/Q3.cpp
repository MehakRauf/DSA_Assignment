#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

// doubly linked list
struct node
{
    int transactionId;
    int transactionAmount;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

void DELETE(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        struct node *curr = start;
        // iterate till the end of the linked list
        while (curr != NULL)
        {
            // as the id should be there according to the constraints that's 
            //why making this Fraudulent amount as zero
            if (curr->transactionId == arr[i])
            {
                curr->transactionAmount = 0;
            }
            //moving the pointer forward
            curr = curr->next;
        }
    }
}
void read()
{
    int numberOfTransactions;
    int numberOfFraudulentTransactions;
    int transId;
    int transAmount;
    char comma;
    string line;
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return;
    }
    // read the numberOfTransactions
    inputFile >> numberOfTransactions;
    // read the  numberOfFraudulentTransactions
    inputFile >> numberOfFraudulentTransactions;
    // calculating the size for an array to store the elements
    // multiplied the numberOfTransactions with 2 beacuse there will be id as well
    // as the transactionAmounts
    int size = numberOfTransactions * 2 + numberOfFraudulentTransactions;
    // declaring the array
    int arr[size];
    // to read the FraudulentTransacrions
    int del[numberOfFraudulentTransactions];
    // the loop will run till the end of the inputFile
    for (int i = 0; i < size; i++)
    {
        // to read the ids and non fraudulent amounts
        while (i < numberOfTransactions)
        {
            // the first one will be the id
            inputFile >> arr[i];
            // reading the comma (separated by comma)
            inputFile >> comma;
            // the second one will be the transaciton amount
            inputFile >> arr[i + 1];
            // memory allocation
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            // storing the id
            temp->transactionId = arr[i];
            // storing the amount
            temp->transactionAmount = arr[i + 1];
            temp->next = NULL;
            struct node *curr = start;
            // if start is null then make the temp as start
            if (start == NULL)
            {
                start = temp;
            }
            // else add it at the end of the linked list
            else
            {
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = temp;
                temp->prev = curr;
            }
            i++;
        }
    }
    // now this will read the FraudulentTransactions
    for (int i = 0; i < numberOfFraudulentTransactions; i++)
    {
        inputFile >> del[i];
    }
    // delete function will be calles
    DELETE(del, numberOfFraudulentTransactions);
}
// function to print the elements
void print()
{
    //if start is null means there is no element in the linked list
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr = start;
    while (curr != NULL)
    {
        // as the node is present with the id so,this to skip the FraudulentTransaction ids from prinitng
        if (curr->transactionAmount != 0)
        {
            cout << curr->transactionId << "," << curr->transactionAmount << endl;
        }
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    read();
    print();
}