/*
 * Codificare Prufer
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using std::vector;
const int dim = 10000; 
size_t noduri, muchii;
int tata[dim], fii[dim];
vector<int>prufer;
std::queue<size_t>coada;
int apare[dim];

/*
 * Citesc grafu 
 */
void citescGraf(std::string numeF) {
	using std::cin;
	using std::ifstream;

	ifstream in(numeF);
	in >> noduri >> muchii;
	for (size_t i = 0; i < muchii; i++) {
		int nodP, nodD;
		in >> nodP >> nodD;
		fii[nodP]++;
		tata[nodD] = nodP;
	}
}

/*
 * Codific pruffer
 */
void pruferCod() {
	for (size_t pas = 1; pas <= noduri - 1; pas++) {
		for (size_t i = 1; i <= noduri; i++) {
			if (fii[i] == 0) {
				prufer.push_back(tata[i]);
				fii[tata[i]]--;
				fii[i]--;
				break;
			}
		}
	}
}

void citescCodu(std::string numeF) {
	size_t elem;
	std::ifstream in(numeF);
	
	while (in >> elem) {
		coada.push(elem);
		apare[elem]++;
	}
}

int main() {

	int c = 1;
	if (c) {
		citescGraf("graf.txt");
		pruferCod();

		std::cout << "Codificarea prufer este : \n";
		for (size_t c = 0; c < prufer.size(); c++) {
			std::cout << prufer.at(c) << " ";
		}
		std::cin.get();
	}

	else {
		citescCodu("prufer.txt");

		size_t noduri = coada.size() + 1;
		size_t pasi = coada.size();
		while (pasi--) {
			size_t nodTata = coada.front();
			coada.pop();
			apare[nodTata]--;
			for (size_t nod2 = 1; nod2 <= noduri; nod2++) {
				if (!apare[nod2] && nodTata != nod2) {
					std::cout << "Avem " << nodTata << " " << nod2 << "\n";
					apare[nod2]++;
					coada.push(nod2);
					break;
				}
			}
		}
		std::cin.get();
	}

	return 0;
}