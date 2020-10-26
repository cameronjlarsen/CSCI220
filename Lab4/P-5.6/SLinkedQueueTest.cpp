/*
	Program: SLinkedQueueTest
	Author: Cameron Larsen
	Course: CSCI 220
	Date: 10/21/2020
	Description: Test program showing Queue ADT by means of a singly linked list

	I certify that the following code is my own work.

	Exception(s): N/A
*/

#include <iostream>
#include "LinkedQueue.h"

int main() {
	std::cout << "Author: Cameron Larsen\n"
		<< "This program will showcase an implementation of a queue data structure\n";

	LinkedQueue<int> queue;

	std::cout << "\nLet's create a queue and check its status\n";
	if (queue.empty()) {
		std::cout << "The queue is empty\n";
	}
	else {
		std::cout << "The queue is not empty\n";
	}
	std::cout << "The size of the queue is: " << queue.size() << "\n";

	std::cout << "\nLet's enqueue some numbers and then recheck it's status\n"
		<< "Adding 2, 3, 5 to queue\n";

	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(5);

	if (queue.empty()) {
		std::cout << "The queue is empty\n";
	}
	else {
		std::cout << "The queue is not empty\n";
	}
	std::cout << "The size of the queue is: " << queue.size() << "\n";
	std::cout << "Let's check the item at the front of the queue: "
		<< queue.front();

	std::cout << "\n\nNow let's dequeue some items, then re-check the queue's status\n";

	queue.dequeue();
	std::cout << "\nThe size of the queue is: " << queue.size() << "\n";
	std::cout << "Let's check the item at the front of the queue: "
		<< queue.front();

	queue.dequeue();
	std::cout << "\n\nThe size of the queue is: " << queue.size() << "\n";
	std::cout << "Let's check the item at the front of the queue: "
		<< queue.front();

	queue.dequeue();
	std::cout << "\n\nThe size of the queue is: " << queue.size() << "\n";
	std::cout << "Let's check the item at the front of the queue: "
		<< queue.front();

	if (queue.empty()) {
		std::cout << "\nThe queue is empty\n";
	}
	else {
		std::cout << "\nThe queue is not empty\n";
	}

	return 0;
}