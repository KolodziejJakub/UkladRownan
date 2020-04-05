#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*class Wektor
{
  double tab[ROZMIAR];

  public:

  Wektor operator + (Wektor & W2);
};*/
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  
  double tab[ROZMIAR];
  
  public:
  

  Wektor operator += (const Wektor & W2);
  Wektor operator + (const Wektor & W2) const;
  Wektor operator - (const Wektor & W2) const;
  double operator * (const Wektor & W2) const;

  Wektor operator * (double li) const;

  bool operator == (const Wektor & W2) const;
  bool operator != (const Wektor & W2) const;
  
  
  double dlugosc() const;
  
  
  const double & operator[] (int index) const;
  double & operator[] (int index);    
};

Wektor operator * (double l1, Wektor W2);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);


#endif
