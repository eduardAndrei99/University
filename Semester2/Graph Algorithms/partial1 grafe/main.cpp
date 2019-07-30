#include <bits/stdc++.h>

using namespace std;

ifstream in("graf.in");

const int dim = 500;
const int infinit = 100000;
int noduri, muchii;
vector<int>graf[dim];
int d[dim];
bool viz[dim];
int tata[dim];
int nodI, nodF;

/*
 * Citirea grafului
 */
void input() {
    in >> noduri >> muchii;
    for (int i = 0; i < muchii; i++) {
        int u, v;
        in >> u >> v;
        graf[u].push_back(v);
    }
}

queue<int>q;

void moore(int nodI, int nodF) {

    for (int i = 1; i <= noduri; i++) {
        viz[i] = false;
        d[i] = infinit;
    }

    q.push(nodI);
    viz[nodI] = true;
    d[nodI] = 0;
    tata[nodI] = -1;

    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (size_t j = 0; j < graf[u].size(); j++) {
            int vecin = graf[u][j];
            if (!viz[vecin]) {
                q.push(vecin);
                viz[vecin] = true;
                d[vecin] = 1 + d[u];
                tata[vecin] = u;
                if (vecin == nodF) {
                    return;
                }
            }
        }
    }
}

void afiseazaDrum(int nod) {
    if (tata[nod] == -1) {
        return;
    }
    afiseazaDrum(tata[nod]);
    cout << nod << " ";
}


int main() {

    input();

    cout << "Nodul initial : ";
    cin >> nodI;
    cout << "Nodul final : ";
    cin >> nodF;

    moore(nodI,nodF);
    //for (int i = 1; i <= noduri; i++) {
      //  cout << d[i] << " ";
    //}

    if (d[nodF] == infinit) {
        cout << "Nu exista drum";
        return 0;
    }

    cout << nodI << " ";
    afiseazaDrum(nodF);
    cout << "\n Lg drum = " << d[nodF];


    return 0;
}
