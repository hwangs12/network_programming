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