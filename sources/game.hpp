#ifndef GAME_H_
#define GAME_H_

#include "player.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{

    class Game{

        
        Player &p1;
        Player &p2;
        int cards_number = 52;
        int winner;
        bool turn;
        bool print_done;
        bool print_log_done;
        bool print_last_turn;



        public:
        

            Game(Player &pl1, Player &pl2):p1(pl1),p2(pl2){
                
                if (&p1==&p2)
                {
                    throw runtime_error("Player can't play with himself!!!");
                }
                
                if (!p1.getName().empty()&&!p2.getName().empty())
                {
                    this->p1 = pl1;
                    this->p2 = pl2;
                    this->turn = false;
                    this->print_done = false;
                    this->print_log_done = false;
                    this->print_last_turn = false;
                    this->winner = -1;
                }
                else{

                  throw runtime_error("The name should not be empty!!");

                }
                 
            }
            
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            bool getTurn();
            int get_Number_cards();
            int getWinner();
            bool isPrintLog();
            bool isPrintLastTurn();
            bool isPrintDone();
            void setLastP(bool ans);
            void setlogP(bool ans);
            void setDoneP(bool ans);
            void setTurn(bool ans);



            
        };

 };

    

#endif