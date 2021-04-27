Krystian Cyga

Przepraszam za male opoznienie (okolo 1h).
Program mysle ze przemyslalem i wprowadzilem ciekawe i warte uwagi fragmenty jak na przyklad to ze klasa prostokat dziedziczy z klasy vektor. Prostokat jest tablica 4 wektorow. Prostokat dziedziczy konstruktor od vektora. 

Program jest w pełni modulowy. Napisalem wszystkie wymagane metody.

MODYFIKACJA liczenia wyznacznika rowniez została napisana. Jest metodą klasy macierz.

Wszystkie metody i funckcje opisane.

NIESTETY testy się wysypują. A program wyrzuca segma... :(
Undefined reference do kolejnych metod...

Testów jest kilka najwazniejszych ale skoro się nie kompilowały to nie pisalem wiecej.
Jesli bede mial czas to w majowke poszukam bledow. Bedzie to juz po czasie ale przynajmniej sie czegos wiecej nauczę:).

EDIT: 24h Później
Udalo sie po dlugiej analizie poprawic blad... Teraz program się kompiluje dlatego zabieram się do dalszego debugowania. Już z górki. 

EDIT: 32h Później

Było kilka problemow z zapisywaniem do pliku poniewaz nie wiedzialem ze ma to wieksze znaczenie dla łacza do gnuplota
a jednak rysowalo mi prostokat bez lini... Poprawione.
Przesuniecie o wektor działa bezblednie.
Z obrotem był taki problem,że chciałem stworzyć kopie, zmodyfikować i nadpisać oryginał, ale nie do końca działało więc zostałem przy operacji na orginale.
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: 

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```


