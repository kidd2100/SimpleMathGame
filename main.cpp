/*
Two Players compete on answering simple Math Problems.
Scores are added up thru out game, and winner declared at end.

                               Written By Eric Michael Cauley
                               Utilizing CodeBlocks 20.03
                               12/02/2020
*/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Structs
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
struct player{

    string playerName;
    int playerScore;

};
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Function Declarations
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
void intro();
int startGame();
void endGame(int, int, string, string);

int main()
{
    intro();
    player player1;
    player player2;
    player1.playerScore = 0;
    player2.playerScore = 0;
    srand(time(0));
    bool keepPlaying = true;


    cout << "What is player 1's name?\n>";
    cin >> player1.playerName;
    cout << "What is player 2's name?\n>";
    cin >> player2.playerName;

    while(keepPlaying == true){
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(20) << setfill('=') << player1.playerName << " , it is your turn. \n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n\n";

    player1.playerScore = player1.playerScore + startGame();

    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(20) << setfill('=') << player2.playerName << " , it is your turn.\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n\n";

    player2.playerScore = player2.playerScore + startGame();

    cout << player1.playerName << " has scored " << player1.playerScore << " points!\n"
         << player2.playerName << " has scored " << player2.playerScore << " points!\n";
    cout << "Do you wish to keep playing, Y or N?\n>";
         char y;
         cin >> y;
         if(y != 'y' && y != 'Y')
            keepPlaying = false;
    }

    endGame(player1.playerScore, player2.playerScore, player1.playerName, player2.playerName);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Function Intro
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void intro(){
    cout << setfill('=') << setw(60) << "\n";
    cout << setfill('=') << setw(60) << "\n";
    cout << "This is a simple game where two players complete answering\n"
         << "simple math problems. After 5 questions the scores are \n"
         << "added up. If the two players are finished playing, the game\n"
         <<"will end.\n";
    cout << setfill('=') << setw(60) << "\n";
    cout << setfill('=') << setw(60) << "\n\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Function Start Game
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

int startGame(){
    int score = 0;
    int userInput;

    for(int x = 0;  x < 5 ; x++){
    int firstNumber = rand()%10;
    int secondNumber = rand()%10;
    int randomOperator = rand()%3;

    switch(randomOperator){// Switch statement to determine what type of math problems to ask the players
    case 1:
    cout << right << setw(4) << setfill(' ') << firstNumber;
    cout << right << setw(5) << "\nx  " << secondNumber << "\n____\n>";
    cin  >> userInput;
    if (userInput == firstNumber * secondNumber)
        score += 10;
    cout << endl;
    break;
    case 2:
            cout << right << setw(4) << setfill(' ') << firstNumber;
    cout << right << setw(5) << "\n+  " << secondNumber << "\n____\n>";
    cin  >> userInput;
    if (userInput == firstNumber + secondNumber)
        score += 10;
    break;
    default:
            cout << right << setw(4) << setfill(' ') << firstNumber;
    cout << right << setw(5) << "\n-  " << secondNumber << "\n____\n>";
    cin  >> userInput;
    if (userInput == firstNumber - secondNumber)
        score += 10;
    break;

    }
}
return score;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Function End Game
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void endGame(int player1Score, int player2Score, string player1Name, string player2Name){
    cout << "\n\n";
     cout << "________________$$$$__________________$$$$\n";
 cout << "_______________$__$$_________________$$__$\n";
 cout << "______________$$___$_________________$___$$\n";
 cout << "______________$$___$_________________$___$$\n";
 cout << "_____________$$___$$_________________$___$$\n";
 cout << "____________$$____$__________________$____$$\n";
 cout << "__________$$$____$$__________________$$____$$$\n";
 cout << "_________$$_____$$____________________$$_____$$\n";
 cout << "________$$______$$____________________$$______$$\n";
 cout << "_______$$_______$_______________________$_______$$\n";
 cout << "______$$________$$$$$$$___________$$$$$$$________$$\n";
 cout << "__$$$$$_______________$$$_______$$$_______________$$$$\n";
 cout << "_$$$____________$$$$____$$_____$$____$$$$____________$$\n";
 cout << "$$____________$$$__$$$___$_____$___$$$__$$$___________$\n";
 cout << "$____________$$$________$$_____$$________$$$___________$\n";
 cout << "$____________$$$$$$____$$_______$$____$$$$$$___________$\n";
 cout << "$___________$$____$$$$$$$_______$$$$$$$____$$__________$\n";
 cout << "$___________$$$$_______$$_______$$_______$$$$__________$\n";
 cout << "$$_________$$__$$$$$$$$$_________$$$$$$$$$__$$________$\n";
 cout << "_$$$$_____$$$$________$___________$________$$$$______$$\n";
 cout << "__$$$$$____$$$$$$____$$___________$$____$$$$$$____$$$$\n";
 cout << "______$$__$$____$$$$$$_____________$$$$$$____$$__$$\n";
 cout << "_______$$$_$$$_____$________________$_____$$$_$$$\n";
 cout << "_________$$$$$$$$$$__________________$$$$$$$$$..\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << "Thank you so much for playing!\n\n";
    cout << player1Name << " has scored " << player1Score << " points!\n"
         << player2Name << " has scored " << player2Score << " points!\n";
    cout << setw(60) << setfill('*') << "\n";
    cout << setw(60) << setfill('*') << "\n";




}

