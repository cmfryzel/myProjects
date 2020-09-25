#ifndef __STACK_H__
#define __STACK_H__

#include "exceptions.h"
#include "dll.h"

template <typename T>
class Stack {
private:
    Dll<T> stack;
public:
    Stack(){
      stack = Dll<T>();  
    } // create an empty stack
    void push(T value){
        stack.insert(0, value);
    } // add an item to the top of the stack
    T pop(){
        if(stack.empty())
        {
            throw InvalidOperationException("Stack empty.");
        }
        return stack.remove(0);
    } // remove of the value at the top of the stack and return its value
    T peek(){
        if(stack.empty())
        {
            throw InvalidOperationException("Stack empty.");
        }
        return stack.at(0);
    } // return the value at the top of the stack, keeping it in the stack
    int size() const{
        return stack.size();
    } // return how many items are in the stack
    bool empty() const{
        return (stack.empty());
    } // return if the stack is empty
    void display(ostream &os) const{
        stack.display(os);
    } // write the contents of the stack to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Stack<T> &stack){
    stack.display(os);
    return os;
} // write the contents of the stack to the ostream

#endif
