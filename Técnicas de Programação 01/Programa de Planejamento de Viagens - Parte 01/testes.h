/**
 * @file teste.h
 * @brief Declaração das classes de teste para os domínios e entidades.
 */

#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <iostream>
#include "dominios.h"
#include "entidades.h"
using namespace std;

/**
 * @class TUAvaliacao
 * @brief Classe de teste para o domínio Avaliacao.
 *
 * Testa valores válidos e inválidos para o domínio Avaliacao.
 */
class TUAvaliacao{
private:
    const string VALORES_VALIDOS = "5";    /**< Valor válido de avaliação. */
    const string VALORES_INVALIDOS = "6";  /**< Valor inválido de avaliação. */

    Avaliacao *avaliacao;    /**< Ponteiro para objeto do tipo Avaliacao a ser testado. */
    EstadoTeste estado;      /**< Estado do teste (sucesso ou falha). */

    /**
     * @brief Configura o ambiente de teste (instancia objeto).
     */
    void setUp();

    /**
     * @brief Limpa o ambiente de teste (deleta objeto).
     */
    void tearDown();

    /**
     * @brief Testa cenários de sucesso.
     */
    void testarCenariosSucesso();

    /**
     * @brief Testa cenários de falha.
     */
    void testarCenariosFalha();

public:
    /**
     * @brief Executa o teste do domínio Avaliacao.
     * @return EstadoTeste indicando sucesso ou falha.
     */
    EstadoTeste run();
};


/**
 * @class TUCodigo
 * @brief Classe de teste para o domínio Codigo.
 *
 * Testa valores válidos e inválidos para o domínio Codigo.
 */
class TUCodigo {
private:
    const string VALORES_VALIDOS = "ABCDEF";   /**< Valor válido de código. */
    const string VALORES_INVALIDOS = "-asetf"; /**< Valor inválido de código. */

    Codigo *codigo;     /**< Ponteiro para objeto do tipo Codigo a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TU_Data
 * @brief Classe de teste para o domínio Data.
 *
 * Testa valores válidos e inválidos para o domínio Data.
 */
class TU_Data{
private:
    string data_valida = "29-02-20";    /**< Valor válido de data. */
    string data_invalida = "29-02-23"; /**< Valor inválido de data. */

    Data data;           /**< Objeto Data a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    /**
     * @brief Testa cenário válido.
     */
    void testar_cenario_valido();

    /**
     * @brief Testa cenário inválido.
     */
    void testar_cenario_invalido();

public:
    EstadoTeste run();
};

/**
 * @class TU_Dinheiro
 * @brief Classe de teste para o domínio Dinheiro.
 *
 * Testa valores válidos e inválidos para o domínio Dinheiro.
 */
class TU_Dinheiro{
private:
    string valor_valido = "20.158,56";   /**< Valor válido de dinheiro. */
    string valor_invalido = "1.000.000,01"; /**< Valor inválido de dinheiro. */

    Dinheiro dinheiro;   /**< Objeto Dinheiro a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    void testar_cenario_valido();
    void testar_cenario_invalido();

public:
    EstadoTeste run();
};

/**
 * @class TUDuracao
 * @brief Classe de teste para o domínio Duracao.
 *
 * Testa valores válidos e inválidos para o domínio Duracao.
 */
class TUDuracao{
private:
    const int VALORES_VALIDOS = 360;  /**< Valor válido de duração. */
    const int VALORES_INVALIDOS = -1; /**< Valor inválido de duração. */

    Duracao *duracao;     /**< Ponteiro para objeto Duracao a ser testado. */
    EstadoTeste estado;    /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUHorario
 * @brief Classe de teste para o domínio Horario.
 *
 * Testa valores válidos e inválidos para o domínio Horario.
 */
class TUHorario{
private:
    const string VALORES_VALIDOS = "04:45"; /**< Valor válido de horário. */
    const string VALORES_INVALIDOS = "00500"; /**< Valor inválido de horário. */

    Horario *horario;   /**< Ponteiro para objeto Horario a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUNome
 * @brief Classe de teste para o domínio Nome.
 *
 * Testa valores válidos e inválidos para o domínio Nome.
 */
class TUNome{
private:
    const string VALORES_VALIDOS = "michele";
    /**< Valor válido de nome. */

    const string VALORES_INVALIDOS = "-1fdisjfvisjfcsidofjkcsdfjsfisfjmifjosd";
    /**< Valor inválido de nome (muito extenso). */

    Nome *nome;       /**< Ponteiro para objeto Nome a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUSenha
 * @brief Classe de teste para o domínio Senha.
 *
 * Testa valores válidos e inválidos para o domínio Senha.
 */
class TUSenha{
private:
    const string VALORES_VALIDOS = "26485";  /**< Valor válido de senha. */
    const string VALORES_INVALIDOS = "12345"; /**< Valor inválido de senha (sequência). */

    Senha *senha;    /**< Ponteiro para objeto Senha a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUHospedagem
 * @brief Classe de teste para a entidade Hospedagem.
 *
 * Testa cenários com valores válidos para a entidade Hospedagem.
 */
class TUHospedagem{
private:
    string VALORES_VALIDOS_Nome = "michele";    /**< Valor válido de nome. */
    string VALORES_VALIDOS_Codigo = "ABCDEF";   /**< Valor válido de código. */
    string VALORES_VALIDOS_Avaliacao = "5";     /**< Valor válido de avaliação. */
    string VALORES_VALIDOS_Dinheiro = "9.000,99"; /**< Valor válido de valor monetário. */

    Hospedagem hospedagem; /**< Objeto Hospedagem a ser testado. */
    EstadoTeste estado;    /**< Estado do teste. */

    /**
     * @brief Testa cenário com valores válidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUViagem
 * @brief Classe de teste para a entidade Viagem.
 *
 * Testa cenários com valores válidos para a entidade Viagem.
 */
class TUViagem{
private:
    string VALORES_VALIDOS_Nome = "Paulo";   /**< Valor válido de nome para viagem. */
    string VALORES_VALIDOS_Codigo = "123456"; /**< Valor válido de código para viagem. */
    string VALORES_VALIDOS_Avaliacao = "3";   /**< Valor válido de avaliação para viagem. */

    Viagem viagem;    /**< Objeto Viagem a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Testa cenário com valores válidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUDestino
 * @brief Classe de teste para a entidade Destino.
 *
 * Testa cenários com valores válidos para a entidade Destino.
 */
class TUDestino{
private:
    string VALORES_VALIDOS_Nome = "Paulo";       /**< Valor válido de nome para destino. */
    string VALORES_VALIDOS_Codigo = "123456";    /**< Valor válido de código para destino. */
    string VALORES_VALIDOS_Avaliacao = "3";      /**< Valor válido de avaliação para destino. */
    string VALORES_VALIDOS_DataI = "05-10-99";   /**< Valor válido de data inicial para destino. */
    string VALORES_VALIDOS_DataF = "26-10-99";   /**< Valor válido de data final para destino. */

    Destino destino;  /**< Objeto Destino a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Testa cenário com valores válidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUConta
 * @brief Classe de teste para a entidade Conta.
 *
 * Testa cenários com valores válidos para a entidade Conta.
 */
class TUConta {
private:
    const string VALOR_VALIDO_CODIGO = "1W2e33"; /**< Valor válido de código para conta. */
    const string VALOR_VALIDO_SENHA = "19283";   /**< Valor válido de senha para conta. */

    Conta* conta;     /**< Ponteiro para objeto Conta a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Configura ambiente de teste.
     */
    void setUp();

    /**
     * @brief Limpa ambiente de teste.
     */
    void tearDown();

    /**
     * @brief Testa cenário com valores válidos.
     */
    void testarCenario();
public:
    EstadoTeste run();
};

/**
 * @class TUAtividade
 * @brief Classe de teste para a entidade Atividade.
 *
 * Testa cenários com valores válidos para a entidade Atividade.
 */
class TUAtividade {
private:
    Atividade *atividade; /**< Ponteiro para objeto Atividade a ser testado. */
    EstadoTeste estado;   /**< Estado do teste. */

    /**
     * @brief Configura ambiente de teste.
     */
    void setUp();

    /**
     * @brief Limpa ambiente de teste.
     */
    void tearDown();

    /**
     * @brief Testa cenário de sucesso.
     */
    void testarCenarioSucesso();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    EstadoTeste run();
};

#endif // TESTE_H_INCLUDED
