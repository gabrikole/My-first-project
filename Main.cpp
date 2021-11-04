#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::accumulate;
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;
using std::to_string;
using std::ifstream;
using std::ofstream;



struct duomenys {
	string Vard, Pav;
	vector<int> paz = { 0 };
	int egz;
	float GP = 0;
};

duomenys get(list<duomenys> _list, int _i) {
	list<duomenys>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

int generate()
{
	return rand() % 10 + 1;
}

vector<int> auto_marks(int how_many_marks)
{
	vector<int> skaiciai;
	for (int i = 0; i < how_many_marks; i++)
	{
		skaiciai.push_back(generate());
	}
	return skaiciai;

}
float count(vector<int> skaiciai) {
	duomenys Eil;
	Eil.GP = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate();
	return Eil.GP;
}

int generate(vector<int> pazymiai)
{
	int kiek;
	cout << "iveskite studentu skaiciu: " << endl;
	cin >> kiek;
	string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::ofstream out_data(pavadinimas);
	vector<int> skaiciai;
	duomenys Eil;
	out_data << setw(20) << left << "Vardas"
		<< setw(20) << left << "Pavarde"
		<< setw(20) << left << "Galutinis(vid.)" << endl;
	for (int s = 1; s <= kiek; s = s + 1)
	{
		skaiciai = auto_marks(5);
		out_data << setw(20) << "Vardas" + to_string(s) <<
			setw(20) << "Pavarde" + to_string(s) <<
			setw(18) << count(skaiciai) << endl;;
		skaiciai.clear();
	}
	return kiek;
}
void read(std::list<duomenys>& Eil, int kiek) 
{
	int student_counter = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {

		auto start = std::chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> std::ws, buff);
		while (student_counter < kiek)
		{
			duomenys duom;
			fileRead >> duom.Vard;
			fileRead >> duom.Pav;
			fileRead >> duom.GP;
			Eil.push_back(duom);
			student_counter++;
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
	}
}

int main()  //atspausdina rezultatus

{
	vector<int> skaiciai;

	int kiek = generate(skaiciai);
	list<duomenys> studentai;
	read(studentai, kiek);
	list<duomenys> protingi;
	list<duomenys> vargsiukai;
	int vargs = 0;
	int prot = 0;

	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < kiek; i++) {
		float paz = 5.00;
		if (get(studentai, i).GP < paz) {
			vargsiukai.push_back(get(studentai, i));
			vargs++;
		}
	}
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		int _gp = get(studentai, j).GP;
		if (get(studentai, j).GP >= paz) {
			protingi.push_back(get(studentai, j));
			prot++;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Failo rusiavimas su " + to_string(kiek) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";
	string pav;
	pav = "vargsiukai_" + to_string(kiek) + ".txt";
	ofstream vargs_failas(pav);
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i = 0; i < vargs; i++) {
		float paz = 5.00;
		if (get(vargsiukai, i).GP < 5.00) {
			vargs_failas << get(vargsiukai, i).Vard << setw(20) << get(vargsiukai, i).Pav << setw(18) << get(vargsiukai, i).GP << endl;
		}
	}
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo isvedimas su " + to_string(kiek) + " studentais  i vargsiukus uztruko : " << diff1.count() << " s\n";

	pav = "kietekai3_" + to_string(kiek) + ".txt";
	ofstream prot_failas(pav);
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		//int _gp = get(studentai, j).GP;
		if (get(studentai, j).GP >= paz) {
			prot_failas << get(studentai, j).Vard << setw(20) << get(studentai, j).Pav << setw(18) << get(studentai, j).GP << endl;
		}
	}
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	cout << "Failo isvedimas su " + to_string(kiek) + " studentais  i kietekus uztruko : " << diff2.count() << " s\n";
}
