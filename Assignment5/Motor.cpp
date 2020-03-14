#include <iostream>
#include "Motor.h"

RotationMotor::RotationMotor(float inRPM):RPM(inRPM){
  std::cout<<"Motor has been generated!"<<std::endl;
  std::cout<<"RPM = "<<RPM<<std::endl;
}

RotationMotor::~RotationMotor(){
  std::cout<<"Motor has been removed!"<<std::endl;
}

void RotationMotor::start(){
  std::cout<<"Motor has been started"<<std::endl;
  RPM = 2.5;
  std::cout<<"RPM = "<<RPM<<std::endl;
}

float RotationMotor::getRPM(){
  return RPM;
}

void RotationMotor::restart(){
  RPM = 0;
  std::cout<<"Motor has been restarted"<<std::endl;
}

void RotationMotor::shutdown(){
  RPM = 0;
  std::cout<<"Shutting down..."<<std::endl;
}

void RotationMotor::incRPM(){
  if ((RPM+STEP)<=MAXPOS)
      RPM+=STEP;
  else RPM=MAXPOS;
  std::cout<<"RPM has been increased"<<std::endl;
}

void RotationMotor::decRPM(){
  if ((RPM-STEP)>=MINNEG)
      RPM-=STEP;
  else RPM=MINNEG;
  std::cout<<"RPM has been decreased"<<std::endl;
}
