#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main()
{
    Game game("/home/eduardo/VocabularioIngles.txt");
    game.Run();

    return 0;
}