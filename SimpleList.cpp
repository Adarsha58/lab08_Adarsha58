#include "SimpleList.h"
#include <iostream>
#include <string>
using namespace std;
template<class T>

void destroy(T element) {
	// do nothing
}

template <class T>
void destroy(T* element) {
	// delete the pointer type
	delete element;
}

template<class T>
SimpleList<T>::SimpleList(){
    numElements = 0;
    elements = new T[CAPACITY];
}

template<class T>
SimpleList<T>:: ~SimpleList(){
    delete [] elements;
}

template<class T>
T SimpleList<T>:: at(int index) const throw (InvalidIndexException){
    if(index >= numElements || index < 0) throw InvalidIndexException();
    return elements[index];
}

template<class T>
bool SimpleList<T>:: empty() const{
    if(numElements == 0) return true;
    return false;
}

template<class T>
T SimpleList<T>:: first() const throw (EmptyListException){
    if(numElements == 0) throw EmptyListException();
    return elements[0];
}

template<class T>
T SimpleList<T>:: last() const throw (EmptyListException){
    if(numElements == 0) throw EmptyListException();
    return elements[numElements-1];
}

template<class T>
int SimpleList<T>:: getNumElements() const{
    return numElements;
}

template<class T>
void SimpleList<T>:: insert(T item) throw (FullListException){
    if(numElements == CAPACITY) throw FullListException();
    elements[numElements++] = item;
}

template<class T>
void SimpleList<T>:: remove(int index) throw(InvalidIndexException, EmptyListException){
    if(numElements == 0) throw EmptyListException();
    if(index >= numElements || index < 0) throw InvalidIndexException();
    for(int i = index; i < numElements -1; i++){
       elements[i] = elements[i+1];
    }
    numElements--;
    if (is_pointer<T>::value) 
        destroy (elements[numElements]);
    else
        destroy (elements[numElements]);
}
