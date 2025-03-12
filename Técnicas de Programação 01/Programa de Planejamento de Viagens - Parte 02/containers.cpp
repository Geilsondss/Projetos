#include "containers.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;
/**
 * @file Container.cpp
 * @brief Implementa��o das classes de cont�ineres para armazenamento em mem�ria.
 * @date 2025
 */

/**
*@brief O metodo autenticar implementa a autenticacao do usuario em mem�ria pelos paramentros Codigo e senha passados, aqui comparamos os parametros com as informacoes salvas no container.
*/

bool ContainerConta::autenticar(Codigo& codigo, Senha& senha){// Tau� Valentim - 231021389
    map<string, Conta>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        if(it->second.getSenha().getValor() == senha.getValor()){
            return true;
        }
    }
    return false;
}

/**
*@brief O metodo criar implementa a cria��o do usu�rio em mem�ria pelos paramentros Codigo e senha passados, aqui salvamos os parametros no formato da classe Conta no container.
*/
bool ContainerConta::criar(Conta conta){ // Tau� Valentim - 231021389
    return container.insert(make_pair(conta.getCodigo().getValor(), conta)).second;
}

/**
*@brief O metodo excluir remove a instancia de conta desejada do container, pelo Codigo podemos excluir a conta de um usuario.
*/
bool ContainerConta::excluir(Codigo codigo){ // Tau� Valentim - 231021389
    map<string, Conta>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

/**
*@brief O metodo pesquisar busca a instancia de conta desejada do container, se encontrada a instancia e impressa na tela com todos os dados salvos.
*/
bool ContainerConta::pesquisar(Conta* conta){ // Tau� Valentim - 231021389
    map<string, Conta>::iterator it = container.find(conta->getCodigo().getValor());
    if(it != container.end()){
        *conta = it->second;
        return true;
    }
    return false;
}

/**
*@brief O metodo atualizar busca a instancia de conta desejada do container e permite que as informacoes nao identificadoras sejam mudadas.
*/
bool ContainerConta::atualizar(Conta conta){ // Tau� Valentim - 231021389
    map<string, Conta>::iterator it = container.find(conta.getCodigo().getValor());
    if(it != container.end()){
        it->second = conta;
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------------------------------------------------------


//Jo�o Vitor Santos de Sena - 190089890

// Inicializa��o das listas est�ticas
list<Viagem> ContainerViagem::viagens;
list<Destino> ContainerDestino::destinos;
list<Hospedagem> ContainerHospedagem::hospedagens;
list<Atividade> ContainerAtividade::atividades;

// Function objects for searching
struct ViagemCodigoEquals {
    Codigo codigo;
    ViagemCodigoEquals(const Codigo& c) : codigo(c) {}
    bool operator()(const Viagem& v) const {
        return v.getCodigoViagem().getValor() == codigo.getValor();
    }
};

struct ViagemContaEquals {
    Codigo codigo;
    ViagemContaEquals(const Codigo& c) : codigo(c) {}
    bool operator()(const Viagem& v) const {
        return v.getConta() && v.getConta()->getCodigo().getValor() == codigo.getValor();
    }
};

struct DestinoCodigoEquals {
    Codigo codigo;
    DestinoCodigoEquals(const Codigo& c) : codigo(c) {}
    bool operator()(const Destino& d) const {
        return d.getCodigo().getValor() == codigo.getValor();
    }
};

struct DestinoViagemEquals {
    Codigo codigo;
    DestinoViagemEquals(const Codigo& c) : codigo(c) {}
    bool operator()(const Destino& d) const {
        return d.getViagem() && d.getViagem()->getCodigoViagem().getValor() == codigo.getValor();
    }
};

struct HospedagemCodigoEquals {
    Codigo codigo;
    HospedagemCodigoEquals(const Codigo& c) : codigo(c) {}
    bool operator()( Hospedagem& h) {
        return h.getCodigoHospedagem().getValor() == codigo.getValor();
    }
};

struct HospedagemDestinoEquals {
    Codigo codigo;
    HospedagemDestinoEquals(const Codigo& c) : codigo(c) {}
    bool operator()(const Hospedagem& h) {
        return h.getCodigoHospedagem().getValor() == codigo.getValor();
    }
};

// ContainerViagem implementation
void ContainerViagem::incluir(Viagem viagem) {
    // Verifica se j� existe uma viagem com o mesmo c�digo
    for (const Viagem& v : viagens) {
        if (v.getCodigoViagem().getValor() == viagem.getCodigoViagem().getValor()) {
            throw invalid_argument("Ja existe uma viagem com este codigo.");
        }
    }
    viagens.push_back(viagem);
}

void ContainerViagem::remover(Codigo codigo) {
    auto it = find_if(viagens.begin(), viagens.end(),
        [codigo](const Viagem& v) {
            return v.getCodigoViagem().getValor() == codigo.getValor();
        });

    if (it == viagens.end()) {
        throw invalid_argument("Viagem nao encontrada.");
    }

    viagens.erase(it);
}

void ContainerViagem::atualizar(Viagem viagem) {
    auto it = find_if(viagens.begin(), viagens.end(),
        [viagem](const Viagem& v) {
            return v.getCodigoViagem().getValor() == viagem.getCodigoViagem().getValor();
        });

    if (it == viagens.end()) {
        throw invalid_argument("Viagem nao encontrada.");
    }

    *it = viagem;
}

Viagem ContainerViagem::pesquisar(Codigo codigo) {
    auto it = find_if(viagens.begin(), viagens.end(),
        [codigo](const Viagem& v) {
            return v.getCodigoViagem().getValor() == codigo.getValor();
        });

    if (it == viagens.end()) {
        throw invalid_argument("Viagem nao encontrada.");
    }

    return *it;
}

list<Viagem> ContainerViagem::getViagens() {
    return viagens;
}

list<Viagem> ContainerViagem::getViagensPorConta(Codigo codigo) {
    list<Viagem> resultado;
    copy_if(viagens.begin(), viagens.end(), back_inserter(resultado),
        [codigo](const Viagem& v) {
            return v.getConta() && v.getConta()->getCodigo().getValor() == codigo.getValor();
        });
    return resultado;
}

// ContainerDestino implementation
void ContainerDestino::incluir(Destino destino) {
    // Verifica se j� existe um destino com o mesmo c�digo
    for (const Destino& d : destinos) {
        if (d.getCodigo().getValor() == destino.getCodigo().getValor()) {
            throw invalid_argument("Ja existe um destino com este codigo.");
        }
    }
    destinos.push_back(destino);
}

void ContainerDestino::remover(Codigo codigo) {
    auto it = find_if(destinos.begin(), destinos.end(),
        [codigo](const Destino& d) {
            return d.getCodigo().getValor() == codigo.getValor();
        });

    if (it == destinos.end()) {
        throw invalid_argument("Destino nao encontrado.");
    }

    destinos.erase(it);
}

void ContainerDestino::atualizar(Destino destino) {
    auto it = find_if(destinos.begin(), destinos.end(),
        [destino](const Destino& d) {
            return d.getCodigo().getValor() == destino.getCodigo().getValor();
        });

    if (it == destinos.end()) {
        throw invalid_argument("Destino nao encontrado.");
    }

    *it = destino;
}

Destino ContainerDestino::pesquisar(Codigo codigo) {
    auto it = find_if(destinos.begin(), destinos.end(),
        [codigo](const Destino& d) {
            return d.getCodigo().getValor() == codigo.getValor();
        });

    if (it == destinos.end()) {
        throw invalid_argument("Destino nao encontrado.");
    }

    return *it;
}

list<Destino> ContainerDestino::getDestinos() {
    return destinos;
}

list<Destino> ContainerDestino::getDestinosPorViagem(Codigo codigo) {
    list<Destino> resultado;
    copy_if(destinos.begin(), destinos.end(), back_inserter(resultado),
        [codigo](const Destino& d) {
            return d.getViagem() && d.getViagem()->getCodigoViagem().getValor() == codigo.getValor();
        });
    return resultado;
}

// ContainerHospedagem implementation
void ContainerHospedagem::incluir(Hospedagem hospedagem) {
    // Verifica se j� existe uma hospedagem com o mesmo c�digo
    for (const Hospedagem& h : hospedagens) {
        if (h.getCodigoHospedagem().getValor() == hospedagem.getCodigoHospedagem().getValor()) {
            throw invalid_argument("Ja existe uma hospedagem com este codigo.");
        }
    }
    hospedagens.push_back(hospedagem);
}

void ContainerHospedagem::remover(Codigo codigo) {
    auto it = find_if(hospedagens.begin(), hospedagens.end(),
        [codigo](const Hospedagem& h) {
            return h.getCodigoHospedagem().getValor() == codigo.getValor();
        });

    if (it == hospedagens.end()) {
        throw invalid_argument("Hospedagem nao encontrada.");
    }

    hospedagens.erase(it);
}

void ContainerHospedagem::atualizar(Hospedagem hospedagem) {
    auto it = find_if(hospedagens.begin(), hospedagens.end(),
        [hospedagem](const Hospedagem& h) {
            return h.getCodigoHospedagem().getValor() == hospedagem.getCodigoHospedagem().getValor();
        });

    if (it == hospedagens.end()) {
        throw invalid_argument("Hospedagem nao encontrada.");
    }

    *it = hospedagem;
}

Hospedagem ContainerHospedagem::pesquisar(Codigo codigo) {
    auto it = find_if(hospedagens.begin(), hospedagens.end(),
        [codigo](const Hospedagem& h) {
            return h.getCodigoHospedagem().getValor() == codigo.getValor();
        });

    if (it == hospedagens.end()) {
        throw invalid_argument("Hospedagem nao encontrada.");
    }

    return *it;
}

list<Hospedagem> ContainerHospedagem::getHospedagens() {
    return hospedagens;
}

list<Hospedagem> ContainerHospedagem::getHospedagensPorDestino(Codigo codigo) {
    list<Hospedagem> resultado;
    // Primeiro, encontrar o destino correspondente
    auto destino = ContainerDestino::pesquisar(codigo);
    // Se o destino tem uma hospedagem associada, adicionar à lista
    if (destino.getHospedagem() != nullptr) {
        auto hospedagem = pesquisar(destino.getHospedagem()->getCodigoHospedagem());
        resultado.push_back(hospedagem);
    }
    return resultado;
}

// ContainerAtividade implementation
void ContainerAtividade::incluir(Atividade atividade) {
    // Verifica se j� existe uma atividade com o mesmo c�digo
    for (const Atividade& a : atividades) {
        if (a.getCodigo().getValor() == atividade.getCodigo().getValor()) {
            throw invalid_argument("Ja existe uma atividade com este codigo.");
        }
    }
    atividades.push_back(atividade);
}

void ContainerAtividade::remover(Codigo codigo) {
    for (auto it = atividades.begin(); it != atividades.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            atividades.erase(it);
            return;
        }
    }
    throw invalid_argument("Nao existe atividade com o codigo especificado.");
}

void ContainerAtividade::atualizar(Atividade atividade) {
    for (auto& a : atividades) {
        if (a.getCodigo().getValor() == atividade.getCodigo().getValor()) {
            a = atividade;
            return;
        }
    }
    throw invalid_argument("Nao existe atividade com o codigo especificado.");
}

Atividade ContainerAtividade::pesquisar(Codigo codigo) {
    for (const Atividade& a : atividades) {
        if (a.getCodigo().getValor() == codigo.getValor()) {
            return a;
        }
    }
    throw invalid_argument("Nao existe atividade com o codigo especificado.");
}

list<Atividade> ContainerAtividade::getAtividades() {
    return atividades;
}

list<Atividade> ContainerAtividade::getAtividadesPorDestino(Codigo codigo) {
    list<Atividade> atividadesDestino;
    // Primeiro, encontrar o destino correspondente
    auto destino = ContainerDestino::pesquisar(codigo);
    // Filtrar atividades que correspondem à data do destino
    for (const Atividade& a : atividades) {
        string dataAtividade = a.getData().getValor();
        string dataInicio = destino.getDataInicio().getValor();
        string dataTermino = destino.getDataTermino().getValor();

        // Como a data está no formato DD-MM-AA, podemos comparar as strings diretamente
        if (dataAtividade >= dataInicio && dataAtividade <= dataTermino) {
            atividadesDestino.push_back(a);
        }
    }
    return atividadesDestino;
}

