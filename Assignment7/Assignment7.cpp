#include <iostream>
#include "DOFxyRz.h"

int main() {
    DOFxyRz robot1;
    DOFxyRz robot2(2.2, 3.3);
    CartVec2D vector(4.4, 5.5);
    std::cout<<"Initial vectors:"<<std::endl;
    std::cout<<"\trobot1 = "<<robot1<<std::endl;
    std::cout<<"\trobot2 = "<<robot2<<std::endl;
    std::cout<<"\tvector = "<<vector<<std::endl;
    std::cout<<std::endl;
    std::cout<<"robot1 = robot2 + vector"<<std::endl;
    robot1 = robot2 + vector;
    std::cout<<"robot1 = robot1 + 6.7"<<std::endl;
    robot1 = robot1 + 6.7;
    std::cout<<"robot1 = "<<robot1<<std::endl;
    std::cout<<"Heading vector of robot1: "<<robot1.heading()<<std::endl;
    return 0;
}