#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <iostream>
using namespace std;


namespace ariel{

    class Player {


    string name;
    
    public:
    struct statistics
    {
        int Ncards;
        int Ndraws;
        double win_rate;
        double draws_rate;
        //Card cards_won();
    };

   
    

    
    Player(string const &name){
        if(!name.empty()){
             this->name=name;
        }else{
            throw runtime_error("The name should not be empty!!");
        }
    }
    
    Player(){}
    string getName();
    int stacksize();
    int cardesTaken();
    struct statistics getStatistics();

    };


    
    

};

#endif 