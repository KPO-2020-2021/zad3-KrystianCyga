#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include "size.hh"
#include <iostream>
#include <math.h>
#include <fstream>

#define epsilon 0.00001

class punkt
{
public:
    double x, y;
    punkt();
};

punkt::punkt()
{
    x = 0;
    y = 0;
}

class prostokat : public punkt
{
protected:
    punkt a, b, c, d;
    double AB, BC, CD, DA;

public:
    prostokat();
    prostokat pobierz_prostokat();
    void boki();
};

prostokat::prostokat()
{
    punkt(a);
    punkt(b);
    punkt(c);
    punkt(d);

    AB = 0;
    BC = 0;
    CD = 0;
    DA = 0;
}

void prostokat::boki()
{
    AB = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    BC = sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
    CD = sqrt((d.x - c.x) * (d.x - c.x) + (d.y - c.y) * (d.y - c.y));
    DA = sqrt((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y));

    if (abs(AB - CD) < epsilon)
    {
        std::cout << "Dluzsze boki :" << AB << " i " << CD << " sa rowne." ;
    }
    else
    {
        std::cout << "Dluzsze boki :" << AB << " i " << CD << " nie sa rowne." ;
    }

    if (abs(BC - DA) < epsilon)
    {
        std::cout << "Krotsze boki :" << BC << " i " << DA << " sa rowne." ;
    }
    else
    {
        std::cout << "Krotsze boki :" << BC << " i " << DA << " nie sa rowne." ;
    }
}

prostokat prostokat::pobierz_prostokat()
{

    std::ifstream StrmPlikowy;

    StrmPlikowy.open("../datasets/prostokat.dat");
    if (!StrmPlikowy.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \""
                  << "prostokat.dat"
                  << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        exit(0);

        StrmPlikowy >> prostokat::a.x;
        StrmPlikowy >> prostokat::a.y;
        StrmPlikowy >> prostokat::b.x;
        StrmPlikowy >> prostokat::b.y;
        StrmPlikowy >> prostokat::c.x;
        StrmPlikowy >> prostokat::c.y;
        StrmPlikowy >> prostokat::d.x;
        StrmPlikowy >> prostokat::d.y;
    }
}

#endif