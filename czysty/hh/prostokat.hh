#include "size.hh"
#include <iostream>
#include <math.h>

class punkt
{
    public:

    double x,y;
    punkt();
};

punkt::punkt()
{
    x=0;
    y=0;
}


class prostokat : public punkt
{
    punkt a,b,c,d;
    double AB,BC,CD,DA;

public:
    prostokat();
    bool boki();


};

prostokat::prostokat()
{
    punkt(a);
    punkt(b);
    punkt(c);
    punkt(d);

    AB=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    BC=sqrt((c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y));
    CD=sqrt((d.x-c.x)*(d.x-c.x)+(d.y-c.y)*(d.y-c.y));
    DA=sqrt((a.x-d.x)*(a.x-d.x)+(a.y-d.y)*(a.y-d.y));
}

bool prostokat::boki()
{
    
}