#include "vector.hh"
#include "matrix.hh"
#include <iostream>
#include <cstdlib>

int main()
{
    char wyb;
    while (wyb != 'k')
    {
        boki_spr();

        std::cout << "************************MENU************************\n";
        std::cout << "  o-obrot prostokata o zadany kat\n";
        std::cout << "  p-przesuniecie o dany wektor\n";
        std::cout << "  w-wyswietlenie wspolrzednych wierzcholkow\n";
        std::cout << "  k-koniec dzialania programu\n";
        std::cout << "  Twoj wybor -> :";
        std::cin >> wyb;

        switch (wyb)
        {

        case 'o':

            break;

        case 'p':

            break;

        case 'w':

            break;

        case 'm':

            return main();

            break;

        case 'k':

            return 0;

            break;

        default:
            std::cout << "Zly wybor !!! \n";
            std::cout << "Mozliwe to o,p,w,m,k\n";
            break;
        }
    }
}