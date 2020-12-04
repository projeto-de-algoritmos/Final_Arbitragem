#include "InterfacePrincipal.hpp"

void InterfacePrincipal::menuPrincipal() {
    int opcao = 1;
    while(opcao != 0) {
        cout << "(1) Iniciar nova tabela" << endl;
        cout << "(2) Cadastrar nova moeda" << endl;
        cout << "(3) Deletar moeda" << endl;
        cout << "(4) Alterar valor de conversão" << endl;
        cout << "(5) Ver tabela de conversão" << endl;
        cout << "(6) Calcular o maior lucro com operação de conversão" << endl; 
        cout << "(7) Carregar exemplo" << endl;
        cout << "(8) Carregar tabela" << endl;
        cout << "(9) Salvar tabela" << endl;
        cout << "(0) Finalizar" << endl;
        opcao = getInt();
        if(opcao == 1)
            cadastrarTabela(); 
        else if(opcao == 5)
            grafo.imprimirTabela();
    }
}

void InterfacePrincipal::cadastrarTabela() {
    int quantidade = getQuantidade("Quantidade de moedas: ");
    vector <string> moedas;
    for(int i = 0; i < quantidade; i++) {
        string moeda = getSigla("Moeda " + to_string(i + 1) + ": ");
        moedas.push_back(moeda);
    }
    vector <vector <double>> tabela(quantidade, vector <double>(quantidade));
    for(int i = 0; i < quantidade; i++) {
        tabela[i][i] = 1;
        for(int j = i + 1; j < quantidade; j++) {
            string mensagem = "De " + moedas[i] + " para " + moedas[j] + ": ";
            double conversao = getConversao(mensagem);
            tabela[i][j] = conversao;
            tabela[j][i] = 1 / conversao;
        }
    }
    grafo.setMoedas(moedas);
    grafo.setTabela(tabela);
}

int InterfacePrincipal::getQuantidade(string mensagem) {
    int valor;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> valor;
        if(cin.fail() || valor <= 0) {
            cin.clear();
            cout << "Quantidade inválida (deve ser maior do que 0)" << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}

string InterfacePrincipal::getSigla(string mensagem) {
    string entrada;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        getline(cin, entrada);
        loop = false;
        if(!validaSigla(entrada)) {
            cout << "Sigla inválida (deve conter 3 letras)" << endl; 
            loop = true;
        }
    }
    return entrada;
}

bool InterfacePrincipal::validaSigla(string &sigla) {
    if(sigla.length() != 3)
        return false;
    for(int i = 0; i < (int)sigla.size(); i++) {
        if(!isalpha(sigla[i]))
            return false;
        sigla[i] = toupper(sigla[i]);
    }
    return true;
}

double InterfacePrincipal::getConversao(string mensagem) {
    double valor;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> valor;
        if(cin.fail() || valor <= 0) {
            cin.clear();
            cout << "Valor inválido (deve ser maior do que 0)" << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}

int InterfacePrincipal::getInt() {
    int valor;
    bool loop = true;
    while(loop) {
        loop = false;
        cin >> valor;
        if(cin.fail()) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return valor;
}
