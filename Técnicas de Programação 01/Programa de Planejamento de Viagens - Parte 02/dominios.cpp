/**
 * @file dominios.cpp
 * @brief Implementação dos métodos das classes de domínio.
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <string>
#include <typeinfo>
#include <iomanip>
#include "dominios.h"
using namespace std;

void Avaliacao::setValor(string val){
    validar(val);
    this->valor = val;}

void Avaliacao::validar(string valor){

        //Verificacao do tamanho.
        if(valor.length() != 1){
            throw invalid_argument("Tamanho incorreto.");
            }

        //Verfica se o formato esta correto
        //Usei o metodo isdigit() que verifica se o caracter eh um digito alphanumerico
        if(!isdigit(valor[0])){
            throw invalid_argument("Formato incorreto.");}

        //Mudando uma varivel de tipo string para int
        //para futuramente verificar se eh valido
        int avali = stoi(valor);

        //Verifica se a avaliacao eh valida
        if (avali > 5 || avali < 0){
            throw invalid_argument("O digito da avaliacao deve ser entre 0 a 5.");}

}


void Codigo::validar(string cod){
    if(cod.length() != TAMANHO){
        throw invalid_argument("O codigo deve conter exatos 6 caracteres");
    }
    for(int i = 0; i < 6 ; i++) {
        if( !isalpha(cod[i]) && !isdigit(cod[i]) ){ // se o caracter não for nem alfabeticou nem numerico ele não é aceito
                throw invalid_argument("O codigo deve conter apenas caracteres alfanumericos");
        }
    }
}

void Codigo::setValor(string val){
    validar(val);
    this->valor = val;
}


void Data::validar(string data){

    //Primeiro verifica que tem o tamanho certo
    if (data.length() != 8){

        throw invalid_argument("Tamanho invalido");
    }

    //Em seguida verfica se o formato esta correto
    if (data[2] != '-' || data[5] != '-'){

        throw invalid_argument("Formato invalido");
    }

    //Por algum motivo o operador += nao estava funcionando, entao usei o pushback para separar
    //o dia, o mes e o ano
    string dia_str, mes_str, ano_str;
    dia_str.push_back(data[0]);
    dia_str.push_back(data[1]);
    mes_str.push_back(data[3]);
    mes_str.push_back(data[4]);
    ano_str. push_back(data[6]);
    ano_str. push_back(data[7]);

    int dia = stoi(dia_str);
    int mes = stoi(mes_str);
    int ano = stoi(ano_str);

    //Verifica se o dia eh valido
    if (dia > 31 || dia < 0){

        throw invalid_argument("Dia invalido");
    }

    //Verifica se o mes eh valido
    if (mes > 12 || mes < 1){

        throw invalid_argument("Mes invalido");
    }

    //Verifica se o ano eh valido
    if (ano > 99 || ano < 00){

        throw invalid_argument("Ano invalido");
    }

    //Verifica se eh um dos meses que tem 30 dias
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){

            if (dia == 31){

                throw invalid_argument("Este mes so tem 30 dias");
            }
    }

    //Verifica se eh fevereiro
    if (mes == 2){

        //Verifica se o ano eh bissexto
        if (( ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 ){

            //Se o ano eh bissexto, fevereiro possui 29 dias
            if (dia != 29){

                throw invalid_argument("Neste ano este mes tem 29 dias");
            }
        }

        //Se o ano nao eh bissexto, entao fevereiro possui 28 dias
        else if (dia != 28){

            throw invalid_argument("Neste ano este mes tem 28 dias");
        }
    }
}

void Data::setValor(string data) {
    validar(data);
    this->valor = data;
}

void Dinheiro::setValor(string valor_str){

        validar(valor_str);
        this->valor = valor_str;

}

void Dinheiro::validar(string valor_str){

    //Esse loop retira os pontos e muda a separação decimal de virgula para ponto
    std::string novo_valor;
    for (int i = 0; i < valor_str.length(); i++){

        if (valor_str[i] != '.' && valor_str[i] != ','){

            novo_valor += valor_str[i];
        }

        if (valor_str[i] == ','){

            novo_valor += '.';

        }
    }

    //Verifica se os centavos estao no formato correto (duas casas decimais)
    bool cont_centavos = false;
    string centavos;
    for (int i = 0; i < novo_valor.length(); i++){
        if (novo_valor[i] == '.'){
            cont_centavos = true;
        }
        else if (cont_centavos){
            centavos.push_back(novo_valor[i]);
        }
    }

    if (centavos.length() != 2){

        throw invalid_argument("Centavos no formato incorreto");

    }

    double valor_double = std::stod(novo_valor); //Transforma o numero de string para double e lanca excecao caso nao seja um numero
    if (valor_double > LIMITE_MAX){

        throw invalid_argument("Valor acima do limite maximo.");

    }
    if (valor_double < LIMITE_MIN){

        throw invalid_argument("Valor abaixo do limite minimo.");

    }

}

void Duracao::validar(int val) {
    if (val < MINIMO || val > MAXIMO)
        throw invalid_argument("O valor da duracao deve ser de 0 e 360.");
}

void Duracao::setValor(int val){
    validar(val);
    this->valor = val;
}


void Horario::validar(string valor){

    //Primeiro verifica se o tamanho esta correto
    if (valor.length() != 5){
        throw invalid_argument("Tamanho incorreto.");}


    //Logo apos verfica se o formato esta correto
    //Usei o metodo isdigit() que verifica de o caracter eh um digito alphanumerico
    if (!isdigit( valor[0]) || !isdigit( valor[1]) || valor[2] != ':' || !isdigit( valor[3]) || !isdigit( valor[4])){
        throw invalid_argument("Formato incorreto.");}

    //Usei o metodo pushback para separar
    //as horas e os minutos
    string horas_str, minutos_str;
    horas_str.push_back(valor[0]);
    horas_str.push_back(valor[1]);
    minutos_str.push_back(valor[3]);
    minutos_str.push_back(valor[4]);

    //Mudando uma varivel de tipo string para int
    //para futuramente verificar se eh valido
    int horas = stoi(horas_str);
    int minutos = stoi(minutos_str);

    //Verifica se o horas eh valido
    if (horas > 23 || horas < 0){
        throw invalid_argument("O digito das horas deve ser entre 00 a 23.");}


    //Verifica se o minutos eh valido
    if (minutos > 59 || minutos < 0){
        throw invalid_argument("O digito das minutos deve ser entre 00 a 59.");}

}

void Horario::setValor(string valor){

    //verifica se eh valido e atribui o valor a class
    validar(valor);
    this->valor = valor;}


void Nome::validar(string val) {
    if (val.length() > VALOR_MAXIMO)
        throw invalid_argument("O nome deve conter menos que 30 caracteres.");
}

void Nome::setValor(string val){
    validar(val);
    this->valor = val;
}



void Senha::validar(string valor){
        int i,j, repeti;
        int adicao, subtra;
        string decrescente, crescente;

        //Verificacao do tamanho da senha.
        if(valor.length() != 5){
                throw invalid_argument("Tamanho de senha incorreto.");}


         //Verificacao se todos os dígitos são números.
        for(int i = 0; i < valor.length(); i++){
            if(!isdigit(valor[i])){
                throw invalid_argument("Senha com caracteres invalidos.");}
        }



        //Verificacao da sequencia.
        adicao = (valor[0] - '0'); //adicao sera o numero base para calcular a sequência crescente.
        subtra = (valor[0] - '0'); //subtra sera o numero base para calcular a sequência decrescente.
        for(int i = 0; i < 5; i++){
            crescente += to_string(adicao); //forma a sequência crescente pelo adição de mais 1 no numero base
            adicao += 1;
            decrescente += to_string(subtra); //forma a sequência decrescente pelo  subtração de menos 1 no numero base
            subtra -= 1;
        }

        if(valor == crescente || valor == decrescente){
            throw invalid_argument("Senha em sequencia invalida");}


        //Verificacao se hã repetição de digitos.
        for(i = 0; i<5; i++){
            repeti = 0;
            for(j=0; j<5; j++){
                if(valor[i] == valor[j]){
                    repeti += 1;}

                if (repeti > 1){
                    throw invalid_argument("Senha com caracteres repetidos.");}

            }
        }
    }

void Senha::setValor(string val){
    validar(val);
    this->valor = val;
}


