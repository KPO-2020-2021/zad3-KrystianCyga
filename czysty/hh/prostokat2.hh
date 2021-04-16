#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <math.h>
#include <fstream>
#include "vector.hh"

#define epsilon 0.00001



class prostokat : public punkt
{
    public:
    punkt a, b, c, d;
    double AB, BC, CD, DA;

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
        std::cout << "Dluzsze boki : " << AB << " i " << CD << " sa rowne.\n";
    }
    else
    {
        std::cout << "Dluzsze boki : " << AB << " i " << CD << " nie sa rowne.\n";
    }

    if (abs(BC - DA) < epsilon)
    {
        std::cout << "Krotsze boki : " << BC << " i " << DA << " sa rowne.\n";
    }
    else
    {
        std::cout << "Krotsze boki : " << BC << " i " << DA << " nie sa rowne.\n";
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
    }
    prostokat pom;

    StrmPlikowy >> pom.a.x;
    StrmPlikowy >> pom.a.y;
    StrmPlikowy >> pom.b.x;
    StrmPlikowy >> pom.b.y;
    StrmPlikowy >> pom.c.x;
    StrmPlikowy >> pom.c.y;
    StrmPlikowy >> pom.d.x;
    StrmPlikowy >> pom.d.y;

    StrmPlikowy.close();

    return pom;


}



#endif