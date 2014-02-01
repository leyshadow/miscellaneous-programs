#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string Playername;
char Playagain; // will user press y/n to play again at end

int DICEGAME(); // recall our function so compiler sees it here

int main()
{
    srand(time(0)); // seed our generator randomly

    cout << "Hello there! Please enter your name: ";

    cin >> Playername; // get the player's name

    cout << "ok, " << Playername << ", let's begin!" << endl;

    DICEGAME();

return 0; // exit our function
}

int DICEGAME()
{
    do // start a do loop
    {

        int HeadsOrTails = (rand()%2) + 1; // create a random number between 1 and 2

        cout << "Enter heads or tails into the console: ";

        string Userguess;// our user's guess

        cin >> Userguess;
        int ConvertedUserguess; // will become a 1 or 2 depending on heads/ tails

        if (Userguess == "heads" || Userguess == "HEADS" || Userguess == "Heads") // begin if statement
        {
            ConvertedUserguess = 1;

        }
        else // if it's not heads, it has to be tails?
        {
            ConvertedUserguess = 2;
        }

        if (ConvertedUserguess == HeadsOrTails) // if it's correct
        {
            cout << "Congratulations, you guessed " << Userguess << "!" << endl;
        }

        else // our else here
            cout << "Sorry, you incorrectly guessed "<< Userguess << "." << endl;

        cout << "Would you like to play again? y/n";


        cin >> Playagain;

    }while (Playagain == 'y' || Playagain == 'Y');


}
