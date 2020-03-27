#include "DOFxyRz.h"
#include <cmath>

std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs) {
    os << "CartVec2D: " << rhs.xy_ << ", " << "Rz: " << rhs.Rz_;
    return os;
}

DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs) {
    DOFxyRz result;
    result += lhs.Rz_;
    result += lhs.xy_;
    result += rhs;
    return result;
}

DOFxyRz operator+(const CartVec2D &lhs, const DOFxyRz &rhs) {
    DOFxyRz result;
    result += rhs.Rz_;
    result += rhs.xy_;
    result += lhs;
    return result;
}

DOFxyRz operator+(double lhs, const DOFxyRz &rhs) {
    DOFxyRz result;
    result += rhs.xy_;
    result += rhs.Rz_;
    result += lhs;
    return result;
}

DOFxyRz operator+(const DOFxyRz &lhs, double rhs) {
    DOFxyRz result;
    result += rhs;
    result += lhs.xy_;
    result += lhs.Rz_;
    return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs) {
    DOFxyRz result;
    result += lhs.Rz_;
    result += lhs.xy_;
    result -= rhs;
    return result;
}

DOFxyRz operator-(const CartVec2D &lhs, const DOFxyRz &rhs) {
    DOFxyRz result;
    result -= rhs.Rz_;
    result -= rhs.xy_;
    result += lhs;
    return result;
}

DOFxyRz operator-(double lhs, const DOFxyRz &rhs) {
    DOFxyRz result;
    result -= rhs.Rz_;
    result -= rhs.xy_;
    result += lhs;
    return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, double rhs) {
    DOFxyRz result;
    result += lhs.xy_;
    result += lhs.Rz_;
    result -= rhs;
    return result;
}

DOFxyRz::DOFxyRz(): DOFxyRz(0.0, 0.0) {} //default ctr

DOFxyRz::DOFxyRz(double x, double y): Rz_(0.0) {
    xy_.setX(x);
    xy_.setY(y);
}

DOFxyRz& DOFxyRz::operator+=(const CartVec2D &rhs) {
    xy_.setX(xy_.getX()+rhs.getX());
    xy_.setY(xy_.getY()+rhs.getY());
    return *this;
}

DOFxyRz& DOFxyRz::operator-=(const CartVec2D &rhs) {
    xy_.setX(xy_.getX()-rhs.getX());
    xy_.setY(xy_.getY()-rhs.getY());
    return *this;
}

DOFxyRz& DOFxyRz::operator+=(const double rhs) {
    Rz_ += rhs;
    while (Rz_ > M_PI) {
        Rz_ -= (2*M_PI);
    }
    while (rhs < -M_PI) {
        Rz_ += (2*M_PI);
    }
    return *this;
}

DOFxyRz& DOFxyRz::operator-=(const double rhs) {
    Rz_ -= rhs;
    while (Rz_ > M_PI) {
        Rz_ -= (2*M_PI);
    }
    while (rhs < -M_PI) {
        Rz_ += (2*M_PI);
    }
    return *this;
}

void DOFxyRz::setRz(double Rz) {
    while (Rz > M_PI) {
        Rz -= (2*M_PI);
    }
    while (Rz < -M_PI) {
        Rz += (2*M_PI);
    }
    Rz_ = Rz;
}

double DOFxyRz::getRz() const {
    return Rz_;
}

CartVec2D DOFxyRz::getXY() const {
    return xy_;
}

CartVec2D DOFxyRz::heading() const {
    CartVec2D result(cos(Rz_), sin(Rz_));
    return result;
}
