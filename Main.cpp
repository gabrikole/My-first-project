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


void print_student(std::vector<studentas> Eil, int pazymiu_sk) //atspausdina rezultatus
{
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output << std::setw(20) << std::left << Eil[i].vardas
            << std::setw(20) << std::left << Eil[i].pavarde
            << std::setw(18) << std::left << Eil[i].galut
            << mediana(Eil[i].paz) << std::endl;
    }
    output << "\n\n";
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

void read_from_file(std::vector<studentas>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    fileRead.open("studentai10000.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).vardas;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).pavarde;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            //std::cout << Eil.at(student_counter).Vard;
            Eil.at(student_counter).galut = Eil.at(student_counter).galut / *pazymiu_sk;
            Eil.at(student_counter).galut = Eil.at(student_counter).galut * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    }
    else { std::cout << "-\n"; }
}
