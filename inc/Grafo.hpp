#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Grafo {
private:
    vector <string> moedas;
    vector <vector <double>> tabela;
public:
    string getMoeda(int indice);
    void setMoedas(vector <string> &moedas);
    void setTabela(vector <vector <double>> &tabela);
    void imprimirTabela();
};

#endif
