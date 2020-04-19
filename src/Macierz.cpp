#include "Macierz.hh"
#include <algorithm>



Wektor & Macierz::operator[](int index){

if(index <0 || index >=ROZMIAR){
      cerr << "Poza zakresem" <<endl;
      exit(1);
    }
   
   return tab[index];

}
const Wektor & Macierz::operator[](int index)const{
if(index <0 || index >=ROZMIAR){
      cerr << "Poza zakresem" <<endl;
      exit(1);
    }
   
   return tab[index];

}

Macierz::Macierz(Wektor A, Wektor B, Wektor C){

tab[0]=A;
tab[1]=B;
tab[2]=C;

}

Macierz::Macierz(){

  Wektor X;
for(int i=0; i<ROZMIAR;i++)
  tab[i]=X;
}


const Wektor  Macierz::operator *(const Wektor & B){

Wektor B1;

for(int i=0; i<ROZMIAR;i++)

B1[i]=tab[i]*B;

return B1;

}

const Macierz Macierz::operator +(const Macierz & B){

Macierz M;


for(int i=0; i<ROZMIAR;i++)
M[i]=tab[i]+B[i];

return M;
}

const Macierz Macierz::operator -(const Macierz & B){

Macierz M;


for(int i=0; i<ROZMIAR;i++)
M[i]=tab[i]-B[i];

return M;
}

const Macierz Macierz::operator * (const Macierz & B){

Macierz M;

M[0][0]=tab[0][0]*B[0][0]+tab[0][1]*B[1][0]+tab[0][2]*B[2][0];
M[0][1]=tab[0][0]*B[0][1]+tab[0][1]*B[1][1]+tab[0][2]*B[2][1];
M[0][2]=tab[0][0]*B[0][2]+tab[0][1]*B[1][2]+tab[0][2]*B[2][2];
M[1][0]=tab[1][0]*B[0][0]+tab[1][1]*B[1][0]+tab[1][2]*B[2][0];
M[1][1]=tab[1][0]*B[0][1]+tab[1][1]*B[1][1]+tab[1][2]*B[2][1];
M[1][2]=tab[1][0]*B[0][2]+tab[1][1]*B[1][2]+tab[1][2]*B[2][2];
M[2][0]=tab[2][0]*B[0][0]+tab[2][1]*B[1][0]+tab[2][2]*B[2][0];
M[2][1]=tab[2][0]*B[0][1]+tab[2][1]*B[1][1]+tab[2][2]*B[2][1];
M[2][2]=tab[2][0]*B[0][2]+tab[2][1]*B[1][2]+tab[2][2]*B[2][2];

return M;
}



double Macierz::wyznacznik(){



double Wynik;

Wynik=tab[0][0]*tab[1][1]*tab[2][2]+tab[1][0]*tab[2][1]*tab[0][2]+tab[2][0]*tab[0][1]*tab[1][2]-tab[0][2]*tab[1][1]*tab[2][0]-tab[1][2]*tab[2][1]*tab[0][0]-tab[2][2]*tab[0][1]*tab[1][0];

return Wynik;



}


const Macierz Macierz::transponuj()const{

Macierz Trans;

for(int i=0; i<ROZMIAR;i++)
for(int j=0; j<ROZMIAR;j++)
Trans[j][i]=tab[i][j];


return Trans;


}

void Macierz::Transponuj(){

Macierz M;

for(int i=0; i<ROZMIAR;i++)
for(int j=0; j<ROZMIAR;j++)

M[i][j]=tab[i][j];

for(int i=0; i<ROZMIAR;i++)
for(int j=0; j<ROZMIAR;j++)

tab[j][i]=M[i][j];



}


/*
const Macierz Macierz::dopelnien(int x, int y)const{

double wyzn_dopel;

for(int i=0; i<ROZMIAR;i++)
for(int j=0; j<ROZMIAR;j++)
wyzn_dopel=tab[x+1][y+1]*tab[x+2][y+2];

}*/
/*
const Macierz Macierz::odwracaj() const{

Macierz Odwroc;
double wyznacznik=(*this).wyznacznik;


//Odwroc=1/wyznacznik;//

return Odwroc;

} */

std::ostream & operator << (std::ostream &Strm, const Macierz &Mac){

for(int i=0; i<ROZMIAR;i++)
Strm<<Mac[i];
return Strm;
}


std::istream& operator >> (std::istream &Strm, Macierz &Mac){

for(int i=0; i<ROZMIAR;i++)
Strm>>Mac[i];

return Strm;

}


bool Macierz::operator==(const Macierz & M2)const{

double epsilon=0.000001;

for(int i=0; i<ROZMIAR;i++){
for(int j=0; j<ROZMIAR;j++)
if( abs(tab[i][j]-M2[i][j]) > epsilon)

return false;

}
return true;
}

bool Macierz::operator !=(const Macierz & M2)const{


if(*this==M2)
return false;

 return true;

}
