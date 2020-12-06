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
    void atualizaTabela(vector <double> &coversoes);
    int numMoedas(); 
    void atualizaMoedas(string moeda);
    void excluirMoeda(string moeda);
    void atualizarConversao(string moeda1, string moeda2, double conversao);
    void imprimirTabela();
    void bellmanFord(double valor);
    int getQtDeMoedas();
    double getValor(int i, int j);
    int acharMoeda(string moeda);
};

#endif
