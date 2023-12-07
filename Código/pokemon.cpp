#include <iostream>
#include <string>
#include "pokemon.h"

using namespace std;

//Construtor
Pokemon::Pokemon(){

}

// Cria um novo Pokemon
Pokemon::Pokemon(int newPokedexNumber, string newName, string newType, int newHP,
					string newMoveName1, string newMoveType1, int newPower1, int newPP1,
					string newMoveName2, string newMoveType2, int newPower2, int newPP2,
					string newMoveName3, string newMoveType3, int newPower3, int newPP3,
					string newMoveName4, string newMoveType4, int newPower4, int newPP4)
{
	pokedexNumber = newPokedexNumber;

	name = newName;
	type = newType;
	hpRemaining = newHP;
	hpTotal = newHP;

	move1.name = newMoveName1;
	move1.type = newMoveType1;
	move1.power = newPower1;
	move1.ppRemaining = newPP1;
	move1.ppTotal = newPP1;

	move2.name = newMoveName2;
	move2.type = newMoveType2;
	move2.power = newPower2;
	move2.ppRemaining = newPP2;
	move2.ppTotal = newPP2;

	move3.name = newMoveName3;
	move3.type = newMoveType3;
	move3.power = newPower3;
	move3.ppRemaining = newPP3;
	move3.ppTotal = newPP3;

	move4.name = newMoveName4;
	move4.type = newMoveType4;
	move4.power = newPower4;
	move4.ppRemaining = newPP4;
	move4.ppTotal = newPP4;
}

// Retorna o numero do Pokemon
int Pokemon::getPokedexNumber()
{
	return pokedexNumber;
}

// Retorna o nome do Pokemon
string Pokemon::getName()
{
	return name;
}

// Retorna o tipo do Pokemon
string Pokemon::getType()
{
	return type;
}

//	Muda o valor do HP
void Pokemon::setHP(int newHP)
{
	hpRemaining = newHP;
}

// Retorna o valor restante do HP do pokemon
int Pokemon::getHPRemaining()
{
	return hpRemaining;
}

// Retorna o valor Total de HP do pokemon
int Pokemon::getHPTotal()
{
	return hpTotal;
}

// Retorna o movimento especificado
MoveSet Pokemon::getMove(int move)
{
	if (move == 1)
	{
		return move1;
	}
	else if (move == 2)
	{
		return move2;
	}
	else if (move == 3)
	{
		return move3;
	}
	else
	{
		return move4;
	}
}

// Dimniui o PP a cada vez que o movimento é utilizado
void Pokemon::usePP(int move)
{
	if (move == 1)
	{
		move1.ppRemaining--;
	}
	else if (move == 2)
	{
		move2.ppRemaining--;
	}
	else if (move == 3)
	{
		move3.ppRemaining--;
	}
	else
	{
		move4.ppRemaining--;
	}
}

