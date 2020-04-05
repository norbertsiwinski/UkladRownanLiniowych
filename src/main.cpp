#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych UklRown;   // To tylko przykladowe definicje zmiennej

  
  cout << endl << " Start programu " << endl << endl;

 Wektor W1(1,2,3); 
 Wektor W2(1,2,3);
 Wektor W3(3,2,1);
 Wektor W11(1,1,1); 
 Wektor W22(1,1,1);
 Wektor W33(1,1,1);
 

 
cout<<3*W1;


W1.dlugosc();
cout<<endl;


Macierz M1(W1,W2,W3);
Macierz M2(W11,W22,W33);
cout<<endl;


cout<<endl;

M1.transponuj();
cout<<endl;

cout <<M1;

M1.Transponuj();

cout<<M1;


}
