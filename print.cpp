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

#include "print.h"
#include "mediana.h"

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
