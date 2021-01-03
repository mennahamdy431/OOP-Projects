#include "UserList.h"
#include "User.h"

UserList::UserList() {}

UserList::UserList(int capacity)
{
    users = new User[capacity];
}

void UserList::addUser(User user)
{
    users[usersCount] = user;
    users[usersCount].setId(usersCount + 1 + usersDelete);
    usersCount++;
}

User* UserList::searchUser(string name)
{
    for (int i = 0; i < usersCount; ++i)
    {
        if (users[i].getName() == name)
            return users + i;
    }
    return nullptr;
}

User* UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount; ++i)
    {
        if (users[i].getId() == id)
            return users + i;
    }
    return nullptr;
}

void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount; ++i)
    {
        if (users[i].getId() == id)
        {
            for (int j = i; j < usersCount - 1; ++j)
            {
                users[i] = users[i + 1];

            }
            usersCount--;
            usersDelete++;
            break;
        }
    }
}

ostream& operator<<(ostream& output, UserList& userList)
{
    for (int i = 0; i < userList.usersCount; ++i)
    {
        User user = userList.users[i];
        output << "\n========User " << userList.users[i].getId() << " info========" << endl;
        cout << user;
    }

    return output;
}

UserList::~UserList()
{
    delete[] users;
}
