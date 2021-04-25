#pragma once

#include "SIZE.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#define epsilon 0.000001

class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy

public:
    Matrix(double[SIZE][SIZE]); // Konstruktor klasy

    Matrix(); // Konstruktor klasy

    Vector operator*(Vector tmp); // Operator mnożenia przez wektor

    Matrix operator+(Matrix tmp);

    double &operator()(unsigned int row, unsigned int column);

    const double &operator()(unsigned int row, unsigned int column) const;

    Matrix Mobrot_tworzenie(int kat);

    bool operator==(const Matrix &tmp) const;
    
    double gauss();
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

