#ifndef DOFXYRZ_H
#define DOFXYRZ_H

#include"CartVec2D.h"

class DOFxyRz {
    friend std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs);
    friend DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs);
    friend DOFxyRz operator+(const CartVec2D &lhs, const DOFxyRz &rhs);
    friend DOFxyRz operator+(const double lhs, const DOFxyRz &rhs);
    friend DOFxyRz operator+(const DOFxyRz &lhs, const double rhs);
    friend DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs);
    friend DOFxyRz operator-(const CartVec2D &lhs, const DOFxyRz &rhs);
    friend DOFxyRz operator-(const double lhs, const DOFxyRz &rhs);
    friend DOFxyRz operator-(const DOFxyRz &lhs, const double rhs);
    public:
        DOFxyRz(); //default ctr
        DOFxyRz(double x, double y);
        DOFxyRz &operator+=(const CartVec2D &rhs);
        DOFxyRz &operator-=(const CartVec2D &rhs);
        DOFxyRz &operator+=(const double rhs);
        DOFxyRz &operator-=(const double rhs);
        void setRz(double Rz);
        double getRz() const;
        CartVec2D heading() const;
    private:
        CartVec2D xy_;
        double Rz_;
};

#endif