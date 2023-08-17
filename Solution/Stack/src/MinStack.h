#pragma once
class MinStack
{
private:
	struct node
	{
		int value;
		node* prev;
		node* nextMin;
	};
	node* head;
	node* min;
public:
	MinStack();

	// pushes an element to the top of the stack
	void push(int val);
	// removes top element of stack
	void pop();
	// retrieves top element of stack
	int top();
	// retrieves minimum element in stack
	int getMin();


};

