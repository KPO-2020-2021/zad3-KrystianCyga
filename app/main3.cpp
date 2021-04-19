// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"

prostokat prost;
PzG::LaczeDoGNUPlota Lacze;

int main()
{
  Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);
  Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);
  Lacze.ZmienTrybRys(PzG::TR_2D);

  char wyb;

  while (wyb != 'k')
  {

    prost.wczytaj("../datasets/prostokat.dat");
    prost.boki();

    std::cout << "************************MENU************************\n";
    std::cout << "  o-obrot prostokata o zadany kat\n";
    std::cout << "  p-przesuniecie o dany wektor\n";
    std::cout << "  w-wyswietlenie wspolrzednych wierzcholkow\n";
    std::cout << "  m-powrot do menu\n";
    std::cout << "  k-koniec dzialania programu\n";
    std::cout << "  r-Rysuj prostokat w Gnuplocie\n";
    std::cout << "  Twoj wybor -> :";
    std::cin >> wyb;

    switch (wyb)
    {

    case 'o':

      double kat, ilosc;
      std::cout << "Podaj kat obrotu: ";
      std::cin >> kat;
      std::cout << "Podaj ilosc operacji: ";
      std::cin >> ilosc;
      prost.obrot(kat, ilosc);
      std::cout << prost;
      break;

    case 'p':
      Vector VecPrzesu;
      std::cout << "Podaj wektor przesuniecia (x) (y): ";
      std::cin >> VecPrzesu;
      prost.owektor(VecPrzesu);
      std::cout << prost;
      break;

    case 'w':
      std::cout << prost;
      break;

    case 'r':
      prost.zapis("../datasets/prostokat.dat");
      Lacze.Rysuj();
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
