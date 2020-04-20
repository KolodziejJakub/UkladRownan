#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  
  Wektor tab[ROZMIAR];

  public:
  Macierz();
  Macierz(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
  Macierz(Wektor a1, Wektor a2, Wektor a3);

  Wektor operator * (Wektor W);
  Macierz operator * (Macierz W);
  Macierz operator + (Macierz W);
  Macierz operator - (Macierz W);
  Macierz operator * (double l);

  double wyznacznikSarus();

  void odwrotnosc();
  double Wyznacznik2x2(double mac2x2[4]);

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index);

  const Macierz & transpozycja() const;
  void transpozycja();

  bool operator == (const Macierz & W2) const;
  bool operator != (const Macierz & W2) const;

  const Wektor & zwroc_kolumne(int ind);
  void zmien_kolumne(int ind, Wektor nowa);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
