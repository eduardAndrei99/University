/*
 * Rezolvare labirint
 * Implementare : Nechifor Eduard-Andrei
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <deque>

using namespace std;

const int dim = 300; //Dimensiunea labirintului maxima, se poate modifica oricand

/*
 * Structura unei pozitii
 * Param :: linie -> linia din labirint
 * Param :: coloana -> coloana din labirint
*/
typedef struct pozitie {
    int linie;
    int coloana;
} pozitie;

/*
 * Avem nevoie de o coada
 * De pozitii
 * Unde initial vom avea nodul sursa(adica de unde incepem sa plecam)
 * O matrice ce va memora labirintul propriu zis
 * 1 semnifica perete, 0 pozitie libera
*/
queue<pozitie>q;
int labirint[dim][dim], liniiLabirint, coloaneLabirint;
bool vizitat[dim][dim], gasit;
pozitie sursa, destinatie;

void citireLabirint() {

    freopen("labirint.in", "r", stdin);
    char caracter;
    int linie = 1, coloana = 1;
    char s[dim];

    while (true) {
        coloana = 1;
        cin.get(s, dim);
        cin.get();
        if (strlen(s) == 0) {
            return;
        } else {
            liniiLabirint++;
            coloaneLabirint = strlen(s);
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '1') {
                    labirint[liniiLabirint][coloana] = 1;
                    coloana++;
                } else if (s[i] == ' ') {
                    labirint[liniiLabirint][coloana] = 0;
                    coloana++;
                } else if (s[i] == 'S') {
                    sursa.linie = liniiLabirint;
                    sursa.coloana = coloana;
                    labirint[liniiLabirint][coloana] = 0;
                    coloana++;
                } else if (s[i] == 'F') {
                    labirint[liniiLabirint][coloana] = 0;
                    coloana++;
                    destinatie.linie = liniiLabirint;
                    destinatie.coloana = coloana;
                }
            }
        }
    }
}

bool inLabirint(int i, int j) {
    return (i >= 1 && i <= liniiLabirint && j >= 1 && j <= coloaneLabirint && labirint[i][j] == 0);
}

deque<pozitie>solutie;

void sol(int i, int j) {

    if (gasit) return;
    if (labirint[i][j] == 0) {
        gasit = 1;
        return;
    }
    /*
    sus
    */
    if (labirint[i - 1][j] == labirint[i][j] - 1) {
        pozitie poz;
        poz.linie = i - 1, poz.coloana = j;
        solutie.push_back(poz);
        sol(i - 1, j);
        //solutie.pop_back();
    }

    if (labirint[i + 1][j] == labirint[i][j] - 1) {
        pozitie poz;
        poz.linie = i + 1, poz.coloana = j;
        solutie.push_back(poz);
        sol(i + 1, j);
        //solutie.pop_back();
    }

    if (labirint[i][j + 1] == labirint[i][j] - 1) {
        pozitie poz;
        poz.linie = i, poz.coloana = j + 1;
        solutie.push_back(poz);
        sol(i, j + 1);
        //solutie.pop_back();
    }

    if (labirint[i][j - 1] == labirint[i][j] - 1) {
        pozitie poz;
        poz.linie = i, poz.coloana = j - 1;
        solutie.push_back(poz);
        sol(i, j - 1);
       // solutie.pop_back();
    }

}

char matriceSol[dim][dim];
int finalSol[dim][dim];


int main() {

    citireLabirint();
    q.push(sursa);
    vizitat[sursa.linie][sursa.coloana] = true;
    labirint[sursa.linie][sursa.coloana - 1] = vizitat[sursa.linie][sursa.coloana] = 1;
    labirint[sursa.linie][sursa.coloana + 1] = vizitat[sursa.linie][sursa.coloana + 1] = 1;
    labirint[destinatie.linie][destinatie.coloana - 1] = vizitat[destinatie.linie][destinatie.coloana - 1] = 1;
    labirint[destinatie.linie][destinatie.coloana + 1] = vizitat[destinatie.linie][destinatie.coloana + 1] = 1;


    while (q.empty() == false) {
        pozitie elementCurent = q.front();
        q.pop();
        int linie = elementCurent.linie;
        int coloana = elementCurent.coloana;
        /*
        Sus
        */
        if (inLabirint(linie - 1, coloana)) {
            if (!vizitat[linie - 1][coloana]) {
                pozitie deAdaugat;
                deAdaugat.linie = linie - 1;
                deAdaugat.coloana = coloana;
                q.push(deAdaugat);
                vizitat[linie - 1][coloana] = true;
                labirint[linie - 1][coloana] = 1 + labirint[linie][coloana];
            }
        }
        /*
        Jos
        */
        if (inLabirint(linie + 1, coloana)) {
            if (!vizitat[linie + 1][coloana]) {
                pozitie deAdaugat;
                deAdaugat.linie = linie + 1;
                deAdaugat.coloana = coloana;
                q.push(deAdaugat);
                vizitat[linie + 1][coloana] = true;
                labirint[linie + 1][coloana] = 1 + labirint[linie][coloana];
            }
        }
        /*
        Stanga
        */
        if (inLabirint(linie, coloana - 1)) {
            if (!vizitat[linie][coloana - 1]) {
                pozitie deAdaugat;
                deAdaugat.linie = linie;
                deAdaugat.coloana = coloana - 1;
                q.push(deAdaugat);
                vizitat[linie][coloana - 1] = true;
                labirint[linie][coloana - 1] = 1 + labirint[linie][coloana];
            }
        }
        /*
        Dreapta
        */
        if (inLabirint(linie, coloana + 1)) {
            if (!vizitat[linie][coloana + 1]) {
                pozitie deAdaugat;
                deAdaugat.linie = linie;
                deAdaugat.coloana = coloana + 1;
                q.push(deAdaugat);
                vizitat[linie][coloana + 1] = true;
                labirint[linie][coloana + 1] = 1 + labirint[linie][coloana];
            }
        }
    }

    /*
    for (int i = 1; i <= liniiLabirint; i++) {
        for (int j = 1; j <= coloaneLabirint; j++)
            printf("%3d", labirint[i][j]);
            cout <<endl;
    }
    */

    solutie.push_back(destinatie);
    sol(destinatie.linie, destinatie.coloana);
    for (int i  = 0 ; i <= labirint[destinatie.linie][destinatie.coloana]; i++)
        matriceSol[solutie[i].linie][solutie[i].coloana] = 'x';

    cout <<"\n\n";
    for (int i = 1; i <= liniiLabirint; i++) {
        for (int j = 1; j <= coloaneLabirint; j++)
            printf("%c", matriceSol[i][j]);
            cout <<"\n";
    }

    int contor = 1;

   for (int i = 1; i <= liniiLabirint; i++)
        for (int j = 1; j <= coloaneLabirint; j++)
            if (matriceSol[i][j] == 'x') {
                finalSol[i][j] = contor;
                contor++;
        }

    /*
    for (int i = 1; i <= liniiLabirint; i++) {
        for (int j = 1; j <= coloaneLabirint; j++)
            printf("%3d", finalSol[i][j]);
            cout <<endl;
    }
    */

    return 0;
}
