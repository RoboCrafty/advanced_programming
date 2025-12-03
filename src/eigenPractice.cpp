// As part of the Wks5 Ex2, I need to practice the basic of the Eigen library. 
#include <iostream>
#include <Eigen/Dense> 

Eigen::Matrix3d m1;



int main ()
{
    m1 = Eigen::Matrix3d::Random();
    m1 <<  -1,0,0,
            4,5,6,
            7,8,9;

    Eigen::Vector3d v1;
    v1 << 1,2,6;

    
    

    auto r1 = m1*v1;

    std::cout << "Here is the multiplication :\n" << r1 << std::endl;
    return 0;
}