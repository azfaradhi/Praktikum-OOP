#include "Kompleks.hpp"

Kompleks::Kompleks(){
    this->real = 0;
    this->imag = 0;
}

Kompleks::Kompleks(double r, double i){
    this->real = r;
    this->imag = i;
}

Kompleks::Kompleks(const Kompleks& other){
    this->real = other.real;
    this->imag = other.imag;
}

double Kompleks::getReal() const{
    return real;
}

double Kompleks::getImag() const{
    return imag;
}

double Kompleks::setReal(double r){
    this->real = r;
    return r;
}

double Kompleks::setImag(double r){
    this->imag = r;
    return r;
}


Kompleks Kompleks::operator+(const Kompleks& other) const{
    double a = this->real + other.real;
    double b = this->imag + other.imag;
    return Kompleks(a,b);
}

Kompleks Kompleks::operator-(const Kompleks& other) const{
    double a = this->real - other.real;
    double b = this->imag - other.imag;
    return Kompleks(a,b);
}

Kompleks Kompleks::operator*(const Kompleks& other) const{
    double a = (this->real * other.real) - (this->imag * other.imag);
    double b = (this->real * other.imag) + (this->imag * other.real);
    return Kompleks(a,b);
}

bool Kompleks::operator==(const Kompleks& other) const{
    return (this->real == other.real && this->imag == other.imag);
}

Kompleks& Kompleks::operator=(const Kompleks& other){
    this->setReal(other.real);
    this->setImag(other.imag);
    return *this;
}

ostream& operator<<(ostream& os, const Kompleks& c){
    os << "";
    if (c.getImag() == 0){
        os << c.getReal();
    }
    else if (c.getImag() > 0){
        if (c.getReal() != 0){
            os << c.getReal() << " + " << c.getImag() << "i";
        }
        else{
            os << c.getImag() << "i";
        }
    }
    else{
        if (c.getReal() != 0){
            os << c.getReal() << " - " << (-1 * c.getImag()) << "i";
        }
        else{
            os << "- " << (-1 * c.getImag()) << "i";
        }
    }
    return os;
}