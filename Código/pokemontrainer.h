#ifndef POKEMONTRAINER_H
#define POKEMONTRAINER_H

#include <string>
#include <vector>

#include "pokemon.h"

using namespace std;

class PokemonTrainer
{
public:
    PokemonTrainer();                                                       // Construtor
	PokemonTrainer(string newName, vector<Pokemon> newTeam); 	        	// Cria um treinador
	void setName(string newName);											// Da um nome ao treinador
	string getName();														// Retorna o nome do treinador
	int getNumPokemon();													// Retorna o numero de Pokemon que o treinador possui
	Pokemon getPokemon(int i);												// Procura um Pokemon, pelo numero
	Pokemon getPokemon(string name);										// Procura um Pokemon, pelo nome
	bool isInTeam(string name);											    // Verifica se um Pokemon esta no time, pelo nome
	void removePokemon(string name);										// Remove um Pokemon do time

private:
	string name;															// Nome do Treinador
	int numPokemon;															// Numero de Pokemon do Treinador
	vector<Pokemon> pokemonTeam;											// Vetor com os Pokemon do Treinador
};

#endif
