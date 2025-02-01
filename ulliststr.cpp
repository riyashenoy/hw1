#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

// mine 

void ULListStr::push_back(const std::string& val){
  // creates new item if empty or if last item is full
  if(tail_ == NULL || tail_->last == ARRSIZE){
    Item* newNode = new Item();

    // places new val in the new node beginning
    newNode->val[0] = val;
    // incremements last index
    newNode->last++;

    // sets head & tail to the new node if list empty
    if(tail_ == NULL){
      head_ = newNode;
      tail_ = newNode;
    }
    // if its not empty, it updates the new node to current tail and updates
    else{
      tail_->next = newNode;
      newNode->prev = tail_;
      tail_ = newNode; 
    }
  }
  // if space itll add the value to the current tail
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  // incrememnts list size
  size_++;
}

// add to front
void ULListStr::push_front(const std::string& val){
  // checks if list is empty to make new item 
  if(head_ == NULL || head_->first == 0){
    Item* newNode = new Item();

    // puts it in the end of new node, and adjusts first and last indices val
    newNode->val[ARRSIZE - 1] = val; 
    newNode->last = ARRSIZE;
    newNode->first = ARRSIZE - 1;

    // sets head and tail to new node
    if(head_ == NULL){
      head_ = newNode;
      tail_ = newNode;
    }
    // sets new node to current head anad updates its ptr
    else{
      head_->prev = newNode;
      newNode->next = head_;
      head_ = newNode;
    }
  }
  // adds value if spsace in head
  else{
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  // incremements list size
  size_++;
}

// remove front
void ULListStr::pop_front(){

  // nothing to remove if the list is empty!
  if(head_ == NULL){
    return;
  }

  // removes first elements by moving index forwasd
  head_->first++;

  // checks if the item is empty after moving, and dthen removes the item
  if(head_->first == head_->last){
    Item* temp = head_;

    // moves head ptr to next item
    head_ = head_->next;
    if(head_ != NULL){
      // updates prev ptr
      head_->prev = NULL;
    }
    // sets tail to null if list is empty
    else{
      tail_ = NULL;
    }
    // delete old head
    delete temp;
  }
  // decrement list size
  size_--;
}

// remove back
void ULListStr::pop_back(){
  
  // check if list empty
  if(tail_ == NULL){
    return;
  }

  // removes back index, move last index back
  tail_->last--;

  // checks if now empty, if so, removes it
  if(tail_->first == tail_->last){
    // temp value to store ptr
    Item* temp = tail_;

    // moves tail ptr to prev item
    tail_ = tail_->prev;
    
    if(tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_ = NULL;
    }
    // delete old head
    delete temp;
  }
  // decrement list size
  size_--;
}

// return last elment, NOT removing
std::string const& ULListStr::back() const{
  // empty list / empty tail exception
  if(tail_ == NULL || tail_->last == tail_->first){
      throw std::out_of_range("No value to remove");
  }
  else{
    // returns last val in tail item
    return tail_->val[tail_->last - 1];
  }
}

// first element, NOT removing
std::string const& ULListStr::front() const{
  if(head_ == NULL || head_->last == tail_->first){
      throw std::out_of_range("No value to remove");
  }
  else{
    // returns first val in head
    return head_->val[head_->first];
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  // checks location bounds
  if(loc < 0 || loc >= size_){
    throw std::out_of_range("No value to remove");
  }

  size_t i = 0;
  Item* currPtr = head_;
  // goes thru list until the right location
  while(i + (currPtr->last - currPtr->first) <= loc){
    i = i + currPtr->last - currPtr-> first;
    currPtr = currPtr->next;
  }

  // moves it to theright location
  size_t nodeIndex = loc - i;

  // reutrns ptr with current location value
  return &currPtr->val[currPtr->first + nodeIndex];
}