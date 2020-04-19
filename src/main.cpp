#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include <fstream>



using namespace std;


int main()
{
    

  
  cout << endl << " Start programu " << endl;

Wektor W1; 
Macierz M1;
Wektor X;


  cin >> M1>> W1;
  UkladRownanLiniowych U(M1,W1);
  
  cout << U;


X=U.Oblicz();

cout << "Rozwiazanie x: ";
cout << X;


Wektor Err=M1*X-W1;

cout<< "Blad: " << Err << "Dlugosci: " << Err.dlugosc()<< endl;

}





