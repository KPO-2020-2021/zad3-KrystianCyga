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

class prostokat
{

    Vector wektor[4];

    double AB, BC, CD, DA;

public:

    friend std::ostream &operator<<(std::ostream &out, prostokat const &prost);
    friend std::ofstream &operator<<(std::ofstream &of, prostokat const &prost);
    prostokat();
    void boki();
    prostokat obrot(double kat, int ilosc);
    prostokat obrot(double kat);
    Vector operator[](int punkt);
    bool zapis(const std::string &nazwa) const;
    bool owektor(Vector &wek);
    bool wczytaj(const std::string &nazwa);
    
};

std::ifstream &operator>>(std::istream &in, prostokat &prost);
