#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

const int dim = 1e4;
bool matriceAdiacenta[dim][dim];
int numarNoduri;
bool matriceIncidenta[dim][dim];
vector<int>grafLista[dim];
int nrMuchii;

void citireGrafAdiacenta() {
    ifstream in("graf.in");

    in >> numarNoduri;
    int nodPlecare, nodSosire;
    while (in >> nodPlecare >> nodSosire) {
        assert(nodPlecare < dim && nodPlecare > 0 && nodSosire < dim && nodSosire > 0);
        matriceAdiacenta[nodPlecare][nodSosire] = true;
        matriceAdiacenta[nodSosire][nodPlecare] = true;
    }
    in.close();
}

void afisareMatriceAdiacenta() {
    int i, j;
    cout << "Matricea de adiacenta este : \n";
    for (i = 1; i <= numarNoduri; i++) {
        for (j = 1; j <= numarNoduri; j++)
            cout << matriceAdiacenta[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void afisareGrafIncidenta() {
    int i, j;
    cout << "Matricea de incidenta este : \n";
    for (i = 1; i <= numarNoduri; i++) {
        for (j = 1; j <= numarNoduri; j++)
            cout << matriceIncidenta[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void citireGrafIncidenta() {
    ifstream in("graf.in");

    in >> numarNoduri;
    int nodPlecare, nodSosire;
    nrMuchii = 0;
    while (in >> nodPlecare >> nodSosire) {
            ++nrMuchii;
            matriceIncidenta[nodPlecare][nrMuchii] = matriceIncidenta[nodSosire][nrMuchii] = 1;
    }
    in.close();
}

void adiacentaInLista() {

    citireGrafAdiacenta();
    //Golesc lista
    for (int i = 1; i <= numarNoduri; i++)
        grafLista[i].clear();

    for (int i = 1; i<= numarNoduri; i++)
        for (int j = 1; j <= numarNoduri; j++) {
            if (matriceAdiacenta[i][j] == true)
                grafLista[i].push_back(j);
        }
}

void afisezLista() {

    for (int i = 1; i<= numarNoduri; i++) {
        cout << i << " este vecin cu ";
        for(int j = 0; j < grafLista[i].size(); j++) {
            cout << grafLista[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void incidentaInLista() {
    for (int i = 1; i <= numarNoduri; i++)
        grafLista[i].clear();
    citireGrafIncidenta();
    int nodPlecare, nodSosire;
    int muchie;
    for (muchie = 1; muchie <= nrMuchii; muchie++) {
        nodPlecare = -1;
        nodSosire = -1;
        for (int linie = 1; linie <= numarNoduri; linie++)
            if(matriceIncidenta[linie][muchie] && nodPlecare == -1) {
                nodPlecare = linie;
            } else if(matriceIncidenta[linie][muchie] && nodPlecare != -1) {
                nodSosire = linie;
            }
        grafLista[nodPlecare].push_back(nodSosire);
        grafLista[nodSosire].push_back(nodPlecare);
    }
}

void printUi() {
    printf("1 -> Pentru matricea de adiacenta \n");
    printf("2 -> Pentru matricea de incidenta \n");
    printf("3 -> Conversia din adiacenta in lista \n");
    printf("4 -> Conversia din incidenta in lista \n");
    printf("5 -> Iesire \n");
    printf("\n");
}


int main() {
    while(1) {
        int option;
        printUi();
        scanf("%d", &option);
        if (option == 1) {
            citireGrafAdiacenta();
            afisareMatriceAdiacenta();
        } else if (option == 2) {
            citireGrafIncidenta();
            afisareGrafIncidenta();
        } else if (option == 5) {
            return 0;
        } else if (option == 3) {
            adiacentaInLista();
            afisezLista();
        } else if (option == 4) {
            incidentaInLista();
            afisezLista();
        }
    }

    return 0;
}
