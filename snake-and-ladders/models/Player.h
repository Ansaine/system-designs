#ifndef Player_H
#define Player_H

#include<bits/stdc++.h>
using namespace std;

class Player{
private:
    string name;
    int position;

public:
    Player(string name); 
    string getName();
    int getPosition();
    void setPosition(int position);
};

#endif