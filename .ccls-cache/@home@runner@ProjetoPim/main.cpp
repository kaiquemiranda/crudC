
#include <fstream>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

// ======= Variaveis globais =======
const int maxrow = 1000;
int EmpTamN[maxrow] = {};
string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
string EmpNameC[maxrow] = {};
string EmpCPF[maxrow] = {};
string EmpTel[maxrow] = {};
string EmpCargo[maxrow] = {};
string EmpSalario[maxrow] = {};
string salario, funcao;
int folhaPagamento;
int logado;

// ========= Funções ==========

//====== FUNCOES DO LOGIN ========
//================================
void esqueceu()
// Função para recuperar senha esquecida
{
	int ch;
	system("cls");
	cout << "ESQUECEU? Nos estamos aqui para te ajudar\n\n";
	cout << "[1] Procurar conta pelo nome de usuario" << endl;
	cout << "[2] Procurar conta pela senha" << endl;
	cout << "[3] Menu principal\n" << endl;
	cout << "Digite sua opção >> ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		int count = 0;
		string searchuser, su, sp;
		cout << "\nDigite seu nome de usiario >> ";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				count = 1;
			}
		}
		searchu.close();
		if (count == 1)
		{
			cout << "\n\nconta localizada\n";
			cout << "\nSua senha é: " << sp;
			cin.get();
			cin.get();
			system("cls");
			//main();
		}
		else
		{
			cout << "\nDesculpe, seu nome de usuario não foi localizado\n";

			cin.get();
			cin.get();
			//   main();
		}
		break;
	}
	case 2:
	{
		int count = 0;
		string searchpass, su2, sp2;
		cout << "\nDigite sua senha:";
		cin >> searchpass;

		ifstream searchp("database.txt");
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				count = 1;
			}
		}
		searchp.close();
		if (count == 1)
		{
			cout << "\nSua senha  foi localizada\n";
			cout << "\nSeu usuario é : " << su2;
			cin.get();
			cin.get();
			system("cls");
			//    main();
		}
		else
		{
			cout << "Desculpe, senha não localizada \n";

			cin.get();
			cin.get();
			//main();
		}

		break;
	}

	case 3:
	{
		cin.get();
        break;
	}
	default:
		cout << "Opção invalida, tente novamente" << endl;
		esqueceu();
	}
}
//==============================
void login()
// validação de login
{
	int count;

	string user, pass, u, p;
	system("cls");
	cout << "===================\n";
	cout << "  Digite seu login" << endl;
	cout << "===================\n";
	cout << "  USUARIO >> ";
	cin >> user;
	cout << "\n\n  SENHA >> ";
	cin >> pass;
	ifstream input("database.txt");
	while (input >> u >> p)
	{
		if (u == user && p == pass)

		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\n\n       <LOGADO COM SUCESSO>\n\n        Ola " << user << "!\n";
		cin.get();
		cin.get();
		logado = 1;
		//main();
	}
	else
	{
		logado = 0;
		//  main();
	}
}

//===========================
void registr()
//cadastro de novo usuario
{
	string reguser, regpass, ru, rp;
	system("cls");
	cout << "Digite seu nome de usuario: ";
	cin >> reguser;
	cout << "\nDigite sua senha:";
	cin >> regpass;

	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	system("cls");
	cout << "\nCADASTRADO COM SUCESSO\n";
	Sleep(2000);
//	  main();
}
//===================================
//======FUNCOES FUNCIONARIOS========
void openFile()
// para salvar dados em um arquivo txt. (ainda nao esta funcionando 100%)
{
	string line;
	ifstream myfile("funcionarios.txt");
	if (myfile.is_open())
	{
		int x = 0;
		while (getline(myfile, line))
		{
			EmpID[x] = line.substr(0, 3);
			EmpCargo[x] = line.substr(3, 18);
			if(EmpCargo[x] == "programador junior")
            {
                folhaPagamento += 3500;
            }
            if(EmpCargo[x] == "programador pleno ")
            {
                folhaPagamento += 5500;
            }
            if(EmpCargo[x] == "programador senior")
            {
                folhaPagamento += 8000;
            }
			EmpSalario[x] = line.substr(21, 8);
			EmpName[x] = line.substr(29, 25);
			x++;
		}
	}
}
//=================================
void cadastrarF()
// função  para cadastrar novo funcionario
{
	char name[50];
	char empno[12];
	char cargo[50];
	char salario[50];
	cin.ignore();

	cout << "ID funcionario >> " << endl;
	cin.getline(empno, 12);
	cout << "Nome do funcionario >> " << endl;
	cin.getline(name, 50);
	cout << "Função do colaborador " << endl;
	cout << "[1] programador junior " << endl;
	cout << "[2] programador pleno " << endl;
	cout << "[3] programador senior " << endl;
	cin.getline(cargo, 50);

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == "\0")
		{
			EmpID[x] = empno;
			EmpName[x] = name;
			EmpCargo[x] = cargo;
			EmpSalario[x] = salario;
			EmpTamN[x] = strlen(name);

			if (EmpCargo[x] == "1")
			{
				folhaPagamento += 3500;
				EmpSalario[x] = "R$ 3,500";
				EmpCargo[x] = "programador junior";
			}
			else if (EmpCargo[x] == "2")
			{
				folhaPagamento += 5500;
				EmpSalario[x] = "R$ 5,500";
				EmpCargo[x] = "programador pleno ";
			}
			else if (EmpCargo[x] == "3")
			{
				folhaPagamento += 8000;
				EmpSalario[x] = "R$ 8,000";
				EmpCargo[x] = "programador senior";
			}
			else
			{
				cout << "Digite um cargo valido! ";
				Sleep(2000);
				cadastrarF();
			}

			cout << "Cadastrado com sucesso!\n";

			break;
		}
	}
}
//=================================

void alterarF(string buscar)
// função para alterar dados de funcionario ja cadastrado
{
	char name[50];
	char empno[12];
	char cargo[50];
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
			Sleep(2000);
			system("cls");
			break;
		}
	}

	if (contador == 0)
	{
		cout << "Funcionario não encontrado" << endl;
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
			if(EmpCargo[x] == "programador junior")
			{
				folhaPagamento -= 3500;
			}
			else if(EmpCargo[x] == "programador pleno ")
			{
				folhaPagamento -= 5500;
			}
			else if(EmpCargo[x] == "programador senior")
			{
				folhaPagamento -= 8000;
			}
			contador++;
			EmpName[x] = "";
			EmpID[x] = "";
			EmpCargo[x] = "";
			EmpSalario[x] = "";

			cout << "Funcionario excluido com sucesso!" << endl;
			break;
		}
	}

	if (contador == 0)
	{
		cout << "Funcionario não encontrado! ";
	}
}

//===================================
void buscarF(string buscar)
// função para consultar um funcionario pelo CPF
{
	system("cls");
	cout << "		Buscar funcionarios" << endl;
	cout << "==================================================================" << endl;
	cout << " ID |       FUNÇÃO          |  SALARIO  |    COLABORADOR   " << endl;
	cout << "------------------------------------------------------------------\n";
	int contador = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == buscar)
		{
			contador++;
			cout << EmpID[x];
			cout << "   " << EmpCargo[x];
			cout << "      " << EmpSalario[x];
			cout << "    " << EmpName[x] << endl;
			break;
		}
	}
	cout << "------------------------------------------------------------------" << endl;
}

//=================================
void verTodosF()
// função para consultar todos os funcionarios cadastrados
{
	string espaco = "\t";
	system("cls");
	int contador = 0;
	cout << "		todos os funcionarios" << endl;
	cout << "==================================================================" << endl;
	cout << " ID |       FUNÇÃO          |  SALARIO  |    COLABORADOR   " << endl;
	cout << "------------------------------------------------------------------\n";
	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] != "\0")
		{
			contador++;
			if (EmpCargo[x] == "1")
			{
				funcao = "programador junior";
				salario = "R$ 3,500 ";
			}
			else if (EmpCargo[x] == "2")
			{
				funcao = "programador pleno";
				salario = "R$ 5,500 ";
			}
			else if (EmpCargo[x] == "3")
			{
				funcao = "programador senior";
				salario = "R$ 8,000 ";
			}
			else
            {

            }
				cout << EmpID[x] ;
                cout << "   " << EmpCargo[x];
                cout << "      " << EmpSalario[x];
                cout << "    " << EmpName[x] << endl;

		}
	}
	if (contador == 0)
	{

		cout << "nenhum funcionario encontrado! " << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
}
//==================================
void salvarF()
// função para salvar todas as alterações feitas (ainda não comsegui fazer funcionar 100%)
{
	ofstream myfile;
	myfile.open("funcionarios.txt");

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == "\0")
		{
			break;
		}
		else
		{
			myfile << EmpID[x];
			myfile << EmpCargo[x];
            myfile << EmpSalario[x];
            myfile << EmpName[x] << endl;
		}
	}
myfile.close();
}
//===================================
//======FUNCOES CLIENTES============
void cadastrarC()
// funcao para cadastrar cliente
{
	char name[50];
	char empno[12];
	char telefone[30];
	cin.ignore();

	cout << "CPF cliente >> " << endl;
	cin.getline(empno, 12);
	cout << "Telefone do cliente  >> " << endl;
	cin.getline(telefone, 30);
	cout << "Nome do cliente >> " << endl;
	cin.getline(name, 50);

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpCPF[x] == "\0")
		{
			EmpCPF[x] = empno;
			EmpNameC[x] = name;
			EmpTel[x] = telefone;
			break;
		}
	}
}
//==================================

void openFileC()
// para salvar dados em um arquivo txt. (ainda nao esta funcionando 100%)
{
	string line;
	ifstream myfileC("clientes.txt");
	if (myfileC.is_open())
	{
		int x = 0;
		while (getline(myfileC, line))
		{
			EmpCPF[x] = line.substr(0, 11);
			EmpTel[x] = line.substr(11, 13);
			EmpNameC[x] = line.substr(24, 20);

			x++;
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
		if (EmpCPF[x] == buscar)
		{
			contador++;

			cout << "Nome do Cliente >> ";
			cin.getline(name, 50);

			EmpNameC[x] = name;

			cout << "Alterado com sucesso!" << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	}

	if (contador == 0)
	{
		cout << "ID não encontrado" << endl;
	}
}
//================================

void excluirC(string buscar)
//funcao para exluir clientes do banco de dados
{
	int contador = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpCPF[x] == buscar)
		{
			contador++;

			EmpNameC[x] = "";
			EmpCPF[x] = "";
			EmpTel[x] = "";

			cout << "Cliente excluido com sucesso!" << endl;
			break;
		}
	}

	if (contador == 0)
	{
		cout << "ID não encontrado! ";
	}
}
//=================================

void buscarC(string buscar)
// funcao para buscar clientes por cpf
{
	system("cls");
	cout << "		Buscar clinte" << endl;
	cout << "===================================================================" << endl;
	cout << "ID |      CPF       |     TELEFONE      |         NOME       " << endl;
	cout << "-------------------------------------------------------------------\n";
	int contador = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpCPF[x] == buscar)
		{
			contador++;
			cout << " " << contador;
			if (contador >= 10)
			{
				cout << "   ";
			}
			else
			{
				cout << "      ";
			}
			cout << EmpCPF[x];
			cout << "       " << EmpTel[x];
			cout << "        " << EmpNameC[x] << endl;

			break;
		}
	}
	cout << "-------------------------------------------------------------------" << endl;
}
//===============================

void verTodosC()
// funcao para ver todos os clientes cadastrados
{
	system("cls");
	string espace;
	int contador = 0;
	cout << "      todos os clientes" << endl;
	cout << "===================================================================" << endl;
	cout << "ID |  ""    CPF       |     TELEFONE      |         NOME       " << endl;
	cout << "-------------------------------------------------------------------\n";
	for (int x = 0; x < maxrow; x++)
	{
		if (EmpCPF[x] != "\0")
		{
			contador++;
			espace = '\t';
			cout << " " << contador;
			if (contador >= 10)
			{
				cout << "   ";
			}
			else
			{
				cout << "    ";
			}
			cout << EmpCPF[x];
			cout << "       " << EmpTel[x];
			cout << "        " << EmpNameC[x] << endl;
		}
	}

	if (contador == 0)
	{
		cout << "nenhum funcionario encontrado! " << endl;
	}

	cout << "-------------------------------------------------------------------" << endl;
}

void salvarC()
// função para salvar todas as alterações feitas (ainda não comsegui fazer funcionar 100%)
{
	ofstream myfileC;
	myfileC.open("clientes.txt");

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpCPF[x] == "\0")
		{
			break;
		}
		else
		{
			myfileC << EmpCPF[x] << EmpTel[x] << EmpNameC[x] << endl;
		}
	}
	myfileC.close();
}
//==================================
//==================================
// ========= codigo principal ==========
int main()
{
    setlocale(LC_ALL, "Portuguese");
	std::cout << "MENU \n";
	string empID;
	system("cls");
	openFile();
	openFileC();
	int choice;
	string tab = "\t";
	string cifrao = " R$ ";
	system("color 03");

	// =========== Login ===============
	cout << "========================\n";
	cout << "      START INVEST  \n";
	cout << "========================\n";
	cout << "========================\n";
	cout << " LOGIN  |  CADASTRAR-SE    \n";
	cout << "========================\n\n";
	cout << " [1] LOGIN" << endl;
	cout << " [2] CADASTRAR-SE" << endl;
	cout << " [3] ESQUECEU A SENHA?" << endl;
	cout << " [4] SAIR" << endl;
	cout << "\n";
	cout << " Escolha uma opcao >> ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		login();
		system("cls");
		break;
	case 2:
		registr();
		break;
	case 3:
		esqueceu();
		system("cls");
		main();
		break;
	case 4:
		logado = 3;
		break;
	default:
		system("cls");
	    system("color 04");
		cout << "\n     OPÇÃO INVALIDA \n     Digite uma opçao valida!";
		Sleep(2000);
		system("color 03");
		main();
	}

	// ========= Menu principal ==========
	if (logado == 0)
	{
		//se entrar com longin invalido
		system("color 04");
		cout << "\n\n       login invalido... tente novamente\n";
		Sleep(2000);
		system("color 03");
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
		cout << "         START INVEST   \n";
		cout << "=================================\n\n";
		cout << " [1] CLIENTES ";
		cout << "   [2] COLABORADORES" << endl;
		cout << "\n\n";
		cout << " Escolha uma opcao >>  ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			//menu crud clientes
			//==============================
			system("cls");

			do
			{
				cout << "=================================\n";
				cout << "          START INVEST   \n";
				cout << "=================================\n\n";
				cout << "=================================\n";
				cout << "          CLIENTES   \n";
				cout << "=================================\n\n";
				cout << " [1] cadastrar Cliente" << endl;
				cout << " [2] alterar clientes" << endl;
				cout << " [3] excluir cliente " << endl;
				cout << " [4] buscar cliente" << endl;
				cout << " [5] ver todos " << endl;
				cout << " [6] sair e salvar " << endl;
				cout << "==================================          by  kaique miranda © " << endl;
				cout << " selecione sua opcao  >>  ";
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
					system("cls");
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
					salvarC();
					cout << "Saindo... salvando arquivo!" << endl;
					Sleep(2000);
					system("cls");
					break;

				default:
					system("cls");
					system("color 04");
					cout << "Digite uma opcao valida!\n\n";
					Sleep(2000);
					system("color 03");
					opcaoC = 1;
					break;
				}

			} while (opcaoC != 6);
			break;
		//===========================
		case 2:
			// menu crud funcionarios
			system("cls");
			do
			{
				cout << "=================================\n";
				cout << "          START INVEST   \n";
				cout << "=================================\n\n";
				cout << "=================================\n";
				cout << "      COLABORADORES   \n";
				cout << "=================================\n\n";

				cout << " [1] cadastrar funcionario " << endl;
				cout << " [2] alterar funcionario" << endl;
				cout << " [3] excluir funcionario" << endl;
				cout << " [4] buscar funcionario" << endl;
				cout << " [5] ver todos " << endl;
				cout << " [6] folha de pagamento " << endl;
				cout << " [7] salvar e sair" << endl;
				cout << "==================================          by  kaique miranda © " << endl;
				cout << " selecione sua opcao  >>  ";
				cin >> opcaoF;

				switch (opcaoF)
				{
				case 1:
					cadastrarF();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout << "Buscar por ID >> ";
					getline(cin, empID);
					alterarF(empID);
					break;
				case 3:
					cin.ignore();
					cout << "Excluir pelo ID >> ";
					getline(cin, empID);
					excluirF(empID);
					cin.ignore();
					system("cls");
					break;
				case 4:
					cin.ignore();
					cout << "Buscar por ID >> ";
					getline(cin, empID);
					buscarF(empID);
					break;
				case 5:
					verTodosF();
					break;
				case 6:
					cin.ignore();
					int continua;
					cout << "===========================" << endl;
					cout << "     folha salarial" << endl;
					cout << "--------------------------" << endl;
					cout << tab << cifrao << folhaPagamento << endl;
					cout << "---------------------------" << endl;
					cout << "deseja voltar ao menu ?" << endl;
					cout << "[1] sim   |    [2]  não " << endl;
					cout << " \ndigite sua opcao >> ";
					cin >> continua;
					if (continua == 1)
					{
						system("cls");
						break;
					}
					else
					{
						system("cls");
						opcaoF = 7;
					}
					break;
				case 7:
					salvarF();
					cout << "Saindo... salvando arquivo!" << endl;
					Sleep(2000);
					system("cls");
					break;

				default:
					system("cls");
					system("color 04");
					cout << "Digite uma opcao valida!\n\n";
					Sleep(2000);
					system("color 03");
					opcaoF = 1;
					break;
				}

			} while (opcaoF != 7);
			break;
        default:
            system("cls");
            system("color 04");
            cout << "\n\n       Digite uma opçao valida! ";
            Sleep(2000);
            system("color 03");
            main();
            break;

		}
	}
	system("cls");
	cout << "\n\n=================================";
	cout << "\n obrigado por usar nosso sistema! \n";
	cout << "=================================\n\n";
	cout << "---------------------------------\n";
	cout << "          feito por \n \n ";
	cout << "      Kaique Miranda      ©\n";
	cout << "---------------------------------\n";
	cout << "       Rodrigo costa       ©\n";
	cout << "---------------------------------\n";
	cout << "       Wellington Vinicius ©\n";
	cout << "---------------------------------\n\n\n\n\n\n";




	return 0;
}
