#include<iostream>
#include<array>
#include"Motor.h"

std::array<int, 3> ar{2, -2, 3};

int main()
{
    //---a--------------------------------------------//
    for (auto& el: ar)
    {
        std::cout<<el<<" ";
        el*=10;

        //el is a reference to an array element in ar
        //Hence, the value of all elements in ar will be
        //multiplied by 10 after being printed.
    }
    std::cout<<std::endl; //{20 -20 30}

    ar[0] = 10*ar[1];
    //Assign new value (10 times ar[1]) to ar[0].

    for (const auto el: ar)
    {
      std::cout<<el<<" ";
    }
    std::cout<<std::endl; //{-200 -20 30}
    
    //---b--------------------------------------------//
    //If the & in line 11 is removed, el will have different
    //address from elements of ar in the memory. Therefore, 
    //the ar remains the same at line 20.
    
    //---c--------------------------------------------//
    //The second for loop (line 25-28) only prints the
    //contents of ar without any changes. const should
    //be used to prevent any changes that cn be made by
    //mistake.

    //---d--------------------------------------------//
    //Due to the lack of the & in line 25, el is generated
    //as a new variable which has the same value as one of
    //members of ar but not the member itself.

    //---e--------------------------------------------//
    //At line 22, ar[1] can be replaced by ar.at(1).
    //This function help detect the invalid index and give
    //an error message.
    //The program still runs with ar[5] though the return
    //value does not belong to the array. However, the
    //program will aborts when seeing ar.at(1).

    //---f--------------------------------------------//
    std::array<int, 3> arNew;
    arNew=ar;

    for (const auto el: arNew)
    {
      std::cout<<el<<" ";
    }
    std::cout<<std::endl;
    //This style of copying can not be done with a classic
    //C-array.

    //---g--------------------------------------------//
    std::array<RotationMotor, 4> Motors;

    //---h--------------------------------------------//
    for (auto& member:Motors)
    {
        member.incRPM();
        std::cout<<"Current RPM = "<<member.getRPM()<<std::endl;
    }
    std::cout<<"Exit the loop."<<std::endl;
    return 0;
}
