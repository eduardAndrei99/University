#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int dim = 101;

ifstream in("graf.in");
bool graf[dim][dim];
int nrNoduri, nrMuchii;

void citireGraf() {
    in >> nrNoduri >> nrMuchii;
    for (int i = 0; i < nrMuchii; i++) {
        int nodPlecare, nodSosire;
        in >> nodPlecare >> nodSosire;
        graf[nodPlecare][nodSosire] = true;
    }
}

void royW() {
    for (int k = 1; k <= nrNoduri; k++) {
        for (int i = 1; i <= nrNoduri; i++) {
            for (int j = 1; j <= nrNoduri; j++) {
                if (!graf[i][j]) {
                    graf[i][j] = graf[i][k] & graf[k][j];
                }
            }
        }
    }
}

int main() {

    citireGraf();
    royW();

    for (int i = 1; i <= nrNoduri; i++) {
        for (int j = 1; j <= nrNoduri; j++)
            cout << graf[i][j] << " ";
        cout <<"\n";
    }

    return 0;
}
