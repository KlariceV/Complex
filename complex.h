#pragma once

#include <iostream>

#define ROOT_EPSILON 0.000001

class Complex {
    private:
        double r;
        double i;
    public:
        Complex() {
            this->r = 0;
            this->i = 0;
        }
        Complex(double r, double i) {
            this->r = r;
            this->i = i;
        }
        ~Complex() {
            this->r = {};
            this->i = {};
        }
        Complex(const Complex& c) {
            this->r = c.r;
            this->i = c.i;
        }
        Complex(const double& n) {
            this->r = n;
            this->i = 0;
        }
        Complex& operator=(const Complex& c) {
            this->r = c.r;
            this->i = c.i;
            return *this;
        }
        Complex& operator=(const double& n) {
            this->r = n;
            this->i = 0;
            return *this;
        }
        Complex operator+(const Complex& c) {
            return Complex(this->r+c.r, this->i+c.i);
        }
        Complex operator+(const double& n) {
            return Complex(this->r+n, this->i);
        }
        Complex operator-(const Complex& c) {
            return Complex(this->r-c.r, this->i-c.i);
        }
        Complex operator-(const double& n) {
            return Complex(this->r-n, this->i);
        }
        Complex operator*(const Complex& c) {
            return Complex(
                this->r*c.r-this->i*c.i,
                this->r*c.i+this->i*c.r
            );
        }
        Complex operator*(const double& n) {
            return Complex(this->r*n, this->i*n);
        }
        Complex operator/(const Complex& c) {
            return Complex(
                (this->r*c.r+this->i*c.i)/(c.r*c.r+c.i*c.i),
                (-this->r*c.i+this->i*c.r)/(c.r*c.r+c.i*c.i)
            );
        }
        Complex operator/(const double& n) {
            return Complex(this->r/n, this->i/n);
        }
        Complex& operator+=(const Complex& c) {
            *this = *this + c;
            return *this;
        }
        Complex& operator+=(const double& n) {
            *this = *this + n;
            return *this;
        }
        Complex& operator-=(const Complex& c) {
            *this = *this - c;
            return *this;
        }
        Complex& operator-=(const double& n) {
            *this = *this - n;
            return *this;
        }
        Complex& operator*=(const Complex& c) {
            *this = *this * c;
            return *this;
        }
        Complex& operator*=(const double& n) {
            *this = *this * n;
            return *this;
        }
        Complex& operator/=(const Complex& c) {
            *this = *this / c;
            return *this;
        }
        Complex& operator/=(const double& n) {
            *this = *this / n;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
            os << "(" << c.r;
            if(c.i<0) os<<c.i;
            else os<<"+"<<c.i;
            os<<"i)";
            return os;
        }
        double real() {return this->r;}
        double imag() {return this->i;}
};

double abs(Complex c) {
    double s = c.real()*c.real()+c.imag()*c.imag();
    double a = s;
    while((a-s/a)>ROOT_EPSILON) {
        a=(a+s/a)/2.;
    }
    return a;
}