#include "Macierz.hh"


const void Macierz::transpozycja() const
{
    Macierz pomoc;

    for (int i=0; i<ROZMIAR; i++)
    {
        
    }
}

const double Macierz::operator()(int ind1, int ind2) const
{
    
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            if (i=0)
            {
                Strm>>Macierz.a1[j];
            }
            else if (i=1)
            {
                Strm>>Macierz.a2[j];
            }
            else if (i=2)
            {
                Strm>>Macierz.a3[j];
            }
            else
            {
                std::cerr<<"Blad.";
            }
            
        }
    }
}

std::ostream& operator << (std::ostream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            if (i=0)
            {
                Strm<<Macierz.a1[j];
            }
            else if (i=1)
            {
                Strm<<Macierz.a2[j];
            }
            else if (i=2)
            {
                Strm<<Macierz.a3[j];
            }
            else
            {
                std::cerr<<"Blad.";
            }
        }
    }
}