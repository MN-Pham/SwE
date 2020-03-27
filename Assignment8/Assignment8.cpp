#include <iostream>
#include <fstream>
#include "DOFxyRz.h"

int main(void) {
    // Avoid the usage of #define
    const double PI{3.14159265358979323846};
    const double DELTA_t_sec{0.1};
    const double MAX_t_sec{10.0};
    double velocity{0.2}; // m/sec
    double angular_velocity{0.25 * PI};
    double t_sec = 0.0; // rad/sec
    DOFxyRz roomba;
    std::ofstream CSVfile;
    CSVfile.open ("plot.csv");
    // Simulation loop
    // This loop calculates the coordinate and rotating angle of the robot
    // every 0,1 second (DELTA_t_sec)
    while (t_sec <= MAX_t_sec) {
        std::cout << "t = " << t_sec << " " << roomba << std::endl;
        CSVfile << t_sec << "," << roomba.getXY().getX() << "," << roomba.getXY().getY() << std::endl;
        // Calculate rotation every simulation step
        roomba += angular_velocity * DELTA_t_sec;
        // Calculate translation every simulation step
        CartVec2D delta_heading(roomba.heading() * velocity * DELTA_t_sec);
        roomba += delta_heading;
        t_sec += DELTA_t_sec;
    }
}