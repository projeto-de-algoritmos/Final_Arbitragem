#ifndef GERENCIADORARQUIVOS_HPP
#define GERENCIADORARQUIVOS_HPP

#include "Grafo.hpp"
#include <iostream>
#include <vector>

using namespace std;

class GerenciadorArquivos {
public:
    bool carregarArquivo(string nome, Grafo &grafo);
    bool salvarArquivo(string nome, Grafo &grafo);
};

#endif
