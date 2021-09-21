#include <iostream>
#include <iomanip>
#include <string>
#include "libai.hpp"

struct studentas{
  string vardas, pavarde;
  float paz[10];
  float egz;
  float galut;
};

void print(studentas);

int main() {
  cout <<"Įveskite studentų skaičių: "<<endl;
  int n; //studentu skaicius
  cin>> n;
  studentas grupe[n];
  float sum=0;
  for (int i=0; i<n; i++)
  {
    cout<<"Įveskite "<<i+1<<"-o studento vardą ir pavardę:";
    cin>>grupe[i].vardas>>grupe[i].pavarde;
    sum=0;
    for (int j=0; j<7; j++)
    {
      cout<<"Įveskite "<<j+1<<" pažymio įvertį:";
      cin>>grupe[i].paz[j];
      sum+= grupe[i].paz[j];
    }
    cout<<"Įveskite "<<i+1<<" -o studento egzamino pažymį:";
    cin>>grupe[i].egz;
    grupe[i].galut=0.4*sum/7.+0.6*grupe[i].egz;
    }

    for (auto &kint: grupe){
      print(kint);
    }
}

void print(studentas kint){
   cout<<setw(20)<<kint.vardas<<setw(20)<<kint.pavarde;
      for (auto &i: kint.paz) cout<<setw(5)<<i;
      cout<<setw(5)<<kint.egz<<setw(5)<<setprecision(20)<<kint.galut<<endl;
}
