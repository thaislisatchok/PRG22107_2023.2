#include "pokemontrainer.h"

using namespace std;

// Construtor
PokemonTrainer::PokemonTrainer() : name("Red"), numPokemon(0)
{

}

PokemonTrainer::PokemonTrainer(string newName, vector<Pokemon> newTeam)
{
	name = newName;
	numPokemon = newTeam.size();
	pokemonTeam = newTeam;
}

// Da nome ao treinador
void PokemonTrainer::setName(string newName)
{
	name = newName;
}

// Retorna o nome do treinador
string PokemonTrainer::getName()
{
	return name;
}

// Retorna o numero de Pokemon que o treinador possui
int PokemonTrainer::getNumPokemon()
{
	return pokemonTeam.size();
}

// Retorna um Pokemon do time, correspondente ao valor
Pokemon PokemonTrainer::getPokemon(int i)
{
	return pokemonTeam[i];
}

// Retorna um Pokemorn, pelo nome
Pokemon PokemonTrainer::getPokemon(string name)
{
	for(int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonTeam[i].getName() == name)
		{
			return pokemonTeam[i];
		}
	}
}

// Verifica se um Pokemon esta no time
bool PokemonTrainer::isInTeam(string name)
{
	for (int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonTeam[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

// Remove um Pokemon do time
void PokemonTrainer::removePokemon(string name)
{
	for (int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonTeam[i].getName() == name)
		{
			pokemonTeam.erase(pokemonTeam.begin()+i);
		}
	}
}
