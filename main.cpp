
//Smoke Test - provided to give you a quick check of your stack code
#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Top element: " << myStack.peek() << endl; // Outputs 30
    myStack.pop();
    myStack.display(); // Displays: 20 10
    return 0;
}


void moveD(int disk,, Stack &nTower){

}

// <<<< YOUR solveTowersOfHanoi(n) GOES HERE >>>>
void solveTowersOfHanoi(int n) {
  Stack t1;
  Stack t2;
  Stack t3;


  t1.push(3);
  t1.push(2);
  t1.push(1);


  moveD(3, t3);

  

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
 // solveTowersOfHanoi(n);
  return 0;
}
// //* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
