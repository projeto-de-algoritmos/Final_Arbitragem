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
    int numMoedas(); 
    void setTabela(vector <vector <double>> &tabela);
    void atualizaTabela(vector <double> &coversoes);
    void atualizaMoedas(string &moeda); 
    void imprimirTabela();
    void bellmanFord();
};

#endif
