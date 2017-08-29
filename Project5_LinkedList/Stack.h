/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
*** Jonathan Armknecht, Project 5
*** jonathan.armknecht@gmail.com
***
********************************************/

// You may modify any part of this file, but you must not change the name of the
// class or any of the method declarations.  If you do, your project will not
// compile.

#pragma once

#include <exception>

namespace cs235
{
	template <typename type>
	class Stack
	{
	private:
		// Put all your private declarations here.  You'll need some kind of 
		// private node class, a start-pointer, and a count.
		struct StackNode 
		{
			StackNode *nextNode;
			type data;

			StackNode(const type& newItem) 
			{
				nextNode = nullptr;
				data = newItem;
			}
		};

		StackNode *head;
		size_t count;

	public:
		// This is your constructor.  You need to initialize all your fields.
		// Please use member initializer lists, as this is good practice.
		Stack()
		{
			head = nullptr;
			count = 0;
		}

		// This is your destructor.  Make sure you delete all the nodes in the
		// list.
		~Stack()
		{
			Clear();
		}

		// This method should return a count of items in the stack.  You should
		// keep the count in a private field, and not iterate through the stack
		// every time.
		size_t Count()
		{
			return count;
		}

		// This pushes a new item to the top of the stack.
		void Push(type& item)
		{
			StackNode *newNode = new StackNode(item);
			if (count == 0) {
				head = newNode;
			}
			else {
				newNode->nextNode = head;
				head = newNode;
			}
			count++;
		}

		// This removes an item from the top of the stack.  You do not have to
		// return anything.  If the count is zero, you should throw an 
		// out_of_range exception.
		void Pop()
		{
			if (count == 0) {
				throw std::out_of_range("List is empty! Can't Pop.");
			}
			StackNode *tmp = head;
			head = head->nextNode;
			delete tmp;
			count--;
		}

		// This returns the value of the item that is at the top of the stack.  
		// If the stack is empty, this method should throw an out_of_range 
		// exception.
		type& Peek()
		{
			if (count == 0) {
				throw std::out_of_range("List is empty! Can't Peek.");
			}
			return head->data;
		}

		// This will peek at the nth item down the stack.  The count should be
		// zero-based.  If the stack is empty, or if pos is >= to the count of
		// items in the stack, then throw an out_of_range exception.
		type& PeekAt(size_t pos)
		{
			if (count == 0) {
				throw std::out_of_range("List is empty! Can't Peek At.");
			}
			if (pos >= count) {
				throw std::out_of_range("Can't Peek At a position larger or equal to count.");
			}
			StackNode *current = head;
			for (size_t i = 0; i < count; i++) {
				if (pos == i) {
					return current->data;
				}
				current = current->nextNode;
			}
		}

		// This will insert a value in the middle of the stack.  The item should
		// be inserted BEFORE the item indicated by pos.  If pos is equal to the
		// current count of items, then this method will append to the end of
		// the stack.  If pos is zero, then this method will essentially do the
		// same thing as Push().
		void InsertAt(type &item, size_t pos)
		{
			if (pos > count) {
				throw std::out_of_range("Can't Insert past the tail of the list when position is greater than count.");
			}
			if (pos == 0) {
				Push(item);
				return;
			}

			StackNode *newNode = new StackNode(item);
			StackNode *current = head;
			StackNode *previous = nullptr;
			
			for (size_t i = 0; i < pos; i++) {
				previous = current;
				current = current->nextNode;
			}
			previous->nextNode = newNode;
			newNode->nextNode = current;

			count++;
		}

		// This will clear all items in the stack, and reset the count to zero.
		void Clear()
		{
			while (count > 0) {
				Pop();
			}
			count = 0;
		}
	};
}