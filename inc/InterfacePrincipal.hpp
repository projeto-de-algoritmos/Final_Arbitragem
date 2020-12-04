#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "Grafo.hpp"

class InterfacePrincipal {
private:
    Grafo grafo;
public:
    void menuPrincipal();
    void cadastrarTabela();
    int getQuantidade(string mensagem);
    string getSigla(string mensagem);
    bool validaSigla(string &sigla);
    double getConversao(string mensagem);
    int getInt();
};

#endif
