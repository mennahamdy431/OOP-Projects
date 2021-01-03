
#ifndef BOOKS_H
#define BOOKS_H

#include<cstring>
#include<iostream>
#include"User.h"

using namespace std;

class Books {
private:
    string title;
    string isbn;
    int id;
    string category;
    User author;//The author is the user that write the book
    double rate;
public:
    //static member functions
    static int count;
    int numrate = 0;
    int totalrates = 0;

    //constructors
    Books();//Default constructor
    Books(string, string, string);//parameterize constructor
    Books(const Books &);//copy constructor
    //Setters
    void setISBN(string);

    void setTitle(string);

    void setId(int);

    void setCategory(string);

    void setAuthor(User);

    void rateBook(int);

    //Getters
    string getTitle();

    string getISBN();

    string getCategory();

    int getId();

    User getAuthor();

    //operator overloading
    bool operator==(const Books &book);

    friend ostream &operator<<(ostream &output, const Books &book);

    friend istream &operator>>(istream &input, Books &book);
};

#endif // BOOKS_H
