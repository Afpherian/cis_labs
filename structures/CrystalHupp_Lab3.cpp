//Crystal Hupp
//CIS22B
//Lab3

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Book
{
    string author;
    string title;
    string isbn;
    int totalcopies;
    int availcopies;
    int status;
};

//function prototypes
int addbooks(Book [], const int);
int mainMenu();
void bookstofile(Book [], int);
void displayauthor(Book[], int);
void displaytitle(Book[], int);
void searchtitle(Book[], int);
void searchauthor(Book[], int);
void searchisbn(Book[], int);
void checkstatus(Book[], int);
void checkout(Book[], int);
void checkin(Book[], int);

int main()
{
    const int NUM_BOOKS = 10; //to hold maximum books in library
    char choice;
    char again;
    int numbooks; //to hold actual number of books in library
    Book bookarray[NUM_BOOKS]; //an array of Book structures

    //function to fill bookarray or add books
    numbooks=addbooks(bookarray, NUM_BOOKS);

    do
    {
    choice=mainMenu(); //call main menu function
    cout << endl;
        switch(choice)
        {
            case 1: displayauthor(bookarray, numbooks);
                    break;
            case 2: displaytitle(bookarray, numbooks);
                    break;
            case 3: searchtitle(bookarray, numbooks);
                    break;
            case 4: searchauthor(bookarray, numbooks);
                    break;
            case 5: searchisbn(bookarray, numbooks);
                    break;
            case 6: checkstatus(bookarray, numbooks);
                    break;
            case 7: checkout(bookarray, numbooks);
                    break;
            case 8: checkin(bookarray, numbooks);
        }
    cout << endl;
    cout << "Would you like to select another option? Y/N: \n";
    cin >> again;
        while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
        {
            cout << "Invalid entry.\nPlease enter Y or N.\n";
            cin >> again;
        }
    }
    while(again=='y' || again=='Y');

    //write book array to the file
    bookstofile(bookarray, numbooks);

    return 0;
}

//prints main menu and returns user choice
int mainMenu()
{
    int choice;
    cout << "Welcome to Soren's Library!\nPlease choose from one of the options below:\n"
         << "1. Display library collection sorted by Author\n"
         << "2. Display library collection sorted by Title\n"
         << "3. Search for a book by title\n"
         << "4. Search for a book by author\n"
         << "5. Search for a book by ISBN Number\n"
         << "6. List books by availability status\n"
         << "7. Check out a book\n"
         << "8. Check in a book\n";
    cin >> choice;

    while(choice < 1 || choice > 8)
    {
        cout << "Invalid entry.\nPlease enter a valid menu choice.\n";
        cin >> choice;
    }

    return choice;
}

//display books by author
void displayauthor(Book bookarray[], int numbooks)
{
    bool swap1;
    Book temp;

    //bubble sort by author
    do
    {
        swap1 = false;
        for (int index=0; index <(numbooks-1); index++)
        {
            if(bookarray[index].author > bookarray[index+1].author)
            {
                temp = bookarray[index];
                bookarray[index]=bookarray[index+1];
                bookarray[index+1]=temp;
                swap1=true;
            }
        }
    }
    while(swap1);


    //print sorted book array by author
    for(int index=0; index < numbooks; index++)
    {
        cout << (index+1) << ". " <<
        bookarray[index].author << ". " <<
        bookarray[index].title << ". ISBN:" <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status: ";
        if (bookarray[index].status==0)
            cout << "ON SHELF" << endl;
        else
            cout << "CHECKED OUT" << endl;
    }
}

//display books by title
void displaytitle(Book bookarray[], int numbooks)
{
    bool swap1;
    Book temp;

    //bubble sort by title
    do
    {
        swap1 = false;
        for (int index=0; index <(numbooks-1); index++)
        {
            if(bookarray[index].title > bookarray[index+1].title)
            {
                temp = bookarray[index];
                bookarray[index]=bookarray[index+1];
                bookarray[index+1]=temp;
                swap1=true;
            }
        }
    }
    while(swap1);


    //print sorted book array by title
    for(int index=0; index < numbooks; index++)
    {
        cout << (index+1) << ". " <<
        bookarray[index].title << ". " <<
        bookarray[index].author << ". ISBN:" <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status: ";
        if (bookarray[index].status==0)
            cout << "ON SHELF" << endl;
        else
            cout << "CHECKED OUT" << endl;
    }
}

//allows user to search array of book structures for a title or partial title
void searchtitle(Book bookarray[], int numbooks)
{
    string title;
    cin.ignore();
    cout << "What title would you like to search for?\n";
    getline(cin, title);
    bool flag=true;

    for(int index=0; index < numbooks; index++)
    {
        //searches title string for an instances of user input string
        //allows for a match when user types part or all of a title
        if((bookarray[index].title).find(title, 0)!=string::npos)
        {
        cout << bookarray[index].title << ". " <<
        bookarray[index].author << ". ISBN:" <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status:";
            if (bookarray[index].status==0)
                cout << "ON SHELF" << endl;
            else
                cout << "CHECKED OUT" << endl;
        flag=false; //flag to indicate if a match was found
        }
    }
    if(flag)
    {
        cout << "There are no books with that title in this library\n";
    }
}

//allows user to search array of book structures for an author
void searchauthor(Book bookarray[], int numbooks)
{
    string author;
    cin.ignore();
    cout << "What author would you like to search for?\n";
    getline(cin, author);
    bool flag=true;

    for(int index=0; index < numbooks; index++)
    {
        //searches author string for an instances of user input string
        //allows user to search by first or last name
        if((bookarray[index].author).find(author, 0)!=string::npos)
        {
        cout << bookarray[index].author << ". " <<
        bookarray[index].title << ". ISBN:" <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status: ";
            if (bookarray[index].status==0)
                cout << "ON SHELF" << endl;
            else
                cout << "CHECKED OUT" << endl;
        flag=false; //flag to indicate if a match was found
        }
    }
    if(flag)
    {
        cout << "There are no books by that author in this library\n";
    }
}

//allows user to search array of book structures for an isbn number
void searchisbn(Book bookarray[], int numbooks)
{
    string isbn;
    cin.ignore();
    cout << "What ISBN number would you like to search for?\n";
    getline(cin, isbn);
    bool flag=true;

    for(int index=0; index < numbooks; index++)
    {
        if(bookarray[index].isbn==isbn)
        {
        cout << "ISBN:" << bookarray[index].isbn << ". " <<
        bookarray[index].author << ". " <<
        bookarray[index].title <<
         "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status:";
            if (bookarray[index].status==0)
                cout << "ON SHELF" << endl;
            else
                cout << "CHECKED OUT" << endl;
        flag=false;
        }
    }
    if(flag)
    {
        cout << "There are no books with that ISBN number in this library\n";
    }
}

//displays a list of available and a list of unavailable books
void checkstatus(Book bookarray[], int numbooks)
{
    //print all books within the array that are available for check out
    cout << "The following books are available for check out:\n";
    for(int index=0; index < numbooks; index++)
    {
        if(bookarray[index].status==0)
        {
            cout << bookarray[index].author << ". " <<
            bookarray[index].title << ". ISBN:" <<
            bookarray[index].isbn << "\n\tAvailable Copies:" <<
            bookarray[index].availcopies << endl;
        }
    }

    //print all books within the array that are currently checked out
    cout << "\nThe following books are currently checked out and thus unavailable:\n";
    for(int index=0; index < numbooks; index++)
    {
        if(bookarray[index].status==1)
        {
            cout << bookarray[index].author << ". " <<
            bookarray[index].title << ". ISBN:" <<
            bookarray[index].isbn << endl;
        }
    }
}

//allows user to check out a book
void checkout(Book bookarray[], int numbooks)
{
    int selection; //to hold user book choice

    //print list of books
    for(int index=0; index < numbooks; index++)
    {
        cout << (index+1) << ". " <<
        bookarray[index].author << ". " <<
        bookarray[index].title << ". ISBN: " <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status: ";
        if (bookarray[index].status==0)
            cout << "ON SHELF" << endl;
        else
            cout << "CHECKED OUT" << endl;
    }
    cout << "Please enter a number from the list above to check out a copy of that book\n";
    cin >> selection;
    //validate selection
    while(selection < 1 || selection > numbooks)
    {
        cout << "Invalid entry. Please select a number from the list above\n";
        cin >> selection;
    }

    //if there are available copies, allow for check out and adjust available copies
    if(bookarray[selection-1].availcopies > 0)
    {
        bookarray[selection-1].availcopies--;
            //if available copies goes down to zero, status is changed to checked out
            if(bookarray[selection-1].availcopies==0)
            {
                bookarray[selection-1].status=1;
            }
        cout << "You have checked out one copy of " << bookarray[selection-1].title << " by "
        << bookarray[selection-1].author << endl;
    }
    else
        cout << "All copies of that book are currently checked out\n";
}

//allows user to check in a book
void checkin(Book bookarray[], int numbooks)
{
    int selection; //to hold user choice
    //print book list
    for(int index=0; index < numbooks; index++)
    {
        cout << (index+1) << ". " <<
        bookarray[index].author << ". " <<
        bookarray[index].title << ". ISBN:" <<
        bookarray[index].isbn << "\n\tAvailable Copies:" <<
        bookarray[index].availcopies << " Status: ";
        if (bookarray[index].status==0)
            cout << "ON SHELF" << endl;
        else
            cout << "CHECKED OUT" << endl;
    }
    cout << "Please enter a number from the list above to check in a copy of that book\n";
    cin >> selection;
    //validate selection
    while(selection < 1 || selection > numbooks)
    {
        cout << "Invalid entry. Please select a number from the list above\n";
        cin >> selection;
    }
    //as long as the available copies number is not more than the total copies in the library, check in the book
    if(bookarray[selection-1].availcopies < bookarray[selection-1].totalcopies)
    {
        //if all copies were checked out and one is now checked back in, change status to On Shelf
        if(bookarray[selection-1].availcopies==0)
        {
            bookarray[selection-1].status=0;
        }
        bookarray[selection-1].availcopies++;
        cout << "You have checked in one copy of " << bookarray[selection-1].title
        << " by " << bookarray[selection-1].author << endl;
    }
    else
        cout << "All copies of that book are already accounted for.\n Your check in attempt has failed.";
}

//pulls books in from current file (if it exists)
//allows user to add books
int addbooks(Book bookarray[], const int NUM_BOOKS)
{
    ifstream readFile; //to read from file
    char choice; //to hold user choice

    readFile.open("books.txt"); //open the file

    int counter=0; //counts the number of books added to the array
    if (readFile) //if file exists
    {
        while(readFile && counter < NUM_BOOKS) //fill array from file
        {
            string dump;
            getline(readFile, bookarray[counter].author);
            getline(readFile, bookarray[counter].title);
            getline(readFile, bookarray[counter].isbn);
            readFile >> bookarray[counter].totalcopies;
            readFile >> bookarray[counter].availcopies;
            readFile >> bookarray[counter].status;
            getline(readFile, dump);
            counter++;
        }
    }
    else
        cout << "No file was read\n\n"; //user will then need to enter books

    cout << "Welcome to Soren's Library!\nThere are currently " << counter <<
    " books in this library\nDo you want to add a book?\nY/N: ";

    cin >> choice;
    cin.ignore();

    if(choice=='n' || choice=='N') //if user doesn't want to enter books, return to main
    {
        return counter;
    }

    //get new book information from user and store in array while the user wants to enter books
    do
    {
        Book newbook;
        cout << "Enter the author name in the following format: Lastname, Firstname\n";
        getline(cin, newbook.author);
        cout << "Enter the title of the Book:\n";
        getline(cin, newbook.title);
        cout << "Enter the ISBN Number:\n";
        getline(cin, newbook.isbn);
        cout << "How many copies of this book do you wish to add?\n";
        cin >> newbook.totalcopies;
        newbook.availcopies=newbook.totalcopies;
        newbook.status=0;

        //write to the bookarray
        bookarray[counter].author=newbook.author;
        bookarray[counter].title=newbook.title;
        bookarray[counter].isbn=newbook.isbn;
        bookarray[counter].totalcopies=newbook.totalcopies;
        bookarray[counter].availcopies=newbook.availcopies;
        bookarray[counter].status=newbook.status;
        counter++;

        cout << "\nDo you wish to add another book? Enter Y/N: ";
        cin >> choice;
        cin.ignore();
    }
    while(choice =='Y' || choice == 'y' && counter < NUM_BOOKS);
    //if user reaches max number of books, no more can be entered
    if (counter >= NUM_BOOKS)
    {
        cout << "You have reached the maximum number of books\n";
        return counter;
    }
    readFile.close();
    return counter;
}

//prints contents of book array to the file
void bookstofile(Book bookarray[], int numbooks)
{
    ofstream writeFile;
    writeFile.open("books.txt");
    for(int index=0; index < numbooks; index++)
    {
        if (index != 0)
          writeFile << endl;
        writeFile << bookarray[index].author << endl << bookarray[index].title << endl
        << bookarray[index].isbn << endl << bookarray[index].totalcopies << " "
        << bookarray[index].availcopies << " " << bookarray[index].status;
    }
    writeFile.close();
}
