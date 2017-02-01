//CIS22C
//Lab 0
//Crystal Hupp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class DynamicArray
{
private:
	int current_size; //tracks number of entries in array
	const int INITIAL_CAP = 10; //initialize the array size
	int capacity; //used for increasing array size
	string* word_array = nullptr; //declare pointer for array

public:
	//no argument constructor
	DynamicArray()
	{
		current_size = 0;
		capacity = INITIAL_CAP;
		word_array = new string[INITIAL_CAP];
	}

	//accessors
	int getCurrentSize() {
		return current_size;
	}
	int capcity() {
		return capacity;
	}
	bool isEmpty() {
		if (current_size == 0)
			return true;
		else
			return false;
	}

	string getValue(int index) {
		int new_value=0;
		if(index <= current_size && index > 0)
			return word_array[index-1];
		else{
			cout << "Invalid entry. Current size of array is " << getCurrentSize() << endl;
			cin >> new_value;
			while (new_value > current_size || new_value <= 0)
			{
				cout << "Invalid entry. Current size of array is " << getCurrentSize() << endl;
				cin >> new_value;
			}
			return word_array[new_value - 1];
		}
	}

	//mutators
	bool insert(string new_entry) {
		if (current_size < capacity) {
			word_array[current_size] = new_entry;
			++current_size;
		}
		else {
			resize();
			word_array[current_size] = new_entry;
			++current_size;
		}
		return true;
	}

	bool remove(int index) {
		if (index < current_size && index >= 0) {
			word_array[index] = "";
			if (index != current_size - 1) {
				for (int i = index + 1; i < current_size; i++)
					word_array[index] = word_array[i];
			}
			--current_size;
			return true;
		}
		else
			return false;
	}

	void clear() {
		for (int i = 0; i < capacity; i++) {
			word_array[i] = "";
		}
		current_size = 0;
	}


	void resize() {
		string* ptemp = new string[capacity * 2];
		for (int i = 0; i < current_size; i++)
			ptemp[i] = word_array[i];
		delete[] word_array;
		word_array = ptemp;
		capacity *= 2;
	}

};



//function prototype
int main_menu();

int main() {
	int choice; //menu choice
	char again; //to indicate if user is done or not
	string new_entry; //receive new entry from user
	int get_value; //get value at desired index
	int index_choice; //holds user choice of index of array
	fstream input_file; //to read from file
	DynamicArray newArray; //create DynamicArray object

	input_file.open("Words.csv", ios::in);
	
	//load contents of file into Dynamic Array
	while (input_file >> new_entry) {
		newArray.insert(new_entry);
	}
	cout << "The contents of the file Words.csv has been loaded into the Dynamic Array" << endl;

	do{
		choice = main_menu(); //call main menu function
		cout << endl;

		if(choice == 1)
			cout << "Number of entries: " << newArray.getCurrentSize() << endl;
		if(choice == 2)
			cout << "Current capacity of array: " << newArray.capcity() << endl;
		if (choice == 3) {
			if (newArray.isEmpty() == 0)
				cout << "Array is not empty" << endl;
			else
				cout << "Array is empty" << endl;
		}
		if (choice == 4) {
			cout << "Select an index value: ";
			cin >> get_value;
			cout << "Value: " << newArray.getValue(get_value) << endl;
		}
		if (choice == 5) {
			cout << "Enter a new word: ";
			cin >> new_entry;
			newArray.insert(new_entry);
			cout << "New word added." << endl;
		}
		if (choice == 6) {
			bool isremoved;
			cout << "Which element do you want to remove? ";
			cin >> index_choice;
			isremoved = newArray.remove(index_choice - 1);
			if (isremoved)
				cout << "Word removed.";
			else
				cout << "No word was removed.";
		}
		if (choice == 7) {
			newArray.clear();
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
	cout << "1) Get current number of entries in array\n"
		 << "2) Get the current capacity of the array\n"
		 << "3) Check if the array is empty\n"
		 << "4) Return the value stored in a chosen index\n"
		 << "5) Insert another entry\n"
		 << "6) Remove an entry\n"
		 << "7) Clear the array\n";
	cin >> choice;
	
	while (choice < 1 || choice > 7)
	{
		cout << "Invalid entry.\nPlease enter a valid menu choice.\n";
		cin >> choice;
	}

	return choice;
}
