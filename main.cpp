#include <iostream>
#include "UserList.h"
#include"BookList.h"


using namespace std;

void UsersMenu() {
    cout << "Users MENU\n"
         << "1- Create a USER and add it to the list\n"
         << "2- Search for a user\n"
         << "3- Display all users\n"
         << "4- Back to the main menu\n";
}

void BooksMenu() {
    cout << "BOOKS MENU\n"
         << "1- Create a book and add it to the list\n"
         << "2- Search for a book\n"
         << "3- Display all books (with book rating)\n"
         << "4- Get the highest rating book \n"
         << "5- Get all books of a user \n"
         << "6- Copy the current Book List to a new Book List and switch to do \n"
         << "7- Back to the main menu\n";
}

UserList userList;


int main() {
    Main:
    cout << "Select one of the following choices:\n";
    cout << "1- Books Menu\n"
         << "2- Users Menu\n"
         << "3- Exit\n";
    int x;
    cin >> x;

    if (x == 2) {
        cout << "How many users will be added?\n";

        int count;
        cin >> count;
        userList = UserList(count);

        manu:
        UsersMenu();
        int y;
        cin >> y;
        if (y == 1) {

            cout << "Name Age EMail Password\n";
            User user;
            cin >> user;
            userList.addUser(user);
            goto manu;
        } else if (y == 2) {
            SearchList:
            cout << "SEARCH FOR A USER\n";
            cout << "1- Search by name\n"
                 << "2- Search by id\n"
                 << "3- Return to Users Menu\n";
            cin >> x;
            if (x == 1) {
                cout << "Enter Name\n";
                string name;
                cin >> name;
                if (userList.searchUser(name) != nullptr) {

                    cout << "\n========User " << (*userList.searchUser(name)).getId() << " info========" << endl;
                    cout << *userList.searchUser(name) << endl;
                } else {
                    cout << "User Not found\n";
                    goto SearchList;
                }
                cout << "1- Delete User\n";
                cout << "2- Return to Users Menu\n";
                cin >> y;
                if (y == 1) {
                    userList.deleteUser(userList.searchUser(name)->getId());
                    goto SearchList;
                } else if (y == 2) {
                    goto manu;
                }

            } else if (x == 2) {
                cout << "Enter ID\n";
                int id;
                cin >> id;
                if (userList.searchUser(id) != nullptr) {

                    cout << "\n========User " << (*userList.searchUser(id)).getId() << " info========" << endl;
                    cout << *userList.searchUser(id) << endl;

                } else {
                    cout << "User Not fount\n";
                    goto SearchList;
                }
                cout << "1- Delete User\n";
                cout << "2- Return to Users Menu\n";
                cin >> y;
                if (y == 1) {
                    userList.deleteUser(id);
                    goto SearchList;
                } else if (y == 2) {
                    goto manu;
                }

            } else if (x == 3) {
                goto manu;
            }

        } else if (y == 3) {
            cout << userList;
            goto manu;
        } else if (y == 4) {
            cout << "=========================================================\n";
            goto Main;
        }

    } else if (x == 1) {
        cout << "How many books will be added?\n";
        int capacity;
        cin >> capacity;
        //terminate called recursively
        BookList booklist(capacity);
        BookMenu:
        BooksMenu();
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the book information in this order\n"
                 << "Title   ISBN    Category(Space separated)\n";
            Books book;
            cin >> book;
            booklist.addBook(book);
            MenueAfteraddbook:
            cout << "1- Assign author\n"
                 << "2- Continue\n";
            int y;
            cin >> y;
            if (y == 1) {
                cout << "Enter author (user) id:\n";

                int id;
                cin >> id;
                if ((userList.searchUser(id)) != nullptr) {

                    booklist[booklist.getBookCount() - 1].setAuthor(*userList.searchUser(id));
                    goto BookMenu;
                } else {
                    cout << "No user found with id = " << id << "\n";
                    goto MenueAfteraddbook;
                }

            } else if (y == 2) {
                goto BookMenu;
            }
        } else if (choice == 2) {
            cout << "SEARCH FOR A BOOK\n"
                 << "1- Search by name\n"
                 << "2- Search by id\n"
                 << "3- Return to Books Menu\n";
            int y;
            cin >> y;
            if (y == 1) {
                cout << "Enter name\n";
                string name;
                cin >> name;
                if (booklist.searchBook(name) != nullptr) {
                    cout << *(booklist.searchBook(name)) << "\n";
                    cout << "Author: " << booklist.searchBook(name)->getAuthor().getName() << "\n";
                    Books book = *(booklist.searchBook(name));
                    booksSettings:
                    cout << "1- Update author\n"
                         << "2- Update name\n"
                         << "3- Update category\n"
                         << "4- Delete Book\n"
                         << "5- Rate book\n"
                         << "6- Get back to books menu\n";
                    int num;
                    cin >> num;
                    if (num == 1) {
                        cout << "Enter new Author:\n";
                        cout << "Name Age EMail Password\n";
                        User user;
                        cin >> user;

                        book.setAuthor(user);
                    } else if (num == 2) {
                        cout << "Enter new Name:\n";
                        string n;
                        cin >> n;
                        book.setTitle(n);
                    } else if (num == 3) {
                        cout << "Enter new Category:\n";
                        string n;
                        cin >> n;
                        book.setCategory(n);
                    } else if (num == 4) {
                        booklist.deleteBook(book.getId());
                        goto BookMenu;
                    } else if (num == 5) {
                        cout << "Enter Rating Value:\n";
                        int NewRate;
                        cin >> NewRate;
                        book.setRate(NewRate);


                    } else {
                        (*booklist.searchBook(name)) = book;
                        goto BookMenu;

                    }
                    goto booksSettings;
                } else {
                    cout << "BOOK NOT FOUND\n";
                    goto BookMenu;
                }
            } else if (y == 2) {
                cout << "Enter id\n";
                int id;
                cin >> id;
                if (booklist.searchBook(id) != nullptr) {
                    cout << *(booklist.searchBook(id)) << "\n";
                    cout << "Author: " << booklist.searchBook(id)->getAuthor().getName() << "\n";
                    Books book = *booklist.searchBook(id);
                    User user;
                    user = (booklist.searchBook(id))->getAuthor();
                    book.setAuthor(user);
                    BooksSettings:
                    cout << "1- Update author\n"
                         << "2- Update name\n"
                         << "3- Update category\n"
                         << "4- Delete Book\n"
                         << "5- Rate book\n"
                         << "6- Get back to books menu\n";
                    int num;
                    cin >> num;
                    if (num == 1) {
                        cout << "Enter new Author:\n";
                        cout << "Name Age EMail Password\n";
                        User user;
                        cin >> user;
                        //booklist.searchBook(id)->setAuthor(user);
                        book.setAuthor(user);
                    } else if (num == 2) {
                        cout << "Enter new Name:\n";
                        string n;
                        cin >> n;
                        book.setTitle(n);
                    } else if (num == 3) {
                        cout << "Enter new Category:\n";
                        string n;
                        cin >> n;
                        book.setCategory(n);
                    } else if (num == 4) {
                        booklist.deleteBook(id);
                    } else if (num == 5) {
                        cout << "Enter Rating Value:\n";
                        int NewRate;
                        cin >> NewRate;
                        book.setRate(NewRate);
                    } else {
                        *booklist.searchBook(id) = book;
                        goto BookMenu;

                    }
                    goto BooksSettings;
                } else {
                    cout << "BOOK NOT FOUND\n";
                    goto BookMenu;
                }
            } else
                goto BookMenu;
        } else if (choice == 3) {
            cout << booklist << "\n";
            goto BookMenu;
        } else if (choice == 4) {
            {
                cout << booklist.getTheHighestRatedBook() << "\n";
                if (booklist.getTheHighestRatedBook().getAuthor().getName() != "") {
                    cout << "==============Author info==============\n";
                    cout << booklist.getTheHighestRatedBook().getAuthor() << "\n";
                }
            }

            goto BookMenu;
        } else if (choice == 5) {
            cout << "Enter User ID\n";
            int id;
            cin >> id;
            User u = *userList.searchUser(id);
            int Length = booklist.getLengthUserBooks(u);
            Books *arr = new Books[Length];
            arr = booklist.getBooksForUser(u);
            for (int i = 0; i < Length; i++) {
                if (arr[i].getTitle() != "")
                    cout << arr[i] << endl;
            }
        } else if (choice == 6) {
            BookList NewBooksList(booklist);
            cout << "Copied current list ("
                 << booklist.getBookCount()
                 << " books) to a new List and switched to it\n";
            goto BookMenu;

        } else
            goto Main;
    } else
        return 0;
}
