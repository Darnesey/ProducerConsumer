/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadProtection.h
 * Author: James Hunter
 *
 * Created on October 24, 2016, 7:22 PM
 */

#ifndef THREADPROTECTION_H
#define THREADPROTECTION_H

class ThreadProtection {
public:
    ThreadProtection();
    ThreadProtection(const ThreadProtection& orig);
    virtual ~LinkedList();
    
private:
    int s;
    int delay;
    LinkedList* link;
    
        
};

#endif /* THREADPROTECTION_H */

