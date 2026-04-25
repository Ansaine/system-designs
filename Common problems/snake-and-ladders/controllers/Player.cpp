#include "../models/Player.h"

Player::Player(string name){
    this->name = name;
    position = 0;
    cout<<"Player "<<name<<" initialised"<<endl;
}

string Player::getName(){
    return name;
}
int Player::getPosition(){
    return position;
}
void Player::setPosition(int position){
    this->position = position;
}