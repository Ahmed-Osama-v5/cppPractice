#include <iostream>
#include "Batta.hpp"

using namespace strategy;

int main()
{
    Le3ba le3ba;
    le3ba.perform();

    Mescoofy mescoofy;
    mescoofy.perform();

    Mo7bata mo7bata;
    mo7bata.perform();

    mo7bata.gotShot();
    mo7bata.perform();

    return 0;
}