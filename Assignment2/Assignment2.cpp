#include <iostream>
#include "Motor.h"

bool motorOn = false;

int main(){
    RotationMotor myMotor;
    std::string command;

    std::cout<<"Supported commands are:\n"
        <<"\tstart     Start the motor\n"
        <<"\tshutdown  Turn the program off\n"
        <<"\trestart   Restart the motor\n"
        <<"\tincRPM    Increase RPM by 5.0\n"
        <<"\tdecRPM    Decrease RPM by 5.0\n"
        <<"\tgetRPM    Get the RPM value\n";

    while(1){
      std::cout<<"Please enter your command:"<<std::endl;
      std::cin>>command;
        if (command=="start"){
            myMotor.start();
            motorOn = true;
        }
        else if ((command=="shutdown")&&motorOn){
            myMotor.shutdown();
            motorOn = false;
            return 0;
        }
        else if ((command=="restart")&&motorOn){
            myMotor.restart();
        }
        else if ((command=="incRPM")&&motorOn){
            myMotor.incRPM();
        }
        else if ((command=="decRPM")&&motorOn){
            myMotor.decRPM();
        }
        else if ((command=="getRPM")&&motorOn){
	    std::cout<<"RPM = "<<myMotor.getRPM()<<std::endl;
        }
        else {
	    std::cerr<<"Command cannot be exceuted. Unvalid command or the motor has not been started yet."<<std::endl;
        }
    }
    return 0;
}
