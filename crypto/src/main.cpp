#include <iostream>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"

int main()
{
    // MerkelMain app();
    // app.init();
    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    std::cout << "Wallet has BTC " << wallet.containsCurrency("BTC", 10) << std::endl;
    std::cout << wallet.toString() << std::endl;
}