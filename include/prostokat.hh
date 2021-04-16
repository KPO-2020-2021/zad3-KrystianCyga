
#include "SIZE.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include "matrix.hh"
#include <stdexcept>

class prostokat : public Vector
{
    
    Vector wektor[4];

public:
    prostokat();


};

prostokat::prostokat()
    : Vector()
{
    for (int i = 0; i < 4; ++i)
    {
        wektor[i].zapelniacz();
    }
}