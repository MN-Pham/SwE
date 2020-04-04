#include "device.h"
#include <vector>
#include <iostream>

int main(void) {
    Motor Dev1("Motor1");
    Motor Dev2("Motor2");
    Motor Dev3("Motor3");
    std::cout<<std::endl;
    //A list of devices
    std::vector<Device*> pVector{&Dev1, &Dev2, &Dev3};

    Dev1.setSpeed(20.0);
    std::cout<<"Speed of "<<Dev1.getID()<<" is set to "<<Dev1.getSpeed()<<std::endl;
    Dev2.setSpeed(30.0);
    std::cout<<"Speed of "<<Dev2.getID()<<" is set to "<<Dev2.getSpeed()<<std::endl;
    Dev3.setSpeed(40.0);
    std::cout<<"Speed of "<<Dev3.getID()<<" is set to "<<Dev3.getSpeed()<<std::endl;
    std::cout<<std::endl;

    //Shut device 1 down
    pVector[0]->shutdown();
    std::cout<<"Speed of "<<Dev1.getID()<<" is set to "<<Dev1.getSpeed()<<std::endl;

    //Reset device 2
    pVector[1]->reset();
    std::cout<<"Speed of "<<Dev2.getID()<<" is set to "<<Dev2.getSpeed()<<std::endl;
    std::cout<<std::endl;
}