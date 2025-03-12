#include <stdexcept>
#include <iostream>
#include <string>
#include "controladoras.h"
#include <cstdlib>

using namespace std;

int main()
{
    Codigo codigo;
    int resposta;
    while(true){
        cout << endl << "=========================================================" << endl;
        cout << "|    Bem vindo ao SISTEMA DE GERENCIAMENTO DE VIAGEM    |";
        cout << endl << "=========================================================" << endl;
        cout << endl << "O que gostaria de fazer?" << endl << endl;
        cout << " 1. Autenticar" << endl;
        cout << " 2. Conta" << endl;
        cout << " 3. Menu Viagens" << endl;
        cout << " 4. Sair" << endl << endl;
        cout << " Digite um numero : ";
        cin >> resposta;
        cout << endl;

        if (resposta == 1){
            system("cls");

            IntAprAutenticacao *cntrIntAprAutenticacao = new CntrIntAprAutenticacao();
            bool resultado;
            while(true){
                try{
                    resultado = cntrIntAprAutenticacao->autenticar(&codigo);
                }
                catch(const runtime_error &exp){
                    cout << endl << "                                         Erro de sistema." << endl;
                    break;
                }
                if (resultado){
                    cout << endl << "                                     Sucesso autenticacao" << endl;
                    cout << endl << "                                          Codigo : " << codigo.getValor() << endl;
                    break;
                }
                else {
                    cout << endl << "                                       Erro autenticacao." << endl;
                    break;
                }
            }

            delete cntrIntAprAutenticacao;
        }

        else if (resposta == 2){
            system("cls");
            cout << endl << "==================== Opcoes da Conta ====================" << endl;

            IntAprConta *cntrIntAprConta = new CntrIntAprConta();
            bool resultado;
            while(true){
                cout << endl << "1. Criar" << endl;
                cout << "2. Executar" << endl;
                cout << "3. Sair" << endl << endl;
                cout << "Digite um numero : ";
                cin >> resposta;
                cout << endl;

                if (resposta == 1){
                    try{
                        cntrIntAprConta->criar();
                        break;
                    }
                    catch(const runtime_error &exp){
                        cout << endl << "                                         Erro de sistema." << endl;
                        break;
                    }
                }

                else if (resposta == 2) {

                    try{
                        resultado = cntrIntAprConta->executar(codigo);
                    }

                    catch(const runtime_error &exp){
                        cout << endl << "                                         Erro de sistema." << endl;
                        break;
                    }

                    if (resultado){
                        cout << endl << "                                         Sucesso execucao" << endl;
                        break;
                    }

                    else {
                        cout << endl << "                                           Erro execucao." << endl;
                        break;
                    }
                }

                else if (resposta == 3){
                    break;
                }

                else{
                    cout << endl <<"                                            Numero errado" << endl << endl;
                }

            }

        }
        else if (resposta == 3){
            system("cls");
            cout << endl << "=========================================================" << endl;
            cout << "|            GERENCIAMENTO DE VIAGEM                    |";
            cout << endl << "=========================================================" << endl;

            // Create instances of controllers
            CntrServViagem* cntrServViagem = new CntrServViagem();
            CntrApresentacaoViagem* cntrApresentacaoViagem = new CntrApresentacaoViagem();
            CntrIntAprAutenticacao* cntrAprAutenticacao = new CntrIntAprAutenticacao();
            IntServAutenticacao* cntrServAutenticacao = CntrIntServAutenticacao::getInstancia();

            // Connect controllers
            cntrApresentacaoViagem->setCntrServViagem(cntrServViagem);
            cntrAprAutenticacao->setCntrIntServAutenticacao(cntrServAutenticacao);

            // Authenticate user
            Codigo codigoUsuario;
            if(cntrAprAutenticacao->autenticar(&codigoUsuario)) {
                // Execute travel management
                cntrApresentacaoViagem->executar(codigoUsuario);
            } else {
                cout << "Falha na autenticação." << endl;
            }

            // Cleanup
            delete cntrServViagem;
            delete cntrApresentacaoViagem;
            delete cntrAprAutenticacao;

            return 0;
        }

        else if (resposta == 4){
                system("cls");
                cout << endl << "=========================================================" << endl;
                cout << endl << "                  Programa encerrado" << endl ;
                cout  << "                Agradecemos pelo acesso " << endl ;
                cout << endl << "=========================================================" << endl;
                break;
        }

        else{
            cout << endl << "                                            Numero errado" << endl << endl;
        }
    }

    return 0;
}
