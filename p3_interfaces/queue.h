#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "exceptions.h"
#include "dll.h"

template <typename T>
class Queue {
private:
    Dll<T> que;
public:
    Queue(){
        que = Dll<T>();
    } // create an empty queue
    void enqueue(T value){
        que.insert(que.size(), value);
    } // add an item to the front of the queue
    T dequeue(){
        if(que.empty())
        {
            throw InvalidOperationException("Queue empty.");
        }
        return que.remove(0);
    } // remove the value at the front of the queue and return its value 
    T peek(){
        if(que.empty())
        {
            throw InvalidOperationException("Queue empty.");
        }
        return que.at(0);
    } // return the value at the front of the queue, keeping it in the queue
    int size() const{
        return que.size();
    } // return how many items are in the queue
    bool empty() const{
        return (que.empty());
    } // return if the queue is empty
    void display(ostream &os) const{
        que.display(os);
    } // write the contents of the queue to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Queue<T> &queue){
    queue.display(os);
    return os;
} // write the contents of the queue to the ostream

#endif
