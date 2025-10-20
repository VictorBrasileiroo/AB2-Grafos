# AB2 - GRAFOS

Este projeto contém a implementação de quatro algoritmos em grafos em C++:Este projeto contém a implementação de quatro algoritmos em grafos em C++:

1.  **Prim** (Árvore Geradora Mínima) 

2.  **Kruskal** (Árvore Geradora Mínima)

3.  **Dijkstra** (Caminhos Mínimos)

4.  **Kosaraju** (Componentes Fortemente Conexas)



## Pré-requisitos## Pré-requisitos



Para compilar e executar este projeto, você precisará de um ambiente Linux com as seguintes ferramentas instaladas:

* `g++` (Compilador C++)

* `make` (Ferramenta de automação de compilação)



**Para usuários Windows:****Para usuários Windows:**

Recomenda-se o uso do **WSL (Subsistema do Windows para Linux)**. Todos os comandos abaixo devem ser executados dentro do terminal do WSL.

## Estrutura do Projeto

O projeto é dividido em quatro pastas independentes, uma para cada algoritmo:

```
trabalho_grafos/
├── dijkstra/
│   ├── dijkstra.cpp
│   └── Makefile
├── kosaraju/
│   ├── kosaraju.cpp
│   └── Makefile
├── kruskal/
│   ├── kruskal.cpp
│   └── Makefile
└── prim/
    ├── prim.cpp
    └── Makefile
```

## Como Compilar

Cada algoritmo deve ser compilado individualmente.

1.  Abra seu terminal (ou terminal WSL).
2.  Navegue até a pasta do algoritmo desejado.
3.  Execute o comando `make`.

**Exemplo (Compilando o Prim):**

```bash
# Navega até a pasta raiz do projeto
cd /caminho/para/trabalho_grafos/

# Entra na pasta do algoritmo Prim
cd prim/

# Compila o código
make
```

Isso criará um arquivo executável chamado `prim` dentro da pasta `prim/`. Repita o processo para as outras pastas (`kruskal`, `dijkstra`, `kosaraju`).

## Como Executar

Após compilar, você pode executar o programa diretamente do terminal, passando os parâmetros necessários.

### 1. Prim

Calcula a Árvore Geradora Mínima.

```bash
# Exemplo 1: Calcula o custo da AGM com vértice inicial 1
./prim -f arquivo_entrada.dat -i 1

# Exemplo 2: Mostra a árvore (arestas) da solução
./prim -f arquivo_entrada.dat -i 1 -s
```

### 2. Kruskal

Calcula a Árvore Geradora Mínima.

```bash
# Exemplo 1: Calcula o custo da AGM
./kruskal -f arquivo_entrada.dat

# Exemplo 2: Mostra a árvore (arestas) da solução
./kruskal -f arquivo_entrada.dat -s
```

### 3. Dijkstra

Calcula o caminho mínimo do vértice inicial para todos os outros.

```bash
# Exemplo: Mostra a distância do vértice 1 para os demais
./dijkstra -f arquivo_entrada.dat -i 1
```

### 4. Kosaraju

Encontra as componentes fortemente conexas.

```bash
# Exemplo: Imprime as componentes
./kosaraju -f arquivo_entrada.dat
```

### Parâmetros Comuns

  * `-h`: Mostra o menu de ajuda do algoritmo.
  * `-f <arquivo>`: Especifica o arquivo de entrada do grafo.
  * `-o <arquivo>`: Redireciona a saída padrão (resultado) para um arquivo de texto.
  * `-s`: (Prim/Kruskal) Mostra a solução (a árvore) em vez de apenas o custo.
  * `-i <vertice>`: (Prim/Dijkstra) Indica o vértice inicial.

## Como Limpar (Apagar Executáveis)

Para apagar os arquivos executáveis gerados (ex: `prim`, `kruskal`), navegue até a pasta do algoritmo e execute:

```bash
make clean
```