#include "InterfacePrincipal.hpp"

void InterfacePrincipal::menuPrincipal() {
    int opcao = 1;
    while(opcao != 0) {
        cout << "(1) Iniciar nova tabela" << endl;
        cout << "(2) Cadastrar nova moeda" << endl;
        cout << "(3) Deletar moeda" << endl;
        cout << "(4) Alterar valor de conversão" << endl;
        cout << "(5) Ver tabela de conversão" << endl;
        cout << "(6) Computar oportunidades de lucro" << endl; 
        cout << "(7) Carregar exemplo" << endl;
        cout << "(8) Carregar tabela" << endl;
        cout << "(9) Salvar tabela" << endl;
        cout << "(0) Finalizar" << endl;
        opcao = getInt();
        if(opcao == 1)
            cadastrarTabela();
        else if( opcao == 2)
            novaMoeda();
        else if(opcao == 3)
            deletarMoeda();
        else if(opcao == 4)
            alterarConversao();
        else if(opcao == 5)
            mostrarTabela();
        else if(opcao == 6)
            calcularLucro();
        else if(opcao == 7)
            carregarExemplo();
        else if(opcao == 8)
            carregarDados();
        else if(opcao == 9)
            salvarDados();
    }
}

void InterfacePrincipal::mostrarTabela() {
    system("clear||cls");
    grafo.imprimirTabela();
}

void InterfacePrincipal::cadastrarTabela() {
    system("clear||cls");
    int quantidade = getQuantidade("Quantidade de moedas: ");
    vector <string> moedas;
    for(int i = 0; i < quantidade; i++) {
        bool valido = true;
        string moeda = getSigla("Moeda " + to_string(i + 1) + ": ");
        for(int j=0; j< (int) moedas.size(); j++){
            if(moeda == moedas[j]){     
                cout << "Essa moeda já foi cadastrada " << endl;
                i--;
                valido = false;
                break;
            }
        }
        if(valido)
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
    spam("Tabela cadastrada com sucesso");
}

void InterfacePrincipal::novaMoeda() {
    system("clear||cls");
    string moeda = getSigla("Sigla: ");
    if(isNew(moeda)){
        vector <double> conversoes; 
        for(int i=0; i < (int) grafo.numMoedas(); i++){
            string mensagem = "De " + grafo.getMoeda(i) + " para " + moeda + ": ";
            double conversao = getConversao(mensagem);
            conversoes.push_back(1/conversao); 
        }
        conversoes.push_back(1); 
        grafo.atualizaMoedas(moeda);
        grafo.atualizaTabela(conversoes);
        spam("Moeda cadastrada com sucesso!");
    }
    else
        spam(moeda + " já está cadastrada");
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

void InterfacePrincipal::calcularLucro() {
    if(grafo.getQtDeMoedas() == 0) {
        spam("Cadastre uma tabela para utilizar essa opção");
        return;
    }
    system("clear||cls");
    grafo.bellmanFord(getConversao("Digite o valor com o qual deseja lucrar: "));
}

void InterfacePrincipal::deletarMoeda() {
    system("clear||cls");
    if(grafo.numMoedas() == 0){
        spam("Não há moedas cadastradas"); 
        return; 
    }
    string moeda = getSigla("Informe a sigla da moeda que deseja excluir: ");
    grafo.excluirMoeda(moeda);
}

void InterfacePrincipal::alterarConversao() {
    system("clear||cls");
    string moeda1 = getSigla("Moeda 1: ");
    string moeda2 = getSigla("Moeda 2: ");
    if(!isNew(moeda1) && !isNew(moeda2)){
        double conversao = getConversao("Novo valor de conversão: ");
        grafo.atualizarConversao(moeda1, moeda2, conversao);
        spam("Conversão atualizada com sucesso");
    }
    else
        spam("Pelo menos uma das moedas ainda não foi cadastrada");
}

void InterfacePrincipal::carregarExemplo() {
    system("clear||cls");
    if(gerenciadorArquivos.carregarArquivo("exemplo", grafo))
        spam("Dados carregados com sucesso");
    else
        spam("Não foi possível concluir a operação");
}

void InterfacePrincipal::salvarDados() {
    system("clear||cls");
    string nome;
    cout << "Nome do arquivo para salvar: ";
    getline(cin, nome);
    if(gerenciadorArquivos.salvarArquivo(nome, grafo))
        spam("Dados salvos com sucesso");
    else
        spam("Não foi possível concluir a operação");
}

void InterfacePrincipal::carregarDados() {
    system("clear||cls");
    string nome;
    cout << "Nome do arquivo para carregar: ";
    getline(cin, nome);
    if(gerenciadorArquivos.carregarArquivo(nome, grafo))
        spam("Dados carregados com sucesso");
    else
        spam("Não foi possível concluir a operação");
}

void InterfacePrincipal::spam(string mensagem){
    system("clear||cls"); 
    cout << mensagem << endl << endl; 
}

bool InterfacePrincipal::isNew(string moeda){
    for(int i =0; i< grafo.getQtDeMoedas(); i++){
        if(moeda == grafo.getMoeda(i))
            return false;
    }
    return true;
}
