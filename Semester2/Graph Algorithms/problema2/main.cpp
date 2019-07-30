#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int dim = 1e2;
vector<int>graf[dim];
int numarNoduri;

void citireGraf() {
    ifstream in("graf.in");
    in >> numarNoduri;
    int nodPlecare, nodSosire;
    while (in >> nodPlecare >> nodSosire) {
        graf[nodPlecare].push_back(nodSosire);
        graf[nodSosire].push_back(nodPlecare);
    }
}

void noduriIzolate() {
    printf("Nodurile izolate sunt : ");
    for (int i = 1; i <= numarNoduri; i++) {
        if (graf[i].size() == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void printUi() {
    printf("\n1 - > noduri izolate \n");
    printf("2 -> graf regular ? \n");
    printf("3 -> matricea ponderilor \n");
    printf("4 -> royFloyd \n");
    printf("5 -> grafConex \n");
}

void regularGraph() {
    bool ok = true;
    for (int i = 1; i < numarNoduri; i++) {
        if (graf[i].size() != graf[i+1].size()) {
            ok = false;
        }
    }
    if (ok == true) {
        printf("Graful este regular ");
    } else if (ok == false) {
        printf("Graful nu este regular");
    }
}

int matricePonderi[dim][dim];
void initializez() {
    for (int i = 1; i<= dim; i++)
        for (int j = 1; j<= dim; j++)
            matricePonderi[i][j] = INT_MAX;
}

void facMatricePonderi() {
    initializez();
    ifstream in("grafPonderi.in");
    int nodPlecare, nodSosire, cost;
    in >> numarNoduri;
    while (in >> nodPlecare >> nodSosire >> cost)
        matricePonderi[nodPlecare][nodSosire] = cost;
    cout << "Matricea ponderilor este : \n";
    for (int i = 1; i <= numarNoduri; i++) {
        for (int j = 1; j <= numarNoduri; j++)
        if (matricePonderi[i][j] == INT_MAX) {
            cout << "oo ";
        } else {
            cout << matricePonderi[i][j] << " ";
        }
    cout << "\n";
    }
    cout << "\n";
}

int a[dim][dim];

void royFloyd() {
    ifstream in("matriceGraf.in");
    in >> numarNoduri;
    for (int i = 1; i <= numarNoduri; i++) {
        for (int j = 1; j <= numarNoduri; j++){
            int x;
            in >> x;
            a[i][j] = x;
        }
    }
     int n = numarNoduri;
     for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
     }
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == INT_MAX || (i == j) ) {
                cout << "0 ";
            } else cout << a[i][j] << " ";
        }
        cout << "\n";
     }
}

vector<int>grafConex[dim];

void grafConexx() {
    ifstream in("grafConex.in");
    in >> numarNoduri;
    for (int i = 1; i <= numarNoduri; i++)
        for (int j = 1; j <= numarNoduri; j++){
                int x;
                in >> x;
                if (x == 1) {
                    grafConex[i].push_back(j);
                    grafConex[j].push_back(i);
                }
    }
    bool ok = true;
    for (int i = 1; i <= numarNoduri; i++)
    if (grafConex[i].size() == 0) {
        ok = false;
    }
    if (ok) cout <<"conex\n";
    else cout <<"nu e conex\n";
}


int main() {
    citireGraf();
    size_t option;
    while (true) {
            printUi();
            cin >> option;
            if (option == 1) {
                noduriIzolate();
            } else if (option == 2) {
                regularGraph();
            } else if (option == 3) {
                facMatricePonderi();
            } else if (option == 4) {
                royFloyd();
            } else if (option == 5) {
                grafConexx();
            }
    }


    return 0;
}
