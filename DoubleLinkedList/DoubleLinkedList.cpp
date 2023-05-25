#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:

	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void ascending();
	void descending();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string Nama;
	cout << "\nEnter The Roll Number Of The Student : ";
	cin >> nim;
	cout << "\nEnter The Name Of The Student : ";
	cin.ignore();
	getline(cin, Nama);
	Node* newNode = new Node();
	newNode->noMhs = nim;
	newNode->name = Nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate Number Not Allowed" << endl;
			return;
		}
	}
}