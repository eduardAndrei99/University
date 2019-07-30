#include <bits/stdc++.h>

using namespace std;

const int dim = 1000;
const int infinity = 1e7;

vector< pair<int,int> >G[dim];
bool check[dim];
int d[dim];
int nodes, edges;

struct cmpD {
     bool operator()(int x, int y) {
     return d[x] > d[y];
     }
};
priority_queue<int, vector<int>, cmpD>q;

void input() {
    freopen("graf.in", "r", stdin);
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++) {
        int firstNode, secondNode, distance;
        cin >> firstNode >> secondNode >> distance;
        G[firstNode].push_back(make_pair(secondNode, distance));
    }
}

void dijkstra(int node) {

    for (int i = 1; i <= nodes; i++) {
        d[i] = infinity;
    }
    check[node] = true;
    d[node] = 0;
    q.push(node);

    while (q.empty() == false) {
        int u = q.top();
        q.pop();
        check[u] = false;
        for (size_t j = 0; j < G[u].size(); j++) {
            int v = G[u][j].first;
            int distance = G[u][j].second;
            if (d[v] > d[u] + distance) {
                d[v] = d[u] + distance;
                if (check[v] == false) {
                    q.push(v);
                    check[v] = true;
                }
            }
        }
    }
}

int main() {

    input();
    dijkstra(1);
    for (size_t j = 1; j <= nodes; j++) {
        if (d[j] == infinity) {
            cout << " oo ";
        } else {
            cout << d[j] << " ";
        }
    }

    return 0;
}
