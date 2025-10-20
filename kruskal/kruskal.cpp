#include <iostream>

void mostrarHelp(){
    std::cout << "Uso: ./kruskal" << std::endl;
    std::cout << "Opcoes:" << std::endl;
    std::cout << "  -h            : mostra este help" << std::endl;
    std::cout << "  -o <arquivo>  : redireciona a saida para o 'arquivo'" << std::endl;
    std::cout << "  -f <arquivo>  : indica o 'arquivo' que contem o grafo de entrada" << std::endl;
    std::cout << "  -s            : mostra a solucao" << std::endl;
}

int main(int argc, char *argv[]) {
    return 0;
}