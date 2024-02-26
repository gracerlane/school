// Grace Lane
// Stack.h
// Purpose: For declaring the Stack class

#ifndef STACK_H
#define STACK_H

class Stack 
{
	private:
	  struct StackNode {
			int num;
			StackNode *next;
		};
		StackNode *top;
	
	public:
		Stack();
		~Stack();
		void push(int);
		int pop();
		bool isEmpty() const;
};
#endif