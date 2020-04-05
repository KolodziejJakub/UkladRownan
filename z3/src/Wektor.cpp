#include "Wektor.hh"

/*Wektor Wektor::operator + (Wektor & W2)
{
   Wektor Wynik;

   for (int i=0; i<ROZMIAR; i++)
   {
       Wynik[i]=tab[i]+W2[i]
   }
  return Wynik;
}*/
  Wektor Wektor::operator += (const Wektor & W2)
  {
      for (int i=0; i<ROZMIAR; i++)
      {
          tab[i]=tab[i]+W2[i];
      }
    return tab;
  }

  Wektor Wektor::operator + (const Wektor & W2) const
  {
      Wektor Wynik;

      for (int i=0; i<ROZMIAR; i++)
      {
          Wynik[i]=tab[i]+W2[i];
      }
      return Wynik;
  }

  Wektor Wektor::operator - (const Wektor & W2) const
    {
        Wektor Wynik;

        for (int i=0; i<ROZMIAR; i++)
        {
        Wynik[i]=tab[i]-W2[i];
        }
        return Wynik;
    }

  double Wektor::operator * (const Wektor & W2) const
  {
      double Wynik;

      for (int i=0; i<ROZMIAR; i++)
      {
          Wynik = Wynik + (tab[i]*W2[i]);
      }
      return Wynik;
  }

Wektor Wektor::operator * (double l1) const
  {
    Wektor Wynik;
      
      for (int i=0; i<ROZMIAR; i++)
      {
          Wynik[i]=tab[i]*l1;
      }
    return Wynik;
  }

  bool Wektor::operator == (const Wektor & W2) const
  {
    for (int i=0; i<ROZMIAR; i++)
      {
          if(tab[i] != W2[i])
            return false;
      }
    return true;
  }

  bool Wektor::operator != (const Wektor & W2) const
  {
    for (int i=0; i<ROZMIAR; i++)
      {
          if(tab[i] == W2[i])
            return false;
      }
    return true;
  }

  double dlugosc() const
    {
    double dlugosc;

    for (int i=0; i<ROZMIAR; i++ )
        {
        dlugosc =  dlugosc + (tab[i]*tab[i]);
        }

    dlugosc = pow(dlugosc, (1/2));

    return dlugosc;
    }

double Wektor::operator[] (int index) const
{
    if (index < 0 || index >= ROZMIAR) 
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

    return tab[index];
}

double Wektor::operator[] (int index)
{
    if (index < 0 || index >= ROZMIAR) 
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

    return tab[index];
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Wek[i];
        return Strm;
    }
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
        return Strm;
    }
}

Wektor operator * (Wektor W2, double l1)
{
    Wektor Wynik;

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=W2[i]*l1;
    }
    return Wynik;
}
