#include "GerenciadorArquivos.hpp"
#include "Grafo.hpp"
#include <fstream>
#include <sstream>

void GerenciadorArquivos::carregarArquivo(string nome, vector <vector <double>> &tabela, vector <string> &moedas) {
    ifstream inFile("data/" + nome + ".txt");
    string linha;
    if(inFile.is_open()) {
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
    } else
        cout << "Não foi possível abrir o arquivo" << endl; 
}
