#include <thread>
#include <iostream>
int x=0;
void work1()
{
    while (x!=1)
    {   std::cout << "This is work1, ID is " << &std::this_thread::get_id << std::endl;
        // std::cout << "I am work1 while the main loop waits for your input" << std::endl;
    }
}
void work2()
{
    while (x!=2)
    {  
        std::cout << "This is work2, ID is " << &std::this_thread::get_id << std::endl;
    }   
}
void updX(){
    std::cin >> x;
}

int main(){
    while (x!=99)
    {
        std::thread Worker1(work1);
        std::thread Worker2(work2);
        std::thread inputUpdater(updX);
        
        Worker1.join();
        Worker2.join();
        inputUpdater.join();
    }
    
    return 0;
}
