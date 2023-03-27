#include "doctest.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;



TEST_CASE("Good input")
{
   Player p1("Alice");
   Player p2("Bob");

   

   CHECK_NOTHROW(Game(p1,p2));
   CHECK_NOTHROW(Player("Mohanad"));
   CHECK_NOTHROW_MESSAGE(Player("Safi"),"The name is not empty and not the same player, it's good");
   CHECK_NOTHROW_MESSAGE(Game(p1,p2),"The name is not empty and not the same player, it's good");

}


TEST_CASE("Success_print_Winner"){


         Player p1("Alice");
         Player p2("Bob");
         Game game(p1,p2);
         game.playAll();

         CHECK_EQ(game.isPrintDone(),true);


}


TEST_CASE("IsTurnBegin"){

   Player p1("Alice");
   Player p2("Bob");
   Game game(p1,p2);

   int i;
   for (i=0;i<5;i++) {
    game.playTurn();
    CHECK_EQ(game.getTurn(),1); 
   }

}

TEST_CASE("WithDrawOrNot"){

   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);
   int i;
   for (i=0;i<5;i++) {
    game.playTurn();
   }

   CHECK_EQ(p1.stacksize() ,21);
   CHECK_EQ(p2.cardesTaken(),21);
   // To check after draw ,if that happend!
   CHECK_LT(p1.stacksize(),21);
   CHECK_GT(p2.stacksize(),21);


}

TEST_CASE("Winner"){

   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);
   int i;
   for (i=0;i<5;i++) {
    game.playTurn();
   }

    ariel::Player::statistics sstas1 = p1.getStatistics();
    ariel::Player::statistics sstas2 = p2.getStatistics();

    sstas1.Ncards = 30;
    sstas1.draws_rate = 3.7;
    sstas1.Ndraws = 10;
    sstas1.win_rate = 1.0;

    sstas2.Ncards = 22;
    sstas2.draws_rate = 3.7;
    sstas2.Ndraws = 10;
    sstas2.win_rate = 0.0;
  
   CHECK_EQ(game.getWinner(),1);

}


TEST_CASE("Bad input"){


         Player p1("");
         Player p2("Bob");
         Player p3("");
         CHECK_THROWS(Game(p1,p2));
         CHECK_THROWS(Player(""));
         CHECK_THROWS(Game(p1,p3));
         CHECK_THROWS(Game(p1,p1));


}

TEST_CASE("Printes"){

       Player p1("Alice");
       Player p2("Bob");
       Game game(p1,p2);
       game.playAll();

       CHECK_EQ(game.isPrintDone(),true);
       CHECK_EQ(game.isPrintLastTurn(),true);
       CHECK_EQ(game.isPrintLog(),true);


}


TEST_CASE("IsPlayALLTheGame"){

         Player p1("Alice");
         Player p2("Bob");
         Game game(p1,p2);

         game.playAll();
         CHECK_EQ(game.get_Number_cards(),0);
         
}


TEST_CASE("Statistics Players"){

    Player p1("Bob");
    Player p2("Alice");
    ariel::Player::statistics sstas1 = p1.getStatistics();
    ariel::Player::statistics sstas2 = p2.getStatistics();

         CHECK_EQ(sstas1.draws_rate,0.0);
         CHECK_EQ(sstas1.Ncards,0);
         CHECK_EQ(sstas1.Ndraws,0);
         CHECK_EQ(sstas1.win_rate,0.0);

         CHECK_EQ(sstas2.draws_rate+sstas1.draws_rate,1.0);
         CHECK_EQ(sstas2.Ncards+sstas2.Ncards,52);
         CHECK_EQ(sstas2.Ndraws,sstas2.Ndraws);
         CHECK_EQ(sstas2.win_rate+sstas1.win_rate,1.0);


}




