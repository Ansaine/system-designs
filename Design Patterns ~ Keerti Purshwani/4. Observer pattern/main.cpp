#include<bits/stdc++.h>
#include "Publisher.hpp"
#include "User.hpp"

using namespace std;

int main(){


    // create 3 users with user ID
    User* user1 = new User("ID1");
    User* user2 = new User("ID2");
    User* user3 = new User("ID3");

    // insert them into publisher group
    Publisher publisher;
    publisher.addUser(user1);
    publisher.addUser(user2);
    publisher.addUser(user3);

    publisher.notify("This is message 1");
    publisher.removeUser(user2);
    publisher.notify("This is message 2");

    return 0;
}