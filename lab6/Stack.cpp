#include "Stack.h"


// constructor
// create new array of size from parameter
template <class T>
Stack<T>::Stack (int size) {
	stack_array = new T*[size];		// create memory for array of pointers
	stack_size = 0;
	stack_top = -1;
}


// destructor
// fully delete array to avoid memory leaks
template <class T>
Stack<T>::~Stack () {
	delete [] stack_array;			// delete and de-allocate array memory
	//---- idk if this is correct ^ ----
}	


// push
// add new item to stack
template <class T>
void Stack<T>::push (T* obj) {
	// check if stack is full
	if (is_full()) {
		//throw overflow error
	}
	else {
		stack_top++;						// incriment top
		stack_array[stack_top] = obj;	
	}
}


// pop
// remove and return item from stack
template <class T>
T* Stack<T>::pop () {
	// check if stack is empty
	if (is_empty()) {
		//--throw underflow error
	}
	else {
		stack_top--;						// decriment top
		return stack_array[stack_top+1];	// return pointer to previous top
	}
}


// top
// return pointer to top of stack
template <class T>
T* Stack<T>::top () {
	if (is_empty()) {
		//--throw underflow error
	}
	else {
		return stack_array[stack_top];
	}
}


// length
// return length of current number of objects in stack
template <class T>
int Stack<T>::length () {
	return stack_top + 1;		// current number of objects in stack
}


// empty
// clear stack array and calls delete to avoid memory leaks
template <class T>
void Stack<T>::empty_stack () {
	for (int i=0; i < stack_size; i++) {
		delete stack_array[i];
	}
	stack_top = -1;
}


// is empty
// return true if stack is empty
template <class T>
bool Stack<T>::is_empty () {
	if (stack_size == 0) {		// if stack is empty
		return true //maybe throw underflow error here idky
	}
	else {
		return false;
	}
}


// is full
// return true is stack is full
template <class T>
bool Stack<T>::is_full () {
	if (stack_size <= length()) {
		return true; //maybe throw overflow error
	}
	else {
		return false;
	}
}



/*
stack functions - algorithm
https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/
queue functions - algorithm
https://www.geeksforgeeks.org/introduction-and-array-implementation-of-queue/

stack implementation using templates
https://www.geeksforgeeks.org/implementing-stack-using-class-templates-in-cpp/

*/