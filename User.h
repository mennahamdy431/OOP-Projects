
#ifndef MOHAMED_USER_H
#define MOHAMED_USER_H

#include<cstring>
#include<iostream>

using namespace std;


class User {
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;

    //constractors
    User();//Dafult constractors
    User(string, int, string, string);//parametarize constractor
    User(User &);//copy constractor
    //Setters functions
    void setName(string);

    void setPassword(string);

    void setEmail(string);

    void setAge(int);

    void setId(int);

    //Getters functions
    string getName() const;

    string getPassword();

    string getEmail();

    int getAge();

    int getId();

    //operator overloading
    bool operator==(const User &);

    friend ostream &operator<<(ostream &, const User &);

    friend istream &operator>>(istream &, User &);


};

#endif //MOHAMED_USER_H
