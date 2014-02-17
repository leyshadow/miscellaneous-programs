#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

char name[20];

int coinFLIP() // our function of flipping coin
{
int heads = 1;
int tails = 2; // user either picks a 1 or 2 for their choice

srand(time(0)); // seed our generator
int correctWIN = (rand()%2) + 1;  // random number between 1 and 2 here is generated

int guess = 0; // at first, no guess
cout << "Pick 1 for heads or 2 for tails: ";
cin >> guess; // user enters 1 or 2



if (guess == correctWIN){
    if (guess == 1){

    cout << "You successfully guessed heads! Congratulations.";

    }
    else {
        cout << "You successfully guess tails! Congratulations.";
    }

    }

else {
    if (guess == 1){
        cout << "Sorry, the correct flip was tails!";

    }
    else if (guess == 2){
        cout << "Sorry, the correct flip was heads!";
    }
}



cout << "Play again? y/n ";

char playAGAIN;

cin >> playAGAIN;

if (playAGAIN == 'y'){

    coinFLIP();

}


}

int main(){



cout << "Hello There, What's you name: ";

cin >> name;

cout << "Thanks " << name << ", let's begin!" << endl;

coinFLIP();

return 0;

}
