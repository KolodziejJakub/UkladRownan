#include "UkladRownanLiniowych.hh"

UkladRownanL::UkladRownanL()
{
    Macierz A;
    Wektor b;
};

UkladRownanL::UkladRownanL(Macierz A, Wektor b)
{
    A = _A;
    b= _b;
};

const Macierz & UkladRownanL::get_A() const
{
    return A;
}

const Wektor & UkladRownanL::get_b() const
{
    return b;
}

void set_A(const Macierz & in)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            A[i][j]=in[i][j];
        }
    }
}

void set_b(const Wektor & in)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        b[i]=in[i];
    }
}

Wektor UkladRownanL::oblicz()
{
    Wektor Wynik;


    A.odwrotnosc;
    Wynik = A.operator*(b);

    return Wynik;
}

std::istream& operator >> (std::istream &Strm, UkladRownanL &UklRown)
{
    Strm>>UklRown.Set_A()>>UklRown.Set_b();
    return Strm;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanL &UklRown)
{
    Strm<<"Macierz:"<<std::endl<<UklRown.get_A<<std::endl<<"Wektor:"<<std::endl<<UklRown.get_b;
    return Strm;
}