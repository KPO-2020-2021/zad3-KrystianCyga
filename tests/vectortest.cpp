#include "../tests/doctest/doctest.h"
#include "vector.hh"

TEST_CASE("Operator porownania")
{
    double tab[2]={0,0};
    double tab2[2]={0,0};

    Vector a(tab);
    Vector b(tab2);
    
  CHECK(a == b);

    double tab3[2]={1.000004,3.0000007};
    double tab4[2]={1.0000045,3.0000008};

    Vector c(tab3);
    Vector d(tab4);
    
  CHECK(c == d);


}