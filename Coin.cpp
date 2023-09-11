#include <iostream>
#include "Coin.h"
#include <time.h>
#include <cstdlib>

using namespace std;

char Coin::GetResult(){
    return _result;
}

bool Coin::Toss(){
    try
    {
        srand(time(0));
        int randomNumber = rand() % 2;
        _result = (randomNumber == 0) ? HEAD : TAIL;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Coin::WinOrLose(char userChoice)
{
    return userChoice == _result;
}