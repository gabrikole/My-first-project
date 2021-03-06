#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::vector;
using std::left;

struct studentas{
  string vardas, pavarde;
  vector <float> paz;
  float egz;
  float galut;
  vector <float> mediana;
};

void print(studentas);
double mediana(vector<float> &vec);

int main() {
  cout <<"Iveskite studentu skaiciu: "<<endl;
  int n; //studentu skaicius
  cin>> n;
  vector<studentas> grupe;
  studentas tempas;
  grupe.reserve(n);
  float sum=0, laik, vid, med;
  for (int i=0; i<n; i++)
  {
    cout<<"Iveskite "<<i+1<<"-o studento varda ir pavarde:" <<endl;
    cin>>tempas.vardas>>tempas.pavarde;
    sum=0;

    cout<<"Iveskite "<<i+1<<"-o studento pazymius(po paskutinio pazymio padekite kableli, kad sustabdyti ivedima):" <<endl;
    while (cin>>laik)
   
    { 
      tempas.paz.push_back(laik);
      sum+= laik;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Iveskite "<<i+1<<" -o studento egzamino pazymi:" <<endl;
    cin>>tempas.egz;
    cout<<"Suskaiciuojamas "<<i+1<<" -o studento pazymiu vidurkis:" <<endl;
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
 cout << "\n\n";
    cout << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    {
   cout<<setw(20)<<kint.vardas<<setw(20)<<kint.pavarde;
      //for (auto &i: kint.paz) cout<<setw(5)<<i;
      cout<<setw(5)<<setprecision(2)<<kint.galut<<endl;
      cout<<mediana(kint.mediana);
}
}

double mediana( vector<float> &vec) {
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0) 
    throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
  sort(vec.begin(), vec.end());
  vecSize vid = size / 2;
  return size % 2 == 0? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}
