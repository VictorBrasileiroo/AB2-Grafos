#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

void mostrarHelp(){
    std::cout << "Uso: ./prim" << std::endl;
    std::cout << "Opcoes:" << std::endl;
    std::cout << "  -h            : mostra este help" << std::endl;
    std::cout << "  -o <arquivo>  : redireciona a saida para o 'arquivo'" << std::endl;
    std::cout << "  -f <arquivo>  : indica o 'arquivo' que contem o grafo de entrada" << std::endl;
    std::cout << "  -s            : mostra a solucao" << std::endl;
    std::cout << "  -i <vertice>  : vertice inicial" << std::endl;
}

int main(int argc, char *argv[]) {
    return 0;
}