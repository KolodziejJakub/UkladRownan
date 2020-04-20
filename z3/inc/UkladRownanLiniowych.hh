#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanL {
  
  Macierz A;
  Wektor b;
  
  public:
  Wektor oblicz();
  UkladRownanL();
  UkladRownanL(Macierz A, Wektor b);   

  const Macierz & get_A() const; 
  const Wektor & get_b() const;

  void set_A(const Macierz & in);
  void set_b(const Wektor & in);
};


std::istream& operator >> (std::istream &Strm, UkladRownanL &UklRown);


std::ostream& operator << ( std::ostream &Strm, const UkladRownanL    &UklRown);


#endif