#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "libai.hpp"

struct studentas{
  string vardas, pavarde;
  vector <float> paz;
  float egz;
  float galut;
};

void print(studentas);
double mediana(vector<float> &vec);

int main() {
  cout <<"Įveskite studentų skaičių: "<<endl;
  int n; //studentu skaicius
  cin>> n;
  vector<studentas> grupe;
  studentas tempas;
  grupe.reserve(n);
  float sum=0, laik, vid, med;
  for (int i=0; i<n; i++)
  {
    cout<<"Įveskite "<<i+1<<"-o studento vardą ir pavardę:";
    cin>>tempas.vardas>>tempas.pavarde;
    sum=0;
    while (cin>>laik)
    {
      tempas.paz.push_back(laik);
      sum+= laik;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Įveskite "<<i+1<<" -o studento egzamino pažymį:";
    cin>>tempas.egz;
    vid=std::accumulate(tempas.paz.begin(), tempas.paz.end(), 0.0) / tempas.paz.size();
    med=mediana(tempas.paz);
    cout<<med<<endl;
    tempas.galut=0.4*vid+0.6*tempas.egz;
    grupe.push_back(tempas);
    tempas.paz.clear();
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

double mediana( vector<float> &vec) {
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0) 
    throw std::domain_error("negalima skaičiuoti medianos tuščiam vektoriui");
  sort(vec.begin(), vec.end());
  vecSize vid = size / 2;
  return size % 2 == 0? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}
