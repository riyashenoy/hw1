/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // keeps track of head for even and odd lists
  static Node* evenHead = nullptr;
  static Node* oddHead = nullptr;

  // checks if empty and assigns right heads to each list
  if(in == nullptr){
    odds = oddHead;
    evens = evenHead;
    return;
  }

  // creates a new node based on the current in node
  Node* nextVal = new Node(in->value, nullptr);

  // checks if the value is even
  if(in->value % 2 == 0){
    if(evens != nullptr){
      evens->next = nextVal;
    }
    else{
      evenHead = nextVal;
    }
    evens = nextVal;
  }
  else{
    if(odds != nullptr){
      odds->next = nextVal;
    }
    else{
      oddHead = nextVal; 
    }
    odds = nextVal; 
  }

  // temp stores current node, and moves on to next
  Node* temp = in;
  in = in->next;

  // deletes old node
  delete temp;

  // recursive call to do the rest of list tht is inputted
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
