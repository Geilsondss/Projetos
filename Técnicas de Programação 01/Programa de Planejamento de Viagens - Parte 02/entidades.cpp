/**
 * @file entidades.cpp
 * @brief Implementação dos métodos das classes de entidade.
 */

#include "entidades.h"


// Métodos da classe Viagem
void Viagem::setNomeViagem(Nome& nome) {
    this->nomeViagem.setValor(nome.getValor());
}

void Viagem::setCodigoViagem(Codigo& codigo) {
    this->codigoViagem.setValor(codigo.getValor());
}

void Viagem::setAvaliacaoViagem(Avaliacao& avaliacao) {
    this->avaliacaoViagem.setValor(avaliacao.getValor());
}

Nome Viagem::getNomeViagem() const {
    return nomeViagem;
}

Codigo Viagem::getCodigoViagem() const {
    return codigoViagem;
}

Avaliacao Viagem::getAvaliacaoViagem() const {
    return avaliacaoViagem;
}

// Métodos da classe Destino
void Destino::setNome(Nome& nome) {
    this->nome.setValor(nome.getValor());
}

void Destino::setCodigo(Codigo& codigo) {
    this->codigo.setValor(codigo.getValor());
}

void Destino::setAvaliacao(Avaliacao& avaliacao) {
    this->avaliacao.setValor(avaliacao.getValor());
}

void Destino::setDataInicio(Data& dataInicio) {
    this->dataInicio.setValor(dataInicio.getValor());
}

void Destino::setDataTermino(Data& dataTermino) {
    this->dataTermino.setValor(dataTermino.getValor());
}

Nome Destino::getNome() const {
    return nome;
}

Codigo Destino::getCodigo() const {
    return codigo;
}

Avaliacao Destino::getAvaliacao() const {
    return avaliacao;
}

Data Destino::getDataInicio() const {
    return dataInicio;
}

Data Destino::getDataTermino() const {
    return dataTermino;
}
