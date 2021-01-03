#pragma once
#include"Books.h"
class BookList

	{ private:
		Books* books;
			 int capacity;
			 int length;
			 int booksCount=0;
			 int BooksDelete = 0;

	public:

		BookList(const BookList & anotherList);
			 BookList(int capacity);
			 Books* searchBook(string name);
			 Books* searchBook(int id);

			 void deleteBook(int id);
			 void addBook(Books book);
			 int  getBookCount();
                void UserBooks();
                int getLengthUserBooks(User u);
			 //delete a book
			 Books getTheHighestRatedBook();
			 Books* getBooksForUser(User);
			 // get all books of this author
			 Books & operator [ ] (int position);
			 friend ostream &operator<<( ostream &output, BookList &booklist );
									  //to display all books
			 ~BookList();

};

