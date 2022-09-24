#include <fstream>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <string.h>


using namespace std;

// ======= Variaveis globais =======
const int maxrow = 12;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
int logado;



// ========= Funções ==========

void forgot()
// Função para recuoerar senha esquecida
{
        int ch;
        system("cls");
        cout<<"ESQUECEU? Nos estamos aqui para te ajudar\n";
        cout<<"[1] Procurar conta pelo nome de usuario"<<endl;
        cout<<"[2] Procurar conta pela senha"<<endl;
        cout<<"[3] Menu principal"<<endl;
        cout<<"Digite sua opção:";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nDigite seu nome de usiario :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nconta localizada\n";
                                cout<<"\nSua senha é: "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                //main();
                        }
                        else
                        {
                                cout<<"\nDesculpe, seu nome de usuario não foi localizado\n";
                                
                                cin.get();
                                cin.get();
                             //   main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nDigite sua senha:";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nSua senha  foi localizada\n";
                                cout<<"\nSeu usuario é : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                            //    main();
                        }
                        else
                        {
                                cout<<"Desculpe, senha não localizada \n";
                                
                                cin.get();
                                cin.get();
                            //    main();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                      //  main();
                }
                default:
                        cout<<"Opção invalida, tente novamente"<<endl;
                        forgot();
        }
  }
  //==============================

void login()
// validação de login
{
        int count;
        
        string user,pass,u,p;
        system("cls");
        cout<<"Digite seu login"<<endl;
        cout<<"USUARIO : ";
        cin>>user;
        cout<<"SENHA : ";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\n<LOGADO COM SUCESSO>\nOla  "<<user<<"!\n";
                cin.get();
                cin.get();
                logado = 1;
               //main();
               
        }
        else
        {
                cout<<"\nLOGIN INVALIDO \nPor favor, verifique seu nome de usuario ou senha\n";
                logado = 0;
             //   main();
        }
}
//===========================
void registr()
//cadastro de novo usuario
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Digite seu nome de usuario: ";
        cin>>reguser;
        cout<<"\nDigite sua senha:";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nCADASTRADO COM SUCESSO\n";
      //  main();
}
//=================================

void openFile()
// para salvar dados em um arquivo txt. (ainda nao esta funcionando 100%)
{
    string line;
    ifstream myfile("databases.txt");
    if (myfile.is_open())
    {
        int x = 0;
        while (getline(myfile, line))
        {
            EmpID[x] = line.substr(0, 3);
            EmpName[x] = line.substr(4, 1 - 4);
            x++;
        }
        
    }
    else
    {
        cout << "Impossivel abrir o arquivo txt" << endl;
    }
}

//=================================
void cadastrarF()
// função  para cadastrar novo funcionario
{
    char name[50];
    char empno[12];

    cin.ignore();

    cout << "CPF funcionario >> " << endl;
    cin.getline(empno, 12);
    cout << "Nome do funcionario >> " << endl;
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] == "\0")
        {
            EmpID[x] = empno;
            EmpName[x] = name;

            break;
        }
    }
}
//=================================

void alterarF(string buscar)
// função para alterar dados de funcionario ja cadastrado
{
    char name[50];
   // char empno[12];

    int contador = 0;
    
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == buscar)
        {
            contador++;

            cout << "Nome do funcionario >> ";
            cin.getline(name, 50);

            EmpName[x] = name;

            cout << "Alterado com sucesso!" << endl;
            break;

        }
    }

    if (contador == 0)
    {
        cout << "CPF não encontrado" << endl;

    }
}

//================================
void excluirF(string buscar)
// função para excluir funcionario do banco de dados
{
    int contador = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == buscar)
        {
            contador ++;

            EmpName[x] = "";
            EmpID[x] = "";

            cout << "Funcionario excluido com sucesso!" << endl;
            break;
        }
    }


    if (contador == 0)
    {
        cout << "CPF não encontrado! ";
    }
}

//===================================
void buscarF(string buscar)
// função para consultar um funcionario pelo CPF
{
    system("cls");
    cout << "Funcionarios cadastrados" << endl;
    cout << "==========================" << endl;
    int contador = 0;

    for (int x = 0; x < maxrow; x++)
    {
        
        if (EmpID[x] == buscar)
        {
            contador++;
            cout << "  " << contador << "    " << EmpID[x] << "      " << EmpName[x] << endl;
            break;
        }
    }
}


//=================================
void verTodosF()
// função para consultar todos os funcionarios cadastrados
{
    system("cls");
    cout << "      todos os funcionarios" << endl;
    cout << "=====================================" << endl;

    int contador = 0;
    cout << "ID. |      CPF      |        NOME           " << endl;
    cout << "---------------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] != "\0")
        {
            contador++;
            cout << "  " << contador << "    " << EmpID[x] << "      " << EmpName[x] << endl;

        }
    }

    if (contador == 0)
    {
        cout << "nenhum funcionario encontrado! " << endl;

    }

    cout << "---------------------------------------" << endl;

}

//==================================
void salvarF()
// função para salvar todas as alterações feitas (ainda não comsegui fazer funcionar 100%)
{
    ofstream myfile;
    myfile.open("databases.txt");

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            break;
        }
        else
        {
            myfile << EmpID[x] + "," + EmpName[x] << endl;
        }
    }
}
//==================================
void cadastrarC()
// funcao para cadastrar cliente
{
    char name[50];
    char empno[12];

    cin.ignore();

    cout << "CPF cliente>> " << endl;
    cin.getline(empno, 12);
    cout << "Nome do cliente >> " << endl;
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] == "\0")
        {
            EmpID[x] = empno;
            EmpName[x] = name;

            break;
        }
    }
}
//==================================
void alterarC(string buscar)
//funcao para alterar daodos de cliente
{
    char name[50];
    char empno[12];

    int contador = 0;
    
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == buscar)
        {
            contador++;

            cout << "Nome do Cliente >> ";
            cin.getline(name, 50);

            EmpName[x] = name;

            cout << "Alterado com sucesso!" << endl;
            break;

        }
    }

    if (contador == 0)
    {
        cout << "CPF não encontrado" << endl;

    }
}
//================================

void excluirC(string buscar)
//funcao para exluir clientes do banco de dados
{
    int contador = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == buscar)
        {
            contador ++;

            EmpName[x] = "";
            EmpID[x] = "";

            cout << "Cliente excluido com sucesso!" << endl;
            break;
        }
    }


    if (contador == 0)
    {
        cout << "CPF não encontrado! ";
    }
}
//=================================

void buscarC(string buscar)
// funcao para buscar clientes por cpf
{
    system("cls");
    cout << "Clientes  cadastrados" << endl;
    cout << "==========================" << endl;
    int contador = 0;

    for (int x = 0; x < maxrow; x++)
    {
        
        if (EmpID[x] == buscar)
        {
            contador++;
            cout << "  " << contador << "    " << EmpID[x] << "      " << EmpName[x] << endl;
            break;
        }
    }
}
//===============================

void verTodosC()
// funcao para ver todos os clientes cadastrados
{
    system("cls");
    cout << "      todos os clientes" << endl;
    cout << "=====================================" << endl;

    int contador = 0;
    cout << "ID. |      CPF      |        NOME           " << endl;
    cout << "-----------------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] != "\0")
        {
            contador++;
            cout << "  " << contador << "    " << EmpID[x] << "      " << EmpName[x] << endl;

        }
    }

    if (contador == 0)
    {
        cout << "nenhum funcionario encontrado! " << endl;

    }

    cout << "-----------------------------------------" << endl;

}


//=================================

// ========= codigo principal ==========
int main()
{
    std::cout << "MENU \n";
    string empID;
    system("cls");
    openFile();
    int choice;
    
    
// =========== Login ===============
    cout << "====================\n";
        cout << "     Bem vindo    \n";
        cout << "=====================\n\n";
        cout << "[1] LOGIN" << endl;
        cout <<"[2] CADASTRAR-SE"<<endl;
        cout<<"[3] ESQUECEU A SENHA?"<<endl;
        cout<<"[4] SAIR"<<endl;
        cout<<"\n";
        cout << "Escolha uma opcao >> ";
        cin>>choice;
        cout<<endl;
    
    switch(choice)
        {
                case 1:
                        login();
                        system("cls");
                       
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        system("cls");
                        main();
                        break;
                case 4:

                        cout<<"Obrigado por usar nosso programa \n\n";
                        break;
                default:
                        system("cls");
                        cout<<"Opção invalida, tente novamente..\n"<<endl;
                        main();
        }
        
    // ========= Menu principal ==========
        if (logado == 0)
        {
        	//se entrar com longin invalido
        cout << "login invalido... tente novamente\n";
        main();
        
        }
        if (logado == 1)
        {
        //se logar com sucesso
        int opcaoF;
         int opcaoC;
    	string empID;
    	system("cls");
        int opcao;
        cout << "=================================\n";
        cout << "           EMPRESA X   \n";
        cout << "=================================\n\n";
        cout << "[1] CLIENTES ";
        cout <<"   [2] FUNCIONARIOS"<<endl;
        cout << "\n\n";
        cout << " Escolha uma opcao >>  " ;
        cin >> opcao;
        	
        switch(opcao)
        {
        	case 1:
        	//menu crud clientes
        	//==============================
        		system("cls");
        		 
        		do {
        			cout << "=================================\n";
        cout << "           EMPRESA X   \n";
        cout << "=================================\n\n";
    cout << "[1] cadastrar Clientes " << endl;
    cout << "[2] alterar clientes" << endl;
    cout << "[3] excluir clientes" << endl;
    cout << "[4] buscar clientes" << endl;
    cout << "[5] ver todos " << endl;
    cout << "[6] sair e salvar " << endl;
    cout << "==========================" << endl;

    cout << "selecione sua opcao  >> " << endl;
    cin >> opcaoC;

    switch (opcaoC)
    {
    case 1: 
        cadastrarC();
        system("cls");
        break;
    case 2:
        cin.ignore();
        cout << "buscar por CPF >> ";
        getline(cin, empID);
        alterarC(empID);
        break;
    case 3:
        cin.ignore();
        cout << "Excluir pelo CPF >> ";
        getline(cin, empID);
        excluirC(empID);
        cin.ignore();
        system("cls");
        break;
    case 4:
        cin.ignore();
        cout << "buscar por CPF >> ";
        getline(cin, empID);
        buscarC(empID);
        break;
    case 5:
        verTodosC();
        break;
    case 6:
        cout << "Saindo... salvando arquivo!" << endl;
        system("cls");
       cout << "obrigado por usar nosso sistema! \n\n";
        cout << "-------------------------------\n";
        cout << "          feito por \n \n ";
        cout << "       Kaique Miranda\n";
        cout << "---------------------------------\n";
        break;
    
    default:
        break;
    }

    } while (opcaoC != 6);
        	break;
        	//===========================
        	case 2:
        	// menu crud funcionarios
        		system("cls");
        		do {
    cout << "=================================\n";
        cout << "           EMPRESA X   \n";
        cout << "=================================\n\n";

    cout << "[1] cadastrar funcionario " << endl;
    cout << "[2] alterar funcionario" << endl;
    cout << "[3] excluir funcionario" << endl;
    cout << "[4] buscar funcionario" << endl;
    cout << "[5] ver todos " << endl;
    cout << "[6] sair e salvar " << endl;
    cout << "==========================" << endl;

    cout << "selecione sua opcao  >> " << endl;
    cin >> opcaoF;

    switch (opcaoF)
    {
    case 1: 
        cadastrarF();
        system("cls");
        break;
    case 2:
        cin.ignore();
        cout << "buscar por CPF >> ";
        getline(cin, empID);
        alterarF(empID);
        break;
    case 3:
        cin.ignore();
        cout << "Excluir pelo CPF >> ";
        getline(cin, empID);
        excluirF(empID);
        cin.ignore();
        system("cls");
        break;
    case 4:
        cin.ignore();
        cout << "buscar por CPF >> ";
        getline(cin, empID);
        buscarF(empID);
        break;
    case 5:
        verTodosF();
        break;
    case 6:
        cout << "salvar e sair...." << endl;
        system("cls");
        cout << "obrigado por usar nosso sistema! \n\n";
        cout << "----------------------------------------\n";
        cout << "          feito por \n \n ";
        cout << "     Kaique Miranda\n";
        cout << "------------------------------------------\n";
        break;
    
    default:
        break;
    }

    } while (opcaoF != 6);
        	break;
        }
      
        }
        	
        
        
                     
     return 0;
    
 }

    
   
