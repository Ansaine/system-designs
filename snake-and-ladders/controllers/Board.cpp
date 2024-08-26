#include "../models/Board.h"
#include "../models/Player.h"

Board::Board(int totalPlayers,int totalSnakes, int totalLadders){
    
    this->totalPlayers = totalPlayers;
    
    // add players
    int p = 1;
    while(p<=totalPlayers){
        string name;
        cout<<"Enter player "<<p<<" : ";
        cin>>name;

        Player player(name);
        players.push_back(player);
        ++p;
    }

    // input snakes
    cout<<"Enter snakes locations"<<endl;
    while (totalSnakes)
    {
        int x,y;
        cin>>x>>y;

        // start/end case
        if(x==1 or x==100){
            cout<<"Cannot set snake at start/finish"<<endl;
        }else{
            snakes_mp[x]=y;
            totalSnakes--;
        }

    }

    // input ladders    
    cout<<"Enter ladder locations"<<endl;
    while(totalLadders){
        
        int x,y;
        cin>>x>>y;

        if(x==100){
            cout<<"Cannot set ladder at finish"<<endl;
        }
        else if(snakes_mp.find(x)!=snakes_mp.end()){
            cout<<"Cannot set ladder at snake mouth"<<endl;
        }else if(snakes_mp.find(y)!=snakes_mp.end() and snakes_mp[y]==x){
            cout<<"Cannot set ladder as forming an endless loop with snake"<<endl;
        }
        else{
            ladders_mp[x]=y;
            totalLadders--;
        }
    }
}

void Board::displayStatus(){
    for(auto player:players){
        cout<<"Player "<<player.getName()<<" is at position "<<player.getPosition()<<endl;
    }
}
int Board::toss(){
    return rand()%6+1;
}

void Board::playGame(){

    // display initial status
    displayStatus();

    // game will continue until a player reaches 100
    while(true){
        // iterate for players
        for(Player& player: players){

            int step = toss();
            int position = player.getPosition();
            int newPosition = position+step;

            // end point check
            if(newPosition>100) continue;
            
            player.setPosition(newPosition);

            cout<<"Player "<<player.getName()<<" rolled a "<<step<<" and moved to "<<newPosition<<endl;

            // while position is not ladder bottom or snake mouth
            while(ladders_mp.find(newPosition)!=ladders_mp.end() or snakes_mp.find(newPosition)!=snakes_mp.end()){

                if(snakes_mp.find(newPosition)!=snakes_mp.end()){
                    cout<<"Player "<<player.getName()<<" got bitten by snake at "<<newPosition<<endl;
                    newPosition = snakes_mp[newPosition];
                    player.setPosition(newPosition);
                    cout<<"Player "<<player.getName()<<" moved to "<<newPosition<<" after snake bit"<<endl;
                }

                if(ladders_mp.find(newPosition)!=ladders_mp.end()){
                    cout<<"Player "<<player.getName()<<" climbed ladder at "<<newPosition<<endl;
                    newPosition = ladders_mp[newPosition];
                    player.setPosition(newPosition);
                    cout<<"Player "<<player.getName()<<" moved to "<<newPosition<<" after climbing ladder"<<endl;
                }
                
            }

            // check if player has won
            if(newPosition==100){
                cout<<"Player "<<player.getName()<<" has won the game"<<endl;
                exit(0);
            }
        }

    }    
}