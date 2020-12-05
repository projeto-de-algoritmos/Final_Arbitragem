#ifndef GERENCIADORARQUIVOS_HPP
#define GERENCIADORARQUIVOS_HPP

#include "Grafo.hpp"
#include <iostream>
#include <vector>

using namespace std;

class GerenciadorArquivos {
public:
    void carregarArquivo(string nome, Grafo &grafo);
    void salvarArquivo(string nome, Grafo &grafo);
};

#endif
