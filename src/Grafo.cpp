#include "Grafo.hpp"

string Grafo::getMoeda(int indice) {
    return moedas[indice];
}

void Grafo::setMoedas(vector <string> &moedas) {
    this->moedas = moedas;
}

void Grafo::setTabela(vector <vector <double>> &tabela) {
    this->tabela = tabela;
}
