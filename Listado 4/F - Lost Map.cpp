//KURSKALL!!! Para matriz de adyacencia
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int V;
vector<int> parent;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

vector<Edge> matrizALista(const vector<vector<int>>& matriz) {
    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {      // evitar duplicados
            if (matriz[i][j] != INT_MAX && i != j)
                edges.push_back({i, j, matriz[i][j]});
        }
    }
    return edges;
}

vector<Edge> adyAListaAristas(const vector<vector<pair<int,int>>>& adj) {
    vector<Edge> edges;
    vector<vector<bool>> visitado(V, vector<bool>(V, false));

    for (int u = 0; u < V; u++) {
        for (auto [v, w] : adj[u]) {
            if (!visitado[u][v]) {
                edges.push_back({u, v, w});
                visitado[u][v] = visitado[v][u] = true; // marcar ambos sentidos
            }
        }
    }

    return edges;
}

void kruskalMST(const vector<Edge>& edges) {
    vector<Edge> sorted_edges = edges; // copia local para ordenar
    sort(sorted_edges.begin(), sorted_edges.end(),
         [](const Edge& a, const Edge& b) { return a.w < b.w; });

    parent.resize(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total_cost = 0, edge_count = 0;

    //cout << "Aristas en el MST:\n";
    for (auto& e : sorted_edges) {
        if (find(e.u) != find(e.v)) {
            union1(e.u, e.v);
            //cout << e.u + 1 << " " << e.v + 1 << " (costo " << e.w << ")\n";
            cout << e.u + 1 << " " << e.v + 1 << "\n";
            total_cost += e.w;
            if (++edge_count == V - 1) break;
        }
    }

    //cout << "\nCosto total del MST: " << total_cost << "\n";
}

int main() {
    cin >> V;

    vector<vector<int>> matriz(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int value;
            cin >> value;
            if (value == 0) value = INT_MAX;
            matriz[i][j] = value;
        }
    }

    vector<Edge> edges = matrizALista(matriz);
    kruskalMST(edges);

    return 0;
}


//Versión para lista de adyacencia
/*
int main() {
    cin >> V;
    int E;
    cin >> E;

    // Lista de adyacencia
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w}); // no dirigido
    }

    // Convertir la lista de adyacencia a lista de aristas
    vector<Edge> edges = adyAListaAristas(adj);

    // Ejecutar Kruskal
    kruskalMST(edges);

    return 0;
}
*/


//Notar que si me dan una  lista de aristas no necesito hacer mucho:
/*
int main() {
    cin >> V;
    int E;
    cin >> E;

    // Lista de aristas
    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }

    // Ejecutar Kruskal
    kruskalMST(edges);

    return 0;
}
*/
