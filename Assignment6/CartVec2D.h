#ifndef CARTVEC2D_H
#define CARTVEC2D_H

#include <ostream>

/// CartVec2d represents a 2D Cartesian vector.
class CartVec2D {
    friend std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs);
    friend CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs);
    friend CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs);
    friend CartVec2D operator*(const CartVec2D &lhs, double rhs);
    friend CartVec2D operator*(double lhs, const CartVec2D &rhs);
    public:
        CartVec2D(double x, double y);
        /// Using C++11 ctor delegation for the default ctor.
        CartVec2D();
        /// Default copy ctor.
        CartVec2D(const CartVec2D &other) = default;
        /// Default assignment operator.
        CartVec2D &operator=(const CartVec2D &other) = default;
        /// Default dtor.
        ~CartVec2D() = default;
        // += and -= operators are class member functions.
        CartVec2D &operator+=(const CartVec2D &rhs);
        CartVec2D &operator-=(const CartVec2D &rhs);
        CartVec2D &operator-();
        /// Magnitude of vector.
        double length() const;
        void setX(double x);
        void setY(double y);
        double getX() const;
        double getY() const;
    private:
        double x_;
        double y_;
};
// Naming convention class data members, use _ suffix.

#endif