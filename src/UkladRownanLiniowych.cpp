#include "UkladRownanLiniowych.hh"


 
 const Macierz & UkladRownanLiniowych::get_A() const {

return A;
}
 const Wektor & UkladRownanLiniowych::get_b() const{

return b;
 }


 void UkladRownanLiniowych::set_A(const Macierz & AA){

      this->A=AA;

 }
 void  UkladRownanLiniowych:: set_b(const Wektor & bb){

    this->b=bb;

 }
 Wektor UkladRownanLiniowych::Oblicz() const{

Macierz AA;
AA=A;
 double Wyz_glowny;
 Wektor W(b);
 Wektor Wynik;

 Wyz_glowny=AA.wyznacznik();

 if(Wyz_glowny!=0){

for(int i=0; i<ROZMIAR;i++){
AA[i]=W;
Wynik[i]=AA.wyznacznik();
AA[i]=A[i];
}

for(int i=0; i<ROZMIAR;i++)
Wynik[i]=Wynik[i]/Wyz_glowny;
 }
 else{ cout <<"Wyznaczik glowny rowny 0";
 exit(0);
 }

return Wynik;
 }

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){

 /* Strm >>  UklRown.get_A()  >>  UklRown.get_b(); */


Macierz AA; Wektor bb;

Strm >> AA >> bb;

UklRown.set_A(AA);
UklRown.set_b(bb);

return Strm;

}


std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych  &UklRown){


Strm << "Macierz A:"<< endl << UklRown.get_A().transponuj() << endl << "Wektor wyrazow wolnych b: "<< UklRown.get_b(); 

return Strm;
}