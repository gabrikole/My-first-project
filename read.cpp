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

#include "read.h"
#include "count.h"

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



void read(vector<studentas>& Eil, int* pazymiai)
{
    int skaiciuok = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("studentai100000.txt");
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

