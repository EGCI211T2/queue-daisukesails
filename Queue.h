#ifndef queue_h
#define queue_h
#include "Node.h"

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

void Queue::enqueue(int x){
    NodePtr new_node = new NODE(x);
    if(new_node != NULL){ 
        if(size == 0) 
            headPtr = new_node;
        else 
            tailPtr->set_next(new_node);

        tailPtr = new_node;
        size++;
    }
    else 
        cout << "Out of memory." << endl;
}

int Queue::dequeue(){
    if(size > 0){
        NodePtr t = headPtr;
        headPtr = headPtr->get_next();
        size--;

        if(size == 0) 
            tailPtr = NULL;

        delete t;
        return 1;
    }
    else{
        cout << "Empty Queue" << endl;
        return -1;
    }
}

Queue::Queue(){
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
}

Queue::~Queue(){
    cout << "Dequeue all" << endl;
    while(size > 0) dequeue();
}

#endif