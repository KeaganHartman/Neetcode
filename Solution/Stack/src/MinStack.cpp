#include "MinStack.h"

MinStack::MinStack()
{
	head = nullptr;
	min = nullptr;
}

void MinStack::push(int val)
{
	node* temp = new node;
	temp->value = val;
	temp->nextMin = nullptr;

	if (head == nullptr) // if list is empty
	{
		min = temp;
		temp->prev = nullptr;
	}
	else
	{
		temp->prev = head;
		if (val < min->value)
		{
			temp->nextMin = min;
			min = temp;
		}
	}

	head = temp;
}

void MinStack::pop()
{
	if (min == head)
		min = min->nextMin;
	
	node* temp = head;
	head = head->prev;
	delete temp;
}

int MinStack::top()
{
	return head->value;
}

int MinStack::getMin()
{
	return min->value;
}


