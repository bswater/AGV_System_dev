#include <iomanip>
#include <iostream>

int main() {
    constexpr double PI = 3.14159265358979323846;

    // Body velocity: x forward, y left, z counterclockwise.
    const double vx = 0.5;  // m/s
    const double vy = 0.2;  // m/s
    const double wz = 0.3;  // rad/s

    const double r = 0.1;   // Wheel radius (m).
    const double Lx = 0.5;  // Center-to-wheel distance along x (m).
    const double Ly = 0.5;  // Center-to-wheel distance along y (m).
    const double L = Lx + Ly;

    // Inverse kinematics; wheel angular velocities in rad/s.
    const double w_fl = (vx - vy - L * wz) / r;
    const double w_fr = (vx + vy + L * wz) / r;
    const double w_rl = (vx + vy - L * wz) / r;
    const double w_rr = (vx - vy + L * wz) / r;

    const double rpm_fl = w_fl * 60.0 / (2.0 * PI);
    const double rpm_fr = w_fr * 60.0 / (2.0 * PI);
    const double rpm_rl = w_rl * 60.0 / (2.0 * PI);
    const double rpm_rr = w_rr * 60.0 / (2.0 * PI);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "FL: " << rpm_fl << " RPM\n";
    std::cout << "FR: " << rpm_fr << " RPM\n";
    std::cout << "RL: " << rpm_rl << " RPM\n";
    std::cout << "RR: " << rpm_rr << " RPM\n";
    return 0;
}
