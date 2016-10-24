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
        }
        
        void setHead(Node* head){
            this->head = head;
        }
        
        Node* getHead() {
            return head;
        }
        
        void add(Node* newNode){
            //check for NULL head
            if (head == NULL) {
                setHead(newNode);
                return;
            }
            Node* current_p = head;
            while (current_p->getNext() != NULL){
                current_p = current_p->getNext();
            }
            //reached the end
            //add newNode
            current_p->setNext(newNode);
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
        
        void sayHi() {
            cout << "Hi" << endl;
        }
        
        
        
    private:
        string name;
        Node* head = NULL;
};