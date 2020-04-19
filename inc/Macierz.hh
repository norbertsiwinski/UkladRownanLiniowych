#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {


Wektor tab[ROZMIAR];

  public:

/* gettery i cettery */
  Wektor & operator[](int index);
const Wektor & operator[](int index)const;

  
Macierz();
Macierz(Wektor A, Wektor B, Wektor C);

const Wektor  operator *(const Wektor & B);
const Macierz operator +(const Macierz & B);
const Macierz operator -(const Macierz & B);
const Macierz operator *(const Macierz & B);
const Macierz operator *(double B);


const Macierz transponuj() const;
void Transponuj();
 /*const Macierz dopelnien(int x, int y)const;
const Macierz odwracaj() const; */


double wyznacznik(); /* na razie tylo SARRUS */

bool operator==(const Macierz & W2)const;
bool operator !=(const Macierz & W2)const;

};





/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */









#endif
