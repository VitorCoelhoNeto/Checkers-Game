#include "Jogador.h"



Jogador::Jogador()
{
}

Jogador::Jogador(string nome)
{
	this->nome = nome;
	this->num_pecas = 12;

}


Jogador::~Jogador()
{
}

int Jogador::Get_Pecas()
{

	return num_pecas;
}

string Jogador::Get_nome()
{
	return string(nome);
}
