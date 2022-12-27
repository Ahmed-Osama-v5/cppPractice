#ifndef CALC_HPP
#define CALC_HPP

#include <iostream>

int add(int a, int b);

class mathClass
{
public:
    mathClass();
    ~mathClass()=default;
    int sum(int a, int b);
    int sub(int a, int b);
};

#endif // CALC_HPP