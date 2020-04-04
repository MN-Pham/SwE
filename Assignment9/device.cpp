#include "device.h"
#include <iostream>

Device::Device(const std::string &id): ID_(id) {}

const std::string& Device::getID() const {
    return ID_;
}

Motor::Motor(const std::string &id): Device(id) {
    initialise();
}

Motor::~Motor() {
    std::cout<<"Removing the motor..."<<std::endl;
    std::cout<<"Motor "<<getID()<<" has been removed"<<std::endl;
    setSpeed(0);
}

void Motor::initialise() {
    std::cout<<"Motor has been started!"<<std::endl;
    speed_ = 0;
}

void Motor::reset() {
    std::cout<<"Motor has been reseted!"<<std::endl;
    speed_ = 0;
}

void Motor::shutdown() {
    std::cout<<"Motor has been turned off!"<<std::endl;
    speed_ = 0;
}

void Motor::setSpeed(double speed) {
    speed_ = speed;
}

double Motor::getSpeed() const {
    return speed_;
}