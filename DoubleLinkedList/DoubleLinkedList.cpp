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
		newNode->next = START;
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}

	Node* current = START;
	while (current->next != NULL && nim > current->next->noMhs)
		current = current->next;

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate Roll Number Not Allowed" << endl;
		return;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
	current->next = newNode;
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = *current = START;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;

	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::ascending() {
	if (listEmpty())
		cout << "\nList Empty" << endl;
	else {
		cout << "\nRecords In Ascending Order Of Roll Number Are : " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::descending() {
	if (listEmpty())
		cout << "\nList Is Empty" << endl;
	else {
		cout << "\nRecords In Descending Order Of Roll Number Are : " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList Is Empty" << endl;

	}
	cout << "\nEnter The Roll Number Of Student Whose Record Is To Be Deleted : ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record Not Found " << endl;
	else
		cout << "Record With Roll Number " << rollNo << " Deleted" << endl;
}

void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList Is Empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter The Roll Of The Student Whose Record You Want To Search : ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord Not Found" << endl;
	else {
		cout << "\nRecord Found" << endl;
		cout << "\nRoll Number" << curr->noMhs << endl;
		cout << "\nName : " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add A Record To The List" << endl;
			cout << "2. Delete A Record From The List" << endl;
			cout << "3. View All Records In The Ascending Order Of Roll Numbers" << endl;
			cout << "4. View All Records In The Descending Order Of Roll Numbers" << endl;
			cout << "5. Search For A Record In The List" << endl;
			cout << "6. Exit" << endl;
			cout << "7. \nEnter Your Choice (1 - 6) : ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1' :
				obj.addNode();
				break;
			case '2' :
				obj.hapus();
				break;
			case '3' :
				obj.ascending();
				break;
			case '4' :
				obj.descending();
				break;
			case '5' :
				obj.searchData();
				break;
			}
		}
	}
}