#ifndef MOTOR_H
#define MOTOR_H

class RotationMotor{
    public:
        RotationMotor(float inRPM=0.0);
        ~RotationMotor();
        void start();
        void restart();
        void shutdown();
        void incRPM();
        void decRPM();
        float getRPM();
    private:
        float RPM;
        static constexpr float MAXPOS = 20.0;
        static constexpr float MINNEG = -20.0;
        static constexpr float STEP = 5.0;
};

#endif
