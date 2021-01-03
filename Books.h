#ifndef BOOKS_H
#define BOOKS_H

#include<cstring>
#include<iostream>
#include"User.h"

using namespace std;

class Books
{

private:
    int id;
    int rate;
    string title;
    string isbn;
    string category;
    User author;//The author is the user that write the book

public:
    //static member functions
    static int count;//counter that incremental by one and make the id equal it
    //int numrate = 0;
    //int totalrates = 0;

    //constructors
    Books();//Default constructor

    Books(string, string, string);//parameterize constructor

    Books(const Books&);//copy constructor

    //Setters
    void setISBN(string);

    void setTitle(string);

    void setId(int);

    void setCategory(string);

    void setAuthor(User);

    // void setNewRate(int);

    void setRate(int);

    //Getters
    string getTitle();

    string getISBN();

    string getCategory();

    int getId();

    int getRate();

    User getAuthor();

    //operator overloading
    bool operator==(const Books& book);

    friend ostream& operator<<(ostream& output, const Books& book);

    friend istream& operator>>(istream& input, Books& book);
};

#endif // BOOKS_H
