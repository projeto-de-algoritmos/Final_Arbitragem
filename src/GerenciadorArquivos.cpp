#include "GerenciadorArquivos.hpp"
#include "Grafo.hpp"
#include <fstream>
#include <sstream>

void GerenciadorArquivos::carregarArquivo(string nome, vector <vector <double>> &tabela, vector <string> &moedas) {
    ifstream inFile("data/" + nome + ".txt");
    if(!inFile.is_open()) {
        cout << "Não foi possível abrir o arquivo" << endl;
        return;
    }
    string linha;
    getline(inFile, linha);
    string moeda = "";
    stringstream lineStream(linha);
    while(lineStream >> moeda)
        moedas.push_back(moeda);
    tabela.resize(moedas.size());
    double valor;
    for(int i = 0; i < (int)moedas.size(); i++) {
        for(int j = 0; j < (int)moedas.size(); j++) {
            inFile >> valor;
            tabela[i].push_back(valor);
        }
    }
    inFile.close();
}

void GerenciadorArquivos::salvarArquivo(string nome, vector <vector <double>> &tabela, vector <string> &moedas) {
    ofstream toFile;
    toFile.open("data/" + nome + ".txt");
    if(!toFile.is_open()) {
        cout << "Não foi possível concluir a operação" << endl;
        return;
    }
    for(int i = 0; i < (int)moedas.size(); i++) {
        toFile << moedas[i];
        if(i < (int)moedas.size() - 1)
            toFile << " ";
    }
    toFile << endl;
    for(int i = 0; i < (int)tabela.size(); i++) {
        for(int j = 0; j < (int)tabela.size(); j++) {
            toFile << tabela[i][j];
            if(j < (int)tabela.size() - 1)
                toFile << " ";
        }
        toFile << endl;
    }
    toFile.close();
}
