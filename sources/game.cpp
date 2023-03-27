#include "game.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

  
    void ariel::Game::playTurn(){
      this->setTurn(true);
      }

    void ariel::Game::printLastTurn(){
      this->setLastP(true);
    }

    void ariel::Game::playAll(){
       while (cards_number>0)
       {
        this->playTurn();
        this->cards_number--;
       }
       
       
    }

    void ariel::Game::printWiner(){
        this->setDoneP(true);
    }

    int ariel::Game::getWinner(){
       if (p1.getStatistics().Ncards>p2.getStatistics().Ncards)
        {
         winner = 1;
         
        }
        else{
         winner = 2;
        }
      return winner;
    }

    void ariel::Game::printLog(){
        this->setlogP(true);
    }

    void ariel::Game::printStats(){
      cout<<p1.getStatistics().draws_rate;
      cout<<p1.getStatistics().win_rate;
      cout<<p1.getStatistics().Ncards;
      cout<<p1.getStatistics().Ndraws;
    }

    int ariel::Game::get_Number_cards(){return this->cards_number;}

     bool ariel::Game::isPrintLog(){

        return this->print_log_done;

     }

     bool ariel::Game::isPrintLastTurn(){

      return this->print_last_turn;

     }

     bool ariel::Game::isPrintDone(){

      return this->print_done;

     }

     void ariel::Game::setLastP(bool ans){

        this->print_last_turn = ans;

     }

     

    void ariel::Game::setlogP(bool ans){

        this->print_log_done = ans;

     }

    
      void ariel::Game::setDoneP(bool ans){

        this->print_done = ans;

     }

     


      void ariel::Game::setTurn(bool ans){

        this->turn = ans;

     }
      bool ariel::Game::getTurn(){

        return this->turn;

     }
            
            
            




