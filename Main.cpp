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
#include "print.h"

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
