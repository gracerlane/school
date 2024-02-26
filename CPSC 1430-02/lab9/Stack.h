// Grace Lane
// Stack.h
// Purpose: For declaring the Stack class

#ifndef STACK_H
#define STACK_H

class Stack 
{
	private:
	  int *stackArrPtr;   // pointer to the stack array
		int stackSize;      // size of the stack
		int top;            // top of the stack
	
	public:
		Stack(int);
		~Stack();
		void push(int);
		int pop();
		bool isFull() const;
		bool isEmpty() const;
};

#endif