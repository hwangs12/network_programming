#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int main()
{
    enum Game {ROCK, PAPER, SCISSOR};
    std::string user_input;
    int game_start;
    std::cout << "Hello there. Let's start the game. " << std::endl;
    std::cout << "This is rock paper scissor game." << std::endl;
    std::cout << "You are only allowed the following: ROCK, PAPER, SCISSOR" << std::endl;
    std::cout << "Do you want to continue? Press 1 to start the game Press 0 to exit" << std::endl;
    std::cin >> game_start;



    do 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Awesome. I am going to shout out ROCK, PAPER, SCISSOR. PICK YOURS!" << std::endl;
        sleep_for(1s);
        std::cout << "ROCK!" << std::endl;
        sleep_for(1s);
        std::cout << "PAPER!" << std::endl;
        sleep_for(1s);
        std::cout << "SCISSOR!" << std::endl;

        std::cout << "waiting 5 seconds for response..." << std::endl;
        sleep_for(5s);


        std::cin >> user_input;
        
        std::ostringstream oss{};
        oss << std::cin.rdbuf();
        std::string all_chars{oss.str()};
        std::cout << all_chars;
        break;

        if (user_input != "ROCK" || user_input != "PAPER" || user_input != "SCISSOR")
        {
            std::cout << "The only allowed shot is ROCK, PAPER, SCISSOR. Please try again." << std::endl;
        }
        else
        {
            std::cout << user_input << " was your shot!" << std::endl;
            std::cout << "Do you want to continue? Press 1 to continue the game Press 0 to exit" << std::endl;
            std::cin >> game_start;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> user_input;
    }
    while (game_start != 0);


    std::cout << "It was pleasure to meet you. See you next time!" << std::endl;

    return 0;
}