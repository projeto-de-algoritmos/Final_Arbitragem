#ifndef GERENCIADORARQUIVOS_HPP
#define GERENCIADORARQUIVOS_HPP

#include <iostream>
#include <vector>

using namespace std;

class GerenciadorArquivos {
public:
    void carregarArquivo(string nome, vector <vector <double>> &tabela, vector <string> &moedas);
    void salvarArquivo(string nome, vector <vector <double>> &tabela, vector <string> &moedas);
};

#endif
