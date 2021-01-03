#include "BookList.h"
BookList::BookList(const BookList& anotherList)
{
    capacity = anotherList.capacity;
    booksCount = anotherList.booksCount;
    BooksDelete = anotherList.BooksDelete;
    books = new Books[anotherList.capacity];
    for (int i = 0; i < booksCount; i++) {
        books[i] = anotherList.books[i];
    }
}

BookList::BookList(int capacity)
{
    books = new Books[capacity];
}


Books* BookList::searchBook(string name)
{
    for (int i = 0; i < booksCount; ++i)
    {
        if (books[i].getTitle() == name)
            return books + i;
    }
    return nullptr;
}

Books* BookList::searchBook(int id)
{
    for (int i = 0; i < booksCount; ++i)
    {
        if (books[i].getId() == id)
            return books + i;
    }
    return nullptr;
}

void BookList::deleteBook(int id)
{
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            for (int j = i; j < booksCount - 1; j++) {
                books[i] = books[j + 1];
            }
            BooksDelete++;
            booksCount--;
            break;
        }
    }
}

void BookList::addBook(Books book)
{

    books[booksCount] = book;
    books[booksCount].setId(booksCount + 1 + BooksDelete);

    booksCount++;
}

int BookList::getBookCount()
{
    return booksCount;
}

Books BookList::getTheHighestRatedBook()
{
    int idx = 0, mx = 0;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getRate() > mx) {
            mx = books[i].getRate();
            idx = i;
        }

    }
    return books[idx];
}


Books* BookList::getBooksForUser(User user)
{
    length = 0;
    for (int i = 0; i < booksCount; i++)
    {
        if (user == books[i].getAuthor()) {
            length++;
        }

    }
    int c = 0;
    Books* arr = new Books[length];
    for (int i = 0; i < booksCount; i++)
    {
        if (user == books[i].getAuthor()) {
            arr[c++] = books[i];
        }

    }


    return books;
}
int BookList::getLengthUserBooks(User u) {

    return length;
}


Books& BookList::operator[](int position)
{
    return books[position];
}

BookList::~BookList()
{
    delete[]books;
}

ostream& operator<<(ostream& output, BookList& booklist)
{
    for (int i = 0; i < booklist.booksCount; i++) {
        output << booklist.books[i] << "\n";
        if (booklist.books[i].getAuthor().getName() != "")
        {

            output << "==============Author info==============\n";
            output << booklist.books[i].getAuthor() << "\n";
        }
    }
    return output;
}
