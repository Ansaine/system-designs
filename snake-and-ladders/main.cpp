#include<bits/stdc++.h>
#include "models/Board.h"
using namespace std;


int main(){

    int totalPlayers, totalSnakes, totalLadders;
    cout<<"Input totalPlayers, totalSnakes and totalLadders"<<endl;
    cin>>totalPlayers>>totalSnakes>>totalLadders;

    Board myBoard(totalPlayers,totalSnakes,totalLadders);
    myBoard.displayStatus();
    myBoard.playGame();

    return 0;
}