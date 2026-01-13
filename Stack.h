#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
  int data;
  Node *next;
};
class Stack {
private:
  Node *top;

public:
  Stack();
  ~Stack();
  void push(int newData);
  int pop();
  int peek() const;
  bool isEmpty() const;
  void display(); // Displays the stack contents
  
  // <<<< Your code here >>>>
  
};
#endif // STACK_