#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED
#include "entidades.h"
#include <list>
#include <map>


using namespace std;
/**
 * @file Container.h
 * @brief Classes de contêineres para armazenamento em memória das entidades do sistema.
 * @date 2025
 */

/**
 * @brief A classe ContainerConta implementa o salvamento em memória dos dados passados em cada um dos métodos.
 *
 * Nela ficam armazenados todos os dados e informações das contas.
 */
class ContainerConta { // Tauã Valentim - 231021389
private:
    /**
     * @brief Contêiner que armazena as contas, onde a chave é o código da conta e o valor é o objeto Conta.
     */
    map<string, Conta> container;

    /**
     * @brief Ponteiro para a instância única da classe ContainerConta, implementando o padrão Singleton.
     */
    static ContainerConta *instancia;

    /**
     * @brief Construtor privado da classe.
     */
    ContainerConta(){};

public:
    /**
     * @brief Retorna a instância única da classe ContainerConta.
     *
     * Implementa o padrão Singleton para garantir que exista apenas uma instância.
     *
     * @return Ponteiro para a instância única de ContainerConta.
     */
    static ContainerConta* getInstancia(){
        static ContainerConta instancia;
        return &instancia;
    };

    /**
     * @brief Autentica uma conta no sistema.
     *
     * @param codigo Referência para o código da conta.
     * @param senha Referência para a senha da conta.
     * @return Retorna true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticar(Codigo&, Senha&);

    /**
     * @brief Inclui uma nova conta no contêiner.
     *
     * @param conta Objeto Conta que será inserido no contêiner.
     * @return Retorna true se a conta foi criada com sucesso, false caso contrário.
     */
    bool criar(Conta);

    /**
     * @brief Remove uma conta do contêiner.
     *
     * @param codigo Código da conta que será removida.
     * @return Retorna true se a conta foi removida com sucesso, false caso contrário.
     */
    bool excluir(Codigo);

    /**
     * @brief Pesquisa uma conta pelo seu código.
     *
     * @param conta Ponteiro para o objeto Conta que será preenchido com os dados encontrados.
     * @return Retorna true se a conta for encontrada, false caso contrário.
     */
    bool pesquisar(Conta*);

    /**
     * @brief Atualiza as informações de uma conta existente.
     *
     * @param conta Objeto Conta que contém as novas informações.
     * @return Retorna true se a atualização foi realizada com sucesso, false caso contrário.
     */
    bool atualizar(Conta);
};




//João Vitor Santos de Sena - 190089890
// Forward declaration da classe Container
class Container;

/**
 * @brief Contêiner para armazenamento e gerenciamento de viagens.
 */
class ContainerViagem {
    friend class Container;
private:
    static list<Viagem> viagens;  ///< Lista estática para armazenamento de viagens

public:
    /**
     * @brief Inclui uma nova viagem no contêiner.
     *
     * @param viagem Objeto Viagem a ser incluído.
     * @throw invalid_argument Se já existir uma viagem com o mesmo código.
     */
    static void incluir(Viagem viagem);

    /**
     * @brief Remove uma viagem do contêiner.
     *
     * @param codigo Código da viagem a ser removida.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma viagem existente.
     *
     * @param viagem Objeto Viagem com os novos dados.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static void atualizar(Viagem viagem);

    /**
     * @brief Pesquisa uma viagem pelo seu código.
     *
     * @param codigo Código da viagem a ser pesquisada.
     * @return Viagem Objeto encontrado.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static Viagem pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as viagens armazenadas.
     *
     * @return list<Viagem> Lista de todas as viagens.
     */
    static list<Viagem> getViagens();

    /**
     * @brief Retorna todas as viagens associadas a uma conta.
     *
     * @param codigo Código da conta.
     * @return list<Viagem> Lista de viagens da conta especificada.
     */
    static list<Viagem> getViagensPorConta(Codigo codigo);
};

/**
 * @brief Contêiner para armazenamento e gerenciamento de destinos.
 */
class ContainerDestino {
    friend class Container;
private:
    static list<Destino> destinos;  ///< Lista estática para armazenamento de destinos

public:
    /**
     * @brief Inclui um novo destino no contêiner.
     *
     * @param destino Objeto Destino a ser incluído.
     * @throw invalid_argument Se já existir um destino com o mesmo código.
     */
    static void incluir(Destino destino);

    /**
     * @brief Remove um destino do contêiner.
     *
     * @param codigo Código do destino a ser removido.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de um destino existente.
     *
     * @param destino Objeto Destino com os novos dados.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static void atualizar(Destino destino);

    /**
     * @brief Pesquisa um destino pelo seu código.
     *
     * @param codigo Código do destino a ser pesquisado.
     * @return Destino Objeto encontrado.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static Destino pesquisar(Codigo codigo);

    /**
     * @brief Retorna todos os destinos armazenados.
     *
     * @return list<Destino> Lista de todos os destinos.
     */
    static list<Destino> getDestinos();

    /**
     * @brief Retorna todos os destinos associados a uma viagem.
     *
     * @param codigo Código da viagem.
     * @return list<Destino> Lista de destinos da viagem especificada.
     */
    static list<Destino> getDestinosPorViagem(Codigo codigo);
};

/**
 * @brief Contêiner para armazenamento e gerenciamento de hospedagens.
 */
class ContainerHospedagem {
    friend class Container;
private:
    static list<Hospedagem> hospedagens;  ///< Lista estática para armazenamento de hospedagens

public:
    /**
     * @brief Inclui uma nova hospedagem no contêiner.
     *
     * @param hospedagem Objeto Hospedagem a ser incluído.
     * @throw invalid_argument Se já existir uma hospedagem com o mesmo código.
     */
    static void incluir(Hospedagem hospedagem);

    /**
     * @brief Remove uma hospedagem do contêiner.
     *
     * @param codigo Código da hospedagem a ser removida.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma hospedagem existente.
     *
     * @param hospedagem Objeto Hospedagem com os novos dados.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static void atualizar(Hospedagem hospedagem);

    /**
     * @brief Pesquisa uma hospedagem pelo seu código.
     *
     * @param codigo Código da hospedagem a ser pesquisada.
     * @return Hospedagem Objeto encontrado.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static Hospedagem pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as hospedagens armazenadas.
     *
     * @return list<Hospedagem> Lista de todas as hospedagens.
     */
    static list<Hospedagem> getHospedagens();

    /**
     * @brief Retorna todas as hospedagens associadas a um destino.
     *
     * @param codigo Código do destino.
     * @return list<Hospedagem> Lista de hospedagens do destino especificado.
     */
    static list<Hospedagem> getHospedagensPorDestino(Codigo codigo);
};

/**
 * @brief Contêiner para armazenamento e gerenciamento de atividades.
 */
class ContainerAtividade {
    friend class Container;
private:
    static list<Atividade> atividades;  ///< Lista estática para armazenamento de atividades

public:
    /**
     * @brief Inclui uma nova atividade no contêiner.
     *
     * @param atividade Objeto Atividade a ser incluído.
     * @throw invalid_argument Se já existir uma atividade com o mesmo código.
     */
    static void incluir(Atividade atividade);

    /**
     * @brief Remove uma atividade do contêiner.
     *
     * @param codigo Código da atividade a ser removida.
     * @throw invalid_argument Se não existir atividade com o código especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma atividade existente.
     *
     * @param atividade Objeto Atividade com os novos dados.
     * @throw invalid_argument Se não existir atividade com o código especificado.
     */
    static void atualizar(Atividade atividade);

    /**
     * @brief Pesquisa uma atividade pelo seu código.
     *
     * @param codigo Código da atividade a ser pesquisada.
     * @return Atividade Objeto encontrado.
     * @throw invalid_argument Se não existir atividade com o código especificado.
     */
    static Atividade pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as atividades armazenadas.
     *
     * @return list<Atividade> Lista de todas as atividades.
     */
    static list<Atividade> getAtividades();

    /**
     * @brief Retorna todas as atividades associadas a um destino.
     *
     * @param codigo Código do destino.
     * @return list<Atividade> Lista de atividades do destino especificado.
     */
    static list<Atividade> getAtividadesPorDestino(Codigo codigo);
};

/**
 * @brief Classe estática que fornece acesso aos contêineres do sistema.
 */
class Container {
public:
    /**
     * @brief Inclui uma nova viagem no contêiner.
     *
     * @param viagem Objeto Viagem a ser incluído.
     * @throw invalid_argument Se já existir uma viagem com o mesmo código.
     */
    static void incluirViagem(Viagem viagem) {
        ContainerViagem::incluir(viagem);
    }

    /**
     * @brief Remove uma viagem do contêiner.
     *
     * @param codigo Código da viagem a ser removida.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static void removerViagem(Codigo codigo) {
        ContainerViagem::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de uma viagem existente.
     *
     * @param viagem Objeto Viagem com os novos dados.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static void atualizarViagem(Viagem viagem) {
        ContainerViagem::atualizar(viagem);
    }

    /**
     * @brief Pesquisa uma viagem pelo seu código.
     *
     * @param codigo Código da viagem a ser pesquisada.
     * @return Viagem Objeto encontrado.
     * @throw invalid_argument Se não existir viagem com o código especificado.
     */
    static Viagem pesquisarViagem(Codigo codigo) {
        return ContainerViagem::pesquisar(codigo);
    }

    /**
     * @brief Retorna todas as viagens armazenadas.
     *
     * @return list<Viagem> Lista de todas as viagens.
     */
    static list<Viagem> getViagens() {
        return ContainerViagem::getViagens();
    }

    /**
     * @brief Retorna todas as viagens associadas a uma conta.
     *
     * @param codigo Código da conta.
     * @return list<Viagem> Lista de viagens da conta especificada.
     */
    static list<Viagem> getViagensPorConta(Codigo codigo) {
        return ContainerViagem::getViagensPorConta(codigo);
    }

    /**
     * @brief Inclui um novo destino no contêiner.
     *
     * @param destino Objeto Destino a ser incluído.
     * @throw invalid_argument Se já existir um destino com o mesmo código.
     */
    static void incluirDestino(Destino destino) {
        ContainerDestino::incluir(destino);
    }

    /**
     * @brief Remove um destino do contêiner.
     *
     * @param codigo Código do destino a ser removido.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static void removerDestino(Codigo codigo) {
        ContainerDestino::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de um destino existente.
     *
     * @param destino Objeto Destino com os novos dados.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static void atualizarDestino(Destino destino) {
        ContainerDestino::atualizar(destino);
    }

    /**
     * @brief Pesquisa um destino pelo seu código.
     *
     * @param codigo Código do destino a ser pesquisado.
     * @return Destino Objeto encontrado.
     * @throw invalid_argument Se não existir destino com o código especificado.
     */
    static Destino pesquisarDestino(Codigo codigo) {
        return ContainerDestino::pesquisar(codigo);
    }

    /**
     * @brief Retorna todos os destinos armazenados.
     *
     * @return list<Destino> Lista de todos os destinos.
     */
    static list<Destino> getDestinos() {
        return ContainerDestino::getDestinos();
    }

    /**
     * @brief Retorna todos os destinos associados a uma viagem.
     *
     * @param codigo Código da viagem.
     * @return list<Destino> Lista de destinos da viagem especificada.
     */
    static list<Destino> getDestinosPorViagem(Codigo codigo) {
        return ContainerDestino::getDestinosPorViagem(codigo);
    }

    /**
     * @brief Inclui uma nova hospedagem no contêiner.
     *
     * @param hospedagem Objeto Hospedagem a ser incluído.
     * @throw invalid_argument Se já existir uma hospedagem com o mesmo código.
     */
    static void incluirHospedagem(Hospedagem hospedagem) {
        ContainerHospedagem::incluir(hospedagem);
    }

    /**
     * @brief Remove uma hospedagem do contêiner.
     *
     * @param codigo Código da hospedagem a ser removida.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static void removerHospedagem(Codigo codigo) {
        ContainerHospedagem::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de uma hospedagem existente.
     *
     * @param hospedagem Objeto Hospedagem com os novos dados.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static void atualizarHospedagem(Hospedagem hospedagem) {
        ContainerHospedagem::atualizar(hospedagem);
    }

    /**
     * @brief Pesquisa uma hospedagem pelo seu código.
     *
     * @param codigo Código da hospedagem a ser pesquisada.
     * @return Hospedagem Objeto encontrado.
     * @throw invalid_argument Se não existir hospedagem com o código especificado.
     */
    static Hospedagem pesquisarHospedagem(Codigo codigo) {
        return ContainerHospedagem::pesquisar(codigo);
    }

    /**
     * @brief Retorna todas as hospedagens armazenadas.
     *
     * @return list<Hospedagem> Lista de todas as hospedagens.
     */
    static list<Hospedagem> getHospedagens() {
        return ContainerHospedagem::getHospedagens();
    }

    /**
     * @brief Retorna todas as hospedagens associadas a um destino.
     *
     * @param codigo Código do destino.
     * @return list<Hospedagem> Lista de hospedagens do destino especificado.
     */
    static list<Hospedagem> getHospedagensPorDestino(Codigo codigo) {
        return ContainerHospedagem::getHospedagensPorDestino(codigo);
    }

    /**
     * @brief Inclui uma nova atividade no contêiner.
     *
     * @param atividade Objeto Atividade a ser incluído.
     * @throw invalid_argument Se já existir uma atividade com o mesmo código.
     */
    static void inserirAtividade(Atividade atividade) {
        ContainerAtividade::incluir(atividade);
    }

    /**
     * @brief Obtém uma atividade pelo código.
     * @param codigo Código da atividade.
     * @param atividade Ponteiro para armazenar a atividade.
     */
    static void getAtividade(Codigo codigo, Atividade* atividade) {
        *atividade = ContainerAtividade::pesquisar(codigo);
    }

    /**
     * @brief Atualiza uma atividade existente.
     * @param atividade Atividade com os novos dados.
     */
    static void atualizarAtividade(Atividade atividade) {
        ContainerAtividade::atualizar(atividade);
    }

    /**
     * @brief Exclui uma atividade.
     * @param codigo Código da atividade a ser excluída.
     */
    static void excluirAtividade(Codigo codigo) {
        ContainerAtividade::remover(codigo);
    }

    /**
     * @brief Obtém todas as atividades.
     * @return Lista de todas as atividades.
     */
    static list<Atividade> getAtividades() {
        return ContainerAtividade::getAtividades();
    }

    /**
     * @brief Obtém todas as atividades de um destino.
     * @param codigo Código do destino.
     * @return Lista de atividades do destino.
     */
    static list<Atividade> getAtividadesPorDestino(Codigo codigo) {
        return ContainerAtividade::getAtividadesPorDestino(codigo);
    }
};



#endif // CONTAINERS_H_INCLUDED
