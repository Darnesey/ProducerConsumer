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
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>


using namespace std;

/*
 * 
 */

void *sayHi(void *id){
   long tid;
   tid = (long)id;
   
    cout << "Hi thread " << tid << "!" << endl;
    pthread_exit(NULL);
}


int main(int argc, char** argv) {

    cout << "Heeloooo...." << endl;
    
    Node first(1);
    Node* pointer = &first;
    Node second(2);
    Node third(3);
    
    LinkedList list(pointer);
    pointer = &second;
    list.add(&second);
    list.add(&third);
    
    list.printList();
    
    cout << "Linkage complete\n" << endl;
    list.remove(1);
    list.printListBackwards();
    
    int er;
    int i;
    for(i = 0; i < 5; i++) {
        pthread_t threads[5];
        er = pthread_create(&threads[i], NULL, sayHi, (void *)(uintptr_t)i);
        usleep(0.01);
        if (er){
            cout << "THREAD BUILD ERROR," << er << endl;
            exit(-1);
        }
    }
    
    //list.sayHi(10);
    
    return 0;
}

