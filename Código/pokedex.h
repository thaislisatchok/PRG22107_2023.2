#ifndef POKEDEX_H
#define POKEDEX_H

#include <iomanip>			
#include <iostream>			// cin, cout, endl, etc.
#include <vector>			// vector

#include "pokemon.h"

using namespace std;

class Pokedex
{
public:
	Pokedex();								// 	Constructor, inicializa a Pokedex
	void printFullPokedexNames();			// 	Imprime o nome de todos os Pokemon na Pokedex
	void printFullPokedexInfo();			// 	Imprime todas a imformacoes dos Pokemon 
	int getSize();							// 	Retorna o numero de Pokemon na Pokedex
	Pokemon findPokemon(int number);		// 	Retorna o Pokemon listado no numero específico da Pokedex
	Pokemon getPokemon(int number);			// 	Retorna o Pokemon baseado no numero do vetor da Pokedex
	bool isInPokedex(int number);			// 	Verifica se existe um pokemon com o numero requerido

private:
	void bootUp();							//	Funcao de iniciacao que cria o vetor Pokedex
	vector<Pokemon> pokedex;				//	Vetor Pokedex
};

#endif
