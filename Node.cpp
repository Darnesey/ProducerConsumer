/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
    
public:
    Node(string value){
        this->value = value;
    }
    Node(string value, Node* next) : value(value), next(next)
    {    
    }
    string getValue(){
        return value;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* next){
        this->next = next;
    }
    
    
    
private:
    string value;
    Node* next = NULL;
    
    
};