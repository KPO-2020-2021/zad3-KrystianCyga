
#include "SIZE.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include "matrix.hh"
#include <stdexcept>
#include <string>

#define epsilon 0.00001

class prostokat : public Vector
{

    Vector wektor[4];

    double AB, BC, CD, DA;

public:
    prostokat();
    void boki();
    prostokat obrot(double kat,int ilosc);
};

std::ifstream &operator>>(std::istream &in, prostokat &prost);

std::ostream &operator<<(std::ifstream &out, prostokat const &prost);

prostokat::prostokat()
    : Vector()
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double tab[2] = {i, j};

            wektor[i].zapelniacz(tab);
        }
    }
}

void prostokat::boki()
{
    AB = wektor[0].dlugosc(wektor[1]);
    BC = wektor[1].dlugosc(wektor[2]);
    CD = wektor[2].dlugosc(wektor[3]);
    DA = wektor[3].dlugosc(wektor[0]);

    std::cout.precision(15);

    std::string dlugosc, dlugosc2;

    if (AB > DA)
    {
        dlugosc = "Dluzsze";
        dlugosc2 = "Krotsze";
    }
    else if (AB < DA)
    {
        dlugosc = "Krotsze";
        dlugosc2 = "Dluzsze";
    }

    if (abs(AB - CD) < epsilon)
    {
        std::cout << "  " << dlugosc << " boki : " << AB << " i " << CD << " sa rowne.\n";
    }
    else
    {
        std::cout << "  " << dlugosc << " boki : " << AB << " i " << CD << " nie sa rowne.\n";
    }

    if (abs(BC - DA) < epsilon)
    {
        std::cout << "  " << dlugosc2 << " boki : " << BC << " i " << DA << " sa rowne.\n\n";
        if(AB==BC)
        {
            std::cout<<"Ta figura to kwadrat !!!";
        }
    }
    else
    {
        std::cout << "  " << dlugosc2 << " boki : " << BC << " i " << DA << " nie sa rowne.\n\n";
    }
    std::cout.precision(4);
}

prostokat prostokat::obrot(double kat,int ilosc)
{
    prostokat obrocony;
    Matrix Mrotacji;

    Mrotacji.Mobrot_tworzenie(kat);

    for (int i = 0; i < 4; i++)
    {
        obrocony.wektor[i]=Mrotacji*this->wektor[i];
    }
    
    return obrocony;

}

std::ostream &operator<<(std::ifstream &out, prostokat const &prost)
{
    out
}

std::ifstream &operator>>(std::istream &in, prostokat &prost)
{

}