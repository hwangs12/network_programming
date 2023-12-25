#include <iostream>
#include <string>

int main()
{
    
    std::string user_input;
    int game_start;
    std::cout << "Hello there. Let's start the game. " << std::endl;
    std::cout << "This is rock paper scissor game." << std::endl;
    std::cout << "You are only allowed the following: ROCK, PAPER, SCISSOR" << std::endl;
    std::cout << "Do you want to continue? Press 1 to start the game Press 0 to exit" << std::endl;
    std::cin >> game_start;

    do 
    {
        std::cout << 
        std::cin >> user_input;
    }
    while (game_start != 0)

    if (user_input != "ROCK" || user_input != "PAPER" || user_input != "SCISSOR")
    {
        std::cout << "The only allowed shot is ROCK, PAPER, SCISSOR. Please try again." << std::endl;
    }
    else
    {
        std::cout << user_input << " was your shot!" << std::endl;
    }


    return 0;
}