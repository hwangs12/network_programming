#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
#include <sstream>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

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

    if (game_start == 0)
    {
        std::cout << "thanks for joining. see you next time" << std::endl;
        exit(0);
    }

    fd_set fdset;
    struct timeval timeout;
    int  rc;
    int  val;

    timeout.tv_sec = 5;   /* wait for 6 seconds for data */
    timeout.tv_usec = 0;



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
        FD_ZERO(&fdset);

        FD_SET(0, &fdset);

        rc = select(1, &fdset, NULL, NULL, &timeout);
        if (rc == -1)  /* select failed */
        {
            printf("ERROR path\n");
            break;
        }
        else if (rc == 0)  /* select timed out */
        {
            printf("You didn't choose any. Please try again\n");
            continue;
        }
        else 
        {
            if (FD_ISSET(0, &fdset)) 
            {
                val = getchar();
            }
        }
        std::cout << "?????? " << val << " ??????" << std::endl;
       /*  std::cout << "waiting 5 seconds for response..." << std::endl;
        std::cin >> user_input;

        int kaka = user_input == "ROCK";

        std::cout << kaka << std::endl;
 */
        if (val != 'R' && val != 'P' && val != 'S')
        {
            std::cout << "The only allowed shot is ROCK, PAPER, SCISSOR. Please try again." << std::endl;
            continue;
        }
        else
        {
            std::cout << val << " was your shot!" << std::endl;
            std::cout << "Do you want to continue? Press 1 to continue the game Press 0 to exit" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cin >> game_start;
            if (game_start == 0)
            {
                break;
            }
            continue;
        }
    }
    while (game_start != 0);


    std::cout << "It was pleasure to meet you. See you next time!" << std::endl;

    return 0;
}