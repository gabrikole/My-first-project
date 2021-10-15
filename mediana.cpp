
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


#include "mediana.h"

float mediana(vector<int> pazymiai)
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] != 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        return float(pazymiai[(counter / 2)]);
    }
}
