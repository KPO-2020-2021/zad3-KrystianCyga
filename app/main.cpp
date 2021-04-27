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
#include <unistd.h>

#include "../include/exampleConfig.h.in"
#include "../include/example.h"
#include "../include/vector.hh"
#include "../include/matrix.hh"
#include "../include/prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"

int main()
{

  prostokat prost;
  PzG::LaczeDoGNUPlota Lacze;
  Vector VecPrzesu;
  Matrix M;

  Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);
  Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);
  Lacze.ZmienTrybRys(PzG::TR_2D);

  char wyb;

  prost.wczytaj("../datasets/prostokat.dat");
  prost.boki();

  while (wyb != 'k')
  {

    std::cout << "\n"
              << "************************MENU************************\n";
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
      int pos;
      double kat, ilosc;
      std::cout << "Podaj kat obrotu: ";
      std::cin >> kat;
      std::cout << "Podaj ilosc operacji: ";
      std::cin >> ilosc;
      std::cout << "Czy chcesz ujrzec animacje ? \nZalecam wykonywac ją dla ilosci operacji mniejszych niz 400 i malych katow.\n "
                   "1-tak\n"
                   "lub\n"
                   "2-nie\n-->"
                   "";
      std::cin >> pos;
      if (pos == 1)
      {
        Lacze.Rysuj();
        usleep(2000000);
        for (int i = 0; i < ilosc; i++)
        {
          prost.obrot(kat, 1);
          prost.zapis("../datasets/prostokat.dat");
          Lacze.Rysuj();
          int czas = 10000000 / ilosc;
          usleep(czas);
        }
        prost.boki();
        std::cout << prost;
      }
      else
      {
        prost.obrot(kat, ilosc);
        prost.zapis("../datasets/prostokat.dat");
      std::cout << prost;
      }
        break;
    case 'p':

      std::cout << "Podaj wektor przesuniecia (x) (y): ";
      std::cin >> VecPrzesu;
      prost.owektor(VecPrzesu);
      std::cout << prost;
      break;

    case 'w':
      std::cout << prost;
      break;

    case 'r':
      prost.boki();
      prost.zapis("../datasets/prostokat.dat");
      Lacze.Rysuj();
      break;

    case 'm':

      break;

    case 'k':

      return 0;

      break;

    default:
      std::cout << "Zly wybor !!! \n";
      std::cout << "Mozliwe to o,r,p,w,m,k\n";
      break;
    }
  }
}
