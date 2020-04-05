#define ROZMIAR 3

class Wektor {
  double tab[ROZMIAR]; //1 propozycja

  //  double x,y,z; //2 propozycja

  //  double *tab;//3 propozycja
  //  int roz;

public:
  Wektor();
  Wektor(double x, double y, double z);
  Wektor(double * tab);

  const Wektor & operator += (const Wektor & W2);
  const Wektor & operator + (const Wektor & W2) const;
  const Wektor & operator - (const Wektor & W2) const;
  double operator * (const Wektor & W2) const;

  const Wektor & operator * (double li) const;

  bool operator == (const Wektor & W2) const;
  bool operator != (const Wektor & W2) const;

  double dlugosc() const;

  //2 propozycja
  //void zmien_x(double nx);
  //double wez_x();

  const double & operator[] (int index) const; //double z=W[3];
  double & operator[] (int index) { //W[2] =3;
    if (index < 0 || index >= ROZMIAR) {
      cerr << "poza zakresem" << endl;
      exit(1);
    }

  }
  
};

ostream operator <<(ostream & strm, const Wektor & W); 
istream operator >>(istream & strm, Wektor & W); 

Wektor operator * (double l1, Wektor W2);
/*==========================
Wektor W;

W[2] =3;*/

/*W[2] =3;

double z=2;
const double c=4;
z=4;
c=7; */ ///blad kompilacji 

/*Wektor W1(1,2,3);
const Wektor W2(4,5,6);

double dl=W1.dlugosc();
double dl=W2.dlugosc();*/



/*========================
  LZ L1;
inicjuj(L1,2,3);

LZ L1(2,3);

LZ L1;
inicjuj(L1);

LZ L1;*/


class MacierzKw {
  double tab[ROZMIAR * ROZMIAR]; //1 propozycja
  double tab[ROMZIAR][ROZMIAR]; //2 popozycja, jeśli 3 zbyt trudna
  Wektor tab[ROZMIAR];//3 propozycja, sugerowana
public:
  MacierzKw();
  MacierzKw(Wektor *w);
  MacierzKw(/*9 double*/);
  MacierzKw(Wektor a1, Wektor a2, Wektor a3);
  const MacierzKw & transpozycja() const;
  void transpozycja();

  const MacierzKw & odwrotnosc() const;
  void odwrotnosc();//z definicji, gauss

  double wyznacznik();//laplace, gauss, sarrus
  double wyznacznikGauss(); //double wyznacznik(Metoda = Gauss) <- enum
  
  Wektor operator * (Wektor W);
  MacierzKw operator * (MacierzKw W);
  MacierzKw operator + (MacierzKw W);
  MacierzKw operator - (MacierzKw W);
  MacierzKw operator * (double l);

  bool operator == (const MacierzKw & W2) const;
  bool operator != (const MacierzKw & W2) const;

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index); // M[2][0] - zerowy element drugiego wektora macierzy

  const double & operator() (int ind1, int ind2) const;
  double & operator() (int ind1, int ind2); //M(2,0)

  const Wektor & zwroc_kolumne(int ind); //dla wierszowej
  void zmien_kolumne(int ind, Wektor nowa);
};

/*operator >>
operator <<

MacierzKw operator * (double l1, MacierzKw W2);

a) wiersze
- konsekwencja notacji matematycznej dla macierzy
- czytanie wymaga transpozycji (ale wciaz latwe)
- łatwa implemetacja mnożenia macierz-wektor (wykorzytuje iloczyn skalarny)
- łatwa metoda gaussa (wyznacznik)
- łatwa metoda gaussa (układ równań, odwrotność)

b) kolumny
- konsekawncja notacji (bo wektory kolumnowe)
- łatwe czytywanie (wg tego jak wczytywac mamy w zadaniu)
- łatwa implementacja metody Cramera roaziązywania URL.
- mniej oczywista ale wciąż łatwa metoda gaussa (wyznacznik)*/

class UkladRownanL {
  Macierz A;
  Wektor b;
public:
  Wektor oblicz();//podobnie jak w macierzy: cramer, gauss
  UkladRownanL();
  UkladRownanL(Macierz AA, Wektor bb);
  const Wektor & zwroc_wektor_wolny(); 
  void zmien_wektor_wolny(Wektor nowy);
  const MacierzKw & zwroc_macierz(); 
  void zmien_macierz(MacierzKw nowy);
  
  
};

/*operator >>
  operator <<*/
