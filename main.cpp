//the program thake a user's Book information and print this information
//and take an information and rating and the information of the author
//and print the information of the Book and it's author and the
//Avrage rating;

//the author is the user that write the book

#include <iostream>
#include "User.h"
#include "Books.h"

using namespace std;

int main() {
    User user1;
    cout << "Let's add a user\nEnter the user info in this order\nName Age Email Password\n";
    cin >> user1;
    cout << user1;

    cout << "Let's add another user\nEnter the user info in this order\nName Age Email Password\n";
    User user2;
    cin >> user2;
    cout << user2 << endl << endl;
    cout << "Let's add a Book\nEnter the Book information in this order\nTitel ISPN Catagory\n";
    Books Book1;
    cin >> Book1;
    cout << Book1 << endl;
    cout << "Let's add another Book\nEnter the Book info in this order\nTitel ISPN Catagory\n";

    Books Book2;
    cin >> Book2;
    cout << Book2 << endl;
    Book1.setAuthor(user1);
    cout << "Let's assign an author for the first book, set the first user as an author\n";
    cout << "Let's rate the first book with 3 and 4 ratings and print the book info\n";
    Book1.rateBook(4);
    Book1.rateBook(3);
    cout << Book1 << Book1.getAuthor() << endl;
    cout << "==================================\n\n";

    cout << "Let's add a new rating for book1 with 5 and print the book info\n";
    Book1.rateBook(5);
    cout << Book1 << Book1.getAuthor() << endl;
}
