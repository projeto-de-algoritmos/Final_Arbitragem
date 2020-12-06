#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "Grafo.hpp"
#include "GerenciadorArquivos.hpp"

class InterfacePrincipal {
private:
    Grafo grafo;
    GerenciadorArquivos gerenciadorArquivos;
public:
    void menuPrincipal();
    void cadastrarTabela();
    void novaMoeda();
    int getQuantidade(string mensagem);
    string getSigla(string mensagem);
    bool validaSigla(string &sigla);
    double getConversao(string mensagem);
    int getInt();
    void spam(string mensagem); 
    void calcularLucro();
    void deletarMoeda(); 
    void carregarExemplo();
    void alterarConversao(); 
    void salvarDados();
    void carregarDados();
    bool isNew(string moeda);
};

#endif
