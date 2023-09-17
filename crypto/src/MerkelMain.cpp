#include <iostream>
#include "CSVReader.h"
#include "MerkelMain.h"

MerkelMain::MerkelMain(){

};

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

int MerkelMain::getUserOption()
{
}

void MerkelMain::printMenu()
{
    // 1 print printHelp
    std::cout << "1: Print help" << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer" << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6: Continue
    std::cout << "6: Continue" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make blah blah blah" << std::endl;
}

void MerkelMain::processUserOption(int userOption)
{
}

// void MerkelMain::printMarketStats()
// {
//     for (std::string const& p : orderBook.getKnownProduc)
// }

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
    std::cout << wallet.toString() << std::endl;
}
