#include <iostream>
#include <cstdlib>
#include <cmath>


double sum (double &a, double &b)
{
    return a + b;
}

double subtract (double &a, double &b)
{
    return a - b;

}

double multiply(double &a, double &b) {
    return a*b;
}

double divide(double &a, double &b) {
    if (b == 0) {
        return 0.0;
    }
    else {
        return a / b;
    }
}

double menu (char& opr, double &a, double &b)
{
    switch (opr)
    {
    case '+':
        return sum(a, b);
        break;
    case '-':
        return subtract(a, b);
        break;
    case '*':
        return multiply(a, b);
        break;
    case '/':
        return divide(a, b);
        break;
    default:
        break;
    }

    return 0;
}

int main (int argc, char** argv)
{
    char opr;
    double a, b;
    std::cout << "Enter operand (+, -, *, /): ";
    std::cin >> opr;
    std::cout << std::endl;

    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << std::endl;

    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << std::endl;

    std::cout << "Result = " << menu(opr, a, b) << std::endl;


    return 0;
}