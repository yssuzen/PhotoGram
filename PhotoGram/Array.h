
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		bool add(T);
		bool remove(int);
		//int get(int index);
		T& operator[](int);
		const T& operator[](int) const;
		Array<T>& operator+=(T);
		Array<T>& operator-=(T);
		void clear();
		int size() const;
		bool isFull();
	
	private:
		int numElements;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
bool Array<T>::add(T t){
	if (numElements >= MAX_ARRAY)   return false;
  	elements[numElements++] = t;
	return true;

}

template <class T>
bool Array<T>::remove(int index){
	if (index < 0 || index >= numElements) return false;
	delete elements[index];
	for (int i = index; i < numElements - 1; i++) {
		elements[i] = elements[i + 1];
	}
	numElements--;
	return true;
}
// bool Array<T>::remove(T t){
// 	int index = 0;
// 	while (index < numElements){
// 		if (t == elements[index]){
// 			--numElements;
// 			break;
// 		}
// 		++index;
// 	}

// 	while (index < numElements){
// 		elements[index] = elements[index + 1];
// 		++index;
// 	}
// }

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull(){
	return numElements >= MAX_ARRAY;
}

// template <class T>
// int Array<T>::get(int index){
// 	if (index < 0 || index >= numElements) {
// 		cerr<<"Array index out of bounds"<<endl;
// 		exit(1);
// 	}
// 	return elements[index];
// }

template <class T>
T& Array<T>::operator[](int t){
	if(t < 0 || t >= numElements){
		cerr<<"Index out of bounds"<<endl;
		exit(1);
	}
	return elements[t];
}

template <class T>
const T& Array<T>::operator[](int t) const{
	if(t < 0 || t >= numElements){
		cerr<<"Index out of bounds"<<endl;
		exit(1);
	}
	return elements[t];
}

template <class T>
Array<T>& Array<T>::operator+=(T temp){
	add(temp);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T temp){
	remove(temp);
	return *this;
}

template <class T>
void Array<T>::clear() {
	numElements = 0;
}

#endif
