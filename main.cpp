/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: James Hunter
 *
 * Created on October 23, 2016, 6:55 PM
 */

#include <cstdlib>
#include <iostream>
#include "LinkedList.cpp"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "Heeloooo...." << endl;
    
    Node first("Ryan");
    Node* pointer = &first;
    Node second("James");
    Node third("Darnell");
    
    LinkedList list(pointer);
    pointer = &second;
    list.add(&second);
    list.add(&third);
    
    list.printList();
    
    cout << "Linkage complete\n" << endl;
    
    list.printListBackwards();
//    cout << list.getHead().getNext().getValue() << endl;
//    cout << list.getHead().getNext().getNext().getValue() << endl;
    list.sayHi();
    
    return 0;
}

