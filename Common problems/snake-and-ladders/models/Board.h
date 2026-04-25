#ifndef BOARD_H
#define BOARD_H


#include<bits/stdc++.h>
#include "Player.h"
using namespace std;

class Board{
private:
    int totalPlayers;
    vector<Player> players;
    unordered_map<int,int> snakes_mp, ladders_mp;

public:
    Board(int totalPlayers, int totalSnakes, int totalLadders);       // will initialise snakes and ladders map with these variables
    void displayStatus();
    int toss();
    void playGame();

};

#endif