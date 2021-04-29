#include "matrix.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator*(Vector tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column)
{

    if (row >= SIZE)
    {
        std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE)
    {
        std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator()(unsigned int row, unsigned int column) const
{

    if (row >= SIZE)
    {
        std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE)
    {
        std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      tmp - macierz czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - sume macierzy.                            |
 */
Matrix Matrix::operator+(Matrix tmp)
{
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
 */
std::istream &operator>>(std::istream &in, Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/******************************************************************************
 |  Tworzy macierz obrotu                                                   |
 |  Argumenty:                                                              |
 |      kat - kat obrotu,                                                   |
 |  Zwraca:                                                                 |
 |      Macierz obrotu                                                      |
 */
Matrix Matrix::Mobrot2D_tworzenie(int kat)
{
    double rad = kat * M_PI / 180;
    value[0][0] = cos(rad);
    value[0][1] = -sin(rad);
    value[1][0] = sin(rad);
    value[1][1] = cos(rad);
    return *this;
}

Matrix Matrix::Mobrot3D_tworzenie(int kat,char os)
{
    double rad = kat * M_PI / 180;
    do
    {
    switch (os)
    {
    case 'z':
    value[0][0] = cos(rad);
    value[0][1] = -sin(rad);
    value[1][0] = sin(rad);
    value[1][1] = cos(rad);
    value[2][0] = 0;
    value[2][1] = 0;
    value[2][2] = 1;
    value[0][2] = 0;
    value[1][2] = 0;
        break;
    
    
    case 'y':
    value[0][0] = cos(rad);
    value[0][2] = -sin(rad);
    value[2][0] = sin(rad);
    value[2][2] = cos(rad);
    value[1][0] = 0;
    value[2][1] = 0;
    value[1][1] = 1;
    value[0][1] = 0;
    value[1][2] = 0;
    break;
    case 'x':
    value[1][1] = cos(rad);
    value[1][2] = -sin(rad);
    value[2][1] = sin(rad);
    value[2][2] = cos(rad);
    value[2][0] = 0;
    value[0][1] = 0;
    value[0][0] = 1;
    value[0][2] = 0;
    value[1][0] = 0;
    break;

    default:
    std::cout<<"Blednie podana os! Mozliwe to x,y,z\nPodaj os: ";
    std::cin>>os;
    break;
    }
    }
    while (os!='z'&&os!='x'&&os!='y');

    return *this;
}

bool Matrix::operator==(const Matrix &tmp) const
{
    int prawdy = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            prawdy += (int)(abs(this->value[i][j] - tmp.value[i][j]) <= epsilon);
        }
    }
    if (prawdy==SIZE*SIZE)
    {
        return true;
    }
    else
        return false;
}

/******************************************************************************
 |  Metoda liczenia wyznacznika Gaussem                                       |
 |  Argumenty:                                                                |
 |      Macierz                                                               |
 |  Zwraca:                                                                   |
 |      Wyznacznik typu double                                                |
 */

double Matrix::gauss()
{
    int i, j, k;
    double temp, x[SIZE];
    for (j = 0; j < SIZE - 1; j++)
    {
        for (i = j + 1; i < SIZE; i++)
        {
            temp = value[i][j] / value[j][j];
            for (k = 0; k < SIZE; k++)
            {
                value[i][k] -= value[j][k] * temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        x[i] = value[i][i];
    }
    double wyznacznik = 1;
    for (i = 0; i < SIZE; i++)
    {
        wyznacznik *= x[i];
    }
    return wyznacznik;
}
