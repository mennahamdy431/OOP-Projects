#include "Books.h"

int Books::count = 0;//counter to increment the id

Books::Books()//default constructor make the member variable of the object empty
{
    count++;
    title = "";
    isbn = "";
    id = count;
    rate = 0;
    category = "";

}

//parameterize constructor take 3 arguments for the parameterize object
Books::Books(string Title, string ISBN, string Category)
{
    count++;
    id = count;
    title = Title;
    isbn = ISBN;
    category = Category;
    rate = 0;
}

Books::Books(const Books& books)//Copy constructor
{
    title = books.title;
    isbn = books.isbn;
    category = books.category;
    id = books.id;
    rate = books.rate;
}

void Books::setTitle(string Title)//set the title for the book
{
    title = Title;
}

string Books::getTitle()//get the title of the book
{
    return title;
}

void Books::setISBN(string ISBN)//function to set the ISBN for the Book
{
    isbn = ISBN;
}

string Books::getISBN()//to get ISBN of the Book
{
    return isbn;
}

void Books::setId(int ID)//Function to set the ID of the Book
{
    id = ID;
}

int Books::getId()//get ID of the Book
{
    return id;
}

void Books::setCategory(string Category)//function to set the category of the Book
{
    category = Category;
}

string Books::getCategory()//to get the category of the book
{
    return category;
}

void Books::setAuthor(User Author)//function that take an object from the user and set it as the author of the book
{
    author = Author;
}

User Books::getAuthor()//get the author of the book
{
    return author;
}

int Books::getRate()
{
    return rate;
}

void Books::setRate(int Rate)//function take the rate and compute the average rate in the rate
{
    rate = Rate;
}
/*
void Books::setNewRate(int Rate)
{
    rate = Rate;
}
*/

bool Books::operator==(const Books& book)//operator over loading that check the 2 books equal or not
{
    bool status;
    if (title == book.title && isbn == book.isbn && category == book.category && id == book.id &&
        author == book.author)
    {
        status = true;
    }
    else
        status = false;
    return status;
}


ostream& operator<<(ostream& output, const Books& book)//operator overloading that output the book's object directly
{

    output << "\n========Book " << book.id << " info ========\n";
    output << "Title : " << book.title << "\nISBN : " << book.isbn;
    output << "\nID:" << book.id << "\nCategory:" << book.category << "\nAvg Rating: " << book.rate;
    return output;
}

istream& operator>>(istream& input, Books& book)//operator overloading that input the book's object directly
{
    input >> book.title >> book.isbn >> book.category;
    return input;
}
