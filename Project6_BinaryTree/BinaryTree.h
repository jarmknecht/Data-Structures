/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
*** Jonathan Armknecht, Project 6
*** jonathan.armknecht@gmail.com
***
********************************************/

// You may modify any part of this file, but you must not change the name of the
// class or any of the method declarations.  If you do, your project will not
// compile.

#pragma once

#include <vector>


template <typename type>
class BinaryTreeNode
{
private:
	type Data;
	BinaryTreeNode<type> *Left;
	BinaryTreeNode<type> *Right;

public:
	BinaryTreeNode(const type& data) :
		Data(data),
		Left(nullptr),
		Right(nullptr)
	{}

	type& GetData()
	{
		return Data;
	}

	template <typename type> friend class BinaryTree;
	template <typename type> friend class TreeHelper;
};


template <typename type>
class BinaryTree
{
private:

	BinaryTreeNode<type> *_root;
	int _count;

	void _addHelper(BinaryTreeNode<type> *current, const type& value)
	{
		if (value < current->GetData()) {
			if (current->Left == nullptr) {
				current->Left = new BinaryTreeNode<type>(value);
			}
			else {
				_addHelper(current->Left, value);
			}
		}
		else if (value > current->GetData()) {
			if (current->Right == nullptr) {
				current->Right = new BinaryTreeNode<type>(value);
			}
			else {
				_addHelper(current->Right, value);
			}
		}
		else {
			throw std::exception("Duplicate item! Cannot add.");
		}
	}

	bool _findHelper(BinaryTreeNode<type> *current, const type& value)
	{
		if (value == current->GetData()) {
			return true;
		}
		else if (value < current->GetData()) {
			if (current->Left == nullptr) {
				return false;
			}
			else {
				_findHelper(current->Left, value);
			}
		}
		else if (value > current->GetData()) {
			if (current->Right == nullptr) {
				return false;
			}
			else {
				_findHelper(current->Right, value);
			}
		}
	}

	BinaryTreeNode<type>* _findMin(BinaryTreeNode<type> *current)
	{
		while (current->Left != nullptr) {
			current = current->Left;
		}
		return current;
	}

	void _removeHelper(BinaryTreeNode<type> *current, const type& value, BinaryTreeNode<type> *parent = nullptr)
	{
		if (current == nullptr) {
			throw std::exception("Search value not found to delete.");
		}
		else if (value < current->GetData()) {
			_removeHelper(current->Left, value, current);
		}
		else if (value > current->GetData()) {
			_removeHelper(current->Right, value, current);
		}
		else if (parent == nullptr) {
			if (current->Left == nullptr && current->Right == nullptr) {
				delete _root;
				_root = nullptr;
			}
			else if (current->Left != nullptr && current->Right == nullptr) {
				BinaryTreeNode<type> *tmp = current;
				_root = current->Left;
				delete tmp;
			}
			else if (current->Right != nullptr && current->Left == nullptr) {
				BinaryTreeNode<type> *tmp = current;
				_root = current->Right;
				delete tmp;
			}
			else {
				BinaryTreeNode<type> *tmp = _findMin(current->Right);
				current->Data = tmp->Data;
				_removeHelper(current->Right, tmp->Data, current);
			}
			
		}
		else {
			if (current->Left == nullptr && current->Right == nullptr) {
				if (parent->Left == current) {
					parent->Left = nullptr;
				}
				else if (parent->Right == current) {
					parent->Right = nullptr;
				}
				delete current;
				current = nullptr;
			}
			else if (current->Left == nullptr) {
				if (parent->Left == current) {
					parent->Left = current->Right;
				}
				else if (parent->Right == current) {
					parent->Right = current->Right;
				}
				delete current;
				current = nullptr;
			}
			else if (current->Right == nullptr) {
				if (parent->Left == current) {
					parent->Left = current->Left;
				}
				else if (parent->Right == current) {
					parent->Right = current->Left;
				}
				delete current;
				current = nullptr;
			}
			else {
				BinaryTreeNode<type> *tmp = _findMin(current->Right);
				current->Data = tmp->Data;
				_removeHelper(current->Right, tmp->Data, current);
			}
		}
	}

	void _destroy(BinaryTreeNode<type> *current) 
	{
		if (current->Left != nullptr) {
			_destroy(current->Left);
		}
		if (current->Right != nullptr) {
			_destroy(current->Right);
		}

		delete current;
	}

public:
	BinaryTree() :
		_root(nullptr),
		_count(0)
	{}


	// Make sure you clean up everything in the destructor.  THe easiest way to
	// do this is to call the Clear() method.
	~BinaryTree()
	{
		Clear();
	}


	// This method returns a pointer to the root tree-node.
	BinaryTreeNode<type> *GetRoot()
	{
		return _root;
	}


	// This method will add a new item to the tree.  You need to check for 
	// duplicates.  If you find a duplicate, you should throw an exception.
	void Add(const type& newItem)
	{
		if (GetRoot() == nullptr) {
			_root = new BinaryTreeNode<type>(newItem);
		}
		else {
			_addHelper(GetRoot(), newItem);
		}

		_count++;
	}


	// This method should remove an item from the tree.  You'll need to traverse
	// the tree until you find the item, then remove the item.  If the item is
	// not in the tree, then throw an exception.
	void Remove(const type &value)
	{
		if (GetRoot() == nullptr) {
			throw std::exception("Cannot remove from an empty tree.");
		}
		_removeHelper(GetRoot(), value);
		_count--;
	}


	// This method should return a count of how many items are in your tree.
	int Count()
	{
		return _count;
	}


	// This method will return a true if the item is a member of the tree, and 
	// false if the item is not in the tree.
	bool Contains(const type &value)
	{
		if (GetRoot() == nullptr) {
			return false;
		}
		else {
			return _findHelper(GetRoot(), value);
		}
	}


	// THis method will delete all the nodes in the tree and reset the count to
	// zero.
	void Clear()
	{
		if (GetRoot() == nullptr) {
			return;
		}
		_destroy(GetRoot());
		_root = nullptr;
		_count = 0;
	}
};