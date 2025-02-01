#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "ulliststr.h"
using namespace std; 

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list = ULListStr();

  // test if value gets added to list and size is 1
  list.push_back("1");
  cout << list.size() << endl;

  // test if get grabs '1'
  cout << list.get(0) << endl;

  // test if get is called when the index is invalid
  try{
    cout << list.get(3) << endl;
  }
  catch(out_of_range& e){
    cout << "Caught exception" << endl;
  }

  // test if value is removed and size is 0 
  list.pop_front();
  cout << list.size() << endl;

  // test if pop front is called when the list is empty
  list.pop_front();
  cout << list.size() << endl;

  // test if pop back is called when the list is empty
  list.pop_back();
  cout << list.size() << endl;

  list.push_back("1");
  list.push_back("2");
  list.push_back("3");
  list.push_back("4");
  list.push_back("5");
  list.push_back("6");
  list.push_back("7");
  list.push_back("8");
  list.push_back("9");
  list.push_back("10");


  list.push_front("0");
  list.push_front("1");
  list.push_front("2");
  list.push_front("3");
  list.push_front("4");
  list.push_front("5");
  list.push_front("6");

  // size should equal 17
  cout << list.size() << endl;

  list.pop_front();
  // the new front should be 5
  cout << list.front() << endl;

  list.pop_back();
  // the new front should be 9
  cout << list.back() << endl;


  return 0;
}
