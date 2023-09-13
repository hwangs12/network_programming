#include "OrderBook.h"
#include "CSVReader.h"
#include "MerkelMain.h"

MerkelMain::MerkelMain(){

};

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}