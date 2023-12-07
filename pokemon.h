#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

struct MoveSet						//	Estrutura movimento
{
	string name;					//	Nome do movimento
	string type;					//	Tipo do Movimento
	int power;						//	Poder do Movimento
	int ppRemaining;				//	PP restante
	int ppTotal;					// 	PP máximo
};

class Pokemon
{
public:
	Pokemon();
	Pokemon(int newPokedexNumber, string newName, string newType, int newHP,
				string newMoveName1, string newMoveType1, int newPower1, int newPP1,
				string newMoveName2, string newMoveType2, int newPower2, int newPP2,
				string newMoveName3, string newMoveType3, int newPower3, int newPP3,
				string newMoveName4, string newMoveType4, int newPower4, int newPP4);

	int getPokedexNumber();			// 	Retorna o numero do Pokemon
	string getName();				// 	Retorna o nome do Pokemon
	string getType();				// 	Retorna o tipo do Pokemon
	void setHP(int newHP);			// 	Modifica o valor de HP do Pokemon
	int getHPRemaining();			// 	Retorna o valor atual de HP do pokemon
	int getHPTotal();				// 	Retorna o valor total de HP do pokemon
	MoveSet getMove(int move);		// 	Retorna um movimento escolido
	void usePP(int move);			// 	Diminui o numero de PP do movimento

private:
	int pokedexNumber;				// 	Numero do Pokemon
	string name;					// 	Nome do Pokemon
	string type;					// 	Tipo do Pokemon
	int hpRemaining;				// 	HP restante
	int hpTotal;					// 	HP total
	MoveSet move1;					//	Primeiro Movimento
	MoveSet move2;					// 	Segundo Movimento
	MoveSet move3;					// 	Terceiro Movimento
	MoveSet move4;					// 	Quarto Movimento
};


#endif
