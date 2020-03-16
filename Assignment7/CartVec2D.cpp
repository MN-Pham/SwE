#include "CartVec2D.h"
#include <cmath>

std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs) {
    os << "[" << rhs.x_ << "," << rhs.y_ << "]";
    return os;
}

CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs) {
    CartVec2D result;
    result -= rhs;
    result += lhs;
    return result;
}

CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs) {
    CartVec2D result;
    result += rhs;
    result += lhs;
    return result;
}

CartVec2D operator*(const CartVec2D &lhs, double rhs) {
    CartVec2D result;
    result.setX(lhs.x_ * rhs);
    result.setY(lhs.y_ * rhs);
    return result;
}

CartVec2D operator*(double lhs, const CartVec2D &rhs) {
    return rhs*lhs;
}

CartVec2D::CartVec2D(double x, double y): x_(x), y_(y) {}

CartVec2D::CartVec2D(): CartVec2D(0.0, 0.0) {};

CartVec2D& CartVec2D::operator+=(const CartVec2D &rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}

CartVec2D& CartVec2D::operator-=(const CartVec2D &rhs) {
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

CartVec2D& CartVec2D::operator-() {
    x_ = -x_;
    y_ = -y_;
    return *this;
}

double CartVec2D::length() const {
    return sqrt(x_*x_ + y_*y_);
}

void CartVec2D::setX(double x) {
    x_ = x;
}

void CartVec2D::setY(double y) {
    y_ = y;
}

double CartVec2D::getX() const {
    return x_;
}

double CartVec2D::getY() const {
    return y_;
}