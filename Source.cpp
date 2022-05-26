#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data{ };
	Node* next{ };
	Node(int data) :
		data(data) {
	}
};

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;

public:

	void print() {

		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void insert_end(int value) {
		Node* node = new Node(value);

		if (!head)
			head = tail = node;
		else {
			tail->next = node;
			tail = node;
		}
		++length;
	}
	bool isEmpty(){
		if (length == 0) {
			cout << "Empty linkedlist\n";
			return true;
		}
		else {
			cout << "Full LinkedList\n";
			return false;
		}
	}

	int lengh() {
		return length;
	}
	void addAsHead(int i) {
		Node* node = new Node(i);
		node->next = head;
		head = node;
		++length;
	 }
	void addAsTail(int i)
	{
		Node* node = new Node(i);
		tail->next = node;
		node = tail;
		length++;
	}
	void addSorted(int i) {
		Node* node = new Node(i);
		for (Node* cur = head; cur; cur = cur->next)
		{
			if (cur->data < i) {
				cur = cur->next;
				node->next = cur->next;
				cur->next = node;			}
		}
		length++;
	}
	Node* find(int i) {
		for (Node* cur = head; cur; cur = cur->next)
			if (cur->data == i) return cur;
			else return nullptr;
	}
	void reverse() {
		Node* current = head , *prev = nullptr , *next = nullptr;
		while (current != NULL) {
			// Store next
			next = current->next;
			// Reverse current node's pointer
			current->next = prev;
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;

	}
	int popHead() {
		int num = head->data;
		cout << " first node is : " << head->data << "\n";
		Node* cur = head;
		head = head->next;
		delete cur;
		length--;
		return  num;
	}
	void removeFirst(int i) {}
	
	void removeAll (){
		Node* current = head;
		Node* next = NULL;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
			length--;
		}
		head = NULL;
	}
	Node* rethead() {
		return head;
	}
	void addList(LinkedList l) {}
};


int main() {

	LinkedList list;


	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
	list.addAsHead(1);
	list.addAsTail(100);
	list.addSorted(7);
	list.reverse();
	list.popHead();
	//list.removeFirst(10);
	list.print();
	list.removeAll();
	list.isEmpty();
	list.print();
	cout <<"len of list = "<< list.lengh();

	return 0;
}