#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Tabuleiro {
public: 
	
	Tabuleiro();
	
	~Tabuleiro();
	char Tab[10][10] = {
		{'-','-','-','-','-','-','-','-','-','-'},
			{'-' ,'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ','-'},
			{ '-',' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X','-' },
			{ '-','X', ' ', 'X', ' ', 'X', ' ', 'X', ' ','-' },
			{ '-',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','-' },
			{ '-',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','-' },
			{ '-',' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O','-' },
			{ '-','O', ' ', 'O', ' ', 'O', ' ', 'O', ' ','-' },
			{ '-',' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O','-' },
		{'-','-','-','-','-','-','-','-','-','-'},
	};
	void MostraTabuleiro(string nome1, int pecas1, string nome2, int pecas2);
	void Guardar(string nome1, int pecas1, string nome2, int pecas2);



	void Carregar(string *nome, string* _nome);
	
	int jogadaBrancas(int pecas)
	{
		int a, b, c, d;
		char mov, captura;
		bool capturavalida = false;
		bool pecavalida = false;
		bool posicaovalida = false;
		int posicaoxcapturar = 0;
		int posicaoycapturar = 0;
		bool capturaresquerda = false;
		bool capturardireita = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Tab[i][j] == 'O' && Tab[i - 1][j - 1] == 'X' && Tab[i - 2][j - 2] == ' ')
				{
					posicaoxcapturar = i;
					posicaoycapturar = j;
					capturaresquerda = true;
					//capturardireita = false;
				}
				if (Tab[i][j] == 'O' && Tab[i - 1][j + 1] == 'X' && Tab[i - 2][j + 2] == ' ')
				{
					posicaoxcapturar = i;
					posicaoycapturar = j;
					//capturaresquerda = false;
					capturardireita = true;
				}
			}
		}

		if (capturaresquerda || capturardireita)
		{
			if (capturaresquerda && capturardireita)
			{
				do
				{
					cout << "Pretende capturar Esquerda(E) ou Direita(D)? " << endl;
					cin >> captura;

					if (captura == 'E' || captura == 'D' || captura == 'e' || captura == 'd')
					{
						if (captura == 'E' || captura == 'e')
						{
							cout << "A pega na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " vai capturar a peca na posicao " <<
								posicaoxcapturar - 1 << " " << posicaoycapturar - 1 << endl;
							Tab[posicaoxcapturar][posicaoycapturar] = ' ';
							Tab[posicaoxcapturar - 1][posicaoycapturar - 1] = ' ';
							Tab[posicaoxcapturar - 2][posicaoycapturar - 2] = 'O';
							pecas--;

							Sleep(5000);
							system("cls");
							capturavalida = true;



						}
						else
						{
							cout << "A pega na posicao: " << posicaoxcapturar << " " << posicaoycapturar - 2 << " vai capturar a peca na posicao " <<
								posicaoxcapturar - 1 << " " << posicaoycapturar - 1 << endl;
							Tab[posicaoxcapturar][posicaoycapturar - 2] = ' ';
							Tab[posicaoxcapturar - 1][posicaoycapturar - 1] = ' ';
							Tab[posicaoxcapturar - 2][posicaoycapturar] = 'O';
							pecas--;

							Sleep(5000);
							system("cls");
							capturavalida = true;

						}

					}
					else
					{
						cout << "O movimento inserido não é valido. " << endl;
					}
				} while (!capturavalida);

			}
			else
			{
				if (capturaresquerda)
				{
					cout << "Obrigatorio Capturar Esquerda" << endl;
					cout << "A peca na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " tem de capturar a peca na posicao " <<
						posicaoxcapturar - 1 << " " << posicaoycapturar - 1 << endl;
					Tab[posicaoxcapturar][posicaoycapturar] = ' ';
					Tab[posicaoxcapturar - 1][posicaoycapturar - 1] = ' ';
					Tab[posicaoxcapturar - 2][posicaoycapturar - 2] = 'O';
					pecas--;

					Sleep(5000);
					system("cls");
				}
				else
				{
					cout << "Obrigatorio Capturar Direita" << endl;
					cout << "A peca na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " tem de capturar a peca na posicao " <<
						posicaoxcapturar - 1 << " " << posicaoycapturar + 1 << endl;

					Tab[posicaoxcapturar][posicaoycapturar] = ' ';
					Tab[posicaoxcapturar - 1][posicaoycapturar + 1] = ' ';
					Tab[posicaoxcapturar - 2][posicaoycapturar + 2] = 'O';
					pecas--;
					Sleep(5000);
					system("cls");

				}
			}



		}
		else
		{
			do
			{
				cout << "Qual a peca que quer mover:" << endl;
				cin >> a >> b;
				//a=a-1;
				//b=b-1;
				if ((Tab[a][b] == 'O') && (Tab[a - 1][b - 1] == ' ' || Tab[a - 1][b + 1] == ' '))
				{
					pecavalida = true;

				}
				else { cout << "Essa posicao nao e valida" << endl; }
			} while (!pecavalida);
			Tab[a][b] = ' ';
			if (Tab[a - 1][b - 1] == ' ' && Tab[a - 1][b + 1] == ' ')
			{
				do
				{
					cout << "Pretende mover Esquerda(E) ou Direita(D)? " << endl;
					cin >> mov;

					if (mov == 'E' || mov == 'D' || mov == 'e' || mov == 'd')
					{
						if (mov == 'E' || mov == 'e')
						{
							Tab[a - 1][b - 1] = 'O';
							posicaovalida = true;
							system("cls");
						}
						else
						{
							Tab[a - 1][b + 1] = 'O';
							posicaovalida = true;
							system("cls");
						}

					}
					else
					{
						cout << "O movimento inserido não é valido. " << endl;
					}
				} while (!posicaovalida);
			}
			else
			{
				if (Tab[a - 1][b - 1] == ' ')
				{
					cout << "Obrigatorio mover esquerda" << endl;
					Tab[a - 1][b - 1] = 'O';
					posicaovalida = true;
					Sleep(5000);
					system("cls");
				}
				else
				{
					cout << "Obrigatorio mover direita" << endl;
					Tab[a - 1][b + 1] = 'O';
					posicaovalida = true;
					Sleep(5000);
					system("cls");
				}

			}

		}
		return pecas;
	}
	
	int jogadaPretas(int pecas)
	{
		int a, b, c, d;
		char mov, captura;
		bool capturavalida = false;
		bool pecavalida = false;
		bool posicaovalida = false;
		int posicaoxcapturar = 0;
		int posicaoycapturar = 0;
		bool capturaresquerda = false;
		bool capturardireita = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Tab[i][j] == 'X' && Tab[i + 1][j - 1] == 'O' && Tab[i + 2][j - 2] == ' ')
				{
					posicaoxcapturar = i;
					posicaoycapturar = j;
					capturaresquerda = true;
					//capturardireita = false;
				}
				if (Tab[i][j] == 'X' && Tab[i + 1][j + 1] == 'O' && Tab[i + 2][j + 2] == ' ')
				{
					posicaoxcapturar = i;
					posicaoycapturar = j;
					//capturaresquerda = false;
					capturardireita = true;
				}
			}
		}

		if (capturaresquerda || capturardireita)
		{
			if (capturaresquerda && capturardireita)
			{
				do
				{
					cout << "Pretende capturar Esquerda(E) ou Direita(D)? " << endl;
					cin >> captura;

					if (captura == 'E' || captura == 'D' || captura == 'e' || captura == 'd')
					{
						if (captura == 'E' || captura == 'e')
						{
							cout << "A pega na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " vai capturar a peca na posicao " <<
								posicaoxcapturar + 1 << " " << posicaoycapturar - 1 << endl;
							Tab[posicaoxcapturar][posicaoycapturar] = ' ';
							Tab[posicaoxcapturar + 1][posicaoycapturar - 1] = ' ';
							Tab[posicaoxcapturar + 2][posicaoycapturar - 2] = 'X';
							pecas--;

							Sleep(5000);
							system("cls");
							capturavalida = true;



						}
						else
						{
							cout << "A pega na posicao: " << posicaoxcapturar << " " << posicaoycapturar - 2 << " vai capturar a peca na posicao " <<
								posicaoxcapturar + 1 << " " << posicaoycapturar - 1 << endl;
							Tab[posicaoxcapturar][posicaoycapturar - 2] = ' ';
							Tab[posicaoxcapturar + 1][posicaoycapturar - 1] = ' ';
							Tab[posicaoxcapturar + 2][posicaoycapturar] = 'X';
							pecas--;

							Sleep(5000);
							system("cls");
							capturavalida = true;

						}

					}
					else
					{
						cout << "O movimento inserido não é valido. " << endl;
					}
				} while (!capturavalida);
			}
			else
			{

				if (capturaresquerda)
				{
					cout << "Obrigatorio Capturar Esquerda" << endl;
					cout << "A peca na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " tem de capturar a peca na posicao " <<
						posicaoxcapturar + 1 << " " << posicaoycapturar - 1 << endl;
					Tab[posicaoxcapturar][posicaoycapturar] = ' ';
					Tab[posicaoxcapturar + 1][posicaoycapturar - 1] = ' ';
					Tab[posicaoxcapturar + 2][posicaoycapturar - 2] = 'X';
					pecas--;
					Sleep(5000);
					system("cls");
				}
				else
				{
					cout << "Obrigatorio Capturar Direita" << endl;
					cout << "A peca na posicao: " << posicaoxcapturar << " " << posicaoycapturar << " tem de capturar a peca na posicao " <<
						posicaoxcapturar + 1 << " " << posicaoycapturar + 1 << endl;

					Tab[posicaoxcapturar][posicaoycapturar] = ' ';
					Tab[posicaoxcapturar + 1][posicaoycapturar + 1] = ' ';
					Tab[posicaoxcapturar + 2][posicaoycapturar + 2] = 'X';
					pecas--;
					Sleep(5000);
					system("cls");

				}
			}

		}
		else
		{
			do
			{
				cout << "Qual a peca que quer mover:" << endl;
				cin >> a >> b;
				//a=a-1;
				//b=b-1;
				if ((Tab[a][b] == 'X') && (Tab[a + 1][b - 1] == ' ' || Tab[a + 1][b + 1] == ' '))
				{
					pecavalida = true;

				}
				else { cout << "Essa posicao nao e valida" << endl; }
			} while (!pecavalida);
			Tab[a][b] = ' ';
			if (Tab[a + 1][b - 1] == ' ' && Tab[a + 1][b + 1] == ' ')
			{
				do
				{
					cout << "Pretende mover Esquerda(E) ou Direita(D)? " << endl;
					cin >> mov;

					if (mov == 'E' || mov == 'D' || mov == 'e' || mov== 'd')
					{
						if (mov == 'E' || mov == 'e')
						{
							Tab[a + 1][b - 1] = 'X';
							posicaovalida = true;
							system("cls");
						}
						else
						{
							Tab[a + 1][b + 1] = 'X';
							posicaovalida = true;
							system("cls");
						}

					}
					else
					{
						cout << "O movimento inserido não é valido. " << endl;
					}
				} while (!posicaovalida);
			}
			else
			{
				if (Tab[a + 1][b - 1] == ' ' && b - 1 > -1)
				{
					cout << "Obrigatorio mover esquerda" << endl;
					Tab[a + 1][b - 1] = 'X';
					posicaovalida = true;
					Sleep(5000);
					system("cls");
				}
				else
				{
					cout << "Obrigatorio mover direita" << endl;
					Tab[a + 1][b + 1] = 'X';
					posicaovalida = true;
					Sleep(5000);
					system("cls");

				}

			}

		}
		return pecas;

	}
};