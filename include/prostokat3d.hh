#pragma once

#include "SIZE.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include "matrix.hh"
#include <stdexcept>
#include <string>
#include <fstream>
#include <iomanip>

#define epsilon 0.000001

class prostokat3d
{

    Vector wektor[8];

public:

    friend std::ostream &operator<<(std::ostream &out, prostokat3d const &prost);
    friend std::ofstream &operator<<(std::ofstream &of, prostokat3d const &prost);
    prostokat3d();
    void boki();
    prostokat3d obrot(double kat, int ilosc);
    prostokat3d obrot(double kat);
    Vector operator[](int punkt);
    bool zapis(const std::string &nazwa) const;
    bool owektor(Vector &wek);
    bool wczytaj(const std::string &nazwa);
    
};

std::ifstream &operator>>(std::istream &in, prostokat3d &prost);