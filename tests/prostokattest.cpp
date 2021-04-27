#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "vector.hh"
#include "prostokat.hh"

TEST_CASE("Konstruktor i operator[] ")
{
    prostokat przyk;
    double tab1[2]={0,0},tab2[2]{0,1},tab3[2]{1,0},tab4[2]{1,1};
    Vector a(tab1),b(tab2),c(tab3),d(tab4);

  CHECK(przyk[0]==a);
  CHECK(przyk[1]==b);
  CHECK(przyk[2]==c);
  CHECK(przyk[3]==d);
}