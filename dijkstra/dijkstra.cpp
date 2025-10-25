#include <bits/stdc++.h>
using namespace std;

struct Aresta {
    int destino;
    int peso;
};

static void mostrarAjuda(const char* prog){
    cout << "Uso: " << prog << " [opções]\n"
         << "Opções:\n"
         << "  -h            : mostra este help\n"
         << "  -o <arquivo>  : redireciona a saída para o arquivo\n"
         << "  -f <arquivo>  : arquivo que contém o grafo de entrada\n"
         << "  -s            : mostra a solução (caminho mínimo)\n"
         << "  -w            : ao usar -s, imprime também o peso como (u,v,w)\n"
         << "  -i <v>        : vértice inicial (1-based; padrão 1)\n";
}

static void adicionarAresta(vector<vector<Aresta>>& grafo, int u, int v, int peso) {
    grafo[u].push_back({v, peso});
    grafo[v].push_back({u, peso});
}

static void dijkstra(int nVertices, const vector<vector<Aresta>>& grafo, int origem, vector<int>& dist, vector<int>& pai) {
    const int INFINITO = numeric_limits<int>::max();
    dist.assign(nVertices, INFINITO);
    pai.assign(nVertices, -1);

    using Par = pair<int,int>; 
    priority_queue<Par, vector<Par>, greater<Par>> fila;

    dist[origem] = 0;
    fila.push({0, origem});

    while (!fila.empty()) {
        auto topo = fila.top(); fila.pop();
        int d = topo.first; 
        int u = topo.second;
        
        if (d > dist[u]) continue;

        for (const auto& e : grafo[u]) {
            int v = e.destino;
            int peso = e.peso;
            
            // dist[u] != INFINITO
            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                pai[v] = u;
                fila.push({dist[v], v});
            }
        }
    }
}

int main(int argc, char *argv[]) {

    string arquivoEntrada;
    string arquivoSaida;
    bool mostrarSolucao = false;
    bool mostrarPesos = false;
    int verticeInicial = 1;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-s") { mostrarSolucao = true; }
        else if (arg == "-w") { mostrarPesos = true; }
        else if (arg == "-f" && i+1 < argc) { arquivoEntrada = argv[++i]; }
        else if (arg == "-o" && i+1 < argc) { arquivoSaida = argv[++i]; }
        else if (arg == "-i" && i+1 < argc) { verticeInicial = stoi(argv[++i]); }
        else if (arg == "-h") { mostrarAjuda(argv[0]); return 0; }
        else {
            mostrarAjuda(argv[0]); 
            return 0;
        }
    }

    if (arquivoEntrada.empty()) {
        mostrarAjuda(argv[0]);
        return 1;
    }

    ifstream arquivo(arquivoEntrada);
    if (!arquivo) {
        cerr << "Erro ao abrir arquivo: " << arquivoEntrada << "\n";
        return 1;
    }

    int nVertices, nArestas;
    arquivo >> nVertices >> nArestas;
    if (!arquivo) { cerr << "Arquivo inválido\n"; return 1; }

    vector<vector<Aresta>> grafo(nVertices);
    for (int i = 0; i < nArestas; ++i) {
        int u, v, peso;
        arquivo >> u >> v >> peso;
        if (!arquivo) { cerr << "Linha de aresta inválida\n"; return 1; }
        adicionarAresta(grafo, u-1, v-1, peso);
    }

    int origem = max(1, min(nVertices, verticeInicial)) - 1;
    vector<int> dist, pai;
    dijkstra(nVertices, grafo, origem, dist, pai);

    ostream* saida = &cout;
    ofstream arquivoSaidaOut;
    if (!arquivoSaida.empty()) {
        arquivoSaidaOut.open(arquivoSaida);
        if (!arquivoSaidaOut) { cerr << "Erro ao abrir saída: " << arquivoSaida << "\n"; return 1; }
        saida = &arquivoSaidaOut;
    }

    if (mostrarSolucao) {
        bool first = true;
        for (int v = 0; v < nVertices; ++v) {
            if (pai[v] != -1) {
                int u = pai[v];
                if (!first) (*saida) << ' ';
                if (mostrarPesos) {
                    (*saida) << '(' << (u+1) << ',' << (v+1) << ',' << (dist[v] - dist[u]) << ')';
                } else {
                    (*saida) << '(' << (u+1) << ',' << (v+1) << ')';
                }
                first = false;
            }
        }
        (*saida) << '\n';
    } else {
        for (int v = 0; v < nVertices; ++v) {
            (*saida) << (v+1) << ':';
            if (dist[v] == numeric_limits<int>::max()) {
                (*saida) << "-1";
            } else {
                (*saida) << dist[v];
            }
            if (v < nVertices - 1) (*saida) << ' ';
        }
        (*saida) << '\n';
    }

    return 0;
}