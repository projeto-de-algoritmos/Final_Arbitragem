#include "GerenciadorArquivos.hpp"
#include <fstream>
#include <sstream>

void GerenciadorArquivos::carregarArquivo(string nome, Grafo &grafo) {
    ifstream inFile("data/" + nome + ".txt");
    if(!inFile.is_open()) {
        cout << "Não foi possível abrir o arquivo" << endl;
        return;
    }
    vector <string> moedas;
    string linha, moeda;
    getline(inFile, linha);
    stringstream lineStream(linha);
    while(lineStream >> moeda)
        moedas.push_back(moeda);
    vector <vector <double>> tabela(moedas.size());
    double valor;
    for(int i = 0; i < (int)moedas.size(); i++) {
        for(int j = 0; j < (int)moedas.size(); j++) {
            inFile >> valor;
            tabela[i].push_back(valor);
        }
    }
    grafo.setMoedas(moedas);
    grafo.setTabela(tabela);
    inFile.close();
    cout << "Dados carregados com sucesso" << endl;
}

void GerenciadorArquivos::salvarArquivo(string nome, Grafo &grafo) {
    ofstream toFile;
    toFile.open("data/" + nome + ".txt");
    if(!toFile.is_open()) {
        cout << "Não foi possível concluir a operação" << endl;
        return;
    }
    for(int i = 0; i < grafo.getQtDeMoedas(); i++) {
        toFile << grafo.getMoeda(i);
        if(i < grafo.getQtDeMoedas() - 1)
            toFile << " ";
    }
    toFile << endl;
    for(int i = 0; i < grafo.getQtDeMoedas(); i++) {
        for(int j = 0; j < grafo.getQtDeMoedas(); j++) {
            toFile << grafo.getValor(i, j);
            if(j < grafo.getQtDeMoedas() - 1)
                toFile << " ";
        }
        toFile << endl;
    }
    toFile.close();
    cout << "Dados salvos com sucesso" << endl;
}
