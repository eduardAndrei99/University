#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

const int mod = 666013;
int query;
int operatie, numar;

std::ifstream in("hashuri.in");
std::ofstream out("hashuri.out");

using std::vector;
vector<int>V[mod];

void op1(int pozitie) {
	bool apare = 0;
	for (const auto& k : V[pozitie]) {
		if (k == numar) {
			apare = 1;
		}
	}
	if (!apare) {
		V[pozitie].push_back(numar);
	}
	return;
}

void op2(int pozitie) {
	if (std::find(V[pozitie].begin(), V[pozitie].end(), numar) != V[pozitie].end()) {
		V[pozitie].erase(std::find(V[pozitie].begin(), V[pozitie].end(), numar));
	}
	return;
}

void op3(int pozitie) {
	bool apare = 0;
	for (const auto& k : V[pozitie]) {
		if (k == numar) {
			apare = 1;
		}
	}
	if (!apare) {
		out << "0\n";
	}
	else {
		out << "1\n";
	}
	return;
}

int main() {

	in >> query;
	for (int i = 0; i < query; i++) {
		in >> operatie >> numar;
		const int undePun = numar % mod;
		if (operatie == 1) {
			op1(undePun);
		}
		else if (operatie == 2) {
			op2(undePun);
		}
		else if (operatie == 3) {
			op3(undePun);
		}
	}

	return 0;
}