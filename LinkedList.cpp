/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "Node.cpp"

using namespace std;

class LinkedList {
    
    public:
        
        LinkedList(Node* head)
        {
            this->head = head;
            this->tail = head;
            size = 1;
            //initialize to 3
            while (size < 3) {
                Node* next = new Node(size);
                add(next);
            }
            
        }
        
        void setHead(Node* head){
            this->head = head;
        }
        
        void setTail(Node* tail) {
            this->tail = tail;
        }
        
        Node* getHead() {
            return head;
        }
        
        Node* getTail() {
            return tail;
        }
        
        void add(Node* newNode){
            //check for NULL head
            if (head == NULL) {
                setHead(newNode);
                setTail(newNode);
                return;
            } else if (size >= 20) {
                //Linked List full
                cout << "Linked List full" << endl;
                return;
            }
            Node* current_p = head;
            while (current_p->getNext() != NULL){
                current_p = current_p->getNext();
            }
            //reached the end
            //add newNode
            current_p->setNext(newNode);
            newNode->setPrev(current_p);
            //set as tail
            setTail(newNode);
            
            //increment size
            size++;
        }
        
        void remove(int value) {
            if (head == NULL) {
                cout << "The list is empty. Remove execution aborted" << endl;
                return;
            }
            cout << "Attempting to remove " << value << endl;
            Node* current_p = head;
            while (current_p != NULL){
                // look for id!
                if (current_p->getValue() == value){
                    cout << "Found " << value << ". Removing..." << endl;
                    if (current_p == head) {
                        head = current_p->getNext();
                        head->setPrev(NULL);
                    } else if (current_p == tail) {
                        tail = current_p->getPrev();
                        tail->setNext(NULL);
                    } else {
                        current_p->getPrev()->setNext(current_p->getNext());
                        current_p->getNext()->setPrev(current_p->getPrev());
                    }
                    current_p = NULL;
                    return;
                }
                current_p = current_p->getNext();
            }
            //if code reaches here, element not found
            cout << "No node with value: " << value << " found" << endl;
        }
        
        void removeFirstMod(int mod) {
            if (head == NULL) {
                cout << "The list is empy. Remove execution aborted" << endl;
                return;
            }
            cout << "Attempting to remove number" << endl;
            Node* current_p = head;
            while (current_p != NULL){
                // look for id!
                if (current_p->getValue() % 2 == mod){ //universal operation for odd vs even
                    cout << "Found " << current_p->getValue() << ". Removing..." << endl;
                    if (current_p == head) {
                        head = current_p->getNext();
                        head->setPrev(NULL);
                    } else if (current_p == tail) {
                        tail = current_p->getPrev();
                        tail->setNext(NULL);
                    } else {
                        current_p->getPrev()->setNext(current_p->getNext());
                        current_p->getNext()->setPrev(current_p->getPrev());
                    }
                    current_p = NULL;
                    return;
                }
                current_p = current_p->getNext();
            }
            cout << "No node with value matching parameters found" << endl;
        }
        
       
        
        void printList(){
            //check for NULL head
            if (head == NULL) {
                cout << "The list is empty" << endl;
                return;
            }
            cout << "List Contents:" << endl;
            Node* current_p = head;
            while (current_p != NULL){
                cout << current_p->getValue() << endl;
                current_p = current_p->getNext();
            }
        }
        
        void printListBackwards(){ 
            //check for NULL tail
            if (tail == NULL) {
                cout << "The list is empty" << endl;
                return;
            }
            cout << "List Contents:" << endl;
            Node* current_p = tail;
            while (current_p != NULL){
                cout << current_p->getValue() << endl;
                current_p = current_p->getPrev();
            }
        }
        
        void *sayHi(int *id) {
            long tid;
            tid = (long)id;

             cout << "Hi thread " << tid << "!" << endl;
             pthread_exit(NULL);
        }
        
        
        
    private:
        string name;
        Node* head = NULL;
        Node* tail = NULL;
        int size;
};