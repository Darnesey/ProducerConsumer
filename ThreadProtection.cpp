
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "LinkedList.cpp"
#include <pthread.h>
#include <stdint.h>

using namespace std;


class ThreadProtection {
    
public:
    ThreadProtection(LinkedList* linklist){
        
    }
    
    static void startThreads(LinkedList* linklist) {
        list = linklist;
        s = 1;
        delay = 0;
        
        pthread_t prod1;
        pthread_t prod2;
        pthread_t cons1;
        pthread_t cons2;
    
        int odd = 1;
        int even = 0;
        pthread_create(&prod1, NULL, producer, (void *)1);
        //pthread_create(&prod2, NULL, producer, (void *)0);
        pthread_create(&cons1, NULL, consumer, (void *)1);
        //pthread_create(&cons2, NULL, consumer, (void *)0);
        
    }
    
    static void *producer(void *id) {
        long mod;
        mod = (long) id;
        int num = 500;
        while(num > 0) {
        //segWait(s)
        segWaitS();
        // produce stuff
        Node* newNode = new Node(mod, mod);
        list->add(newNode);
        cout << "Added New Node" << endl;
        list->printList();
        //segSignalDelay
        segSignalDelay();
        //segSignal S
        segSignalS();
        usleep(0.1);
        num--;
        }
        pthread_exit(NULL);
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
        cout << "Removed a node" << endl;
        list->printList();
        //semSignal S
        segSignalS();
        usleep(0.1);
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
