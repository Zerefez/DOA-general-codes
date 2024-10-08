#pragma once

#include <cassert>
#include "List.h"

using namespace std;

template <typename Object>
class Linked_list : public List<Object>
{
private:
	struct Node
	{
		Object data;
		Node* next;
		Node* prev;
		Node(const Object& d = Object(), Node* n = NULL, Node* p = NULL) : data(d), next(n), prev(p) {}

	};
	int list_size;
	Node* head;
	Node* tail;

	// Recursive helper function
	bool search_helper(Node* node, const Object x) {
		// Base case: if node is nullptr, return false
		if (node == nullptr) {
			return false;
		}
		// Check if the current node's data matches x
		if (node->data == x) {
			return true;
		}
		// Recursive case: move to the next node
		return search_helper(node->next, x);
	}

public:
	Linked_list()
	{
		head = NULL;
		tail = NULL;
		list_size = 0;
	}
	~Linked_list()
	{
		clear();
	}
	int size()
	{
		return list_size;
	}
	bool empty()
	{
		return (size() == 0);
	}
	void clear()
	{
		//delete all nodes
		Node* temp = head;
		while (temp != NULL)
		{
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
		head = NULL;
		tail = NULL;
	}
	void insert(int pos, const Object x)
	{
		assert(pos >= 0 && pos <= size() && "Invalid position");
		if (pos == 0)
		{
			push_front(x);
		}
		else if (pos == size())
		{
			push_back(x);
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < pos; i++)
			{
				temp = temp->next;
			}
			Node* new_node = new Node(x, temp, temp->prev); //create a new node
			temp->prev->next = new_node; //update the next pointer of the previous node
			temp->prev = new_node; //update the previous pointer of the next node
			list_size++;
		}
	}
	void remove(int pos)
	{
		assert(pos >= 0 && pos < size() && "Invalid position");
		//delete the node
		if (pos == 0)
		{
			pop_front();
		}
		else if (pos == size() - 1)
		{
			pop_back();
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < pos; i++)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next; //update the next pointer of the previous node
			temp->next->prev = temp->prev; //update the previous pointer of the next node
			delete temp;
			list_size--;
		}
	}
	void push_back(const Object x)
	{
		//create a new node
		Node* temp = new Node(x, NULL, tail);

		//find the last node
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		//update the tail pointer
		if (tail != NULL)
		{
			tail->next = temp;
		}
		tail = temp;

		//update the head pointer
		if (head == NULL)
		{
			head = temp;
		}
		list_size++;
	}
	void push_front(const Object x)
	{
		//create a new node
		Node* temp = new Node(x, head, NULL);

		//find the first node
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}

		//update the head pointer
		if (head != NULL)
		{
			head->prev = temp;
		}
		head = temp;

		//update the tail pointer
		if (tail == NULL)
		{
			tail = temp;
		}
		list_size++;

	}
	void reverse()
	{
		if (size() > 1)
		{
			Node* temp = head;
			head = tail;
			tail = temp;
			Node* current = head;
			while (current != NULL)
			{
				Node* temp = current->next;
				current->next = current->prev;
				current->prev = temp;
				current = current->next;
			}
		}
	}
	void print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool contains(const Object x)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == x)
			{
				cout << "The list contains " << x << endl;
				return true;
			}
			temp = temp->next;
		}
	}
	Object pop_back()
	{
		assert(!empty() && "Cannot pop from an empty list");
		Node* old_tail = tail; 	//find the last node
		Object data = old_tail->data; //get the data
		tail = tail->prev;

		//update the tail pointer
		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete old_tail;
		list_size--;
		return data;
	}
	Object pop_front()
	{
		assert(!empty() && "Cannot pop from an empty list");
		Node* old_head = head; 	//find the first node
		Object data = old_head->data; //get the data
		head = head->next;

		//update the head pointer
		if (head) {
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete old_head;
		list_size--;
		return data;
	}
	Object find(int pos)
	{
		assert(pos >= 0 && pos < size() && "Invalid position");
		Node* temp = head;
		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	int search(const Object x) {
		return search_helper(head, x);
	}

};