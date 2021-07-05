 #pragma once
#include <iostream>
#include <string>
using namespace std;

class Jogador
{
private: 
	string nome;
	int num_pecas;
public:
	Jogador();
	Jogador(string nome);
	~Jogador();
	int Get_Pecas();
	string Get_nome();
};

