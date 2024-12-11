/**
 * @file entidades.h
 * @brief Declaração das classes de entidade utilizadas no sistema.
 */

#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <iostream>
#include <vector>
#include "dominios.h"

// Declarações antecipadas necessárias para evitar dependência circular
class Viagem;
class Destino;
class Hospedagem;

/**
 * @class Conta
 * @brief Representa uma conta de usuário no sistema.
 *
 * A classe Conta relaciona-se com diversas Viagens (1:N).
 */
class Conta {
private:
    Codigo codigo; /**< Código da conta */
    Senha senha;   /**< Senha da conta */
    vector<Viagem*> viagens; /**< Lista de viagens associadas à conta */

public:
    /**
     * @brief Define o código da conta.
     * @param codigo Objeto do tipo Codigo representando o código da conta.
     */
    void setCodigo(Codigo &codigo);

    /**
     * @brief Obtém o código da conta.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define a senha da conta.
     * @param senha Objeto do tipo Senha representando a senha da conta.
     */
    void setSenha(Senha &senha);

    /**
     * @brief Obtém a senha da conta.
     * @return Objeto do tipo Senha.
     */
    Senha getSenha() const;

    /**
     * @brief Adiciona uma viagem à lista de viagens da conta.
     *
     * Também estabelece a relação da viagem com esta conta.
     * @param viagem Ponteiro para o objeto Viagem a ser adicionado.
     */
    void setViagem(Viagem* viagem);

    /**
     * @brief Remove uma viagem da lista de viagens da conta.
     *
     * @param codigoViagem Código da viagem a ser removida.
     */
    void unsetViagem(const Codigo &codigoViagem);

    /**
     * @brief Obtém a lista de viagens da conta.
     * @return Vetor de ponteiros para objetos do tipo Viagem.
     */
    vector<Viagem*> getViagens() const;
};

/**
 * @class Viagem
 * @brief Representa uma viagem de uma conta.
 *
 * A classe Viagem relaciona-se com um objeto Conta (1:1) e vários Destinos (1:N).
 */
class Viagem {
private:
    Codigo codigoViagem;    /**< Código da viagem */
    Nome nomeViagem;        /**< Nome da viagem */
    Avaliacao avaliacaoViagem; /**< Avaliação da viagem */
    Conta* conta;           /**< Ponteiro para a conta proprietária da viagem */
    vector<Destino*> destinos; /**< Lista de destinos associados à viagem */

public:
    /**
     * @brief Define o código da viagem.
     * @param codigo Objeto do tipo Codigo representando o código da viagem.
     */
    void setCodigoViagem(Codigo &codigo);

    /**
     * @brief Obtém o código da viagem.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigoViagem() const;

    /**
     * @brief Define o nome da viagem.
     * @param nome Objeto do tipo Nome representando o nome da viagem.
     */
    void setNomeViagem(Nome &nome);

    /**
     * @brief Obtém o nome da viagem.
     * @return Objeto do tipo Nome.
     */
    Nome getNomeViagem() const;

    /**
     * @brief Define a avaliação da viagem.
     * @param avaliacao Objeto do tipo Avaliacao representando a avaliação da viagem.
     */
    void setAvaliacaoViagem(Avaliacao &avaliacao);

    /**
     * @brief Obtém a avaliação da viagem.
     * @return Objeto do tipo Avaliacao.
     */
    Avaliacao getAvaliacaoViagem() const;

    /**
     * @brief Associa a viagem a uma conta.
     *
     * @param conta Ponteiro para a conta a ser associada.
     */
    void setConta(Conta* conta);

    /**
     * @brief Obtém a conta associada à viagem.
     * @return Ponteiro para o objeto Conta associado.
     */
    Conta* getConta() const;

    /**
     * @brief Adiciona um destino à lista de destinos da viagem.
     *
     * Também estabelece a relação do destino com esta viagem.
     * @param destino Ponteiro para o objeto Destino a ser adicionado.
     */
    void setDestino(Destino* destino);

    /**
     * @brief Remove um destino da lista de destinos da viagem.
     *
     * @param codigoDestino Código do destino a ser removido.
     */
    void unsetDestino(const Codigo &codigoDestino);

    /**
     * @brief Obtém a lista de destinos da viagem.
     * @return Vetor de ponteiros para objetos do tipo Destino.
     */
    vector<Destino*> getDestinos() const;
};

/**
 * @class Destino
 * @brief Representa um destino de uma viagem.
 *
 * A classe Destino relaciona-se com uma Viagem (1:1) e opcionalmente uma Hospedagem (0..1).
 */
class Destino {
private:
    Codigo codigo;       /**< Código do destino */
    Nome nome;           /**< Nome do destino */
    Data dataInicio;     /**< Data de início da estadia no destino */
    Data dataTermino;    /**< Data de término da estadia no destino */
    Avaliacao avaliacao; /**< Avaliação do destino */
    Viagem* viagem;      /**< Ponteiro para a viagem proprietária do destino */
    Hospedagem* hospedagem; /**< Ponteiro para a hospedagem associada ao destino (opcional) */

public:
    /**
     * @brief Define o código do destino.
     * @param codigo Objeto do tipo Codigo.
     */
    void setCodigo(Codigo &codigo);

    /**
     * @brief Obtém o código do destino.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do destino.
     * @param nome Objeto do tipo Nome.
     */
    void setNome(Nome &nome);

    /**
     * @brief Obtém o nome do destino.
     * @return Objeto do tipo Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de início.
     * @param dataInicio Objeto do tipo Data.
     */
    void setDataInicio(Data &dataInicio);

    /**
     * @brief Obtém a data de início.
     * @return Objeto do tipo Data.
     */
    Data getDataInicio() const;

    /**
     * @brief Define a data de término.
     * @param dataTermino Objeto do tipo Data.
     */
    void setDataTermino(Data &dataTermino);

    /**
     * @brief Obtém a data de término.
     * @return Objeto do tipo Data.
     */
    Data getDataTermino() const;

    /**
     * @brief Define a avaliação do destino.
     * @param avaliacao Objeto do tipo Avaliacao.
     */
    void setAvaliacao(Avaliacao &avaliacao);

    /**
     * @brief Obtém a avaliação do destino.
     * @return Objeto do tipo Avaliacao.
     */
    Avaliacao getAvaliacao() const;

    /**
     * @brief Associa o destino a uma viagem.
     * @param viagem Ponteiro para o objeto Viagem.
     */
    void setViagem(Viagem* viagem);

    /**
     * @brief Obtém a viagem associada ao destino.
     * @return Ponteiro para o objeto Viagem.
     */
    Viagem* getViagem() const;

    /**
     * @brief Associa uma hospedagem ao destino.
     * @param hospedagem Ponteiro para o objeto Hospedagem.
     */
    void setHospedagem(Hospedagem* hospedagem);

    /**
     * @brief Obtém a hospedagem associada ao destino.
     * @return Ponteiro para o objeto Hospedagem ou nullptr se não houver.
     */
    Hospedagem* getHospedagem() const;
};

/**
 * @class Hospedagem
 * @brief Representa uma hospedagem em um destino.
 */
class Hospedagem {
private:
    Codigo codigoHospedagem;     /**< Código da hospedagem */
    Nome nomeHospedagem;         /**< Nome da hospedagem */
    Dinheiro diariaHospedagem;   /**< Valor da diária da hospedagem */
    Avaliacao avaliacaoHospedagem; /**< Avaliação da hospedagem */

public:
    /**
     * @brief Define o código da hospedagem.
     * @param valor Objeto do tipo Codigo.
     */
    void setCodigoHospedagem(Codigo &valor);

    /**
     * @brief Obtém o código da hospedagem.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigoHospedagem() const;

    /**
     * @brief Define o nome da hospedagem.
     * @param valor Objeto do tipo Nome.
     */
    void setNomeHospedagem(Nome &valor);

    /**
     * @brief Obtém o nome da hospedagem.
     * @return Objeto do tipo Nome.
     */
    Nome getNomeHospedagem() const;

    /**
     * @brief Define o valor da diária da hospedagem.
     * @param valor Objeto do tipo Dinheiro.
     */
    void setDiariaHospedagem(Dinheiro &valor);

    /**
     * @brief Obtém o valor da diária da hospedagem.
     * @return Objeto do tipo Dinheiro.
     */
    Dinheiro getDiariaHospedagem() const;

    /**
     * @brief Define a avaliação da hospedagem.
     * @param valor Objeto do tipo Avaliacao.
     */
    void setAvaliacaoHospedagem(Avaliacao &valor);

    /**
     * @brief Obtém a avaliação da hospedagem.
     * @return Objeto do tipo Avaliacao.
     */
    Avaliacao getAvaliacaoHospedagem() const;
};

inline void Hospedagem::setCodigoHospedagem(Codigo &valor) {
    this->codigoHospedagem.setValor(valor.getValor());
}

inline Codigo Hospedagem::getCodigoHospedagem() const {
    return codigoHospedagem;
}

inline void Hospedagem::setNomeHospedagem(Nome &valor) {
    this->nomeHospedagem.setValor(valor.getValor());
}

inline Nome Hospedagem::getNomeHospedagem() const {
    return nomeHospedagem;
}

inline void Hospedagem::setDiariaHospedagem(Dinheiro &valor) {
    this->diariaHospedagem.setValor(valor.getValor());
}

inline Dinheiro Hospedagem::getDiariaHospedagem() const {
    return diariaHospedagem;
}

inline void Hospedagem::setAvaliacaoHospedagem(Avaliacao &valor) {
    this->avaliacaoHospedagem = valor;
}

inline Avaliacao Hospedagem::getAvaliacaoHospedagem() const {
    return avaliacaoHospedagem;
}

/**
 * @class Atividade
 * @brief Representa uma atividade em um determinado destino.
 */
class Atividade {
private:
    Codigo codigo;    /**< Código da atividade */
    Nome nome;        /**< Nome da atividade */
    Data data;        /**< Data da atividade */
    Horario horario;  /**< Horário da atividade */
    Duracao duracao;  /**< Duração da atividade */
    Dinheiro dinheiro;/**< Custo da atividade */
    Avaliacao avaliacao; /**< Avaliação da atividade */

public:
    /**
     * @brief Define o código da atividade.
     * @param codigo Objeto do tipo Codigo.
     */
    inline void setCodigo(const Codigo& codigo) {
        this->codigo.setValor(codigo.getValor());
    }

    /**
     * @brief Obtém o código da atividade.
     * @return Objeto do tipo Codigo.
     */
    inline Codigo getCodigo() const {
        return codigo;
    }

    /**
     * @brief Define o nome da atividade.
     * @param nome Objeto do tipo Nome.
     */
    inline void setNome(const Nome& nome) {
        this->nome.setValor(nome.getValor());
    }

    /**
     * @brief Obtém o nome da atividade.
     * @return Objeto do tipo Nome.
     */
    inline Nome getNome() const {
        return nome;
    }

    /**
     * @brief Define a data da atividade.
     * @param data Objeto do tipo Data.
     */
    inline void setData(const Data& data) {
        this->data = data;
    }

    /**
     * @brief Obtém a data da atividade.
     * @return Objeto do tipo Data.
     */
    inline Data getData() const {
        return data;
    }

    /**
     * @brief Define o horário da atividade.
     * @param horario Objeto do tipo Horario.
     */
    inline void setHorario(const Horario& horario) {
        this->horario = horario;
    }

    /**
     * @brief Obtém o horário da atividade.
     * @return Objeto do tipo Horario.
     */
    inline Horario getHorario() const {
        return horario;
    }

    /**
     * @brief Define a duração da atividade.
     * @param duracao Objeto do tipo Duracao.
     */
    inline void setDuracao(Duracao &duracao) {
        this->duracao.setValor(duracao.getValor());
    }

    /**
     * @brief Obtém a duração da atividade.
     * @return Objeto do tipo Duracao.
     */
    inline Duracao getDuracao() const {
        Duracao temp;
        temp.setValor(this->duracao.getValor());
        return temp;
    }

    /**
     * @brief Define o custo da atividade.
     * @param dinheiro Objeto do tipo Dinheiro.
     */
    inline void setDinheiro(const Dinheiro& dinheiro) {
        this->dinheiro.setValor(dinheiro.getValor());
    }

    /**
     * @brief Obtém o custo da atividade.
     * @return Objeto do tipo Dinheiro.
     */
    inline Dinheiro getDinheiro() const {
        return dinheiro;
    }

    /**
     * @brief Define a avaliação da atividade.
     * @param avaliacao Objeto do tipo Avaliacao.
     */
    inline void setAvaliacao(const Avaliacao& avaliacao) {
        this->avaliacao = avaliacao;
    }

    /**
     * @brief Obtém a avaliação da atividade.
     * @return Objeto do tipo Avaliacao.
     */
    inline Avaliacao getAvaliacao() const {
        return avaliacao;
    }
};

// Métodos de relacionamento da classe Conta
inline void Conta::setViagem(Viagem* viagem) {
    viagens.push_back(viagem);
    viagem->setConta(this);
}

inline void Conta::unsetViagem(const Codigo& codigoViagem) {
    for (auto it = viagens.begin(); it != viagens.end(); ++it) {
        if ((*it)->getCodigoViagem().getValor().compare(codigoViagem.getValor()) == 0) {
            (*it)->setConta(nullptr);
            viagens.erase(it);
            break;
        }
    }
}

inline vector<Viagem*> Conta::getViagens() const {
    return viagens;
}

// Métodos de relacionamento da classe Viagem
inline void Viagem::setConta(Conta* conta) {
    this->conta = conta;
}

inline Conta* Viagem::getConta() const {
    return conta;
}

inline void Viagem::setDestino(Destino* destino) {
    destinos.push_back(destino);
    destino->setViagem(this);
}

inline void Viagem::unsetDestino(const Codigo& codigoDestino) {
    for (auto it = destinos.begin(); it != destinos.end(); ++it) {
        if ((*it)->getCodigo().getValor().compare(codigoDestino.getValor()) == 0) {
            (*it)->setViagem(nullptr);
            destinos.erase(it);
            break;
        }
    }
}

inline vector<Destino*> Viagem::getDestinos() const {
    return destinos;
}

// Métodos de relacionamento da classe Destino
inline void Destino::setViagem(Viagem* viagem) {
    this->viagem = viagem;
}

inline Viagem* Destino::getViagem() const {
    return viagem;
}

inline void Destino::setHospedagem(Hospedagem* hospedagem) {
    this->hospedagem = hospedagem;
}

inline Hospedagem* Destino::getHospedagem() const {
    return hospedagem;
}

#endif // ENTIDADES_H_INCLUDED
