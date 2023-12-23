#include <iostream>
#include <string>

int main()
{
    
    std::string user_input;
    std::cout << "Hello there. Let's start the game. " << std::endl;
    std::cout << "This is rock paper scissor game." << std::endl;
    std::cout << "You are only allowed the following: ROCK, PAPER, SCISSOR" << std::endl;

    std::cin >> user_input;

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