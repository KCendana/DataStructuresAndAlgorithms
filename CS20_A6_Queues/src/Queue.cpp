/*
 * Queue.cpp
 *
 *  Created on: Oct 20, 2019
 *      Author: cenda
 */

#include "Queue.h"

Queue::Queue(int userQueueSize)
{
	//Base Case: User puts a number >=0, default queue size is 100
	if (userQueueSize <= 0)
	{
		cout << "Queue Constructor: Queue size must be greater than 0." << endl;
		maxQueueSize = 100; //default size is 100
	}
	else
		maxQueueSize = userQueueSize;

	queueFront = 0;
	queueRear = maxQueueSize - 1;	// -1 because of index
	numElements = 0;
	list = new Transaction[maxQueueSize]; //list is a string pointer
}

bool Queue::isFull()
{
	if (numElements == maxQueueSize)
	{
		return true;
	}
	else
		return false;
}

bool Queue::isEmpty()
{
	if (numElements == 0)
	{
		return true;
	}
	else
		return false;
}

void Queue::addElement(Transaction &element)
{
	//if queue is not full
	//move queueRear
	//num elements + 1
	//add new transaction to the back of the queue (queueRear)

	if (this->isFull() == false)
	{
		//cout << "addTransaction: Adding " << element.ID << " to the Queue... ";
		queueRear = (queueRear + 1) % maxQueueSize;
		numElements++;
		list[queueRear] = element;
		//cout << "...success!" << endl;
	}
	else
	{
		//cout << "Queue is full. " << endl;
	}
}

void Queue::deleteElement()
{
	if (!isEmpty())
	{
//		cout << "deleteTransaction: Removing front of queue: " << list[queueFront].ID << endl;
//		list[queueFront].ID = ""; //not needed, for clarity
//		list[queueFront].workUnits = 0; //not needed, for clarity;
		numElements--;
		queueFront = (queueFront + 1) % maxQueueSize;
	}
	else
		cout << "deleteTransaction: Queue is already empty, cannot remove. " << endl;
}

void Queue::displayQueue()
{
	for (int i = maxQueueSize-1; i >= 0; i--)
	{
		cout << "Displaying list[" << i << "]: ";
		cout << list[i].ID;
		if (queueFront == i)
		{
			cout << " (queueFront)";
		}
		if (queueRear == i)
		{
			cout << " (queueBack)";
		}
		cout << endl;
	}
}

Queue::~Queue() {
	delete [] list;
}

