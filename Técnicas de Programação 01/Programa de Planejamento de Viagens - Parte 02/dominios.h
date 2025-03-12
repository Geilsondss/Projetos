#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

/**
 * @file dominios.h
 * @brief Declaração das classes de domínio utilizadas no sistema.
 */

#include <iostream>
using namespace std;

/**
 * @class Avaliacao
 * @brief Classe responsável pelo domínio Avaliacao.
 *
 * A classe Avaliacao representa uma avaliação numérica entre 0 e 5.
 * O valor armazenado é uma string, porém o valor válido é garantido
 * pelo método validar().
 */
class Avaliacao{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena a avaliação. */

public:

    /**
     * @brief Retorna o valor da avaliação.
     * @return string com o valor da avaliação.
     */
    string getValor() const;

    /**
     * @brief Define o valor da avaliação.
     *
     * @param val Valor a ser definido.
     * @throws invalid_argument se o valor não for uma avaliação válida (entre 0 e 5).
     */
    void setValor(string val);

    /**
     * @brief Valida o valor da avaliação.
     *
     * Verifica se o valor passado é um dígito entre 0 e 5.
     * @param valor String representando o valor a ser validado.
     * @throws invalid_argument se o valor não for válido.
     */
    void validar(string valor);

};

inline string Avaliacao::getValor() const
{
    return valor;
}

/**
 * @class Codigo
 * @brief Classe responsável pelo domínio Codigo.
 *
 * A classe Codigo representa um código alfanumérico de 6 caracteres.
 * O valor armazenado é garantido pelo método validar().
 */
class Codigo{ // Tau Frade - 231021389
private:
    int TAMANHO = 6; /**< Tamanho fixo do código. */
    string valor; /**< Armazena o código. */

    /**
     * @brief Valida o valor do código.
     *
     * Verifica se o código possui 6 caracteres alfanuméricos.
     * @param cod String com o código a ser validado.
     * @throws invalid_argument se o código não tiver o tamanho correto ou contiver caracteres inválidos.
     */
    void validar(string cod);

public:
    /**
     * @brief Define o valor do código.
     *
     * @param val String com o código.
     * @throws invalid_argument se o valor não for um código válido.
     */
    void setValor(string val);

    /**
     * @brief Retorna o valor do código.
     * @return string com o código.
     */
    string getValor() const;
};

inline string Codigo::getValor() const
{
    return valor;
}

/**
 * @class Data
 * @brief Classe responsável pelo domínio Data.
 *
 * A classe Data representa uma data no formato DD-MM-AA.
 */
class Data{//ARTHUS CESAR DIAS FERNANDES - 231006103
private:
    string valor; /**< Armazena a data no formato DD-MM-AA. */

public:
    /**
     * @brief Retorna o valor da data.
     * @return string com a data.
     */
    string getValor() const;

    /**
     * @brief Define o valor da data.
     *
     * @param data Data no formato DD-MM-AA.
     * @throws invalid_argument se a data não for válida.
     */
    void setValor(string data);

    /**
     * @brief Valida o valor da data.
     *
     * Verifica se a data está no formato correto e se é válida (dia, mês, ano).
     * @param data String com a data a ser validada.
     * @throws invalid_argument se a data for inválida.
     */
    void validar(string data);
};

inline string Data::getValor() const
{
    return valor;
}

/**
 * @class Dinheiro
 * @brief Classe responsável pelo domínio Dinheiro.
 *
 * Representa um valor monetário entre 0 e 200000.00, com duas casas decimais.
 */
class Dinheiro{// Richard Otto - 231006186

private:
    string valor; /**< Armazena o valor monetário. */
    double LIMITE_MAX = 200000.00; /**< Limite máximo do valor. */
    double LIMITE_MIN = 0;         /**< Limite mínimo do valor. */

public:
    /**
     * @brief Retorna o valor do dinheiro.
     * @return string com o valor monetário.
     */
    string getValor() const;

    /**
     * @brief Define o valor do dinheiro.
     *
     * @param valor_str String representando o valor monetário.
     * @throws invalid_argument se o valor não for válido.
     */
    void setValor(string valor_str);

    /**
     * @brief Valida o valor do dinheiro.
     *
     * Verifica formato, limites e presença de duas casas decimais.
     * @param valor_str String com o valor a ser validado.
     * @throws invalid_argument se o valor for inválido.
     */
    void validar(string valor_str);

};

inline string Dinheiro::getValor() const
{
    return valor;
}

/**
 * @class Duracao
 * @brief Classe responsável pelo domínio Duracao.
 *
 * Representa uma duração inteira em minutos, entre 0 e 360.
 */
class Duracao{// Richard Otto - 231006186
private:
    int MINIMO = 0;   /**< Valor mínimo da duração. */
    int MAXIMO = 360; /**< Valor máximo da duração. */

    int valor; /**< Armazena a duração em minutos. */

    /**
     * @brief Valida a duração.
     *
     * Verifica se o valor está entre 0 e 360.
     * @param val Duração em minutos.
     * @throws invalid_argument se o valor não estiver dentro do intervalo.
     */
    void validar(int val);

public:
    /**
     * @brief Define o valor da duração.
     *
     * @param val Inteiro com a duração (em minutos).
     * @throws invalid_argument se a duração for inválida.
     */
    void setValor(int val);

    /**
     * @brief Retorna a duração.
     * @return int com a duração em minutos.
     */
    int getValor() const;
};

inline int Duracao::getValor() const
{
    return valor;
}

/**
 * @class Horario
 * @brief Classe responsável pelo domínio Horario.
 *
 * Representa um horário no formato HH:MM.
 */
class Horario{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena o horário no formato HH:MM. */

    /**
     * @brief Valida o horário.
     *
     * Verifica se o horário está no formato HH:MM e se é válido (00 <= HH <= 23, 00 <= MM <= 59).
     * @param valor String com o horário.
     * @throws invalid_argument se o horário for inválido.
     */
    void validar(string valor);

public:
    /**
     * @brief Retorna o valor do horário.
     * @return string com o horário.
     */
    string getValor() const;

    /**
     * @brief Define o valor do horário.
     *
     * @param valor Horário no formato HH:MM.
     * @throws invalid_argument se o horário for inválido.
     */
    void setValor(string valor);

};
inline string Horario::getValor() const
{
    return valor;
}

/**
 * @class Nome
 * @brief Classe responsável pelo domínio Nome.
 *
 * Representa um nome com no máximo 30 caracteres.
 */
class Nome{ // Michele Nakagomi - 232029078
private:
    int VALOR_MAXIMO = 30; /**< Tamanho máximo do nome. */

    string valor; /**< Armazena o nome. */

    /**
     * @brief Valida o nome.
     *
     * Verifica se o nome não ultrapassa 30 caracteres.
     * @param val String com o nome.
     * @throws invalid_argument se o nome for muito longo.
     */
    void validar(string val);

public:
    /**
     * @brief Define o valor do nome.
     *
     * @param val String com o nome.
     * @throws invalid_argument se o nome for inválido.
     */
    void setValor(string val);

    /**
     * @brief Retorna o valor do nome.
     * @return string com o nome.
     */
    string getValor() const;
};

inline string Nome::getValor() const
{
    return valor;
}

/**
 * @class Senha
 * @brief Classe responsável pelo domínio Senha.
 *
 * Representa uma senha de 5 dígitos numéricos, não sequenciais e sem repetição.
 */
class Senha{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena a senha. */

public:
    /**
     * @brief Retorna o valor da senha.
     * @return string com a senha.
     */
    string getValor() const;

    /**
     * @brief Define o valor da senha.
     *
     * @param valor Senha de 5 dígitos.
     * @throws invalid_argument se a senha não for válida.
     */
    void setValor(string valor);

    /**
     * @brief Valida a senha.
     *
     * Verifica se a senha possui 5 dígitos, todos numéricos, não formam sequência nem possuem dígitos repetidos.
     * @param valor String com a senha.
     * @throws invalid_argument se a senha for inválida.
     */
    void validar(string valor);

};

inline string Senha::getValor() const
{
    return valor;
}

/**
 * @enum EstadoTeste
 * @brief Representa o estado de um teste.
 *
 * @var EstadoTeste::sucesso Representa que o teste foi bem-sucedido.
 * @var EstadoTeste::falha Representa que o teste falhou.
 */
enum EstadoTeste
{
    sucesso = -1, /**< Teste bem-sucedido. */
    falha         /**< Teste falhou. */
};


#endif // DOMINIOS_H_INCLUDED
