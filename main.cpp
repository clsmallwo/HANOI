
//Smoke Test - provided to give you a quick check of your stack code
#include "Stack.h"
#include <iostream>

using namespace std;

// int main() {
//     Stack myStack;
//     myStack.push(10);
//     myStack.push(20);
//     myStack.push(30);
//     cout << "Top element: " << myStack.peek() << endl; // Outputs 30
//     myStack.pop();
//     myStack.display(); // Displays: 20 10
//     return 0;
// }

bool diskAbove(Stack &stack) {
  int top = stack.pop();
  bool result = !stack.isEmpty();
  stack.push(top);
  return result;
  
}

void solveTowersOfHanoi(int n, Stack &source, Stack &destination, Stack &auxiliary) {
  if (n==1) {
    int me = source.pop(); 
    destination.push(me);
    return; 
  }
  //Is there a disk above me?
  if(diskAbove(source)){
    solveTowersOfHanoi(n-1, source, auxiliary, destination);
  }

  int me = source.pop(); //I am at the top already so I can move
  destination.push(me);
  solveTowersOfHanoi(n-1, auxiliary, destination, source);



  //OKsay so about me: I need to move!!!

}

void solveTowersOfHanoi(int n) {
  //Yeah so we start with three towners
  Stack t1;
  Stack t2;
  Stack t3;

  //Then we like put the right about of disk on the first one
  for (int i = n; i > 0; i--){
    t1.push(i);
  } 

  cout << "Inital Conf: \n";
  t1.display();
  t2.display();
  t3.display();

  //Goal: get bottommost disk to t3

  solveTowersOfHanoi(n, t1, t3, t2);

  cout << "\n Final Conf: \n";
  t1.display();
  t2.display();
  t3.display();

  

}

// // Use this main.
int main() {
  int n; // Number of disks
  cout << "Enter the number of disks: ";
  cin >> n;
  if (n <= 0) {
    cout << "Number of disks must be greater than 0." << endl;
    return 1;
  }
  cout << "Steps to solve the Towers of Hanoi:" << endl;
  solveTowersOfHanoi(n);
  return 0;
}
// //* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
