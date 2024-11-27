// RockPaperScissorsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  This program will ask the user to play Rock, Paper, Scissors with itself. This is handled with 6 different functions.
// 
//  The void function introLines has no parameters and prints the title and credits and does not return any values.
// 
//  The string function inputRead will input a string parameter use the first char of the input to determine if the user
//  inputted rock, paper, or scissors by using switch cases to compare chars. inputRead returns a string that indicates 
//  the choice the user made.
//  
//  The string function instructionLines will input an integer and boolean and uses the integer to decide when to instruct
//  users on how to interact with the program while the boolean will catch possible errors to get the user to type something
//  else. This function also calls the inputRead function. instructionLines returns a string that is used as the player's
//  choice.
//  
//  The string function cpuChoice will input no parameters and randomly chooses 0, 1, or 2. The function will then return
//  a string that reads one of the three choices or None if an error occurs.
// 
//  The char function showdown will input two string parameters and compare the two strings to determine if the program
//  or the user wins the round through the use of more switch cases. showdown will return a char that represents a 
//  win (w), loss (l), or tie (t) for the user. However, if an error occurs then the program assumes it was a tie.  
//  
//  The final function is main, where the program primarily runs. The main function will initiate the string variables 
//  playerInput and comInput, the integer totalRematches, the boolean variables errorNum and continuePlay, and the char
//  variable gameStatus. Main also sets the seed for the random function, it then calls the introLines function. 
//  Most of the rest of the main function is a while loop that calls the functions described earlier to input 
//  the user's choice, calculate the program's choice, compare both answers to determine the winner. The program will
//  also keep track of the number of matches played. After a round, the program will ask if the user wants to play again.
//  If the user inputs anything that starts with n, the program will stop and tell the player how many matches they played
//  if the user rematched the program. Otherwise, the program will loop to the beginnging of the while loop and starts another
//  round.


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void introLines() 
{

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Written by:    Hunter Kehler" << endl;
    cout << "Designed, coded, and debugged in an hour and a half." << endl;

}

string inputRead(string input)
{
    char inputChar = input[0];

    switch (inputChar) {

    case 'r':
    case 'R':
    case '1':
        return "Rock";

    case 'p':
    case 'P':
    case '2':
        return "Paper";

    case 's':
    case 'S':
    case '3':
        return "Scissors";

    default:
        return "None";
    }
}

string instructionLines(int rematch, bool errorNum) 
{
    string playerInput = "";
    string translatedInput = "";

    if (errorNum == true)
    {
    cout << "Let's try again!" << endl;
    cout << "Rock, paper, scissors..." << endl;

    cin >> playerInput;
    }
    else if (rematch == 0) 
    {
        cout << "The rules are simple! I'll ask you to input ";
        cout << "and I will randomly choose Rock, Paper, Scissors!" << endl;
        cout << "You can input either the full word, just a letter, or even ";
        cout << "1 for Rock, 2 for Paper, or 3 for Scissors!" << endl << endl;

        cout << "Are you ready to play?" << endl;
        cout << "Rock, paper, scissors..." << endl;

        cin >> playerInput;
    }
    else
    {
        cout << "Ready for another round? Here we go!" << endl;
        cout << "Rock, paper, scissors..." << endl;
        cin >> playerInput;
    }

    translatedInput = inputRead(playerInput);
    return translatedInput;
}

string cpuChoice()
{
    int randomChoice = (rand() % 3);

    switch (randomChoice)
    {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: "None";
    }
    return "None";
}

char showdown(string playerAnswer, string comAnswer)
{
    char charChecker = comAnswer[0];

    if (playerAnswer == comAnswer) { return 't'; }
    else if (playerAnswer == "Rock") 
    {
        switch (charChecker) 
        {
            case 'R': return 't';
            case 'P': return 'l';
            case 'S': return 'w';
        }
    }
    else if (playerAnswer == "Paper")
    {
        switch (charChecker)
        {
        case 'R': return 'w';
        case 'P': return 't';
        case 'S': return 'l';
        }
    }
    else if (playerAnswer == "Scissors")
    {
        switch (charChecker)
        {
        case 'R': return 'l';
        case 'P': return 'w';
        case 'S': return 't';
        }
    }
    return 't';
}

int main()
{
    string playerInput = "";
    string comInput = "";
    int totalRematches = 0;
    bool errorNum = false;
    bool continuePlay = true;
    char gameStatus = 'n';

    srand(time(0));

    introLines();

    while (continuePlay == true) {

        playerInput = "";
        comInput = "";
        errorNum = false;

        playerInput = instructionLines(totalRematches, errorNum);

        while (playerInput == "None")
        {
            errorNum = true;
            cout << "Whoops, that is not a valid input!" << endl;
            playerInput = instructionLines(totalRematches, errorNum);
            errorNum = false;
        }

        comInput = cpuChoice();

        gameStatus = showdown(playerInput, comInput);
    
        while (gameStatus == 't') 
        {
            errorNum = true;
            cout << "Woah, we both picked " << playerInput << " and tied!" << endl;
            playerInput = instructionLines(totalRematches, errorNum);
            comInput = cpuChoice();
            gameStatus = showdown(playerInput, comInput);
            errorNum = false;
        }

        if (gameStatus == 'w')
        {
            cout << "Congratulations! You picked " << playerInput; 
            cout << " and I picked " << comInput << "!" << endl;
            cout << "YOU WIN!" << endl << endl;
        }

        if (gameStatus == 'l')
        {
            cout << "Oh no! You picked " << playerInput;
            cout << " and I picked " << comInput << "!" << endl;
            cout << "YOU LOSE!" << endl << endl;
        }

        totalRematches += 1;

        cout << "Would you like to play again?" << endl;
        cin >> playerInput;
        if (playerInput[0] == 'n' || playerInput[0] == 'N')
        {
            continuePlay = false;
        }
    }

    if (totalRematches > 2) cout << "Thanks for playing! :D";
    else 
    {
        cout << "Thanks for playing! We played " << totalRematches;
        cout << " matches together! :D";
    }

}