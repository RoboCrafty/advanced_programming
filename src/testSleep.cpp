#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char** argv)
{

    int ms = std::stoi(argv[1]);
    int i = 0;

    while (true)
    {
        i++;
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
    
}