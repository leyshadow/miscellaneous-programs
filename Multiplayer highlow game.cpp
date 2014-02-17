#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>



#ifdef _WINDOWS // attempt at multiplatform SUPPORT!
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

using namespace std;


class player // player object type, has 3 vars
{
    public:

        int USER; // number of which the player is, 1st player, 2nd, 3rd, etc.
        int GUESS; // what they actually guess, user will input this
        int NUMguesses; // how many tries it took that specific player


};


int main()
{
    srand(time(0)); // seed our generator
    player Player1; // initialize 2 players, of the player type
    player Player2;


    Player1.USER = 1; // player1 is 1st player
    Player2.USER = 2; // player2 is 2nd player
    Player1.NUMguesses = 0; // initialize both starting guesses to 0
    Player2.NUMguesses = 0;


    int WINNER; // will be what PLAYER wins the game 1, 2, 3 ,etc
    int winnerGUESS; // how many guesses it took THAT player
    int currentuser = Player1.USER; // 1, 2, 3, etc. Says which player's turn it is
    int randomGEN = (rand()% 100 + 1); // generate random numb between 100 and 1

    cout << "Player 1 enter a guess b/w 1 and 100: "; // prompt
    cout << randomGEN;

    do // do this each type while statement is true
    {


        cin >> Player1.GUESS; // player1 enters a guess
        if(Player1.GUESS < randomGEN){ // it is too small
            cout << "Your number was too small!" << endl;
            Player1.NUMguesses++; // increment the guesses
            currentuser = Player2.USER; // switch to different user, should make it do (Player1.USER + 1) each time?
            cout <<"Now player " << currentuser << "'s turn:"; // prompt who's new turn it is
        }
        else if(Player1.GUESS > randomGEN){ // ^^^^this time too large number
            cout << "Your number was too large!" << endl;
            Player1.NUMguesses++;
            currentuser = Player2.USER;
            cout <<"Now player " << currentuser << "'s turn:"; // tell what player's turn it now is.
        }


        else if(Player1.GUESS == randomGEN){ // user got it right!
            cout << "You've won the GAME!!"; // prompt
            Player1.NUMguesses++; // increment guess for last time
            WINNER = Player1.USER; // set the playernumber to WINNER, easier to display
            winnerGUESS = Player1.NUMguesses; // how many guesses it took
            break; //exit our do first do loop, and the next do loop will be false.
        }



        do{ // next do in case the first PLAYER didnt guess correct
            cin >> Player2.GUESS; // ask for user's guess each time
            if(Player2.GUESS < randomGEN) // same as above ^^
        {
            cout << "Your number was too small!" << endl;
            Player2.NUMguesses++;
            currentuser = Player1.USER;
            cout <<"Now player " << currentuser << "'s turn:";
        }

        else if(Player2.GUESS > randomGEN)
        {
            cout << "Your number was too large!" << endl;
            Player2.NUMguesses++;
            currentuser = Player1.USER;
            cout <<"Now player " << currentuser << "'s turn:";
        }


        else if(Player2.GUESS == randomGEN)
        {
            cout << "You've won the GAME!!";
            Player2.NUMguesses++;
            WINNER = Player2.USER;
            winnerGUESS = Player2.NUMguesses;
            break;
        }
        }while(Player2.GUESS != randomGEN && currentuser == Player2.USER); // this will only happen once, since current user switches each time there is a wrong guess



    }while(Player1.GUESS != randomGEN && currentuser == Player1.USER); // this will only happen once, since current user switches each time there is a wrong guess


cout << "\nPlayer " << WINNER << " has won the game in " << (winnerGUESS) << " guesses!"; // final prompt telling who has won, etc.

    return 0;
}


