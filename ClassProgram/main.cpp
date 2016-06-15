//
//  main.cpp
//  BFS
//
//  Created by Hitesh Arora on 6/09/16.
//  Copyright © 2016 Hitesh Arora. All rights reserved.
//

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::random_shuffle;

//----------------------START of BSTNode Class(Binary Search Tree Node)----------------------//

class BSTNode {
    
public:
    BSTNode     (int newValue);
    void        setLeft  (BSTNode* newLeft);
    BSTNode*    getLeft  () const;
    void        setRight (BSTNode* newRight);
    BSTNode*    getRight () const;
    void        print    () const;
    int         getValue () const;
    
private:
    int         value;
    BSTNode*    left;
    BSTNode*    right;
};

//-----Member Functions of BSTNode Class

BSTNode :: BSTNode (int newValue) {
    value = newValue;
    
    left = 0;
    right = 0;
}// end constructor

void BSTNode :: setLeft (BSTNode * newLeft) {
    
    left = newLeft;
}//end setLeft

BSTNode* BSTNode :: getLeft () const {
    
    return left;
}//end getLeft

void BSTNode :: setRight (BSTNode * newRight) {
    
    right = newRight;
}//end setRight

BSTNode* BSTNode :: getRight () const {
    
    return right;
}//end getRight

void BSTNode :: print () const {
    
    cout<< "(" << ((left == 0)?0:left -> getValue())  <<")";
    cout<<value;
    cout<< "(" << ((right == 0)?0:right -> getValue())<<")";
    cout<<endl;
    
}//end print

int BSTNode :: getValue () const {
    
    return value;
}//end getValue
//----------------------------------END of BSTNode Class-------------------------------------//

//------------------------START of ULLNode Class(Unordered Linked List Node)-----------------//

class ULLNode {
    
public:
    ULLNode     (BSTNode* newValue);
    BSTNode*    getValue  () const;
    //    int         getIntValue ();
    ULLNode*    getNext   () const;
    void        setNext   (ULLNode *newNext);
    void        clearNode ();
    
private:
    BSTNode*    value;
    ULLNode*    next;
};

ULLNode :: ULLNode (BSTNode* newValue) {
    
    value = newValue;
}// end constructor

BSTNode* ULLNode :: getValue () const {
    
    return value;
}// end getValue

ULLNode*  ULLNode :: getNext () const {
    
    return next;
}// end constructor

void ULLNode :: setNext (ULLNode* newNext) {
    
    next = newNext;
}// end setNext

void ULLNode :: clearNode () {
    
    value = 0;
    next = 0;
}// end clearNode
//----------------------------------END of ULLNode Class-------------------------------------//

//--------------------------START of UnorderedLinkedList Class-------------------------------//

class UnorderedLinkedList {
    
public:
    UnorderedLinkedList ();
    bool addAtHead      (BSTNode* newHeadValue);
    bool addAtHead      (int newHeadValue);
    bool addAtTail      (BSTNode* newTailValue);
    bool removeFromHead (BSTNode*& oldHeadValue);
    void print () const;
    ULLNode* getHead() const;
    ULLNode* getTail() const;
    
    //    bool removeFromTail(BSTNode*& oldTailValue); NOT NEEDED NOW
private:
    ULLNode*    head;
    ULLNode*    tail;
};

UnorderedLinkedList :: UnorderedLinkedList () {
    head = 0;
    tail = 0;
    
}// end constructor

bool UnorderedLinkedList :: addAtHead (BSTNode* newHeadValue){
    
    bool success     = true;//assume no failure
    ULLNode* newHead = new ULLNode (newHeadValue);
    
    if (newHead != 0) {
        
        if (head == 0){ //Empty List
            head = newHead;
            tail = newHead;
        }
        else
            newHead -> setNext(head);
        
        head = newHead;
    }// end newHead !=0
    else// newHead == 0 -> allocation failed
        success = false;
    
    return success;
}// end addAtHead

bool UnorderedLinkedList :: addAtTail (BSTNode* newTailValue){
    
    bool success     = true;//assume no failure
    ULLNode* newTail = new ULLNode (newTailValue);
    
    if (newTail != 0) {
        
        if (head == 0){ //Empty List
            head = newTail;
            tail = newTail;
        }
        else
            tail -> setNext (newTail);
        
        tail = newTail;
    }// end newTail != 0
    else// newTail == 0 -> allocation failed
        success = false;
    
    return success;
}//end addAtTail

bool UnorderedLinkedList :: removeFromHead (BSTNode*& oldHeadValue){
    
    bool success = true;//assume no failure
    
    if (head != 0) {
        
        oldHeadValue = head -> getValue ();
        ULLNode* toBeDeleted = head;
        head = head -> getNext ();
        //        cout<<"Value parsed:"<<oldHeadValue->getValue()<<endl;
        //        toBeDeleted->setValue(0);
        toBeDeleted -> setNext (0);
        delete toBeDeleted;
    }// end head != 0
    else// head == 0
        success = false;
    
    return success;
}//end RemoveFromHead

void UnorderedLinkedList :: print () const {
    
    
    
    //    cout<< "(" << ((left == 0)?0:left -> getValue())  <<")";
    //    cout<<value;
    //    cout<< "(" << ((right == 0)?0:right -> getValue())<<")";
    //    cout<<endl;
    
    
    
    if (head != 0) {
        BSTNode *nodeHead = head -> getValue ();
        cout<< "Head -->" << ((head == 0)?0:nodeHead->getValue());
    }
    cout<<endl;
    if (tail != 0) {
        BSTNode *nodeTail = tail -> getValue ();
        cout<< "Tail -->" << ((tail == 0)?0:nodeTail->getValue());
    }
    cout<<endl;
    
}//end print

ULLNode* UnorderedLinkedList :: getHead() const{
    return head;
}//return Head of the list

ULLNode* UnorderedLinkedList :: getTail() const{
    return tail;
}//return Tail of the list

//-----------------------------END of UnorderedLinkedList Class------------------------------//

//-----------------------------START of Stack Class------------------------------------------//

class Stack : public UnorderedLinkedList{//is-a relationship
public:
    
    bool push (BSTNode*  newHeadValue);
    bool pop  (BSTNode*& oldHeadValue);
};

bool Stack :: push (BSTNode* newHeadValue){
    
    return addAtHead (newHeadValue);
    //    callAtHead
}// end Push to stack

bool Stack :: pop (BSTNode*& oldHeadValue){
    
    return removeFromHead (oldHeadValue);
}// end Pop from stack
//----------------------------------END of Stack Class---------------------------------------//

//-----------------------------START of Queue Class------------------------------------------//

class Queue : public UnorderedLinkedList{
    
public:
    
    bool add     (BSTNode*  newTailValue);
    bool remove  (BSTNode*& oldTailValue);
};

bool Queue :: add (BSTNode* newTailValue){
    
    return addAtTail (newTailValue);
}// end add to queue

bool Queue :: remove (BSTNode*& oldTailValue){
    
    return removeFromHead (oldTailValue);
}// end remove from queue
//----------------------------------END of Queue Class---------------------------------------//

//-----------------------------START of BinarySearchTree Class-------------------------------//

class BinarySearchTree{
    
public:
    BinarySearchTree ();
    bool add (int newValue);
    int depthFirstTraversal (int number) const;
    int breadthFirstTraversal (int number) const;
    BSTNode* getBSTNodeFromQueue (Queue queue) const;
private:
    BSTNode* root;
};

BinarySearchTree :: BinarySearchTree () {
    
    root = 0;
}// end constructor

bool BinarySearchTree :: add (int newValue) {
    
    bool success    = true;//assume no failure
    BSTNode* newAdd = new BSTNode(newValue);
    
    if (newAdd != 0) {
        
        BSTNode* current  = root;
        BSTNode* previous = 0;
        
        while (current != 0) {
            
            previous = current;
            
            if (newAdd -> getValue () < current -> getValue ()){
                current = current -> getLeft();
            }
            else{
                current = current -> getRight();
            }
            
        }// end while current != 0
        
        
        if (previous !=0) {
            if (newAdd -> getValue () < previous -> getValue ())
                previous -> setLeft (newAdd);
            else
                previous -> setRight (newAdd);
        }// end previous != 0
        else{// previous == 0
            root = newAdd;
            current = 0;
        }
        
        
    }// end newAdd !=0
    else// newAdd == 0 -> allocation failed
        success = false;
    
    return success;
}// end add


int BinarySearchTree :: depthFirstTraversal (int number) const {
    
    Stack s1, s2;
    int count = 0;
    BSTNode* current = root;
    s1.push(current);
    
    
    while (s1.pop(current)) {
        if (current -> getLeft () != 0)
            s1.push(current ->getLeft());
        
        if (current -> getRight () != 0)
            s1.push(current->getRight());
        s2.push(current);
    }//loop to
    
    if (current) {
        while (s2.pop(current)) {
            if (current ->getValue() == number) {
                return count;
            }
            count++;
        }
    }//check if current contains any memory or not
    return count;
}// end depthFirstTraversal

int BinarySearchTree :: breadthFirstTraversal (int number) const {
    
    Queue queue;
    BSTNode* current = root;
    queue.add(root);
    int count = 0;
    if (current) {
        while (queue.removeFromHead(current)) {
            if (current->getValue() == number)
                return count;
            
            //If there is right child, add it to queue
            if (current -> getLeft() != 0)
                queue.add(current -> getLeft());
            
            //If there is right child, add it to queue
            if (current -> getRight() != 0)
                queue.add(current -> getRight());
            
            count++;
        }
    }
    
    return count;
}// end breadthFirstTraversal


BSTNode* BinarySearchTree :: getBSTNodeFromQueue (Queue queue) const {
    BSTNode* bSTNode = NULL;
    UnorderedLinkedList obj = queue;
    ULLNode *uLLnode = obj.getHead();
    if (uLLnode != NULL) {
        bSTNode =  uLLnode->getValue();
    }
    return bSTNode;
}// end fetching head node from Queue


int * storeRandomNumbersInArray(int array[]);

int * storeRandomNumbersInArray(int array[]){
    for (int i = 1; i<= 1000; i++) {
        array[i] = i;
    }
    random_shuffle(array, array + 1001);
    return array;
}//end storeRandomNumbersInArray function


//-----------------------------END of BinarySearchTree Class---------------------------------//
// START of Main-----
int main(int argc, const char * argv[]) {
    
    int arr[1000];
    arr[1000] = *storeRandomNumbersInArray(arr);
    
    
    //    int numberToSeed = 0;
    //    cout<<"Enter random number to seed:\n";
    //    cin>>numberToSeed;
    
    BinarySearchTree tree;
    
    //add array of random numbers to Binary Search Tree.
    for (int i = 0; i<1000; i++) {
        tree.add (arr[i]);
    }
    
    
    cout<<"i    BFS    DFS\n";
    for (int i = 1; i <= 10; i++) {
        int bfsNodeCount = tree.breadthFirstTraversal (i*100);
        int dfsNodeCount = tree.depthFirstTraversal (i*100);
        cout<<i<<"    "<<bfsNodeCount<<"    "<<dfsNodeCount<<endl;
    }
    
    return 0;
}//end main
