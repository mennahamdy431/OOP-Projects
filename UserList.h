#ifndef USERLIST_H
#define USERLIST_H

#include"User.h"
class UserList
{



private:
    User* users;
    int capacity;
    int usersCount = 0;
    int usersDelete = 0;



public:
    UserList();//default constractor

    UserList(int capacity); // parametrize constractor

    void addUser(User user);//add user at the end of the array.

    User* searchUser(string name); // search for auser by his name

    User* searchUser(int id);// search for auser by his id

    void deleteUser(int id);// delete a user from the array

    friend ostream& operator<<(ostream& output, UserList& userList); //to display all users

    ~UserList(); // destructor


};

#endif // USERLIST_H
