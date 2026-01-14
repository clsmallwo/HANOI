#include "Stack.h"

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack() {

}

void Stack::push(int newData ){
    Node* nNode = new Node();
    nNode->next = top;
    nNode->data = newData;
    top = nNode;
}

int Stack::pop(){
    if (nullptr == top) return -1;

    Node* tmp = top;
    top = top->next;

    int data = tmp->data;

    delete tmp;
    return data;

}

int Stack::peek() const {
   return top->data;
}

bool Stack::isEmpty() const {
    return (top == nullptr);
}

void Stack::display() {
    cout << "\nSTACK:";
    Node* curr = top;
    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next; 
    }    
}