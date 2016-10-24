/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sys/time.h>

using namespace std;

class Node {
    
public:
    Node(int value){
        srand(time(NULL) + value);
        this->value = rand() % 40;
    }
    Node(int value, int mod){
        srand(time(NULL) + value);
        this->value = 2 * (rand() % 20) + mod;
    }
    Node(int value, Node* next) : value(value), next(next)
    {    
    }
    int getValue(){
        return value;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* next){
        this->next = next;
    }
    Node* getPrev(){
        return prev;
    }
    void setPrev(Node* prev) {
        this->prev = prev;
    }
    
    
    
private:
    int value;
    Node* next = NULL;
    Node* prev = NULL;
    
    
};