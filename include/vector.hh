#pragma once

#include "SIZE.hh"
#include <iostream>
#include <stdexcept>
#include <math.h>

class Vector {

private:

    double wspolrzedne[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    double dlugosc(const Vector &drugi);

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    bool operator == (const Vector &drugi) const;

    void zapeln(double argu[SIZE]);

    double modul();

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);
