#ifndef __DLL_H__
#define __DLL_H__

#include "exceptions.h"

template <typename T>
class DllNode {
public:
    T value;
    DllNode *prev;
    DllNode *next;
};

template <typename T>
class Dll {
private:
    DllNode<T> *firstNode;
    DllNode<T> *lastNode;
    int length = 0;
public:
        Dll(){
            firstNode = new DllNode<T>;
            lastNode = new DllNode<T>;
            firstNode->next = lastNode;
            lastNode->prev = firstNode;
    } // create an empty list
    Dll(const Dll &src){
        firstNode = new DllNode<T>;
        lastNode = new DllNode<T>;
        firstNode->next = lastNode;
        lastNode->prev = firstNode;
        DllNode<T> *ptrNode = src.firstNode;
        for(int i = 0; i<src.size(); i++)
        {
            ptrNode = ptrNode->next;
            insert(i, ptrNode->value);
        }
    } // create a deep copy of the src list
    Dll(const T arr[], int size){
        firstNode = new DllNode<T>;
        lastNode = new DllNode<T>;
        firstNode->next = lastNode;
        lastNode->prev = firstNode;
        for(int i = 0; i<size; i++)
        {
            insert(i, arr[i]);
        }
    } // create a linked list containing the elements of the array
    Dll &operator=(const Dll &src){
        clear();
        DllNode<T> *ptrNode = src.firstNode;
        for(int i = 0; i<src.size(); i++)
        {
            ptrNode = ptrNode->next;
            insert(i, ptrNode->value);
        }
        return *this;
    } // create a deep copy of the src list
    ~Dll(){
        clear();
        delete firstNode;
        delete lastNode;
    } // free all memory

    bool empty() const{
        return (length==0);
    } // return if the list is empty in O(1)
    int size() const{
            return length;
    } // return how many items are in the list in O(1)

    T &at(int rank){
        if(rank>=length || rank < 0)
        {
            throw new IndexOutOfRangeException("at(): Index was outside the bounds of the linked list.", rank);
        }
        DllNode<T> *ptrNode = firstNode;
        for(int i = 0; i<=rank; i++)
        {
            ptrNode = ptrNode->next;
        }
        return ptrNode->value;
    } // return a reference to the value of the list at a rank/index
    void insert(int rank, T value){
        if(rank>length || rank < 0)
        {
            throw new IndexOutOfRangeException("insert(): Index was outside the bounds of the linked list.", rank);
        }
        
        DllNode<T> *ptrNode = firstNode;
        if (length == rank){
            ptrNode = lastNode->prev;
        }
        else {
            for(int i = 0; i<rank; i++)
            {
              ptrNode = ptrNode->next;
            }
        }
        DllNode<T> *newNode = new DllNode<T>;
        newNode->value = value;
        newNode->next = ptrNode->next;
        ptrNode->next = newNode;
        (newNode->next)->prev = newNode;
        newNode->prev = ptrNode;
        length++;
    } // insert a value at the rank/index
    T remove(int rank){
        if(rank>=length || rank < 0)
        {
            throw new IndexOutOfRangeException("remove(): Index was outside the bounds of the linked list.", rank);
        }
        DllNode<T> *ptrNode = firstNode;
        for(int i = 0; i<=rank; i++)
        {
            ptrNode = ptrNode->next;
        }
        (ptrNode->prev)->next = ptrNode->next;
        (ptrNode->next)->prev = ptrNode->prev;
        T val = ptrNode->value;
        delete ptrNode;
        length--;

        return val;
    } // remove the node at the rank/index and return its value

    void clear(){
        while(!empty()){
            remove(0);
        }
    } // reset the list to an empty list
    void display(ostream &os) const{
        DllNode<T> *ptrNode = firstNode;
        os << "[ ";
        for(int i = 0; i<length; i++)
        {
            ptrNode = ptrNode->next;
            os << ptrNode->value << " ";
        }
        os << "]";
    } // write the contents of the list to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Dll<T> &list){
    list.display(os);
    return os;
} // write the contents of the list to the ostream

#endif
