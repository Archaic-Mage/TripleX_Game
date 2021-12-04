#include <iostream> 
#include <ctime>    

using namespace std;


void PrintIntroduction(int level) {

    // expression statements

    cout << "You are a screat agent breaking into a level " << level <<" secure sever room...\n";
    cout << "Enter the correct code to continue...\n";

}

int Randomize(int level) 
{
    return (rand()%level + level);
}

int PlayGame(int level) {   

    PrintIntroduction(level); 

    // declaration statements

    const int CodeA = Randomize(level), CodeB = Randomize(level), CodeC = Randomize(level);

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // expression statements

    cout << "\n";
    cout << "+ There are three numbers in the code..\n";
    cout << "+ The numbers add-up to: " << CodeSum << "\n";
    cout << "+ The numbers multiply to: " << CodeProduct << "\n\n";


    //store  player guess

    int GuessA, GuessB, GuessC;

    cout << "Enter your three numbers (with spaces in between): ";
    cin >> GuessA >> GuessB >> GuessC;

    //sum and product of the player guess

    int GuessSum = GuessA + GuessB + GuessC;    
    int GuessProduct = GuessA * GuessB * GuessC;

    //to check if the answer is correct

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "You Win!..\n\n";
        return 1;
    }
    else
    {
        cout << "You Lose!..\n\n";
        return 0;
    }
}

int main() // main function
{
    srand(time(NULL));
    
    int play = 1;

    const int MaxLevel = 5;

    while(play <= MaxLevel)
    {
        if(!PlayGame(play)) {

            cout << "Sorry! You have entered the wrong code, try again...\n\n";
            continue;

        } 
        else 
        {
            cout << "Congratulations! You have successfully completed level " << play << "...\n";
            cout << "You move on to the next level...\n\n";

            play++;
        }

        

        cin.clear();
        cin.ignore();
    }

    cout << "Congratulations! You are a excellent agent..\n";

    // return statement

    return 0;
}