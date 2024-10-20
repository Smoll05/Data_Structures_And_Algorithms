#include "List.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;

class SinglyLinkedList : public List {
	node* head;
	node* tail;
	int size;
	
	node* add_between(int num, node* pred, node* succ) {
		node* n = new node;
		n->elem = num;
		n->prev = pred;
		n->next = succ;
		pred->next = n;
		succ->prev = n;
		size++;
		return n;
	}
	
	int remove_node(node* n) {
		node* pred = n->prev;
		node* succ = n->next;
		pred->next = succ;
		succ->prev = pred;
		size--;
		int stuff = n->elem;
		delete n;
		return stuff;
	}
	
	public:
	SinglyLinkedList() {
		size = 0;
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;	
	}

	~SinglyLinkedList() {
		cout << "Deleting myself from here" << endl;
		
		node* curr = head;
		while (curr != tail) {
			curr = curr->next;
			delete curr->prev;
		}
		delete curr;
    }
	

	void addHead(int num) {
		add_between(num, head, head->next);
	}	
	

	void addTail(int num) {
		add_between(num, tail->prev, tail);
	}


	int removeHead() {
		return remove_node(head->next);
	}

	
	int removeTail() {
		return remove_node(tail->prev);
	}
	

	void add(int num) {
		addTail(num);
	}


	void print() {
		cout << "Size: " << size << endl;
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		cout << "From HEAD: ";
		node* curr = head->next;
		while (curr != tail) {
			cout << curr->elem;
			if(curr->next != tail) {
				cout << " -> ";
			}
			curr = curr->next;
		}
		cout << endl << "From TAIL: ";
		curr = tail->prev;
		while (curr != head) {
			cout << curr->elem;
			if(curr->prev != head) {
				cout << " <- ";
			}
			curr = curr->prev;
		}
		cout << endl;
	}
	

	int get(int pos) {
		if(pos < 1 || pos > size) return -1;
		
		node* curr = head;
		for (int i = 0; i < pos; i++) {
			curr = curr->next;
		}
		return curr->elem;
	}
	

	int remove(int num) {
		node* curr = head->next;
		int pos = 1;
		while (curr != tail) {
			if (curr->elem == num) {
				remove_node(curr);
				return pos;
			}
			curr = curr->next;
			pos++;
		}
		return -1;
	}
};