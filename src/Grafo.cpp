#include "Grafo.hpp"

#include <iomanip>
#include <math.h>
#include <algorithm>

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

void Grafo::bellmanFord() {
    vector <vector <double>> tabela = this->tabela;
    for(int i = 0; i < (int)tabela.size(); i++) {
        for(int j = 0; j < (int)tabela[i].size(); j++)
            tabela[i][j] = -1 * log(tabela[i][j]);
    }
    vector <double> M(tabela.size(), INFINITY);
    vector <int> sucessor(tabela.size(), -1);
    M[0] = 0;
    for(int i = 0; i < (int)tabela.size() - 1; i++) {
        for(int v = 0; v < (int)tabela.size(); v++) {
            for(int w = 0; w < (int)tabela[v].size(); w++) {
                if(M[w] > M[v] + tabela[v][w]) {
                    M[w] = M[v] + tabela[v][w];
                    sucessor[w] = v;
                }
            }
        }
    }
    for(int v = 0; v < (int)tabela.size(); v++) {
        for(int w = 0; w < (int)tabela[v].size(); w++) {
            if(M[w] > M[v] + tabela[v][w]) {
                vector <int> ciclo = {w, v};
                int vertex = v;
                while(find(ciclo.begin(), ciclo.end(), sucessor[vertex]) == ciclo.end()) {
                    ciclo.push_back(sucessor[vertex]);
                    vertex = sucessor[vertex];
                }
                ciclo.push_back(sucessor[vertex]);
                cout << "Arbitrage Opportunity: ";
                for(int i: ciclo)
                    cout << moedas[i] << "   ";
                cout << endl;
                break;
            }
        }
    }
}
