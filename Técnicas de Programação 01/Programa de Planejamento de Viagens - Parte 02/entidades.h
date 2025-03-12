#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

/**
 * @file entidades.h
 * @brief Declara��o das classes de entidade utilizadas no sistema.
 */

#include <iostream>
#include <vector>
#include "dominios.h"

// Declara��es antecipadas necess�rias para evitar depend�ncia circular
class Viagem;
class Destino;
class Hospedagem;

//Gabriel Pessoa Faustino - 231006121
class Conta{
private:
    Codigo codigo;
    Senha senha;
    vector<Viagem*> viagens; /**< Lista de viagens associadas � conta */


public:
    void setCodigo(Codigo&);
    Codigo getCodigo(){return codigo;}

    void setSenha(Senha&);
    Senha getSenha(){return senha;}

    void setViagem(Viagem* viagem);

    /**
     * @brief Remove uma viagem da lista de viagens da conta.
     *
     * @param codigoViagem C�digo da viagem a ser removida.
     */
    void unsetViagem(const Codigo &codigoViagem);

    /**
     * @brief Obt�m a lista de viagens da conta.
     * @return Vetor de ponteiros para objetos do tipo Viagem.
     */
    vector<Viagem*> getViagens() const;
};




inline void Conta::setCodigo(Codigo& codigo){
    this -> codigo = codigo;}

inline void Conta::setSenha(Senha& senha){
    this -> senha = senha;}

/**
 * @class Hospedagem
 * @brief Representa uma hospedagem em um destino.
 */
class Hospedagem {
private:
    Codigo codigoHospedagem;     /**< C�digo da hospedagem */
    Nome nomeHospedagem;         /**< Nome da hospedagem */
    Dinheiro diariaHospedagem;   /**< Valor da di�ria da hospedagem */
    Avaliacao avaliacaoHospedagem; /**< Avalia��o da hospedagem */

public:
    /**
     * @brief Define o c�digo da hospedagem.
     * @param valor Objeto do tipo Codigo.
     */
    void setCodigoHospedagem(Codigo &valor);

    /**
     * @brief Obt�m o c�digo da hospedagem.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigoHospedagem() const;

    /**
     * @brief Define o nome da hospedagem.
     * @param valor Objeto do tipo Nome.
     */
    void setNomeHospedagem(Nome &valor);

    /**
     * @brief Obt�m o nome da hospedagem.
     * @return Objeto do tipo Nome.
     */
    Nome getNomeHospedagem() const;

    /**
     * @brief Define o valor da di�ria da hospedagem.
     * @param valor Objeto do tipo Dinheiro.
     */
    void setDiariaHospedagem(Dinheiro &valor);

    /**
     * @brief Obt�m o valor da di�ria da hospedagem.
     * @return Objeto do tipo Dinheiro.
     */
    Dinheiro getDiariaHospedagem() const;

    /**
     * @brief Define a avalia��o da hospedagem.
     * @param valor Objeto do tipo Avaliacao.
     */
    void setAvaliacaoHospedagem(Avaliacao &valor);

    /**
     * @brief Obt�m a avalia��o da hospedagem.
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
 * @class Destino
 * @brief Representa um destino de uma viagem.
 *
 * A classe Destino relaciona-se com uma Viagem (1:1) e opcionalmente uma Hospedagem (0..1).
 */
class Destino {
private:
    Codigo codigo;       /**< C�digo do destino */
    Nome nome;           /**< Nome do destino */
    Data dataInicio;     /**< Data de in�cio da estadia no destino */
    Data dataTermino;    /**< Data de t�rmino da estadia no destino */
    Avaliacao avaliacao; /**< Avalia��o do destino */
    Viagem* viagem;      /**< Ponteiro para a viagem propriet�ria do destino */
    Hospedagem* hospedagem; /**< Ponteiro para a hospedagem associada ao destino (opcional) */

public:
    // Construtor padrão
    Destino() : viagem(nullptr), hospedagem(nullptr) {}

    // Destrutor
    ~Destino() {
        delete hospedagem;
    }

    // Construtor de cópia
    Destino(const Destino& other) : 
        codigo(other.codigo),
        nome(other.nome),
        dataInicio(other.dataInicio),
        dataTermino(other.dataTermino),
        avaliacao(other.avaliacao),
        viagem(other.viagem),
        hospedagem(other.hospedagem ? new Hospedagem(*other.hospedagem) : nullptr) {}

    // Operador de atribuição
    Destino& operator=(const Destino& other) {
        if (this != &other) {
            codigo = other.codigo;
            nome = other.nome;
            dataInicio = other.dataInicio;
            dataTermino = other.dataTermino;
            avaliacao = other.avaliacao;
            viagem = other.viagem;
            
            delete hospedagem;
            hospedagem = other.hospedagem ? new Hospedagem(*other.hospedagem) : nullptr;
        }
        return *this;
    }

    /**
     * @brief Define o cdigo do destino.
     * @param codigo Objeto do tipo Codigo.
     */
    void setCodigo(Codigo &codigo);

    /**
     * @brief Obt�m o c�digo do destino.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do destino.
     * @param nome Objeto do tipo Nome.
     */
    void setNome(Nome &nome);

    /**
     * @brief Obt�m o nome do destino.
     * @return Objeto do tipo Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de in�cio.
     * @param dataInicio Objeto do tipo Data.
     */
    void setDataInicio(Data &dataInicio);

    /**
     * @brief Obt�m a data de in�cio.
     * @return Objeto do tipo Data.
     */
    Data getDataInicio() const;

    /**
     * @brief Define a data de t�rmino.
     * @param dataTermino Objeto do tipo Data.
     */
    void setDataTermino(Data &dataTermino);

    /**
     * @brief Obt�m a data de t�rmino.
     * @return Objeto do tipo Data.
     */
    Data getDataTermino() const;

    /**
     * @brief Define a avalia��o do destino.
     * @param avaliacao Objeto do tipo Avaliacao.
     */
    void setAvaliacao(Avaliacao &avaliacao);

    /**
     * @brief Obt�m a avalia��o do destino.
     * @return Objeto do tipo Avaliacao.
     */
    Avaliacao getAvaliacao() const;

    /**
     * @brief Associa o destino a uma viagem.
     * @param viagem Ponteiro para o objeto Viagem.
     */
    void setViagem(Viagem* viagem);

    /**
     * @brief Obt�m a viagem associada ao destino.
     * @return Ponteiro para o objeto Viagem.
     */
    Viagem* getViagem() const;

    /**
     * @brief Associa uma hospedagem ao destino.
     * @param hospedagem Ponteiro para o objeto Hospedagem.
     */
    void setHospedagem(Hospedagem* hospedagem) {
        delete this->hospedagem;  // Deleta a hospedagem anterior se existir
        this->hospedagem = hospedagem;
    }

    /**
     * @brief Obtm a hospedagem associada ao destino.
     * @return Ponteiro para o objeto Hospedagem ou nullptr se no houver.
     */
    Hospedagem* getHospedagem() const {
        return hospedagem;
    }
};

/**
 * @class Viagem
 * @brief Representa uma viagem de uma conta.
 *
 * A classe Viagem relaciona-se com um objeto Conta (1:1) e v�rios Destinos (1:N).
 */
class Viagem {
private:
    Codigo codigoViagem;    /**< C�digo da viagem */
    Nome nomeViagem;        /**< Nome da viagem */
    Avaliacao avaliacaoViagem; /**< Avalia��o da viagem */
    Conta* conta;           /**< Ponteiro para a conta propriet�ria da viagem */
    vector<Destino*> destinos; /**< Lista de destinos associados � viagem */

public:
    /**
     * @brief Define o c�digo da viagem.
     * @param codigo Objeto do tipo Codigo representando o c�digo da viagem.
     */
    void setCodigoViagem(Codigo &codigo);

    /**
     * @brief Obt�m o c�digo da viagem.
     * @return Objeto do tipo Codigo.
     */
    Codigo getCodigoViagem() const;

    /**
     * @brief Define o nome da viagem.
     * @param nome Objeto do tipo Nome representando o nome da viagem.
     */
    void setNomeViagem(Nome &nome);

    /**
     * @brief Obt�m o nome da viagem.
     * @return Objeto do tipo Nome.
     */
    Nome getNomeViagem() const;

    /**
     * @brief Define a avalia��o da viagem.
     * @param avaliacao Objeto do tipo Avaliacao representando a avalia��o da viagem.
     */
    void setAvaliacaoViagem(Avaliacao &avaliacao);

    /**
     * @brief Obt�m a avalia��o da viagem.
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
     * @brief Obt�m a conta associada � viagem.
     * @return Ponteiro para o objeto Conta associado.
     */
    Conta* getConta() const;

    /**
     * @brief Adiciona um destino � lista de destinos da viagem.
     *
     * Tamb�m estabelece a rela��o do destino com esta viagem.
     * @param destino Ponteiro para o objeto Destino a ser adicionado.
     */
    void setDestino(Destino* destino);

    /**
     * @brief Remove um destino da lista de destinos da viagem.
     *
     * @param codigoDestino C�digo do destino a ser removido.
     */
    void unsetDestino(const Codigo &codigoDestino);

    /**
     * @brief Obt�m a lista de destinos da viagem.
     * @return Vetor de ponteiros para objetos do tipo Destino.
     */
    vector<Destino*> getDestinos() const;
};

/**
 * @class Atividade
 * @brief Representa uma atividade em um determinado destino.
 */
class Atividade {
private:
    Codigo codigo;    /**< C�digo da atividade */
    Nome nome;        /**< Nome da atividade */
    Data data;        /**< Data da atividade */
    Horario horario;  /**< Hor�rio da atividade */
    Duracao duracao;  /**< Dura��o da atividade */
    Dinheiro dinheiro;/**< Custo da atividade */
    Avaliacao avaliacao; /**< Avalia��o da atividade */

public:
    /**
     * @brief Define o c�digo da atividade.
     * @param codigo Objeto do tipo Codigo.
     */
    inline void setCodigo(const Codigo& codigo) {
        this->codigo.setValor(codigo.getValor());
    }

    /**
     * @brief Obt�m o c�digo da atividade.
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
     * @brief Obt�m o nome da atividade.
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
     * @brief Obt�m a data da atividade.
     * @return Objeto do tipo Data.
     */
    inline Data getData() const {
        return data;
    }

    /**
     * @brief Define o hor�rio da atividade.
     * @param horario Objeto do tipo Horario.
     */
    inline void setHorario(const Horario& horario) {
        this->horario = horario;
    }

    /**
     * @brief Obt�m o hor�rio da atividade.
     * @return Objeto do tipo Horario.
     */
    inline Horario getHorario() const {
        return horario;
    }

    /**
     * @brief Define a dura��o da atividade.
     * @param duracao Objeto do tipo Duracao.
     */
    inline void setDuracao(Duracao &duracao) {
        this->duracao.setValor(duracao.getValor());
    }

    /**
     * @brief Obt�m a dura��o da atividade.
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
     * @brief Obt�m o custo da atividade.
     * @return Objeto do tipo Dinheiro.
     */
    inline Dinheiro getDinheiro() const {
        return dinheiro;
    }

    /**
     * @brief Define a avalia��o da atividade.
     * @param avaliacao Objeto do tipo Avaliacao.
     */
    inline void setAvaliacao(const Avaliacao& avaliacao) {
        this->avaliacao = avaliacao;
    }

    /**
     * @brief Obt�m a avalia��o da atividade.
     * @return Objeto do tipo Avaliacao.
     */
    inline Avaliacao getAvaliacao() const {
        return avaliacao;
    }
};

// M�todos de relacionamento da classe Conta
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

// M�todos de relacionamento da classe Viagem
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

// M�todos de relacionamento da classe Destino
inline void Destino::setViagem(Viagem* viagem) {
    this->viagem = viagem;
}

inline Viagem* Destino::getViagem() const {
    return viagem;
}



#endif // ENTIDADES_H_INCLUDED
