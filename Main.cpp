#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::vector;
using std::left;
using std::ofstream;
using std::domain_error;
using std::ifstream;


struct studentas{
  string vardas, pavarde;
  vector <float> paz;
  float egz;
  float galut;
  vector <float> mediana;
};

void print(studentas);
double mediana(vector<float> &vec);



void print(vector<studentas> Eil, int pazymiu_sk) 
{
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output << setw(20) << left << Eil[i].vardas
            << setw(20) << left << Eil[i].pavarde
            << setw(18) << left << Eil[i].galut
            << mediana(Eil[i].paz) << endl;
    }
    output << "\n\n";
}

double mediana( vector<float> &vec) {
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0) 
    throw domain_error("negalima skaiciuoti medianos tusciam vektoriui");
  sort(vec.begin(), vec.end());
  vecSize vid = size / 2;
  return size % 2 == 0? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}

unsigned int count(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}

void read(vector<studentas>& Eil, int* pazymiai)
{
    int skaiciuok = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("studentai10000.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiai = count(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(skaiciuok).vardas;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(skaiciuok).pavarde;
            for (int i = 0; i < *pazymiai; i++)
            {
                fileRead >> temp;
                Eil.at(skaiciuok).paz.push_back(temp);
            }
            fileRead >> Eil.at(skaiciuok).egz;
            Eil.at(skaiciuok).galut = Eil.at(skaiciuok).galut / *pazymiai;
            Eil.at(skaiciuok).galut = Eil.at(skaiciuok).galut * 0.4 + 0.6 * Eil.at(skaiciuok).egz;
            skaiciuok++;
        }
    }
    else { std::cout << "-\n"; }
}


int main()
{
    int pazymiai;
    char temp;
    vector<studentas> Eil;
    read(Eil, &pazymiai);
    print(Eil, pazymiai);
    system("pause");
    return 0;
}
