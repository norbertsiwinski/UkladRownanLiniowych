#include "Wektor.hh"




/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 * 
 */

Wektor::Wektor(double xx, double yy, double zz){

   tab[0]=xx; tab[1]=yy; tab[2]=zz; 
  }

  Wektor::Wektor(){

    tab[0]=0;
    tab[1]=0;
    tab[2]=0;
  }
  

 double & Wektor::operator[](int index){

    if(index <0 || index >=ROZMIAR){
      cerr << "Poza zakresem" <<endl;
      exit(1);
    }
   
   return tab[index];
     
  }
const double & Wektor::operator[](int index) const{
   if(index <0 || index >=ROZMIAR){
      cerr << "Poza zakresem" <<endl;
      exit(1);
    }
   
   return tab[index];

}
 
 const Wektor Wektor::operator+(const Wektor & W2)const{

 Wektor W1;
for(int i=0; i<ROZMIAR; i++)
W1[i]= tab[i]+W2[i];

return W1;
 }

const Wektor Wektor::operator-(const Wektor & W2) const{

 Wektor W1;
for(int i=0; i<ROZMIAR; i++)
W1[i]= tab[i]-W2[i];

return W1;
 } 

double Wektor::operator*(const Wektor & W2) const{

double Wynik=0;


  for(int i=0; i<ROZMIAR; i++)
  Wynik=Wynik+tab[i]*W2[i];

  return Wynik;
}
const Wektor Wektor::operator*(double l2)const{

Wektor W1;

for(int i=0; i<ROZMIAR;i++)
W1[i]=tab[i]*l2;

return W1;


  }

  Wektor operator*(double l1, const Wektor & W2) {

Wektor W1;

for(int i=0; i<ROZMIAR;i++)
W1[i]=l1*W2[i];

return W1;


}

double Wektor::dlugosc()const {

  double dlug=0;
  for(int i=0; i<ROZMIAR;i++)
  dlug=(dlug + tab[i]*tab[i]);
  dlug=sqrt(dlug);


return dlug;
}
  
bool Wektor::operator==(const Wektor & W2)const{

double epsilon=0.00001;

for(int i=0; i<ROZMIAR;i++){
if(abs(tab[i]-W2[i]) > epsilon)

return false;

}

  return true;
}

bool Wektor::operator!=(const Wektor & W2)const{

if(*this==W2)
return false;
else
{
  return true;
}

}



std::istream & operator >> (std::istream &Strm, Wektor &Wek){

for(int i=0; i<ROZMIAR;i++)
Strm>>Wek[i];

return Strm;
}

std::ostream & operator << (std::ostream &strm, const Wektor &W){

strm<<"|"<<W[0] <<" "<< W[1] <<" "<< W[2]<< "|"<<endl;
return strm;

 }