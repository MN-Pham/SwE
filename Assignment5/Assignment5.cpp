#include <iostream>
#include "Motor.h"
#include "Command.h"

bool motorOn = false;

int main(){
    RotationMotor myMotor;
    std::string command;
    CommandProcessor cmdp;

    std::cout<<"Supported commands are:\n"
        <<"\tstart     Start the motor\n"
        <<"\tshutdown  Turn the program off\n"
        <<"\trestart   Restart the motor\n"
        <<"\tincRPM    Increase RPM by 5.0\n"
        <<"\tdecRPM    Decrease RPM by 5.0\n"
        <<"\tgetRPM    Get the RPM value\n";

    cmdp.addCommand("start",
                    std::bind(&RotationMotor::start, &myMotor));
    cmdp.addCommand("shutdown",
                    [&]() {myMotor.shutdown();
                           exit(0);});
    cmdp.addCommand("restart",
                    std::bind(&RotationMotor::restart, &myMotor));
    cmdp.addCommand("incRPM",
                    std::bind(&RotationMotor::incRPM, &myMotor));
    cmdp.addCommand("decRPM",
                    std::bind(&RotationMotor::decRPM, &myMotor));
    cmdp.addCommand("getRPM",
                    [&]() {std::cout<<"RPM = "<<myMotor.getRPM()<<std::endl;});

    while(1){
      std::cout<<"Please enter your command:"<<std::endl;
      std::cin>>command;
      cmdp.executeCommand(command);
    }
    return 0;
}
