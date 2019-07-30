#include <bits/stdc++.h>

using namespace std;

const int dim = 1000;
const int infinity = 1e7;

vector< pair<int,int> >G[dim];
int check[dim];
int d[dim];
int nodes, edges;

void input() {
    ifstream in("grafB.in");
    //freopen("grafB.in", "r", stdin);
    in >> nodes >> edges;
    for (int i = 1; i <= edges; i++) {
        int firstNode, secondNode, distance;
        in >> firstNode >> secondNode >> distance;
        G[firstNode].push_back(make_pair(secondNode, distance));
    }
}

int main() {

    input();
    queue<int> q;
    for (int i = 1; i <= nodes; i++) {
        d[i] = infinity;
    }

    int node;
    cout << "Nodul : ";
    cin >> node;

    check[node] = 1;
    d[node] = 0;
    q.push(node);

    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        //check[u] = false;
        for (size_t j = 0; j < G[u].size(); j++) {
            int v = G[u][j].first;
            int distance = G[u][j].second;
            if (d[v] > d[u] + distance) {
                if (check[v] == nodes + 1) {
                    cout << "Ciclu negativ !\n";
                    return 0;
                }
                d[v] = d[u] + distance;
                check[v]++;
                q.push(v);
            }
        }
    }

     for (int i = 1; i <= nodes; ++i) {
        cout << d[i] << ' ';
    }

    return 0;
}
