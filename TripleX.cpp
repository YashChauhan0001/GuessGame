#include<iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


void PrintIntroduction(int Difficulty)
{
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room....\nEnter the correct code to continue...\n\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    cout << " + There are 3 numbers in the code" << endl;
    cout << " + The codes add up to: " << CodeSum << endl;
    cout << " + The codes multiply to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
    {
        cout << "\n*** Great work agent! we are extracting files, move ahead. ***";
        return true;
    }
    
    else
    {
        cout << "\n*** Wrong code agent! be careful try again! ***";
        return false;
    }
}


int main()
{
    srand(time(NULL)); //Random sequence based on time of day.

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //Cleaning errors
        cin.ignore(); //Cleaning Buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    cout << "\n*** Great work agent! We got every file, now get back to the base safely. ***\n";

    return 0;
}