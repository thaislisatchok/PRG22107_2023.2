#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "pokemon.h"
#include "pokedex.h"
#include "pokemontrainer.h"

using namespace std;

class BattleArena
{
public:
    BattleArena();                                                      //  Construtor
	BattleArena(PokemonTrainer newBlue, PokemonTrainer newRed);    	    //  Cria uma arena com dois treinadores
	void chooseBluePokemon();									        // 	Escolhe aleatoriamente com que Pokemon o Rival vai utilizar
	void chooseRedPokemon();									        // 	Seleciona o Pokemon que o usuario vai utilizar
	Pokemon getBluePokemon();									        // 	Retorna o Pokemon que a CPU esta utilizando no momento
	Pokemon getRedPokemon();									        // 	Retorna o Pokemon que o usuario esta utilizando no momento
	int getBluePokemonRemaining();								        // 	Retorna o numero restante de Pokemon do Rival
	int getRedPokemonRemaining();								        // 	Retorna o numero restante de Pokemon do Usuario
	void blueAttack();											        // 	Escolhe aleatoriamento o movimento que o Pokemon do Rival vai utilizar
	void redAttack();											        // 	Seleciona o movimento que o Pokemon do Usuario vai utilizar
	bool continueBattle();										        // 	Verifica se os dois Jogadores ainda possuem Pokemon

private:
	PokemonTrainer blue;										        // 	Treinador Rival(CPU)
	PokemonTrainer red;											        // 	Treinador Usuario
	Pokemon currentBluePokemon;									        // 	POkemon atual do Rival
	Pokemon currentRedPokemon;									        // 	O Pokemon atual do Usuario
};

#endif
