#include "Grafo.hpp"

#include <iomanip>

string Grafo::getMoeda(int indice) {
    return moedas[indice];
}

void Grafo::setMoedas(vector <string> &moedas) {
    this->moedas = moedas;
}

void Grafo::setTabela(vector <vector <double>> &tabela) {
    this->tabela = tabela;
}

void Grafo::imprimirTabela() {
    cout << "        ";
    for(int i = 0; i < (int)moedas.size(); i++)
        cout << moedas[i] << setw(11);
    cout << endl;
    for(int i = 0; i < (int)tabela.size(); i++) {
        cout << setw(0);
        cout << moedas[i] << setw(11);
        for(int j = 0; j < (int)tabela.size(); j++)
            cout << tabela[i][j] << setw(11);
        cout << endl;
    }
}
