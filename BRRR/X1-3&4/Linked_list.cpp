#include "Linked_list.h"

template<typename Object>
Linked_list<Object>::Linked_list()
{
	head = NULL;
	tail = NULL;
	list_size = 0;
}

template<typename Object>
Linked_list<Object>::~Linked_list()
{
	clear();
}

template<typename Object>
int Linked_list<Object>::size()
{
	return list_size;
}

template<typename Object>
bool Linked_list<Object>::empty()
{

	return (size() == 0);
}

template<typename Object>
void Linked_list<Object>::clear()
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

template<typename Object>
void Linked_list<Object>::insert(int pos, const Object x)
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

template<typename Object>
void Linked_list<Object>::remove(int pos)
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

template<typename Object>
void Linked_list<Object>::push_back(const Object x)
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

template<typename Object>
void Linked_list<Object>::push_front(const Object x)
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

template<typename Object>
void Linked_list<Object>::reverse()
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

template<typename Object>
void Linked_list<Object>::print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename Object>
bool Linked_list<Object>::contains(const Object x)
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
	return false;
}

template<typename Object>
Object Linked_list<Object>::pop_back()
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

template<typename Object>
Object Linked_list<Object>::pop_front()
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

template<typename Object>
Object Linked_list<Object>::find(int pos)
{
	assert(pos >= 0 && pos < size() && "Invalid position");
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}