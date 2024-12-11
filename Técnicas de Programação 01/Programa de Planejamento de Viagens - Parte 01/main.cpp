/**
 * @file main.cpp
 * @brief Programa principal para executar os testes unitários.
 */

#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "testes.h"
using namespace std;

int main(){

    TUAvaliacao testeAvaliacao;

    switch (testeAvaliacao.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Avaliacao";
        break;
    case falha:
        cout << "\nFALHA   - Avaliacao";
        break;
    }

    TUCodigo testeCodigo;

    switch (testeCodigo.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Codigo";
        break;
    case falha:
        cout << "\nFALHA   - Codigo";
        break;
    }

    TU_Data testeData;

    switch (testeData.run()) {
    case sucesso:
        cout << "\nSUCESSO - Data";
        break;
    case falha:
        cout << "\nFALHA   - Data";
        break;
    }


    TU_Dinheiro testeDinheiro;

    switch (testeDinheiro.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Dinheiro";
        break;
    case falha:
        cout << "\nFALHA   - Dinheiro";
        break;}


    TUDuracao testeDuracao;

    switch (testeDuracao.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Duracao";
        break;
    case falha:
        cout << "\nFALHA   - Duracao";
        break;
    }


    TUHorario testeHorario;

    switch (testeHorario.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Horario";
        break;
    case falha:
        cout << "\nFALHA   - Horario";
        break;
    }


    TUNome testeNome;

    switch (testeNome.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Nome";
        break;
    case falha:
        cout << "\nFALHA   - Nome";
        break;
    }


    TUSenha testeSenha;

    switch (testeSenha.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Senha";
        break;
    case falha:
        cout << "\nFALHA   - Senha";
        break;
    }

    TUHospedagem testeHospedagem;

    switch (testeHospedagem.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Hospedagem";
        break;
    case falha:
        cout << "\nFALHA   - Hospedagem";
        break;
    }

    TUViagem testeViagem ;

    switch (testeViagem .run())
    {
    case sucesso:
        cout << "\nSUCESSO - Viagem ";
        break;
    case falha:
        cout << "\nFALHA   - Viagem ";
        break;
    }


    TUDestino testeDestino ;

    switch (testeDestino .run())
    {
    case sucesso:
        cout << "\nSUCESSO - Destino ";
        break;
    case falha:
        cout << "\nFALHA   - Destino ";
        break;
    }

    TUConta testeConta;

    switch (testeConta.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Conta";
        break;
    case falha:
        cout << "\nFALHA   - Conta";
        break;
    }

    TUAtividade testeAtividade;

    switch (testeAtividade.run())
    {
    case sucesso:
        cout << "\nSUCESSO - Atividade";
        break;
    case falha:
        cout << "\nFALHA   - Atividade";
        break;
    }

    return 0;
}
