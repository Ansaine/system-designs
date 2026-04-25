#ifndef User_hpp
#define User_hpp

#include<iostream>
using namespace std;

class User{

string userID;

public:
    User(string id){
        userID = id;
    }
    void notify(string msg){
        cout<<"User "<<userID<<" received "<<msg<<endl;
    }

};

#endif