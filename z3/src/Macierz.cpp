#include "Macierz.hh"

Macierz::Macierz(Wektor a1, Wektor a2, Wektor a3)
{
    Wektor a1,a2,a3;
}

double & Wektor::operator[](int index)
{
    if(index > ROZMIAR || index < 0)
    {
        exit(1);
    }
    return tab[index];
}

const double & Wektor::operator[](int index) const
{
    if(index > ROZMIAR || index < 0)
    {
        exit(1);
    }
    return tab[index];
}


void Macierz::transpozycja()
{
    Macierz pomoc;

    for (int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            pomoc[i][j]=tab[i][j];
        }
    }

    for (int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            tab[i][j]=pomoc[j][i];
        }
    }
}

Wektor Macierz::operator *(Wektor W)
{
    Wektor Wynik;

    for(int i=0; i<ROZMIAR; i++)
    {

        for (int j=0; j<ROZMIAR; j++)
        {
            Wynik[i]=Wynik[i] + (tab[i][j]*W[j]);
        }
    }
    return Wynik;
}

Macierz Macierz::operator *(Macierz W)
{
    Macierz Wynik;

    W.transpozycja();

    for(int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Wynik[i][j]=Wynik[i][j] + (tab[i][j] * W[i][j]);
        }
    }
    return Wynik;
}

Macierz Macierz::operator +(Macierz W)
{
    Macierz Wynik;

    for(int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Wynik[i][j]=tab[i][j]+W[i][j];
        }
    }
    return Wynik;
}

Macierz Macierz::operator -(Macierz W)
{
    Macierz Wynik;

    for(int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Wynik[i][j]=tab[i][j]-W[i][j];
        }
    }
    return Wynik;
}

Macierz Macierz::operator * (double l)
{
    Macierz Wynik;

    for(int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Wynik[i][j]=tab[i][j]*l;
        }
    }
    return Wynik;
}

double Macierz::wyznacznikSarus ()
{
    double Wynik;

    Wynik = tab[0][0]*tab[1][1]*tab[2][2]+tab[1][0]*tab[2][1]*tab[0][2]+
            tab[2][0]*tab[0][1]*tab[0][2]-tab[0][2]*tab[1][1]*tab[2][0]-
            tab[1][2]*tab[2][1]*tab[0][0]-tab[2][2]*tab[0][1]*tab[1][0];

    return Wynik;
}

void Macierz::odwrotnosc()
{
    int s;
    Macierz wyzn, pomoc;
    double mac2x2[4];
    double wyznacznik;

    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            wyzn[i][j]=tab[i][j];
            pomoc[i][j]=tab[i][j];
        }
    }

    wyznacznik = wyzn.wyznacznikSarus;

    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {   
            s=0;
            for (int k=0; k<ROZMIAR; k++)
            {
                for (int l=0; l<ROZMIAR; l++)
                {
                    if (k != i && l != j)
                    {
                        mac2x2[s]=pomoc[k][l];
                        s++;
                    }
                }
            }
            if ((i+j)%2 != 0)
            {
                wyzn[i][j]=-(Wyznacznik2x2(mac2x2));
            }
            else
            {
                wyzn[i][j]=Wyznacznik2x2(mac2x2);
            }
            
        }
    }
    wyzn.transpozycja();

    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            tab[i][j]=(1/wyznacznik)*wyzn[i][j];
        }
    }
}

double Macierz::Wyznacznik2x2 (double mac2x2[4])
{
    double Wynik;

    Wynik=mac2x2[0]*mac2x2[2]-mac2x2[1]*mac2x2[3];

    return Wynik;
}

bool Macierz::operator == (const Macierz & W2)const
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            if (abs(tab[i][j]-W2[i][j]) >= 0.000001)
            {
                return false;
            }
        }
    }
    return true;
}

bool Macierz::operator != (const Macierz & W2)const
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            if (abs(tab[i][j]-W2[i][j]) >= 0.000001)
            {
                return true;
            }
        }
    }
    return false;
}

const Wektor & Macierz::zwroc_kolumne (int ind)
{
    Wektor Wynik;

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = tab[ind][i];
    }
    return Wynik;
}

void Macierz::zmien_kolumne(int ind, Wektor nowy)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        tab[ind][i] = nowy[i];
    }
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Strm>>Mac[i][j];
            return Strm;        
        }
    }
    Mac.transpozycja();
}

std::ostream& operator << (std::ostream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Strm<<Mac[i][j];
            return Strm;
        }
    }
}