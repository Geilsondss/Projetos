#include <string>
#include <typeinfo>
#include <map>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <cstdlib>


#include "controladoras.h"

using namespace std;

/**
*@brief O metodo autenticar recebe e valida o Codigo e a Senha digitados pelo usuario e chama o metodo autenticar da camada de servico para efetuar a autenticacao. Alem disso, sempre que o usuario digita algum dado errado, pergunta-se se deseja continuar tentando autenticar para haver a possibilidade de sair do loop.
*/
//Geilson dos Santos - 231006239
bool CntrIntAprAutenticacao::autenticar(Codigo *codigo) {
    Senha senha;
    string entrada;

    while(true) {
        cout << endl << "================ Autenticacao de Usuario ================" << endl << endl;

        try {
            cout << "Digite o Codigo (6 digitos alfanumericos) : ";
            cin >> entrada;
            codigo->setValor(entrada);
            cout << "Digite a senha (5 digitos numericos)   : ";
            cin >> entrada;
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl << endl;
            int resposta;
            cout << "Deseja continuar?" << endl;
            cout << "1. Sim        2. Nao" << endl << endl;
            cout << "Digite um numero : ";
            cin >> resposta;
            cout << endl;

            if(resposta == 2){
                break;
            }
        }
    }

    ContainerConta* container = ContainerConta::getInstancia();
    bool resultado = container->autenticar(*codigo, senha);
    return resultado;
}

/**
*@brief O metodo criar recebe e valida  o Codigo e a Senha digitados pelo usuario e chama o metodo criar da camada de servico para efetuar a criacao da conta. Alem disso, sempre que o usuario digita algum dado errado, pergunta-se se deseja continuar tentando criar a conta para haver a possibilidade de sair do loop.
*/
void CntrIntAprConta::criar(){ //Michele Nakagomi (232029078)
    Codigo codigo;
    Senha senha;
    Conta conta;
    string entrada;

    while (true){
        system("cls");
        try {
            cout << endl << "===================== Criar Conta =======================" << endl << endl;

            cout << "Digite o Codigo (6 digitos alfanumericos) : ";
            cin >> entrada;
            codigo.setValor(entrada);
            conta.setCodigo(codigo);
            cout << "Digite a senha (5 digitos numericos) : ";
            cin >> entrada;
            senha.setValor(entrada);
            conta.setSenha(senha);
            ContainerConta *container;
            container = ContainerConta::getInstancia();
            bool resultado = container->criar(conta);
            if (resultado){
                cout << endl << "                                Conta criada com sucesso." << endl;
                break;
            }
            else{
                cout << endl << "                                     Falha ao criar conta" << endl << endl;
                int resposta;
                cout << "Deseja continuar?" << endl;
                cout << "1. Sim        2. Nao" << endl << endl;
                cout << "Digite um numero : ";
                cin >> resposta;
                cout << endl;

                if(resposta == 2){
                    break;
                }
            }
        }
        catch (const invalid_argument &exp){
            cout << endl << "Dado em formato incorreto." << endl << endl;
            int resposta;
            cout << "Deseja continuar?" << endl;
            cout << "1. Sim        2. Nao" << endl << endl;
            cout << "Digite um numero : ";
            cin >> resposta;
            cout << endl;

            if(resposta == 2){
                break;
            }
        }
    }
}

/**
*@brief O metodo executar permite o usuario ler, atualizar ou excluir a sua conta. Para cada uma das opcoes, chama-se um metodo da camada de servico para efetuar a acao.
*/
bool CntrIntAprConta::executar(Codigo codigo) { //Michele Nakagomi (232029078)
    string entrada;
    Conta conta;
    conta.setCodigo(codigo);
    int resposta;
    while (true){
        try {
            cout << endl << "=================== Execucao da Conta ===================" << endl;

            cout << endl << "1. Ler" << endl;
            cout << "2. Atualizar" << endl;
            cout << "3. Excluir" << endl;
            cout << "4. Sair" << endl << endl;
            cout << "Digite um numero : ";
            cin >> resposta;
            cout << endl;

            if (resposta == 1){
                ContainerConta *container;
                container = ContainerConta::getInstancia();
                bool resultado = container->pesquisar(&conta);
                if (resultado){
                    cout << "................. Informacoes da conta .................." << endl<< endl;
                    cout << "Codigo : " << conta.getCodigo().getValor() << endl;
                    cout << "Senha : " << conta.getSenha().getValor() << endl;
                }
                else{
                    cout << endl << "                           Nao foi possivel achar a conta" << endl;
                }
            };

            if (resposta == 2){
                Codigo codigo;
                Senha senha;
                cout << "................ Confirmar informacoes .................." << endl<< endl;
                cout << "Codigo : ";
                cin >> entrada;
                codigo.setValor(entrada);
                conta.setCodigo(codigo);
                cout << "Nova Senha : ";
                cin >> entrada;
                senha.setValor(entrada);
                conta.setSenha(senha);
                ContainerConta *container;
                container = ContainerConta::getInstancia();
                bool resultado = container->atualizar(conta);
                if (resultado){
                    cout << endl << "                             Conta atualizada com sucesso" << endl;
                }
                else{
                    cout << endl << "                       Nao foi possivel atualizar a conta" << endl;
                }
            };

            if (resposta == 3){
                ContainerConta *container;
                container = ContainerConta::getInstancia();
                bool resultado = container->excluir(codigo);
                if (resultado){
                    cout << "                               Conta excluida com sucesso"  << endl;
                }
                else{
                    cout << endl << "                         Nao foi possivel excluir a conta" << endl;
                }
            };
            if (resposta == 4){
             break;
            }
        }
        catch (const invalid_argument &exp){
            cout << endl << "                                        Numero incorreto." << endl << endl;
            cout << "Deseja continuar?" << endl;
            cout << "1. Sim        2. Nao" << endl << endl;
            cout << "Digite um numero : ";
            cin >> resposta;
            cout << endl;

            if(resposta == 2){
                break;
            }
        }
    }
    bool resultado = true;
    return resultado;
}


CntrIntServAutenticacao* CntrIntServAutenticacao::instancia = nullptr;
/**
*@brief O metodo getInstancia chama uma instancia j� existente no container.
*/
CntrIntServAutenticacao* CntrIntServAutenticacao::getInstancia() { //ARTHUS CESAR DIAS FERNANDES - 231006103
    if (instancia == nullptr) {
        instancia = new CntrIntServAutenticacao();
    }
    return instancia;
}

/**
*@brief O metodo autenticar chama o metodo autenticar do container para assim retornar o status da autenticacao.
*/
bool CntrIntServAutenticacao::autenticar(Codigo& codigo, Senha& senha) { //ARTHUS CESAR DIAS FERNANDES - 231006103
    ContainerConta* container = ContainerConta::getInstancia();

    if (container->autenticar(codigo, senha)) {
        return true;
    }
    return false;
}

/**
*@brief O metodo criar chama o metodo criar do container para assim retornar o status da criacao de uma conta.
*/
bool CntrIntServConta::criar(Conta conta) { // Tau� Valentim - 231021389
    ContainerConta *container;
    container = ContainerConta::getInstancia();
    return container->criar(conta);
}

/**
*@brief O metodo pesquisar chama o metodo pesquisar do container para assim retornar o status de pesquisa de uma conta.
*/
bool CntrIntServConta::pesquisar(Conta* conta) { // Tau� Valentim - 231021389
    ContainerConta *container;

    container = ContainerConta::getInstancia();

    return container->pesquisar(conta);
}

/**
*@brief O metodo excluir chama o metodo excluir do container para assim retornar o status de exclusao de uma conta.
*/
bool CntrIntServConta::excluir(Codigo codigo) { // Tau� Valentim - 231021389
    ContainerConta *container;

    container = ContainerConta::getInstancia();

    return container->excluir(codigo);
}

/**
*@brief O metodo atualizar chama o metodo atualizar do container para assim retornar o status de atualizacao de uma conta.
*/
bool CntrIntServConta::atualizar(Conta conta) { // Tau� Valentim - 231021389
    ContainerConta *container;

    container = ContainerConta::getInstancia();

    return container->atualizar(conta);
}

//-----------------------------------------------------------------------------------------------------------


//Jo�o Vitor Santos de Sena - 190089890

void CntrApresentacaoViagem::executar(Codigo codigoUsuario) {
    while(true) {
        system("cls");
        cout << endl <<"==================== Menu de Viagens ====================" << endl;
        cout << "1. Gerenciar Viagens" << endl;
        cout << "2. Listar Minhas Viagens" << endl;
        cout << "3. Calcular Custo de Viagem" << endl;
        cout << "4. Sair" << endl;
        cout << "Digite um numero : ";

        char opcao;
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case '1':
                menuViagem(codigoUsuario);
                break;
            case '2':
                listarViagens(codigoUsuario);
                break;
            case '3':
                calcularCustoViagem();
                break;
            case '4':
                return;
            default:
                cout << "                                        Numero incorreto."<< endl;
                cin.get();
        }
    }
}

void CntrApresentacaoViagem::menuViagem(Codigo codigoUsuario) {
    while(true) {
        system("cls");
        cout << endl <<"================ Gerenciamento de Viagens ===============" << endl;
        cout << "1. Criar Viagem" << endl;
        cout << "2. Visualizar Viagem" << endl;
        cout << "3. Atualizar Viagem" << endl;
        cout << "4. Excluir Viagem" << endl;
        cout << "\n5. Gerenciar Destinos" << endl;
        cout << "6. Voltar" << endl;
        cout << "\nDigite um numero : ";

        char opcao;
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case '1':
                criarViagem(codigoUsuario);
                break;
            case '2':
                visualizarViagem();
                break;
            case '3':
                atualizarViagem();
                break;
            case '4':
                excluirViagem();
                break;
            case '5':
                menuDestino();
                break;
            case '6':
                return;
            default:
                cout << "Opcao invalida!" << endl;
                cin.get();
        }
    }
}

void CntrApresentacaoViagem::menuDestino() {
    while(true) {
        system("cls");
        cout << "================ Gerenciamento de Destinos ==============" << endl;
        cout << "1. Criar Destino" << endl;
        cout << "2. Visualizar Destino" << endl;
        cout << "3. Atualizar Destino" << endl;
        cout << "4. Excluir Destino" << endl;
        cout << "\n5. Gerenciar Atividades" << endl;
        cout << "6. Gerenciar Hospedagens" << endl;
        cout << "7. Voltar" << endl;
        cout << "\nDigite um numero : ";

        char opcao;
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case '1':
                criarDestino();
                break;
            case '2':
                visualizarDestino();
                break;
            case '3':
                atualizarDestino();
                break;
            case '4':
                excluirDestino();
                break;
            case '5':
                menuAtividade();
                break;
            case '6':
                menuHospedagem();
                break;
            case '7':
                return;
            default:
                cout << "Opcao invalida!" << endl;
                cin.get();
        }
    }
}

void CntrApresentacaoViagem::menuHospedagem() {
    while(true) {
        system("cls");
        cout << endl <<"============== Gerenciamento de Hospedagens =============" << endl;
        cout << "1. Criar Hospedagem" << endl;
        cout << "2. Visualizar Hospedagem" << endl;
        cout << "3. Atualizar Hospedagem" << endl;
        cout << "4. Excluir Hospedagem" << endl;
        cout << "\n5. Voltar" << endl;
        cout << "Digite um numero : ";;

        char opcao;
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case '1':
                criarHospedagem();
                break;
            case '2':
                visualizarHospedagem();
                break;
            case '3':
                atualizarHospedagem();
                break;
            case '4':
                excluirHospedagem();
                break;
            case '5':
                return;
            default:
                cout << "Opcao invalida!" << endl;
                cin.get();
        }
    }
}

void CntrApresentacaoViagem::menuAtividade() {
    while(true) {
        system("cls");
        cout << endl<<"============== Gerenciamento de Atividades ==============" << endl;
        cout << "1. Criar Atividade" << endl;
        cout << "2. Visualizar Atividade" << endl;
        cout << "3. Atualizar Atividade" << endl;
        cout << "4. Excluir Atividade" << endl;
        cout << "\n5. Voltar" << endl;
        cout << "Digite um numero : ";

        char opcao;
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case '1':
                criarAtividade();
                break;
            case '2':
                visualizarAtividade();
                break;
            case '3':
                atualizarAtividade();
                break;
            case '4':
                excluirAtividade();
                break;
            case '5':
                return;
            default:
                cout << "Opcao invalida!" << endl;
                cin.get();
        }
    }
}

void CntrApresentacaoViagem::criarViagem(Codigo codigoUsuario) {
    try {
        Viagem viagem;
        Codigo codigo;
        Nome nome;
        Avaliacao avaliacao;

        cout << "Digite o codigo da viagem: ";
        string valor;
        getline(cin, valor);

        codigo.setValor(valor);
        viagem.setCodigoViagem(codigo);

        cout << "Digite o nome da viagem: ";
        getline(cin, valor);
        nome.setValor(valor);
        viagem.setNomeViagem(nome);

        cout << "Digite a avaliacao da viagem (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        viagem.setAvaliacaoViagem(avaliacao);

        // Cria uma conta para associar � viagem
        Conta* conta = new Conta();
        conta->setCodigo(codigoUsuario);
        viagem.setConta(conta);

        cntrServViagem->criarViagem(viagem);
        cout << "Viagem criada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::visualizarViagem() {
    try {
        Viagem viagem;
        Codigo codigo;

        cout << "Digite o codigo da viagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarViagem(codigo, &viagem);

        cout << "\n==================== Dados da Viagem ===================="  << endl;
        cout << "Codigo: " << viagem.getCodigoViagem().getValor() << endl;
        cout << "Nome: " << viagem.getNomeViagem().getValor() << endl;
        cout << "Avaliacao: " << viagem.getAvaliacaoViagem().getValor() << endl;

        // Lista os destinos da viagem
        list<Destino> destinos = cntrServViagem->listarDestinosPorViagem(codigo);

        if(destinos.empty()) {
            cout << "\nEsta viagem ainda nao possui destinos cadastrados." << endl;
        } else {
            cout << "\n================== Destinos da Viagem ===================" << endl;
            for(const Destino& destino : destinos) {
                cout << "\nDestino:" << endl;
                cout << "  Codigo: " << destino.getCodigo().getValor() << endl;
                cout << "  Nome: " << destino.getNome().getValor() << endl;
                cout << "  Data Inicio: " << destino.getDataInicio().getValor() << endl;
                cout << "  Data Termino: " << destino.getDataTermino().getValor() << endl;
                cout << "  Avaliacao: " << destino.getAvaliacao().getValor() << endl;

                // Lista a hospedagem do destino, se houver
                list<Hospedagem> hospedagens = cntrServViagem->listarHospedagensPorDestino(destino.getCodigo());

                if(hospedagens.empty()) {
                    cout << "  Hospedagem: Nenhuma hospedagem cadastrada" << endl;
                } else {
                    const Hospedagem& hospedagem = hospedagens.front(); // Pegamos a primeira (e �nica) hospedagem
                    cout << "  Hospedagem:" << endl;
                    cout << "    Codigo: " << hospedagem.getCodigoHospedagem().getValor() << endl;
                    cout << "    Nome: " << hospedagem.getNomeHospedagem().getValor() << endl;
                    cout << "    Diaria: R$ " << fixed << setprecision(2) << hospedagem.getDiariaHospedagem().getValor() << endl;
                    cout << "    Avaliacao: " << hospedagem.getAvaliacaoHospedagem().getValor() << endl;
                }
                cout << "  -------------------" << endl;
            }
        }

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::atualizarViagem() {
    try {
        Viagem viagem;
        Codigo codigo;
        Nome nome;
        Avaliacao avaliacao;

        cout << "Digite o codigo da viagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarViagem(codigo, &viagem);

        cout << "Digite o novo nome da viagem: ";
        getline(cin, valor);
        nome.setValor(valor);
        viagem.setNomeViagem(nome);

        cout << "Digite a nova avaliacao da viagem (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        viagem.setAvaliacaoViagem(avaliacao);

        cntrServViagem->atualizarViagem(viagem);
        cout << "Viagem atualizada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::excluirViagem() {
    try {
        Codigo codigo;
        cout << "Digite o codigo da viagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        // Verifica se a viagem pertence ao usu�rio atual
        Viagem viagem;
        cntrServViagem->visualizarViagem(codigo, &viagem);
        if (viagem.getConta()->getCodigo().getValor() != codigoUsuarioAtual.getValor()) {
            throw invalid_argument("Voce nao tem permissao para excluir esta viagem.");
        }

        cntrServViagem->excluirViagem(codigo);
        cout << "Viagem excluida com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::listarViagens(Codigo codigoUsuario) {
    try {
        list<Viagem> viagens = cntrServViagem->listarViagensPorConta(codigoUsuario);
        if(viagens.empty()) {
            cout << "Nenhuma viagem encontrada." << endl;
        } else {
            for(const Viagem& viagem : viagens) {
                cout << "---------------------------------------------------------" << endl;
                cout << "\nCodigo: " << viagem.getCodigoViagem().getValor() << endl;
                cout << "Nome: " << viagem.getNomeViagem().getValor() << endl;
                cout << "Avaliacao: " << viagem.getAvaliacaoViagem().getValor() << endl;
                cout << "---------------------------------------------------------" << endl;
            }
        }
    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::criarDestino() {
    try {
        Destino destino;
        Codigo codigoViagem, codigo;
        Nome nome;
        Data dataInicio, dataTermino;
        Avaliacao avaliacao;

        cout << "Digite o codigo da viagem para adicionar o destino: ";
        string valor;
        getline(cin, valor);
        codigoViagem.setValor(valor);

        // Verifica se a viagem existe
        Viagem* viagem = new Viagem();
        cntrServViagem->visualizarViagem(codigoViagem, viagem);

        cout << "Digite o codigo do destino: ";
        getline(cin, valor);
        codigo.setValor(valor);
        destino.setCodigo(codigo);

        cout << "Digite o nome do destino: ";
        getline(cin, valor);
        nome.setValor(valor);
        destino.setNome(nome);

        cout << "Digite a data de inicio (DD-MM-AA): ";
        getline(cin, valor);
        dataInicio.setValor(valor);
        destino.setDataInicio(dataInicio);

        cout << "Digite a data de termino (DD-MM-AA): ";
        getline(cin, valor);
        dataTermino.setValor(valor);
        destino.setDataTermino(dataTermino);

        cout << "Digite a avaliacao do destino (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        destino.setAvaliacao(avaliacao);

        // Associa o destino � viagem
        destino.setViagem(viagem);

        cntrServViagem->criarDestino(destino);
        cout << "Destino criado com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::visualizarDestino() {
    try {
        Destino destino;
        Codigo codigo;

        cout << "Digite o codigo do destino: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarDestino(codigo, &destino);

        cout << endl<<"=================== Dados do Destino ====================" << endl;
        cout << "Codigo: " << destino.getCodigo().getValor() << endl;
        cout << "Nome: " << destino.getNome().getValor() << endl;
        cout << "Data Inicio: " << destino.getDataInicio().getValor() << endl;
        cout << "Data Termino: " << destino.getDataTermino().getValor() << endl;
        cout << "Avaliacao: " << destino.getAvaliacao().getValor() << endl;

        // Lista a hospedagem do destino, se houver
        list<Hospedagem> hospedagens = cntrServViagem->listarHospedagensPorDestino(codigo);
        if(hospedagens.empty()) {
            cout << "\nHospedagem: Nenhuma hospedagem cadastrada" << endl;
        } else {
            const Hospedagem& hospedagem = hospedagens.front(); // Pegamos a primeira (e �nica) hospedagem
            cout << "\nHospedagem:" << endl;
            cout << "  Codigo: " << hospedagem.getCodigoHospedagem().getValor() << endl;
            cout << "  Nome: " << hospedagem.getNomeHospedagem().getValor() << endl;
            cout << "  Diaria: R$ " << fixed << setprecision(2) << hospedagem.getDiariaHospedagem().getValor() << endl;
            cout << "  Avaliacao: " << hospedagem.getAvaliacaoHospedagem().getValor() << endl;
        }

        // Lista as atividades do destino, se houver
        list<Atividade> atividades = cntrServViagem->listarAtividadesPorDestino(codigo);
        if(atividades.empty()) {
            cout << "\nAtividades: Nenhuma atividade cadastrada" << endl;
        } else {
            cout << "\nAtividades:" << endl;
            for(const Atividade& atividade : atividades) {
                cout << "  -------------------------------------------------------" << endl;
                cout << "  Codigo: " << atividade.getCodigo().getValor() << endl;
                cout << "  Nome: " << atividade.getNome().getValor() << endl;
                cout << "  Data: " << atividade.getData().getValor() << endl;
                cout << "  Custo: R$ " << fixed << setprecision(2) << atividade.getDinheiro().getValor() << endl;
                cout << "  Avaliacao: " << atividade.getAvaliacao().getValor() << endl;
            }
        }

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::atualizarDestino() {
    try {
        Destino destino;
        Codigo codigo;
        Nome nome;
        Data dataInicio, dataTermino;
        Avaliacao avaliacao;

        cout << "Digite o codigo do destino: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarDestino(codigo, &destino);

        cout << "Digite o novo nome do destino: ";
        getline(cin, valor);
        nome.setValor(valor);
        destino.setNome(nome);

        cout << "Digite a nova data de inicio (DD-MM-AA): ";
        getline(cin, valor);
        dataInicio.setValor(valor);
        destino.setDataInicio(dataInicio);

        cout << "Digite a nova data de termino (DD-MM-AA): ";
        getline(cin, valor);
        dataTermino.setValor(valor);
        destino.setDataTermino(dataTermino);

        cout << "Digite a nova avaliacao do destino (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        destino.setAvaliacao(avaliacao);

        cntrServViagem->atualizarDestino(destino);
        cout << "Destino atualizado com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::excluirDestino() {
    try {
        Codigo codigo;
        cout << "Digite o codigo do destino: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->excluirDestino(codigo);
        cout << "Destino excluido com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::criarHospedagem() {
    try {
        Hospedagem hospedagem;
        Codigo codigoDestino, codigo;
        Nome nome;
        Dinheiro diaria;
        Avaliacao avaliacao;

        cout << "Digite o codigo do destino para adicionar a hospedagem: ";
        string valor;
        getline(cin, valor);
        codigoDestino.setValor(valor);

        // Verifica se o destino existe e se já tem hospedagem
        Destino destino;
        cntrServViagem->visualizarDestino(codigoDestino, &destino);

        // Verifica se o destino já tem uma hospedagem
        list<Hospedagem> hospedagens = cntrServViagem->listarHospedagensPorDestino(codigoDestino);
        if (!hospedagens.empty()) {
            throw invalid_argument("Este destino ja possui uma hospedagem associada.");
        }

        cout << "Digite o codigo da hospedagem: ";
        getline(cin, valor);
        codigo.setValor(valor);
        hospedagem.setCodigoHospedagem(codigo);

        cout << "Digite o nome da hospedagem: ";
        getline(cin, valor);
        nome.setValor(valor);
        hospedagem.setNomeHospedagem(nome);

        cout << "Digite o valor da diaria: ";
        getline(cin, valor);
        diaria.setValor(valor);
        hospedagem.setDiariaHospedagem(diaria);

        cout << "Digite a avaliacao da hospedagem (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        hospedagem.setAvaliacaoHospedagem(avaliacao);

        // Primeiro criamos a hospedagem
        cntrServViagem->criarHospedagem(hospedagem);

        // Depois associamos a hospedagem ao destino
        // A classe Destino agora gerencia a memória automaticamente
        destino.setHospedagem(new Hospedagem(hospedagem));
        cntrServViagem->atualizarDestino(destino);

        cout << "Hospedagem criada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::visualizarHospedagem() {
    try {
        Hospedagem hospedagem;
        Codigo codigo;

        cout << "Digite o codigo da hospedagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarHospedagem(codigo, &hospedagem);

        cout << "=================== Dados da Hospedagem =================" << endl;
        cout << "Codigo: " << hospedagem.getCodigoHospedagem().getValor() << endl;
        cout << "Nome: " << hospedagem.getNomeHospedagem().getValor() << endl;
        cout << "Diaria: R$ " << hospedagem.getDiariaHospedagem().getValor() << endl;
        cout << "Avaliacao: " << hospedagem.getAvaliacaoHospedagem().getValor() << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::atualizarHospedagem() {
    try {
        Hospedagem hospedagem;
        Codigo codigo;
        Nome nome;
        Dinheiro diaria;
        Avaliacao avaliacao;

        cout << "Digite o codigo da hospedagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarHospedagem(codigo, &hospedagem);

        cout << "Digite o novo nome da hospedagem: ";
        getline(cin, valor);
        nome.setValor(valor);
        hospedagem.setNomeHospedagem(nome);

        cout << "Digite o novo valor da diaria: ";
        getline(cin, valor);
        diaria.setValor(valor);
        hospedagem.setDiariaHospedagem(diaria);

        cout << "Digite a nova avaliacao da hospedagem (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        hospedagem.setAvaliacaoHospedagem(avaliacao);

        cntrServViagem->atualizarHospedagem(hospedagem);
        cout << "Hospedagem atualizada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::excluirHospedagem() {
    try {
        Codigo codigo;
        cout << "Digite o codigo da hospedagem: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->excluirHospedagem(codigo);
        cout << "Hospedagem excluida com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::calcularCustoViagem() {
    try {
        Codigo codigo;
        cout << "Digite o codigo da viagem: " << endl;
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        float custoTotal = cntrServViagem->calcularCustoViagem(codigo);
        cout << endl << "Custo total da viagem: R$ " << fixed << setprecision(2) << custoTotal << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::criarAtividade() {
    try {
        Atividade atividade;
        Codigo codigo, codigoDestino;
        Nome nome;
        Data data;
        Dinheiro custo;
        Avaliacao avaliacao;

        cout << "Digite o codigo da atividade: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);
        atividade.setCodigo(codigo);

        cout << "Digite o nome da atividade: ";
        getline(cin, valor);
        nome.setValor(valor);
        atividade.setNome(nome);

        cout << "Digite a data da atividade (DD-MM-AA): ";
        getline(cin, valor);
        data.setValor(valor);
        atividade.setData(data);

        cout << "Digite o custo da atividade (R$ xxxxx,xx): ";
        getline(cin, valor);
        custo.setValor(valor);
        atividade.setDinheiro(custo);

        cout << "Digite a avaliacao da atividade (0-5): ";
        getline(cin, valor);
        avaliacao.setValor(valor);
        atividade.setAvaliacao(avaliacao);

        cout << "Digite o codigo do destino associado: ";
        getline(cin, valor);
        codigoDestino.setValor(valor);

        // Busca o destino para validação
        Destino destino;
        cntrServViagem->visualizarDestino(codigoDestino, &destino);

        // Valida se a data da atividade está dentro do período do destino
        cntrServViagem->validarDataAtividade(atividade, destino);

        // Cria a atividade
        cntrServViagem->criarAtividade(atividade);
        cout << "Atividade criada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::visualizarAtividade() {
    try {
        Atividade atividade;
        Codigo codigo;

        cout << "Digite o codigo da atividade: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->visualizarAtividade(codigo, &atividade);

        cout << "\n=================== Dados da Atividade ==================" << endl;
        cout << "Codigo: " << atividade.getCodigo().getValor() << endl;
        cout << "Nome: " << atividade.getNome().getValor() << endl;
        cout << "Data: " << atividade.getData().getValor() << endl;
        cout << "Custo: R$ " << fixed << setprecision(2) << atividade.getDinheiro().getValor() << endl;
        cout << "Avaliacao: " << atividade.getAvaliacao().getValor() << endl;

        // Busca o destino associado pela data
        list<Destino> destinos = cntrServViagem->listarDestinos();
        for(const Destino& d : destinos) {
            if(atividade.getData().getValor() >= d.getDataInicio().getValor() &&
               atividade.getData().getValor() <= d.getDataTermino().getValor()) {
                cout << "Destino: " << d.getNome().getValor() << endl;
                break;
            }
        }

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::atualizarAtividade() {
    try {
        Atividade atividade;
        Codigo codigo;

        cout << "Digite o codigo da atividade a ser atualizada: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        // Busca a atividade atual
        cntrServViagem->visualizarAtividade(codigo, &atividade);

        Nome nome;
        Data data;
        Dinheiro custo;
        Avaliacao avaliacao;

        cout << "Digite o novo nome da atividade (ou Enter para manter): ";
        getline(cin, valor);
        if (!valor.empty()) {
            nome.setValor(valor);
            atividade.setNome(nome);
        }

        cout << "Digite a nova data da atividade (DD-MM-AA) (ou Enter para manter): ";
        getline(cin, valor);
        if (!valor.empty()) {
            data.setValor(valor);
            atividade.setData(data);

            // Encontra o destino correspondente à data da atividade
            bool destinoEncontrado = false;
            list<Destino> destinos = cntrServViagem->listarDestinos();
            for(const Destino& d : destinos) {
                if(atividade.getData().getValor() >= d.getDataInicio().getValor() &&
                   atividade.getData().getValor() <= d.getDataTermino().getValor()) {
                    // Revalida a data com o destino encontrado
                    cntrServViagem->validarDataAtividade(atividade, d);
                    destinoEncontrado = true;
                    break;
                }
            }
            if (!destinoEncontrado) {
                throw invalid_argument("Nao foi encontrado um destino para a data especificada.");
            }
        }

        cout << "Digite o novo custo da atividade (R$) (ou Enter para manter): ";
        getline(cin, valor);
        if (!valor.empty()) {
            custo.setValor(valor);
            atividade.setDinheiro(custo);
        }

        cout << "Digite a nova avaliacao da atividade (0-5) (ou Enter para manter): ";
        getline(cin, valor);
        if (!valor.empty()) {
            avaliacao.setValor(valor);
            atividade.setAvaliacao(avaliacao);
        }

        cntrServViagem->atualizarAtividade(atividade);
        cout << "Atividade atualizada com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::excluirAtividade() {
    try {
        Codigo codigo;

        cout << "Digite o codigo da atividade a ser excluida: ";
        string valor;
        getline(cin, valor);
        codigo.setValor(valor);

        cntrServViagem->excluirAtividade(codigo);
        cout << "Atividade excluida com sucesso!" << endl;

    } catch(invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }
    cin.get();
}

void CntrApresentacaoViagem::setCntrServViagem(ISV* cntrServViagem) {
    this->cntrServViagem = cntrServViagem;
}


//Jo�o Vitor Santos de Sena - 190089890
// Implementa��o CntrServViagem

void CntrServViagem::criarViagem(Viagem viagem) {
    try {
        ContainerViagem::incluir(viagem);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::visualizarViagem(Codigo codigo, Viagem* viagem) {
    try {
        *viagem = ContainerViagem::pesquisar(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::atualizarViagem(Viagem viagem) {
    try {
        ContainerViagem::atualizar(viagem);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::excluirViagem(Codigo codigo) {
    try {
        ContainerViagem::remover(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

list<Viagem> CntrServViagem::listarViagens() {
    return ContainerViagem::getViagens();
}

list<Viagem> CntrServViagem::listarViagensPorConta(Codigo codigo) {
    return ContainerViagem::getViagensPorConta(codigo);
}

void CntrServViagem::validarDatasDestino(const Destino& destino) {
    string dataInicio = destino.getDataInicio().getValor();
    string dataTermino = destino.getDataTermino().getValor();

    // Como a data está no formato DD-MM-AA, podemos comparar as strings diretamente
    if (dataTermino < dataInicio) {
        throw invalid_argument("A data de termino nao pode ser anterior a data de inicio.");
    }
}

void CntrServViagem::criarDestino(Destino destino) {
    // Valida as datas antes de criar o destino
    validarDatasDestino(destino);

    try {
        // Tenta pesquisar o destino - se não lançar exceção, significa que já existe
        ContainerDestino::pesquisar(destino.getCodigo());
        throw invalid_argument("Ja existe um destino com este codigo.");
    } catch (invalid_argument&) {
        // Se lançou exceção, significa que não existe, então podemos criar
        ContainerDestino::incluir(destino);
    }
}

void CntrServViagem::visualizarDestino(Codigo codigo, Destino* destino) {
    try {
        *destino = ContainerDestino::pesquisar(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::atualizarDestino(Destino destino) {
    // Valida as datas antes de atualizar o destino
    validarDatasDestino(destino);

    try {
        // Verifica se o destino existe
        ContainerDestino::pesquisar(destino.getCodigo());
        // Se não lançou exceção, o destino existe e podemos atualizar
        ContainerDestino::atualizar(destino);
    } catch (invalid_argument& e) {
        throw invalid_argument("Destino nao encontrado.");
    }
}

void CntrServViagem::excluirDestino(Codigo codigo) {
    try {
        ContainerDestino::remover(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

list<Destino> CntrServViagem::listarDestinos() {
    return ContainerDestino::getDestinos();
}

list<Destino> CntrServViagem::listarDestinosPorViagem(Codigo codigo) {
    return ContainerDestino::getDestinosPorViagem(codigo);
}

void CntrServViagem::criarHospedagem(Hospedagem hospedagem) {
    try {
        ContainerHospedagem::incluir(hospedagem);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::visualizarHospedagem(Codigo codigo, Hospedagem* hospedagem) {
    try {
        *hospedagem = ContainerHospedagem::pesquisar(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::atualizarHospedagem(Hospedagem hospedagem) {
    try {
        ContainerHospedagem::atualizar(hospedagem);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::excluirHospedagem(Codigo codigo) {
    try {
        ContainerHospedagem::remover(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

list<Hospedagem> CntrServViagem::listarHospedagens() {
    return ContainerHospedagem::getHospedagens();
}

list<Hospedagem> CntrServViagem::listarHospedagensPorDestino(Codigo codigo) {
    return ContainerHospedagem::getHospedagensPorDestino(codigo);
}

float CntrServViagem::calcularCustoViagem(Codigo codigoViagem) {
    float custoTotal = 0.0f;

    // Obtém todos os destinos da viagem
    list<Destino> destinos = listarDestinosPorViagem(codigoViagem);

    // Para cada destino, soma o custo de suas hospedagens e atividades
    for (const Destino& destino : destinos) {
        // Soma custos de hospedagens
        list<Hospedagem> hospedagens = listarHospedagensPorDestino(destino.getCodigo());
        for (const Hospedagem& hospedagem : hospedagens) {
            custoTotal += stof(hospedagem.getDiariaHospedagem().getValor());
        }

        // Soma custos de atividades
        list<Atividade> atividades = listarAtividadesPorDestino(destino.getCodigo());
        for (const Atividade& atividade : atividades) {
            custoTotal += stof(atividade.getDinheiro().getValor());
        }
    }

    return custoTotal;
}

// Implementação dos métodos de gerenciamento de atividades

void CntrServViagem::criarAtividade(Atividade atividade) {
    try {
        // Verifica se já existe uma atividade com o mesmo código
        ContainerAtividade::pesquisar(atividade.getCodigo());
        throw invalid_argument("Ja existe uma atividade com este codigo.");
    } catch (invalid_argument&) {
        // Se não encontrou, podemos criar
        ContainerAtividade::incluir(atividade);
    }
}

void CntrServViagem::visualizarAtividade(Codigo codigo, Atividade* atividade) {
    try {
        *atividade = ContainerAtividade::pesquisar(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

void CntrServViagem::atualizarAtividade(Atividade atividade) {
    try {
        // Verifica se a atividade existe antes de atualizar
        ContainerAtividade::pesquisar(atividade.getCodigo());
        ContainerAtividade::atualizar(atividade);
    } catch (invalid_argument& e) {
        throw invalid_argument("Atividade nao encontrada.");
    }
}

void CntrServViagem::excluirAtividade(Codigo codigo) {
    try {
        ContainerAtividade::remover(codigo);
    } catch (invalid_argument& e) {
        throw e;
    }
}

list<Atividade> CntrServViagem::listarAtividades() {
    return ContainerAtividade::getAtividades();
}

list<Atividade> CntrServViagem::listarAtividadesPorDestino(Codigo codigo) {
    return ContainerAtividade::getAtividadesPorDestino(codigo);
}

void CntrServViagem::validarDataAtividade(const Atividade& atividade, const Destino& destino) {
    string dataAtividade = atividade.getData().getValor();
    string dataInicio = destino.getDataInicio().getValor();
    string dataFim = destino.getDataTermino().getValor();

    // Como a data está no formato DD-MM-AA, podemos comparar as strings diretamente
    if (dataAtividade < dataInicio || dataAtividade > dataFim) {
        throw invalid_argument("A data da atividade deve estar dentro do periodo do destino.");
    }
}
