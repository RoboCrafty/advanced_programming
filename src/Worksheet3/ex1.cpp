#include <iostream>

int gcdRecursive(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcdRecursive(b, a%b);
    }
}

int gctItr(int a, int b)
{
    int _tmp = 0;
    do
    {
        _tmp = a%b;
        a = b;
        b = _tmp;
    } while (b != 0);
    return a;
}



int main()
{
    int a = 8;
    int b = 12;

    // std::cout<< "Value is: " << gcdRecursive(a,b) << std::endl;

    std::cout<< "Value is: " << gctItr(a,b) << std::endl;

}