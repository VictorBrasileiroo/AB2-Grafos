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
         << "  -s            : mostra a solução (arestas da AGM)\n"
         << "  -w            : ao usar -s, imprime também o peso como (u,v,w)\n"
         << "  -i <v>        : vértice inicial (1-based; padrão 1)\n";
}

static void adicionarAresta(vector<vector<Aresta>>& grafo, int u, int v, int peso) {
    grafo[u].push_back({v, peso});
    grafo[v].push_back({u, peso});
}

static long long primAGM(int nVertices, const vector<vector<Aresta>>& grafo, int origem, vector<int>& pai, vector<int>& pesoAresta) {
    const int INFINITO = numeric_limits<int>::max();
    vector<int> chave(nVertices, INFINITO);
    vector<char> incluido(nVertices, 0);
    pai.assign(nVertices, -1);
    pesoAresta.assign(nVertices, 0);

    using Par = pair<int,int>; // (peso, vertice)
    priority_queue<Par, vector<Par>, greater<Par>> fila;

    chave[origem] = 0;
    fila.push({0, origem});

    long long custo = 0;
    int inseridos = 0;

    while (!fila.empty() && inseridos < nVertices) {
    auto topo = fila.top(); fila.pop();
    int w = topo.first; int u = topo.second;
        if (incluido[u]) continue;
        incluido[u] = 1;
        ++inseridos;
        custo += (w == numeric_limits<int>::max() ? 0 : w);

        for (const auto& e : grafo[u]) {
            int v = e.destino;
            int peso = e.peso;
            if (!incluido[v] && peso < chave[v]) {
                chave[v] = peso;
                pai[v] = u;
                pesoAresta[v] = peso;
                fila.push({peso, v});
            }
        }
    }
    return custo;
}

int main(int argc, char *argv[]) {

    string arquivoEntrada;
    string arquivoSaida;
    bool mostrarSolucao = false;
    bool mostrarPesos = false;
    int verticeInicial = 1; // 1-based por padrão

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
        // converte para 0-based
        adicionarAresta(grafo, u-1, v-1, peso);
    }

    // ajusta vértice inicial (1-based -> 0-based, clamp)
    int origem = max(1, min(nVertices, verticeInicial)) - 1;
    vector<int> pai, pesoAresta;
    long long custo = primAGM(nVertices, grafo, origem, pai, pesoAresta);

    ostream* saida = &cout;
    ofstream arquivoSaidaOut;
    if (!arquivoSaida.empty()) {
        arquivoSaidaOut.open(arquivoSaida);
        if (!arquivoSaidaOut) { cerr << "Erro ao abrir saída: " << arquivoSaida << "\n"; return 1; }
        saida = &arquivoSaidaOut;
    }

    if (mostrarSolucao) {
        // imprime arestas (u,v) com 1-based, ignorando o root sem pai
        bool first = true;
        for (int v = 0; v < nVertices; ++v) {
            if (pai[v] != -1) {
                int u = pai[v];
                if (!first) (*saida) << ' ';
                if (mostrarPesos) {
                    (*saida) << '(' << (u+1) << ',' << (v+1) << ',' << pesoAresta[v] << ')';
                } else {
                    (*saida) << '(' << (u+1) << ',' << (v+1) << ')';
                }
                first = false;
            }
        }
        (*saida) << '\n';
    } else {
        (*saida) << custo << '\n';
    }

    return 0;
}