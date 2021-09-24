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



void print(std::vector<studentas> Eil, int pazymiu_sk) 
{
    std::ofstream output;
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

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::iostream_iterator<std::string>(stream), std::iostream_iterator<std::string>());
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
            Eil.at(student_counter).galut = Eil.at(student_counter).galut / *pazymiu_sk;
            Eil.at(student_counter).galut = Eil.at(student_counter).galut * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    }
    else { std::cout << "-\n"; }
}


int main()
{
    int pazymiu_sk;
    char temp;
    std::vector<studentas> Eil;
    read_from_file(Eil, &pazymiu_sk);
    print(Eil, pazymiu_sk);
    system("pause");
    return 0;
}
