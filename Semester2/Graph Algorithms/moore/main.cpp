#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("graf.in");
const int dim = 250;  //Numarul maxim de noduri ale grafului
int t[dim], d[dim], nrNoduri, nodSursa;
vector<int>G[dim];
queue<int>q;
bool viz[dim];

void citireGraf() {
    in >> nrNoduri;
    int nodS, nodD;
    while (in >> nodS >> nodD) {
        G[nodS].push_back(nodD);
    }
    printf("Nodul sursa : ");
    scanf("%d",&nodSursa);
    return;
}

void afisezDrum(int nod) {
    if (nod==nodSursa or t[nod] == -1) {
        return;
    }
    afisezDrum(t[nod]);
    cout << nod << " ";
}


int main() {
    citireGraf();
    for (int i = 1; i <= nrNoduri; i++) {
        t[i] = -1;
        d[i] = INT_MAX;
    }
    t[nodSursa] = nodSursa;
    d[nodSursa] = 0;
    q.push(nodSursa);
    viz[nodSursa] = true;

    while (q.empty() == false) {
        int nod = q.front();
        q.pop();
        for (size_t i = 0; i < G[nod].size(); i++) {
            int vecin = G[nod][i];
            if (!viz[vecin]) {
                viz[vecin] = true;
                q.push(vecin);
                t[vecin] = nod;
                d[vecin] = 1 + d[nod];
            }
        }
    }

    for (int i = 1; i <= nrNoduri; i++) {
        if (d[i] != INT_MAX)
            cout << d[i] << " ";
        else cout << " oo ";
    }

    cout <<"\n";
    cout <<"\n";

    for (int i = 1; i<= nrNoduri; i++) {
        if (t[i]==-1){
            cout <<"Lantul din nodul " <<i<<" nu exista ";
            cout <<"\n";
        } else {
            cout <<"Lantul din nodul " <<i<<" este ";
            cout << nodSursa << " ";
            afisezDrum(i);
            cout <<"\n";
        }
    }

    return 0;
}
