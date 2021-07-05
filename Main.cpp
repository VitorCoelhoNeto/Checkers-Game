#include <iostream>
#include <string>
#include <fstream>
#include "Tabuleiro.h"
#include "Ponto.h"
#include "Jogador.h"
#include "Main.h"
#include <tuple>
//#include <MMsystem.h>
using namespace std;

int main()
{
	int opcao;
	cout << "\t\t\t JOGO DAS DAMAS" << endl << endl << endl << "\t\t        Escolha uma opcao" << endl << endl << "\t\t1.Comecar novo jogo" << endl << "\t\t2.Carregar jogo existente" << endl << "\t\t3.Ajuda" << endl << "\t\t4.Sair" << endl << endl << "\t\t\t\t\t � Vitor Neto 2019" << endl;
	cin >> opcao;
	Tabuleiro tabuleiro;

	if (opcao == 1) {

		//PlaySound(TEXT("C:\Users\Utilizador\OneDrive\Ambiente de Trabalho\song.mp3"), NULL, SND_SYNC);
		
		system("cls");

		string nome;

		int pecas1;
		int pecas2;

		cout << "Nome Jogador 1:" << endl;
		cin >> nome;
		Jogador Jogador1(nome);
		cout << "Nome Jogador 2:" << endl;
		cin >> nome;
		Jogador Jogador2(nome);
		system("cls");

		

		Tabuleiro tabuleiro;

		pecas1 = Jogador1.Get_Pecas();
		pecas2 = Jogador2.Get_Pecas();
		
		tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
		while (pecas1 > 0 || pecas2 > 0)
		{
			cout << "E a vez do jogador " << Jogador1.Get_nome() << "(brancas)" << endl;
			pecas2 = tabuleiro.jogadaBrancas(pecas2);
			tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
			cout << "E a vez do jogador " << Jogador2.Get_nome() << "(pretas)" << endl;
			pecas1 = tabuleiro.jogadaPretas(pecas1);
			tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
			tabuleiro.Guardar(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
		}

		return 0;

		system("pause");
		return 0;
	}
	else {
		if (opcao == 2) {
			
			system("cls");
			
			
			string nome1, nome2;
			int pecas1 = 12;
			int pecas2 = 12;
			
			tabuleiro.Carregar(&nome1, &nome2);
			
			Jogador Jogador1(nome1);
			Jogador Jogador2(nome2);
			
			tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);

			
			while (pecas1 > 0 || pecas2 > 0)
			{
				cout << "E a vez do jogador " << Jogador1.Get_nome() << "(brancas)" << endl;
				pecas2 = tabuleiro.jogadaBrancas(pecas2);
				tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
				cout << "E a vez do jogador " << Jogador2.Get_nome() << "(pretas)" << endl;
				pecas1 = tabuleiro.jogadaPretas(pecas1);
				tabuleiro.MostraTabuleiro(Jogador1.Get_nome(), pecas1, Jogador2.Get_nome(), pecas2);
			}
		
			system("pause");
			return 0;

		}

		else {
			if (opcao == 3) {
				system("cls");
				cout << "Jogo das damas Regras:" << endl << "1. PREF�CIOAs  REGRAS  DO  JOGO  DE  DAMAS  CL�SSICAS,  a  aplicar no  Territ�rio  Nacional,s�o insuscept�veis de abranger todas as situa��es envolvidas no jogo pr�tico. Assim, quando -em  competi��o  oficial  ou  oficializada-surgirem  situa��es  e  casos  n�o regulamentados pelos artigos das Regras, deve-se procurar alcan�aras decis�es mais adequadas,  por  paralelismo  e  confronto  sensato  com  circunst�ncias  an�logas  que sejam  definidas  pelas  Regras,pressupondo-se  que  os  �rbitros  e  directores  de  prova possuem capacidade de julgamento e de arbitragem, bem como de objectividade.2. DEFINI��ES E CARACTER�STICAS 2.1 NOMENCLATURA DO TABULEIRO 2.1.1 O jogo  de  damas �  disputado  entre  dois  advers�rios  que movem pe�as  (pe�es oudamas) num tabuleiro quadrado denominado �tabuleiro de damas�. 2.1.2O �tabuleiro de damas�� composto poruma rede de 8 (oito) colunas horizontais e  8  (oito)colunas  verticais  que  formam  64  (sessenta  e  quatro)  quadrados  iguais,alternadamenteclaros  (preferencialmente  brancos  ou  castanhosclaros)  e  escuros (preferencialmente pretos ou castanhos escuros). 2.1.3Os   quadrados   escuros -denominados �casas�-correspondem   auma numera��ode 1 a 32, com in�cio na primeira casa inferior direita, seguindoa contagem da direita para a esquerda e de baixo para cima, sempre do lado onde seencontramas brancas.(Diagrama 1)" << endl;
				system("pause");
				system("cls");
				main();
				system("pause");
				return 0;
			}

			else {
				if (opcao == 4) {
					return 0;
				}
				else {
					cout << "Opcao nao valida" << endl;
					system("pause");
					system("cls");

					main();
					system("pause");
					return 0;

				}
			}
		}
	}
}