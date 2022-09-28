#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node()
	{
		data = 0;
		next = nullptr;
	}
	node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};
class linkedlist
{
	node* head;
public:
	linkedlist()
	{
		head = nullptr;
	}
	void insertnode(int);
	void deletenode(int);
	void printlist();
};
void linkedlist::insertnode(int dataforinsertion)
{
	node* newnode = new node(dataforinsertion);
	if (head == nullptr)
	{
		head = newnode;
		return;
	}
	node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
void linkedlist::deletenode(int nodenumber)
{
	node* temp1 = head;
	node* temp2 = nullptr;
	int length = 0;
	if (head == nullptr)
	{
		cout << "List is currently empty" << endl;
		return;
	}
	while (temp1 != nullptr)
	{
		temp1 = temp1->next;
		++length;
	}
	if (length < nodenumber)
	{
		cout << "Node not in range" << endl;
		return;
	}
	temp1 = head;
	if (nodenumber == 1)
	{
		head = head->next;
		delete temp1;
	}
	while (nodenumber-- > 1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	temp2->next = temp1->next;
	delete temp1;
}
void linkedlist::printlist()
{
	node* temp = head;
	if (head == nullptr)
	{
		cout << "List is currently empty" << endl;

	}
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	linkedlist list;
	list.insertnode(55);
	list.insertnode(35);
	list.insertnode(3);
	cout << "printlist function" << endl;
	list.printlist();
	cout << endl;
	list.deletenode(2);
	cout << "prinlist after deleting 35" << endl;
	list.printlist();

	return 0;
}