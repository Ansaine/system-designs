#ifndef Publisher_hpp
#define Publisher_hpp

#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"

// will contain list of suscribers
class Publisher{
private:
    unordered_set<User*> users;

public:
    void addUser(User* user){
        users.insert(user);
    }
    void removeUser(User* user){
        users.erase(user);
    }

    void notify(string msg){
        for(auto x: users){
            x->notify(msg);
        }
    }

};

#endif