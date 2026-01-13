/*

Header file for single linked list class library

*/
#ifndef SLIST_H
#define SLIST_H
#include <sstream>
#include <iostream>
using namespace std;

template <typename T>
struct Node { 
    T data; 
    Node<T>* nxt; 

    Node(T d);


};

template <typename T>
class LinkedList{


    public:
    Node<T>* head;

        LinkedList() {
            Node<T> iNode = new Node<T>()
=
        }
    
        // add(value)				//Adds a new value to the end of this list.

        // clear()					//Removes all elements from this list.

        void clear();
        void add (T x);

        // equals(list)				//Returns true if the two lists contain the same elements in the same order.
        bool equals(LinkedList<T> &list);

        //get(index)				//Returns the element at the specified index in this list.

        T get(int idx);


        //insert(index, value)		//Inserts the element into this list before the specified index.

        void insert(int idx, T value);

        //exchg(index1, index2)		//Switches the payload data of specified indexex.

        void exchg(int idx1,int idx2);

        //swap(index1,index2)		//Swaps node located at index1 with node at index2

        void swap(int idx1,int idx2);

        // isEmpty()				//Returns true if this list contains no elements.

        bool isEmpty();

        // DO NOT IMPLEMENT.   FYI mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

        // remove(index)			//Removes the element at the specified index from this list.

        void remove(int idx);

        // set(index, value)		//Replaces the element at the specified index in this list with a new value.

        void set(int idx);

        // size()					//Returns the number of elements in this list.

        int size();

        // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

        Node<T> subList(int start, int length);

        // toString()				//Converts the list to a printable string representation.
        std::string toString();

};

/*

Class Library File

*/

template <typename T>
Node<T>::Node(T d){
    data = d;
    nxt = nullptr;
}


template <typename T>
void LinkedList<T>::clear() {
    Node<T>* cNode = head;
    Node<T>* nNode;

    

    while(cNode != nullptr){
        nNode = cNode->nxt;
        delete cNode;
        cNode=nNode;
    }

    head = nullptr; 
}

template <typename T>
void LinkedList<T>::add (T node) {
    Node<T>* nNode = new Node(node);
    Node<T>* cNode = this->head;
    
    while (cNode->nxt != nullptr) {
        cNode = cNode->nxt;
    }

    cNode->nxt = node;

}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
template <typename T>
bool  LinkedList<T>::equals(LinkedList<T> &list) {
    Node<T>* cNode = head;
    Node<T>* oNode = list.head;
    bool equals = true;
    while(cNode->nxt != nullptr) {
        if (oNode->nxt ==nullptr){
            return false;
        }
        if(!(cNode->nxt->T == oNode->nxt->T)) {
            return false;
        }
        cNode = cNode->nxt;
        oNode = oNode->nxt; 
    }
    cNode = head;
    oNode = list.head;
    while(oNode->nxt != nullptr) {
        if (cNode->nxt ==nullptr){
            return false;
        }
        if(!(oNode->nxt->T == cNode->nxt->T)) {
            return false;
        }
        oNode = cNode->nxt;
        cNode = cNode->nxt; 
    }


    return true;


}

//get(index)				//Returns the element at the specified index in this list.
template <typename T>
T LinkedList<T>::get(int idx){
    Node<T>*cNode = head;
    int itt = 0;
    while (cNode !=nullptr) {
        if(idx == itt) {
            return *cNode;
        }
        itt++;
    }
    return cNode->T;

}


//insert(index, value)		//Inserts the element into this list before the specified index.
template <typename T>
void LinkedList<T>::insert (int idx, T value) {
    Node<T>* nNode = new Node(value);
    Node<T>* tmpNode = new Node(value);
    Node<T>* cNode = this->head;
    int itt = 0;
    while (cNode->nxt != nullptr) {
        if(idx == (itt++ -1) ) {
            tmpNode = cNode->nxt;
            cNode->nxt = value;
            cNode->nxt->nxt = tmpNode;
            return;
        }
        cNode = cNode->nxt;

    }


}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
template <typename T>
void exchg(int idx1,int idx2);

//swap(index1,index2)		//Swaps node located at index1 with node at index2
template <typename T>
void LinkedList<T>::swap(int idx1,int idx2){
    if (idx1 == idx2) return;
    
    int temp = idx1;
    idx1 = idx2;
    idx2 = temp;
    
    
    Node<T>* prevA = nullptr;
    Node<T>* a = head;
    int itt = 0;
    while (a != nullptr && itt < idx1) {
        prevA = a;
        a = a->nxt;
        itt++;
    }
    
    Node<T>* prevB = a;
    Node<T>* b = a;
    while (b != nullptr && itt < idx2) {
        prevB = b;
        b = b->nxt;
        itt++;
    }
    
    if (a == nullptr || b == nullptr) return;
    
    if (a->nxt == b) {
        a->nxt = b->nxt;
        b->nxt = a;
    } else {
        Node<T>* temp = a->nxt;
        a->nxt = b->nxt;
        b->nxt = temp;
        prevB->nxt = a;
    }
    
    if (prevA == nullptr) {
        head = b;
    } else {
        prevA->nxt = b;
    }
}

// isEmpty()				//Returns true if this list contains no elements.
template <typename T>
bool LinkedList<T>::isEmpty(){
    return head==nullptr;
}

// DO NOT IMPLEMENT.   FYI mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

// remove(index)			//Removes the element at the specified index from this list.
template <typename T>
void LinkedList<T>::remove(int idx){
    if (head == nullptr) return;
    if (idx == 0) {
        Node<T>* temp = head;
        head = head->nxt;
        delete temp;
        return;
    }
    
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    int itt = 0;
    
    while (current != nullptr && itt < idx) {
        prev = current;
        itt++;
    }
    
    if (current == nullptr) return;
    
    prev->nxt = current->nxt;
    delete current;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
template <typename T>
void set(int idx);

// size()					//Returns the number of elements in this list.
template <typename T>
int LinkedList<T>::size(){
    Node<T>* cNode = head;
    int itt = 0;
    while (cNode !=nullptr) {
        itt++;
    }
    return itt;

}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
template <typename T>
Node<T> subList(int start, int length);

// toString()				//Converts the list to a printable string representation.
template <typename T>
std::string  LinkedList<T>::toString() { 
    stringstream ss; 
    Node<T>* cNode = head;
    while(cNode != nullptr) { 
        ss << cNode->data;
    }

    return ss.str();
}


template <typename T>
void LinkedList<T>::exchg(int idx1, int idx2){
    Node<T>* aNode = get(idx1);
    Node<T>* bNode = get (idx2);

    T tmpData = aNode->T;
    aNode->T = bNode->T;
    bNode->T = aNode->T;

}
// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.


//get(index)				//Returns the element at the specified index in this list.


//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.

#endif