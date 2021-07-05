#include "Tabuleiro.h"
#include <ostream>
#include <iostream>
#include <fstream>


Tabuleiro::Tabuleiro()
{
}


Tabuleiro::~Tabuleiro()
{
}



void Tabuleiro::MostraTabuleiro(string nome1, int pecas1, string nome2, int pecas2)
{
	int z = 1;
	cout << "   1   2   3   4   5   6   7   8  " << endl;

	for (int x = 1; x < 9; ++x)
	{
		cout << " |---|---|---|---|---|---|---|---|" << endl;
		cout << z << "| " << Tab[x][1] << " | "
			<< Tab[x][2] << " | "
			<< Tab[x][3] << " | "
			<< Tab[x][4] << " | "
			<< Tab[x][5] << " | "
			<< Tab[x][6] << " | "
			<< Tab[x][7] << " | "
			<< Tab[x][8] << " | " << endl;

		z++;
	}
	cout << " |---|---|---|---|---|---|---|---|" << endl;
	cout << "O " << nome1 << " tem " << pecas1 << " pecas " << endl;
	cout << "O " << nome2 << " tem " << pecas2 << " pecas " << endl;
}

void Tabuleiro::Guardar(string nome1, int pecas1, string nome2, int pecas2) {

	ofstream myfile;
	myfile.open("DadosPartida.txt");
	myfile << nome1 << endl;
	myfile << nome2 << endl;
	myfile << pecas1 << endl;
	myfile << pecas2 << endl;
	int z = 1;
	for (int x = 1; x < 9; ++x)
	{
		myfile << Tab[x][1] << endl;
		myfile << Tab[x][2] << endl;
		myfile << Tab[x][3] << endl;
		myfile << Tab[x][4] << endl;
		myfile << Tab[x][5] << endl;
		myfile << Tab[x][6] << endl;
		myfile << Tab[x][7] << endl;
		myfile << Tab[x][8] << endl;


	}
	for (int x = 1; x < 9; ++x)
	{
		myfile << " |---|---|---|---|---|---|---|---|" << endl;
		myfile << z << "| " << Tabuleiro::Tab[x][1] << " | "
			<< Tabuleiro::Tab[x][2] << " | "
			<< Tabuleiro::Tab[x][3] << " | "
			<< Tabuleiro::Tab[x][4] << " | "
			<< Tabuleiro::Tab[x][5] << " | "
			<< Tabuleiro::Tab[x][6] << " | "
			<< Tabuleiro::Tab[x][7] << " | "
			<< Tabuleiro::Tab[x][8] << " | " << endl;

		z++;
	} 
	myfile.close();

}

void Tabuleiro::Carregar(string *nome, string *_nome) {

	string nome1, nome2;
	string pecas1, pecas2;
	string line;
	ifstream myfile("DadosPartida.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		nome1 = line;
		getline(myfile, line);
		nome2 = line;
		getline(myfile, line);
		pecas1 = line;
		getline(myfile, line);
		pecas2 = line;
		for (int x = 1; x < 9; ++x)
		{
			getline(myfile, line);
			Tab[x][1] = line[0];
			getline(myfile, line);
			Tab[x][2] = line[0];
			getline(myfile, line);
			Tab[x][3] = line[0];
			getline(myfile, line);
			Tab[x][4] = line[0];
			getline(myfile, line);
			Tab[x][5] = line[0];
			getline(myfile, line);
			Tab[x][6] = line[0];
			getline(myfile, line);
			Tab[x][7] = line[0];
			getline(myfile, line);
			Tab[x][8] = line[0];
		}

		/*

while (getline(myfile,line))
	  {
		cout << line << '\n';
	  }*/
	  //cout << nome1 << endl << nome2 << endl << pecas1 << endl << pecas2 << endl;
		
		myfile.close();
		*nome = nome1;
		*_nome = nome2;
		int pecas10 = stoi(pecas1);
	}
};