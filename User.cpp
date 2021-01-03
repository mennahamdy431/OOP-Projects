#include "User.h"

int User::count = 0;//counter to increment the id

User::User() {//default constructor make the member variable of the object empty when initialized
    count++;
    age = 0;
    id = count;
    name = "";
    email = "";
    password = "";
}

User::User(string Name, int Age, string Email, string Password)//parameterize constructor that
{                                                              //takes the name,age,email and password
    count++;                                                   //to the user
    id = count;
    name = Name;
    age = Age;
    email = Email;
    password = Password;
}

User::User(User &user) {//copy constructor
    name = user.name;
    age = user.age;
    email = user.email;
    password = user.password;
    id = user.id;
}

bool User::operator==(const User &obj) {//equal operator to check if two user's object equal or not
    bool status;
    if (name == obj.name && id == obj.id && age == obj.age && email == obj.email) {
        status = true;
    } else
        status = false;
    return status;
}

void User::setName(string Name) { name = Name; }//set the name of the user
string User::getName() const { return name; }//get the name of the user
void User::setPassword(string pass) { password = pass; }//set the password of the user
string User::getPassword() { return password; }//gets user's password
void User::setEmail(string Email) { email = Email; }//set the user's Email
string User::getEmail() { return email; }//get the user's email
void User::setAge(int Age) { age = Age; }//set the user's book
int User::getAge() { return age; }//get user's book
void User::setId(int ID) { id = ID; }//set user's ID
int User::getId() { return id; }//get user's ID
ostream &operator<<(ostream &output, const User &user) {
    //operator overloading to that print the user's object directly
    output << "\n========User " << user.id << " info========" << endl;

    output << "Name: " << user.name << "|Age: " << user.age;
    output << "|ID:" << user.id << "|Email:" << user.email << "\n";
    output << "=================================================\n";
    return output;
}

istream &operator>>(istream &input, User &user) {
    //operator overloading to that input the user's object directly

    input >> user.name >> user.age >> user.email >> user.password;
    return input;
}

