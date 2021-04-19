#include <vector.hh>

#define epsilon 0.000001

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        wspolrzedne[i] = 0;
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        wspolrzedne[i] = tmp[i];
    }
}

/******************************************************************************
 |  Oblicza dlugosc wectora.                                                  |
 |  Argumenty:                                                                |
 |      drugi - drugi wektor.                                                 |
 |  Zwraca:                                                                   |
 |      Dlugosc wektora                                                       |
*/
double Vector::dlugosc(const Vector &drugi)
{
    return sqrt(pow(drugi.wspolrzedne[0] - this->wspolrzedne[0], 2) + (pow(drugi.wspolrzedne[1] - this->wspolrzedne[1], 2)));
}
/******************************************************************************
 |  Oblicza modul wectora.                                                    |
 |  Argumenty:                                                                |
 |      -wektor                                                               |
 |  Zwraca:                                                                   |
 |      -modul wektora                                                        |
*/
double Vector::modul()
{
    return (sqrt(wspolrzedne[0] * wspolrzedne[0] + wspolrzedne[1] * wspolrzedne[1]));
}

/******************************************************************************
 |  Uzupelnia pola wektora podanymi argumentami.                              |
 |  Argumenty:                                                                |
 |      arg-tablica elementow                                                 |
 |                                                                            |
 |                                                                            |
*/
void Vector::zapelniacz(double argu[2])
{
    this->zapelniacz(argu);
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator+(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = wspolrzedne[i] += v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator-(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = wspolrzedne[i] -= v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator*(const double &tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = wspolrzedne[i] *= tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator/(const double &tmp)
{
    Vector result;

    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = wspolrzedne[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        std::out_of_range("Error: Vektor jest poza zasiegiem");
    }
    return wspolrzedne[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator<<(std::ostream &out, Vector const &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator>>(std::istream &in, Vector &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

bool Vector::operator==(const Vector &drugi)
{
    if (abs(this->wspolrzedne[0] - drugi.wspolrzedne[0]) <= epsilon &&
        abs(this->wspolrzedne[1] - drugi.wspolrzedne[1]) <= epsilon)
    {
        return true;
    }
    else
        return false;
}