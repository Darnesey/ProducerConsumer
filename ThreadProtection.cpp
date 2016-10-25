
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "LinkedList.cpp"
#include <pthread.h>
#include <stdint.h>

using namespace std;

void *method(void *in) {
    cout << "it works" << endl;
}

class ThreadProtection {
    
public:
    ThreadProtection(LinkedList* linklist){
        list = linklist;
        s = 1;
        delay = 0;
        
        pthread_t prod1;
        pthread_t prod2;
        pthread_t cons1;
        pthread_t cons2;
    
        int odd = 1;
        int even = 0;
        pthread_create(&prod1, NULL, method, (void *)0);
        pthread_create(&prod2, NULL, producer, (void *)(uintptr_t)even);
        pthread_create(&cons1, NULL, consumer, (void *)(uintptr_t)odd);
//        pthread_create(&cons2, NULL, consumer, (void *)(uintptr_t)even);
        
    }
    
    static void *producer(void *id) {
        long mod;
        mod = (long) id;
        while(true) {
        //segWait(s)
        segWaitS();
        // produce stuff
        Node* newNode = new Node(mod, mod);
        list->add(newNode);
        list->printList();
        //segSignalDelay
        segSignalDelay();
        //segSignal S
        segSignalS();
        }
    }
    void producer1(void *id) {
        
        while(true) {
        //segWait(s)
        segWaitS();
        // produce stuff
        Node* newNode = new Node(1, 1);
        list->add(newNode);
        list->printList();
        //segSignalDelay
        segSignalDelay();
        //segSignal S
        segSignalS();
        }
    }
    
    static void *consumer(void *id) {
        long mod;
        mod = (long) id;
        while(true) {
        //semWait Delay
        segWaitDelay(delay);
        //semWait S
        segWaitS();
        //consume
        list->removeFirstMod(mod);
        list->printList();
        //semSignal S
        segSignalS();
        }
    }
    
    static void segWaitS() {
        while (s == 0){
            /* do nothing */
        }
    }
    static void segWaitDelay(int oldDelay) {
        while (delay == oldDelay) {
            /* do nothing */
        }
    }
    
    static void segSignalS(){
        s = (s + 1) % 2;
    }
    static void segSignalDelay() {
        delay = (delay + 1) % 2;
    }
    
    
private:
    static int s;
    static int delay;
    static LinkedList* list;
    
    
};