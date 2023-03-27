#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;

    string name;
    
   
    string ariel::Player::getName(){
        return name;
    };
    
    struct ariel::Player::statistics ariel::Player::getStatistics(){
            
       ariel::Player::statistics sstas;

       sstas.draws_rate=0.0;
       sstas.win_rate=0.0;
       sstas.Ncards=0;
       sstas.Ndraws=0;

       return sstas;
        
    };

    int ariel::Player::stacksize(){
        return 0;
    };



    int ariel::Player::cardesTaken(){
        return 0;
    };



  

