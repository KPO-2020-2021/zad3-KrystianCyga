#include "../tests/doctest/doctest.h"
#include "vector.hh"

TEST_CASE("Operator porownania")
{
  double tab[2] = {0, 0};
  double tab2[2] = {0, 0};

  Vector a(tab);
  Vector b(tab2);

  CHECK(a == b);
}

TEST_CASE("Operator porownania2")
{
  double tab3[2] = {1.000004, 3.0000007};
  double tab4[2] = {1.0000045, 3.0000008};

  Vector c(tab3);
  Vector d(tab4);

  CHECK(c == d);
}

TEST_CASE("Dodawanie")
{
  double tab[2] = {2, 2};
  double tab2[2] = {3, 3};
  double tab3[2] = {5, 5};

  Vector a(tab);
  Vector b(tab2);
  Vector c(tab3);

  CHECK(c==a+b);
}

TEST_CASE("Odejmowanie")
{
  double tab[2] = {2, 2};
  double tab2[2] = {3, 3};
  double tab3[2] = {-1, -1};

  Vector a(tab);
  Vector b(tab2);
  Vector c(tab3);

  CHECK(c==a-b);
}

TEST_CASE("Mnozenie przez skalar")
{
  double tab[2] = {2, 2};
  double x = 3;
  double tab3[2] = {6, 6};

  Vector a(tab);
  Vector c(tab3);

  CHECK(c==a*x);
}

TEST_CASE("Dzielenie prze skalar")
{
  double tab[2] = {2, 2};
  double x = 3;
  double tab3[2] = {0.6666667, 0.6666667};

  Vector a(tab);
  Vector c(tab3);

  CHECK(c==a/x);
}

TEST_CASE("Operator wyluskania [] ")
{
  double tab[2] = {3, 2};
  

  Vector a(tab);

  CHECK(a[0]==3);
  CHECK(a[1]==2);
}

TEST_CASE("Modul")
{
  double tab[2] = {3, 4};
  double x = 5;

  Vector a(tab);

  CHECK(a.modul()==x);
}

