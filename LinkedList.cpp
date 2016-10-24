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
            cout << "Hi thread ," << id << "!" << endl;
        }
        
        
        
    private:
        string name;
        Node* head = NULL;
        Node* tail = NULL;
};