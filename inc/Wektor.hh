#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {

   double tab[ROZMIAR];

  public:

  Wektor(double xx, double yy, double zz); 
  Wektor();

double & operator [] (int index);
  const double & operator [] (int index) const;
  

  const Wektor operator+(const Wektor & W2) const; 
  const Wektor operator-(const Wektor & W2) const; 
   double operator*(const Wektor & W2) const;
  const Wektor operator*(double l2)const; 
   
 
  double dlugosc() const;

  bool operator==(const Wektor & W2)const;
  bool operator!=(const Wektor & W2)const;

  

};

 Wektor operator*(double l1, const Wektor & W2); 

std:: ostream & operator << (std::ostream &strm, const Wektor &W);
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *   ~bk/edu/kpo/zalecenia.txt 
 */


#endif
