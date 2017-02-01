//CIS22C
//Lab 1
//Crystal Hupp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

static int nodeCounter = 0; //to count number of nodes created

/*
class UProducts {
private:
	string product;
	double price;
	string value;

public:
	//constructor
	UProducts(string new_value) {
		value = new_value;
		//parse the value out to assign product and price
	}

	//assessors
	string getProduct() const {
		return product;
	}

	double getPrice() const {
		return price;
	}
};
*/

template <class T>
class ListNode {
public:
	T value;
	ListNode<T> *next;

	//constructor
	ListNode(T nodeValue) {
		value = nodeValue;
		next = nullptr;
		++nodeCounter;
	}
};

template <class T>
class LinkedList {
private:
	ListNode<T> *head; //list head pointer

public:
	//constructor
	LinkedList() {
		head = nullptr;
	}

	//operations for linked list
	int getCurrentSize();
	bool isEmpty();
	bool insert(T);
	bool remove(T);
	void clear();
	bool contains(T);
};

template <class T>
int LinkedList<T>::getCurrentSize() {
	return nodeCounter;
	/*
	int current_size=0; //node counter
	ListNode<T> *nodePtr; //to go through list
	nodePtr = head; //start at head of list

	while(nodePtr) { //while nodePtr can point to a node, move through list
	++current_size; //count this node
	nodePtr = nodePtr->next; //move to next node

	}*/
}

template <class T>
bool LinkedList<T>::isEmpty() {
	if (!head)
		return true;
	else
		return false;
}

template <class T>
bool LinkedList<T>::insert(T newValue) {
	ListNode<T> *newNode; //points to new node
	ListNode<T> *nodePtr; //to move through list

	//create new node and store newValue there
	newNode = new ListNode<T>(newValue);

	//if list empty, make newNode the first node
	if (!head)
		head = newNode;
	else { //if there are nodes, insert newNode at end
		nodePtr = head; //set pointer to head of list
		while (nodePtr->next) //search for the end of the list (null)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode; //add node to end of list
	}
}

template <class T>
bool LinkedList<T>::remove(T searchValue) {
	ListNode<T> *nodePtr; //to search list
	ListNode<T> *previousNode; //points to previous node

	if (!head)//if list is empty, return false and do nothing
		return false;

	//if value is the first node in the list
	if (head->value == searchValue) {
		nodePtr = head->next; //assign pointer to next in list
		delete head; //delete first node
		head = nodePtr; //assign head to next in the list
		--nodeCounter;
		return true;
	}
	else {
		nodePtr = head;
		//******THIS HAS PROBLEMS AS VALUE IS 2 OPTIONS!*******
		//while value is not the one being searched for, continue on
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			notePtr = nodePtr->next;
		}

		//as long as node isn't at end of list (condition checked above),
		//link previous node to node after nodePtr, then delete nodePtr
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
			--nodeCounter;
		}
		return true;
	}
}

template <class T>
void LinkedList<T>::clear() {
	ListNode<T> *nodePtr; //To Traverse the list
	ListNode<T> *nextNode; //points to next node

	nodePtr = head;

	while (nodePtr != nullptr) { //while not at the end of the list
		nextNode = nodePtr->next; //points to next in list to safely delete nodePtr
		delete nodePtr;
		nodePtr = nextNode; //move to next in the list and then enter loop again to delete
	}
	nodeCounter = 0;
}

//****Value you problem here! How to search object value?
template <class T>
bool LinkedList<T>::contains(T nEntry) {
	ListNode<T> *nodePtr; //move through list
	nodePtr = head; //start at beginning of list
	while (nodePtr != nullptr && nodePtr->value != nEntry)
		nodePtr = nodePtr->next;
	if (nodePtr) //if not at the end of the list, value was found
		return true;
	else //end of list was reached without value being found
		return false;
}

//function prototype
int main_menu();

int main() {
	int choice; //menu choice
	char again; //to indicate if user is done or not
	string new_value; //receive new product
	fstream input_file; //to read from file
	LinkedList<string> list; //define a LinkedList with string values

	input_file.open("UProducts.csv", ios::in);

	//load contents of file into the linked list
	while (getline(input_file, new_value)) {
		list.insert(new_value);
	}

	cout << "The contents of the file UProducts.csv has been loaded into the Linked List" << endl;

	do {
		choice = main_menu(); //call main menu function
		cout << endl;

		if (choice == 1)
			cout << "Number of entries: " << list.getCurrentSize() << endl;
		if (choice == 2) {
			if (list.isEmpty() == 0)
				cout << "Linked List is not empty" << endl;
			else
				cout << "Linked List is empty" << endl;
		}
		if (choice == 3) {
			cout << "Enter a product and price with format item,price: ";
			getline(cin, new_value);
			list.insert(new_value);
			cout << "New product added to list." << endl;
		}
		if (choice == 4) {
			bool isremoved;
			cout << "Which product do you want to remove? ";
			getline(cin, new_value); //holds user entered product value
			isremoved = list.remove(new_value);
			if (isremoved)
				cout << "First instance of product was removed.";
			else
				cout << "No product was removed.";
		}
		if (choice == 5) {
			bool isremoved;
			cout << "What product do you want to search for? ";
			getline(cin, new_value);
			isremoved = list.contains(new_value);
			if (isremoved)
				cout << "Product was found in the list." << endl;
			else
				cout << "Product was not found in the list." << endl;
		}
		if (choice == 6) {
			list.clear();
			cout << "All entries were removed" << endl;
		}
		cout << endl;
		cout << "Would you like to select another option? Y/N: \n";
		cin >> again;
		while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
		{
			cout << "Invalid entry.\nPlease enter Y or N.\n";
			cin >> again;
		}
	} while (again == 'y' || again == 'Y');

	return 0;
}

int main_menu() {
	int choice;
	cout << "1) Get current size of the linked list\n"
		<< "2) Check if the linked list is empty\n"
		<< "3) Add a new entry to the linked list\n"
		<< "4) Remove an entry from the linked list\n"
		<< "5) Test whether the linked list contains a specific entry\n"
		<< "6) Remove all entries from the linked list\n";
	cin >> choice;

	while (choice < 1 || choice > 6)
	{
		cout << "Invalid entry.\nPlease enter a valid menu choice.\n";
		cin >> choice;
	}

	return choice;
}