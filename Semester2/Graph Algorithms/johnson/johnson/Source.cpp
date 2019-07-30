#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

const int dim = 500;
const int inf = 1e9;
vector < pair<int, int>>G[dim];
int d[dim][dim];
int h[dim];
int check[dim];
int noduri, muchii;

/*
 * Citesc graful
 */
void citire() {
	in >> noduri >> muchii;
	for (int k = 0; k < muchii; k++) {
		int i, j, cost;
		in >> i >> j >> cost;
		G[i].push_back(make_pair(j, cost));
	}
}

/*
 * Il introduc pe S 
 */
void introducPeS() {
	for (int i = 1; i <= noduri; i++) {
		G[0].push_back(make_pair(i, 0));
	}
}

/*
 * Alg lui bf, returneaza -1 daca are cicluri negative, 0 daca nu are
 */
int bf(int nod) {
	
	queue<int>q;
	for (int i = 1; i <= noduri; i++) {
		h[i] = inf;
	}
	h[nod] = 0;
	q.push(nod);
	check[nod]++;
	while (q.empty() == 0) {
		int x = q.front();
		q.pop();
		for (auto& y : G[x]) {
			int vecin = y.first;
			int cost = y.second;
			if (h[vecin] > h[x] + cost) {
				if (check[vecin] == noduri - 1) {
					return -1;
				}
				h[vecin] = h[x] + cost;
				q.push(vecin);
				check[vecin]++;
			}
		}
	}
	return 0;
}


int D[dim];
struct cmp {
	bool operator()(int i, int j) {
		return D[i] > D[j];
	}
};

priority_queue<int, vector<int>, cmp>pq;
bool viz[dim];

void dij(int nod) {

	for (int i = 0; i <= noduri; i++) {
		viz[i] = 0;
		D[i] = inf;
	}

	viz[nod] = 1;
	D[nod] = 0;
	pq.push(nod);

	while (pq.empty() == false) {
		int u = pq.top();
		pq.pop();
		viz[u] = false;
		for (auto& v : G[u]) {
			int vecin = v.first;
			int cost = v.second;
			if (D[vecin] > D[u] + cost) {
				D[vecin] = D[u] + cost;
				if (!viz[vecin]) {
					pq.push(vecin);
					viz[vecin] = true;
				}
			}
		}
	}
	for (int j = 0; j <= noduri; j++) {
		d[nod][j] = D[j];
	}
}


int main() {

	citire();
	introducPeS();
	if (bf(0) == -1) {
		out << "Ciclu negativ!\n";
		return 0;
	}
	for (int i = 0; i <= noduri; i++) {
		for (auto& x : G[i]) {
			x.second = x.second + h[i] - h[x.first];
		}
	}
	/*
	for (int i = 0; i <= noduri; i++) {
		for (auto& x : G[i]) {
			int vecin = x.first;
			int cost = x.second;
			cout << i << " " << vecin << " " << cost << "\n";
		}
	}
	*/

	for (int i = 1; i <= noduri; i++) {
		dij(i);
		for (int j = 1; j <= noduri; j++) {
			//d[i][j] = d[i][j] + h[j] - h[i];
		}
	}

	cout << "\n\n h = ";
	for (int i = 1; i <= 5; i++) {
		cout << h[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= noduri; i++) {
		//dij(i);
		for (int j = 1; j <= noduri; j++) {
			d[i][j] = d[i][j] + h[j] - h[i];
		}
	}

	for (int i = 1; i <= noduri; i++) {
		for (int j = 1; j <= noduri; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

	cin.get();

	return 0;
}