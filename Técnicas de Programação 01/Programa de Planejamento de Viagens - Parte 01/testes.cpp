/**
 * @file teste.cpp
 * @brief Implementação dos métodos dos testes unitários.
 */

#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "testes.h"

using namespace std;

void TUAvaliacao::setUp()
{
    avaliacao = new Avaliacao();
    estado = sucesso;
}

void TUAvaliacao::tearDown()
{
    delete avaliacao;
}

void TUAvaliacao::testarCenariosSucesso()
{
    try
    {
        avaliacao->setValor(VALORES_VALIDOS);
        if (avaliacao->getValor() != VALORES_VALIDOS)
            estado = falha;
    }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUAvaliacao::testarCenariosFalha()
{
        try{
            estado = falha;
            avaliacao->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (avaliacao->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUAvaliacao::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

// Declara��es dos m�todos do Teste Unit�rio TUCodigo

void TUCodigo::setUp()
{
    codigo = new Codigo();
    estado = sucesso;
}

void TUCodigo::tearDown()
{
    delete codigo;
}

void TUCodigo::testarCenariosSucesso()
{
    try
    {
        codigo->setValor(VALORES_VALIDOS);
        if (codigo->getValor() != VALORES_VALIDOS)
            estado = falha;
    }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUCodigo::testarCenariosFalha()
{
        try
        {
            estado = falha;
            codigo->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (codigo->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUCodigo::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}

// Declara��es dos m�todos do Teste Unit�rio TUData
void TU_Data::testar_cenario_valido(){
    try{
        data.setValor(data_valida);
        if (data.getValor() != data_valida){
            estado = falha;
        }
    }
    catch(invalid_argument){
        estado = falha;
    }
}

void TU_Data::testar_cenario_invalido(){
    try{
        data.setValor(data_invalida);
        estado = falha;
    }
    catch(invalid_argument){
        if (data.getValor() == data_invalida)
            estado = falha;
    }
}

EstadoTeste TU_Data::run(){
    estado = sucesso;
    testar_cenario_valido();
    testar_cenario_invalido();
    return estado;
}


// Declara��es dos m�todos do Teste Unit�rio TUDinheiro
void TU_Dinheiro::testar_cenario_valido(){
    try{
        dinheiro.setValor(valor_valido);
        if (dinheiro.getValor() != valor_valido){
            estado = falha;
        }
    }
    catch(invalid_argument){
        estado = falha;
    }
}

void TU_Dinheiro::testar_cenario_invalido(){
    try{
        dinheiro.setValor(valor_invalido);
        estado = falha;
    }
    catch(invalid_argument){
        if (dinheiro.getValor() == valor_invalido)
            estado = falha;
    }
}

EstadoTeste TU_Dinheiro::run(){
    estado  = sucesso;
    testar_cenario_valido();
    testar_cenario_invalido();
    return estado;
}


// Declara��es dos m�todos do Teste Unit�rio TUDuracao

void TUDuracao::setUp()
{
    duracao = new Duracao();
    estado = sucesso;
}

void TUDuracao::tearDown()
{
    delete duracao;
}

void TUDuracao::testarCenariosSucesso()
{
    try
    {
        duracao->setValor(VALORES_VALIDOS);
        if (duracao->getValor() != VALORES_VALIDOS)
            estado = falha;
    }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUDuracao::testarCenariosFalha()
{
        try
        {
            estado = falha;
            duracao->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (duracao->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUDuracao::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}


// Declara��es dos m�todos do Teste Unit�rio TUHorario
void TUHorario::setUp()
{
    horario = new Horario();
    estado = sucesso;
}

void TUHorario::tearDown()
{
    delete horario;
}

void TUHorario::testarCenariosSucesso()
{
    try
    {
        horario->setValor(VALORES_VALIDOS);
        if (horario->getValor() != VALORES_VALIDOS)
            estado = falha;
    }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUHorario::testarCenariosFalha()
{
        try
        {
            estado = falha;
            horario->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (horario->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUHorario::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}


// Declara��es dos m�todos do Teste Unit�rio TUNome

void TUNome::setUp()
{
    nome = new Nome();
    estado = sucesso;
}

void TUNome::tearDown()
{
    delete nome;
}

void TUNome::testarCenariosSucesso()
{
    try
    {
            nome->setValor(VALORES_VALIDOS);
            if (nome->getValor() != VALORES_VALIDOS)
                estado = falha;
        }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUNome::testarCenariosFalha()
{

        try
        {
            estado = falha;
            nome->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (nome->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUNome::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}


// Declara��es dos m�todos do Teste Unit�rio TUAvaliacao

void TUSenha::setUp()
{
    senha = new Senha();
    estado = sucesso;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::testarCenariosSucesso()
{
    try
    {
            senha->setValor(VALORES_VALIDOS);
            if (senha->getValor() != VALORES_VALIDOS)
                estado = falha;
        }
    catch (invalid_argument &excecao)
    {
        estado = falha;
    }
}

void TUSenha::testarCenariosFalha()
{

        try
        {
            estado = falha;
            senha->setValor(VALORES_INVALIDOS);
        }
        catch (invalid_argument &excecao)
        {
            if (senha->getValor() != VALORES_INVALIDOS)
                estado = sucesso;
        }
}

EstadoTeste TUSenha::run()
{
    setUp();
    testarCenariosSucesso();
    testarCenariosFalha();
    tearDown();
    return estado;
}




// Declara��es dos m�todos do Teste Unit�rio TUHospedagem
void TUHospedagem::testarCenario()
{
        Codigo codigo;
        codigo.setValor(VALORES_VALIDOS_Codigo);
        hospedagem.setCodigoHospedagem(codigo);
        if (hospedagem.getCodigoHospedagem().getValor() != VALORES_VALIDOS_Codigo)
            estado = falha;

        Nome nome;
        nome.setValor(VALORES_VALIDOS_Nome);
        hospedagem.setNomeHospedagem(nome);
        if (hospedagem.getNomeHospedagem().getValor() != VALORES_VALIDOS_Nome)
            estado = falha;


        Dinheiro dinheiro;
        dinheiro.setValor(VALORES_VALIDOS_Dinheiro);
        hospedagem.setDiariaHospedagem(dinheiro);
        if (hospedagem.getDiariaHospedagem().getValor() != VALORES_VALIDOS_Dinheiro)
            estado = falha;

        Avaliacao avaliacao;
        avaliacao.setValor(VALORES_VALIDOS_Avaliacao);
        hospedagem.setAvaliacaoHospedagem(avaliacao);
        if (hospedagem.getAvaliacaoHospedagem().getValor() != VALORES_VALIDOS_Avaliacao)
            estado = falha;

}

EstadoTeste TUHospedagem::run()
{
    estado = sucesso;
    testarCenario();
    return estado;
}

// Declara��es dos m�todos do Teste Unit�rio TUDestino
void TUDestino::testarCenario()
{
        Codigo codigo;
        codigo.setValor(VALORES_VALIDOS_Codigo);
        destino.setCodigo(codigo);
        if (destino.getCodigo().getValor() != VALORES_VALIDOS_Codigo)
            estado = falha;

        Nome nome;
        nome.setValor(VALORES_VALIDOS_Nome);
        destino.setNome(nome);
        if (destino.getNome().getValor() != VALORES_VALIDOS_Nome)
            estado = falha;


        Avaliacao avaliacao;
        avaliacao.setValor(VALORES_VALIDOS_Avaliacao);
        destino.setAvaliacao(avaliacao);
        if (destino.getAvaliacao().getValor() != VALORES_VALIDOS_Avaliacao)
            estado = falha;

        Data data;
        data.setValor(VALORES_VALIDOS_DataI);
        destino.setDataInicio(data);
        if (destino.getDataInicio().getValor() != VALORES_VALIDOS_DataI)
            estado = falha;

        Data data2;
        data2.setValor(VALORES_VALIDOS_DataF);
        destino.setDataTermino(data2);
        if (destino.getDataTermino().getValor() != VALORES_VALIDOS_DataF)
            estado = falha;

}

EstadoTeste TUDestino::run()
{
    estado = sucesso;
    testarCenario();
    return estado;
}

// Declara��es dos m�todos do Teste Unit�rio TUViagem
void TUViagem::testarCenario()
{
        Codigo codigo;
        codigo.setValor(VALORES_VALIDOS_Codigo);
        viagem.setCodigoViagem(codigo);
        if (viagem.getCodigoViagem().getValor() != VALORES_VALIDOS_Codigo)
            estado = falha;

        Nome nome;
        nome.setValor(VALORES_VALIDOS_Nome);
        viagem.setNomeViagem(nome);
        if (viagem.getNomeViagem().getValor() != VALORES_VALIDOS_Nome)
            estado = falha;


        Avaliacao avaliacao;
        avaliacao.setValor(VALORES_VALIDOS_Avaliacao);
        viagem.setAvaliacaoViagem(avaliacao);
        if (viagem.getAvaliacaoViagem().getValor() != VALORES_VALIDOS_Avaliacao)
            estado = falha;

}

EstadoTeste TUViagem::run()
{
    estado = sucesso;
    testarCenario();
    return estado;
}

// declara��es metodos TU conta

void TUConta::setUp()
{
    conta = new Conta();
    estado = sucesso;
}

void TUConta::tearDown()
{
    delete conta;
}

void TUConta::testarCenario(){

    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    conta->setSenha(senha);
    if(conta->getSenha().getValor() != VALOR_VALIDO_SENHA)
        estado = falha;

    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    conta->setCodigo(codigo);
    if(conta->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = falha;
}

EstadoTeste TUConta::run()
{
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

void TUAtividade::setUp() {
    atividade = new Atividade();
    estado = sucesso;
}

void TUAtividade::tearDown() {
    delete atividade;
}

void TUAtividade::testarCenarioSucesso() {
    try {
        Codigo codigo;
        codigo.setValor("ABC123");
        atividade->setCodigo(codigo);
        if (atividade->getCodigo().getValor() != "ABC123")
            estado = falha;

        Nome nome;
        nome.setValor("Passeio");
        atividade->setNome(nome);
        if (atividade->getNome().getValor() != "Passeio")
            estado = falha;

        Data data;
        data.setValor("01-01-24");
        atividade->setData(data);
        if (atividade->getData().getValor() != "01-01-24")
            estado = falha;

        Horario horario;
        horario.setValor("14:30");
        atividade->setHorario(horario);
        if (atividade->getHorario().getValor() != "14:30")
            estado = falha;

        Duracao duracao;
        duracao.setValor(120);
        atividade->setDuracao(duracao);
        if (atividade->getDuracao().getValor() != 120)
            estado = falha;

        Dinheiro dinheiro;
        dinheiro.setValor("150,00");
        atividade->setDinheiro(dinheiro);
        if (atividade->getDinheiro().getValor() != "150,00")
            estado = falha;

        Avaliacao avaliacao;
        avaliacao.setValor("5");
        atividade->setAvaliacao(avaliacao);
        if (atividade->getAvaliacao().getValor() != "5")
            estado = falha;
    }
    catch (invalid_argument &excecao) {
        estado = falha;
    }
}

EstadoTeste TUAtividade::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

