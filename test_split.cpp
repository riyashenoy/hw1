/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
#include "split.h"
using namespace std; 

int main(int argc, char* argv[])
{
  // LL nodes + values, and linking each
  Node* node1 = new Node(3, nullptr);
  Node* node2 = new Node(2, nullptr);
  node1->next = node2; 
  Node* node3 = new Node(8, nullptr);
  node2->next = node3;
  Node* node4 = new Node(12, nullptr);
  node3->next = node4;
  Node* node5 = new Node(13, nullptr);
  node4->next = node5;
  Node* node6 = new Node(10, nullptr);
  node5->next = node6;
  Node* node7 = new Node(5, nullptr);
  node6->next = node7;

  // keeps track of og LL
  Node* currNode = node1;

  cout << "Un-split Linked List: ";
  while(currNode != nullptr){
    cout << " " << currNode->value;
    currNode = currNode->next;
  }
  cout << endl;

  Node* evenList = nullptr;
  Node* oddList = nullptr;

  // separates even and odd values
  split(node1, oddList, evenList);

  cout << "Even Linked List: ";
  while(evenList != nullptr){
    cout << " " << evenList -> value;
    evenList = evenList->next;
  }

  cout << endl;
  cout << "Odd Linked List: ";

  while(oddList != nullptr){
    cout << " " << oddList->value;
    oddList = oddList->next;
  }
}
