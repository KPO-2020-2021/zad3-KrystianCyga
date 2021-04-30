#include "prostokat3d.hh"

/******************************************************************************
 |  Konstruktor klasy Protokat odziedziczacy z klasy vector.                  |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |                                      |
 */

prostokat3d::prostokat3d()
{
    int k = 0;
    for (double i = 0; i < 2; ++i)
    {
        for (double j = 0; j < 2; ++j)
        {
            double tab[2] = {i, j};
            this->wektor[k].zapeln(tab);
            k++;
        }
    }
}

/******************************************************************************
 |  Przeciazenie operatora wyluskania                                         |
 |  Argumenty:                                                                |
 |      punkt-indeks.                                                         |
 |  Zwraca:                                                                   |
 |      Dany punkt (wektor) prostokat3da.                                       |
 */
Vector prostokat3d::operator[](int punkt)
{
    return wektor[punkt];
}

/******************************************************************************
 |  Metoda obliczajaca i porownujaca dlugosci bokow.                             |
 |  Argumenty:                                                                   |
 |      prostokat3d.                                                               |
 |  Wyswietla:                                                                   |
 |      Komunikat czy boki sa rowne i ile wynosi ich dlugosc.                    |
 */
void prostokat3d::boki()
{
    if (SIZE == 2)
    {
        double AB, BC, CD, DA;

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
            if (AB == BC)
            {
                std::cout << "Ta figura to kwadrat !!!";
            }
        }
        else
        {
            std::cout << "  " << dlugosc2 << " boki : " << BC << " i " << DA << " nie sa rowne.\n\n";
        }
        std::cout.precision(4);
    }
    if (SIZE == 3)
    {
        double A0, A1, A2, A3, B0, B1, B2, B3, C0, C1, C2, C3;

        A0 = wektor[0].dlugosc(wektor[1]);
        A1 = wektor[2].dlugosc(wektor[3]);
        A2 = wektor[4].dlugosc(wektor[5]);
        A3 = wektor[6].dlugosc(wektor[7]);
        B0 = wektor[1].dlugosc(wektor[2]);
        B1 = wektor[0].dlugosc(wektor[3]);
        B2 = wektor[5].dlugosc(wektor[6]);
        B3 = wektor[4].dlugosc(wektor[7]);
        C0 = wektor[0].dlugosc(wektor[4]);
        C1 = wektor[1].dlugosc(wektor[5]);
        C2 = wektor[2].dlugosc(wektor[6]);
        C3 = wektor[3].dlugosc(wektor[7]);

        std::cout.precision(15);

        std::string dlugosc1, dlugosc2, dlugosc3;

        if (A0 > B0 && A0 > C0)
        {
            dlugosc1 = "Dluzsze";
            if (B0 > C0)
            {
                dlugosc2 = "Poprzeczne";
                dlugosc3 = "Krotsze";
            }
            else
            {
                dlugosc3 = "Poprzeczne";
                dlugosc2 = "Krotsze";
            }
        }
        if (B0 > A0 && B0 > C0)
        {
            dlugosc2 = "Dluzsze";
            if (A0 > C0)
            {
                dlugosc1 = "Poprzeczne";
                dlugosc3 = "Krotsze";
            }
            else
            {
                dlugosc3 = "Poprzeczne";
                dlugosc1 = "Krotsze";
            }
        }
        if (C0 > A0 && C0 > C0)
        {
            dlugosc3 = "Dluzsze";
            if (A0 > B0)
            {
                dlugosc1 = "Poprzeczne";
                dlugosc2 = "Krotsze";
            }
            else
            {
                dlugosc2 = "Poprzeczne";
                dlugosc1 = "Krotsze";
            }
        }
        if ((abs(A0 - A1) < epsilon) && (abs(A0 - A2) < epsilon) && (abs(A0 - A3) < epsilon))
        {
            std::cout << "  " << dlugosc1 << " boki sa sobie rowne.\n";
            std::cout << "   Dlugosc pierwszego boku: " << A0 << "\n";
            std::cout << "   Dlugosc drugiego boku: " << A1 << "\n";
            std::cout << "   Dlugosc trzeciego boku: " << A2 << "\n";
            std::cout << "   Dlugosc czwartego boku: " << A3 << "\n";
        }
        if ((abs(B0 - B1) < epsilon) && (abs(B0 - B2) < epsilon) && (abs(B0 - B3) < epsilon))
        {
            std::cout << "  " << dlugosc2 << " boki sB sobie rowne.\n";
            std::cout << "   Dlugosc pierwszego boku: " << B0 << "\n";
            std::cout << "   Dlugosc drugiego boku: " << B1 << "\n";
            std::cout << "   Dlugosc trzeciego boku: " << B2 << "\n";
            std::cout << "   Dlugosc czwartego boku: " << B3 << "\n";
        }
        if ((abs(C0 - C1) < epsilon) && (abs(C0 - C2) < epsilon) && (abs(C0 - C3) < epsilon))
        {
            std::cout << "  " << dlugosc3 << " boki sa sobie rowne.\n";
            std::cout << "   Dlugosc pierwszego boku: " << C0 << "\n";
            std::cout << "   Dlugosc drugiego boku: " << C1 << "\n";
            std::cout << "   Dlugosc trzeciego boku: " << C2 << "\n";
            std::cout << "   Dlugosc czwartego boku: " << C3 << "\n";
        }
    }
}

/******************************************************************************
 |  Metoda obrotu protokata.                                                  |
 |  Argumenty:                                                                |
 |      kat   - kat obrotu                                                    |
 |      ilosc - ilosc operacji obrotu                                         |
 |  Zwraca:                                                                   |
 |      Obrocony prostokat3d.                                                   |
 */
prostokat3d prostokat3d::obrot(double kat, int ilosc)
{
    Matrix Mrotacji;

    Mrotacji.Mobrot2D_tworzenie(kat);

    for (int j = 0; j < ilosc; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            this->wektor[i] = Mrotacji * this->wektor[i];
        }
    }

    return *this;
}

prostokat3d prostokat3d::obrot(double kat)
{
    return this->obrot(kat, 1);
}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      prost-prostokat3d                                                       |
 */
std::ostream &operator<<(std::ostream &out, prostokat3d const &prost)
{
    for (int i = 0; i < 4; i++)
    {
        out << prost.wektor[i] << std::endl;
    }
    out << prost.wektor[0];

    return out;
}

std::ofstream &operator<<(std::ofstream &of, prostokat3d const &prost)
{
    of << std::setprecision(10) << std::fixed;
    for (int i = 0; i < 4; i++)
    {
        of << prost.wektor[i] << std::endl;
    }
    return of;
}

/******************************************************************************
 |  Metoda zapisu prostokat3da do pliku                                         |
 |  Argumenty:                                                                |
 |      nazwa-nazwa pliku zapisu                                              |
 |  Zwraca:                                                                   |
 |      Poprawnosc operacji.                                                  |
 */
bool prostokat3d::zapis(const std::string &nazwa) const
{
    std::ofstream plik;

    plik.open(nazwa, std::ofstream::out);
    if (plik.is_open() == false)
    {
        return false;
    }

    plik << *this;
    plik << this->wektor[0];
    if (plik.fail())
    {
        plik.close();
        return false;
    }
    plik.close();
    return true;
}

/******************************************************************************
 |  Metoda przesuniecia o wektor                                               |
 |  Argumenty:                                                                 |
 |      wek - wektor przesuniecia,                                             |
 |  Zwraca:                                                                    |
 |      Poprawnosc operacji.                                                   |
 */
bool prostokat3d::owektor(Vector &wek)
{
    if (wek.modul() == 0)
        return false;
    for (int i = 0; i < 4; i++)
    {
        wektor[i] = wektor[i] + wek;
    }
    return true;
}
/******************************************************************************
 |  Metoda wczytania prostokat3da do pliku                                      |
 |  Argumenty:                                                                |
 |      nazwa-nazwa pliku odczytu                                             |
 |  Zwraca:                                                                   |
 |      Poprawnosc operacji.                                                  |
 */
bool prostokat3d::wczytaj(const std::string &nazwa)
{
    std::fstream plik;

    plik.open(nazwa);
    if (plik.is_open() == false)
    {
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        plik >> wektor[i];
        if (plik.fail())
        {
            plik.close();
            return false;
        }
    }
    plik.close();
    return true;
}
