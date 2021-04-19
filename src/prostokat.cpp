#include "prostokat.hh"

/******************************************************************************
 |  Konstruktor klasy Protokat odziedziczacy z klasy vector.                  |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |                                      |
 */

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

/******************************************************************************
 |  Przeciazenie operatora wyluskania                                         |
 |  Argumenty:                                                                |
 |      punkt-indeks.                                                         |
 |  Zwraca:                                                                   |
 |      Dany punkt (wektor) prostokata.                                       |
 */
Vector prostokat::operator[](int punkt)
{
    return wektor[punkt];
}

/******************************************************************************
 |  Metoda obliczajaca i porownujaca dlugosci bokow.                             |
 |  Argumenty:                                                                   |
 |      Prostokat.                                                               |
 |  Wyswietla:                                                                   |
 |      Komunikat czy boki sa rowne i ile wynosi ich dlugosc.                    |
 */
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

/******************************************************************************
 |  Metoda obrotu protokata.                                                  |
 |  Argumenty:                                                                |
 |      kat   - kat obrotu                                                    |
 |      ilosc - ilosc operacji obrotu                                         |
 |  Zwraca:                                                                   |
 |      Obrocony prostokat.                                                   |
 */
prostokat prostokat::obrot(double kat, int ilosc)
{
    prostokat obrocony;
    Matrix Mrotacji;

    Mrotacji.Mobrot_tworzenie(kat);

    for (int i = 0; i < 4; i++)
    {
        obrocony.wektor[i] = Mrotacji * this->wektor[i];
    }

    return obrocony;
}

prostokat prostokat::obrot(double kat)
{
    return this->obrot(kat,1);
}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      prost-prostokat                                                       |
 */
std::ostream &operator<<(std::ostream &out, prostokat const &prost)
{
    for (int i = 0; i < 4; i++)
    {
        out << prost.wektor[i] << std::endl;
    }
    return out;
}

std::ifstream &operator>>(std::istream &in, prostokat &prost)
{
}
/******************************************************************************
 |  Metoda zapisu prostokata do pliku                                         |
 |  Argumenty:                                                                |
 |      nazwa-nazwa pliku zapisu                                              |
 |  Zwraca:                                                                   |
 |      Poprawnosc operacji.                                                  |
 */
bool prostokat::zapis(const std::string &nazwa) const
{
    std::fstream plik;

    plik.open(nazwa, std::fstream::out);
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
bool prostokat::owektor(Vector &wek)
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
 |  Metoda wczytania prostokata do pliku                                      |
 |  Argumenty:                                                                |
 |      nazwa-nazwa pliku odczytu                                             |
 |  Zwraca:                                                                   |
 |      Poprawnosc operacji.                                                  |
 */
bool prostokat::wczytaj(const std::string &nazwa)
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
    plik >> wektor[3];
    plik.close();
    return true;
}
