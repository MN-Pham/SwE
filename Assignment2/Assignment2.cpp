#include <iostream>

using namespace std;

class RotationMotor{
    public:
        RotationMotor(float inRPM=0.0);
        ~RotationMotor();
        void start();
        void restart();
        void shutdown();
        void incRPM();
        void decRPM();
        const float getRPM();
    private:
        float RPM;
        static constexpr float MAXPOS = 20.0;
        static constexpr float MINNEG = -20.0;
        static constexpr float STEP = 5.0;
};

RotationMotor::RotationMotor(float inRPM):RPM(inRPM){
    cout<<"Motor has been generated!"<<endl;
    cout<<"RPM = "<<RPM<<endl;
}

RotationMotor::~RotationMotor(){
    cout<<"Motor has been removed!"<<endl;
}

void RotationMotor::start(){
    cout<<"Motor has been started"<<endl;
    RPM = 2.5;
    cout<<"RPM = "<<RPM<<endl;
}

const float RotationMotor::getRPM(){
    return RPM;
}

void RotationMotor::restart(){
    RPM = 0;
    cout<<"Motor has been restarted"<<endl;
}

void RotationMotor::shutdown(){
    RPM = 0;
    cout<<"Shutting down..."<<endl;
}

void RotationMotor::incRPM(){
    if ((RPM+STEP)<=MAXPOS)
        RPM+=STEP;
    else RPM=MAXPOS;
    cout<<"RPM has been increased"<<endl;
}

void RotationMotor::decRPM(){
    if ((RPM-STEP)>=MINNEG)
        RPM-=STEP;
    else RPM=MINNEG;
    cout<<"RPM has been decreased"<<endl;
}

bool motorOn = false;

int main(){
    RotationMotor myMotor;
    string command;

    cout<<"Supported commands are:\n"
        <<"\tstart: Start the motor\n"
        <<"\tshutdown: Turn the program off\n"
        <<"\trestart: Restart the motor\n"
        <<"\tincRPM: increase RPM by 5.0\n"
        <<"\tdecRPM: decrease RPM by 5.0\n"
        <<"\tgetRPM: get the RPM value\n";

    while(1){
        cout<<"Please enter your command:"<<endl;
        cin>>command;
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
            cout<<"RPM = "<<myMotor.getRPM()<<endl;
        }
        else {
            cerr<<"Command cannot be exceuted. Unvalid command or the motor has not been started yet."<<endl;
        }
    }
    return 0;
}