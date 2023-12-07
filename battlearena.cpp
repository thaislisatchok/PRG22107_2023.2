#include <cstdlib>				// exit
#include <iostream>				// cin, cout, endl, etc.
#include <stdlib.h>				// rand, srand
#include <time.h>				// time
#include <vector>				// vector

#include "battlearena.h"

using namespace std;

//  Construtor
BattleArena::BattleArena(){

}

//  Cria uma arena de batalha com dois treinadores
BattleArena::BattleArena(PokemonTrainer newBlue, PokemonTrainer newRed)
{
	blue = newBlue;		// Rival (CPU)
	red = newRed;		// Usuario
}

//	Escolhe aleatoriamente os Pokemon da CPU
void BattleArena::chooseBluePokemon()
{
	srand (time(NULL));
	currentBluePokemon = blue.getPokemon(rand() % blue.getNumPokemon());		// Um pokemon é aleatoriamente escolhido a partir do time da CPU
	cout << "\n" << blue.getName() << ": " << currentBluePokemon.getName() << ", Eu escolho voce!." << endl;
}

// Seleciona o Pokemon ativo do usuario
void BattleArena::chooseRedPokemon()
{
	string selection;
	cout << "Qual Pokemon voce quer escolher?" << endl;
	for (int i = 0; i < red.getNumPokemon(); i++)							//	Imprime todos os Pokemon disponiveis no time
	{
		cout << "\t" << red.getPokemon(i).getName() << endl;
	}

	cout << "Digite o nome do Pokemon: " << endl;
	cin >> selection;
	while (cin.fail() || red.isInTeam(selection) == false)
	{
		cout << "Esse Pokemon nao foi encontrado no seu time." << endl;
		cin >> selection;
	}
	currentRedPokemon = red.getPokemon(selection);
}

// Retorna o Pokemon ativo da CPU
Pokemon BattleArena::getBluePokemon()
{
	return currentBluePokemon;
}

//	Retorna o Pokemon ativo do Usuario
Pokemon BattleArena::getRedPokemon()
{
	return currentRedPokemon;
}

// Retorna o numero de Pokemon restantes da CPU
int BattleArena::getBluePokemonRemaining()
{
	return blue.getNumPokemon();
}

//	Retorna o numero de Pokemon restantes do Usuario
int BattleArena::getRedPokemonRemaining()
{
	return red.getNumPokemon();
}

//	Seleciona o movimento que o Pokemon da CPU vai utilizar
void BattleArena::blueAttack()
{
	srand (time(NULL));
	int moveChoice = rand() % 4 + 1;								//	Seleciona aleatoriamente o movimento
	int damage;														//	Dano causado

	if (currentBluePokemon.getMove(moveChoice).ppRemaining == 0)	//	Se o movimento nao possuir mais PP, ele nao pode ser mais utilizado
	{
		blueAttack();
	}

	cout << "O " << currentBluePokemon.getName() << " inimigo atacou o seu " << currentRedPokemon.getName() << " usando " << currentBluePokemon.getMove(moveChoice).name << "!" << endl;
	currentBluePokemon.usePP(moveChoice);

	damage = currentBluePokemon.getMove(moveChoice).power;
	if (damage >= 100)
	{
		cout << "Dano Critico!" << endl;
	}
	if (damage == 0)
	{
		cout << "Sem efeito!" << endl;
	}
	std::cout << "O " << currentBluePokemon.getName() << " inimigo causou " << damage << " de dano no seu " << currentRedPokemon.getName() << "!" << endl;

	currentRedPokemon.setHP(currentRedPokemon.getHPRemaining() - damage);		//	Diminui o HP do Pokemon
	if (currentRedPokemon.getHPRemaining() <= 0)								//	Se o HP do Pokemon for menor ou igual a zero, o Pokemon desmaia...
	{
		cout << currentRedPokemon.getName() << " !" << endl;
		red.removePokemon(currentRedPokemon.getName());							//	Remove o Pokemon do jogo
		if (red.getNumPokemon() > 0)											//	Se o Usuario ainda tem Pokemon no time, sera escolhido outro
		{
			chooseRedPokemon();
		}
	}
}

//	Seleciona o movimento do Pokemon do Usuario
void BattleArena::redAttack()
{
	int moveChoice;		// Movimento escolhido
	int damage;			// Dano causado

	cout << currentRedPokemon.getName() << " vai atacar o " << currentBluePokemon.getName() << " inimigo!" << endl;

	cout << "Qual movimento o " << currentRedPokemon.getName() << " deve usar?" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << i+1 << ": " << currentRedPokemon.getMove(i+1).name << " [" << currentRedPokemon.getMove(i+1).ppRemaining << "/" << currentRedPokemon.getMove(i+1).ppTotal << "] - Power: " << currentRedPokemon.getMove(i+1).power <<endl;
	}
	cout << "Digite o numero do movimento que o Pokemon deve usar: ";
	cin >> moveChoice;
	while (cin.fail() || moveChoice > 4 || moveChoice < 1 || currentRedPokemon.getMove(moveChoice).ppRemaining == 0)
            {
		if (currentRedPokemon.getMove(moveChoice).ppRemaining == 0)
		{
			cout << "Esse movimento nao possui mais PP!" << endl;
		}
		else
		{
			cout << "Essa nao é uma escolha valida." << endl;
		}
		cout << "Selecione outro movimento: ";
		cin >> moveChoice;
	}

	cout << currentRedPokemon.getName() << " Atacou o " << currentBluePokemon.getName() << " inimigo usando " << currentRedPokemon.getMove(moveChoice).name << "!" << endl;
	currentRedPokemon.usePP(moveChoice);

	damage = currentRedPokemon.getMove(moveChoice).power;
	if (damage >= 100)
	{
		cout << "Dano critico!" << std::endl;
	}
	if (damage == 0)
	{
		cout << "Sem efeito!" << std::endl;
	}
	cout << currentRedPokemon.getName() << " causou " << damage << " de dano no " << currentBluePokemon.getName() << " inimigo!" << endl;

	/* UPDATE STATS */
	currentBluePokemon.setHP(currentBluePokemon.getHPRemaining() - damage);
	if (currentBluePokemon.getHPRemaining() <= 0)
	{
		cout << currentBluePokemon.getName() << " desmaiou!" << endl;
				blue.removePokemon(currentBluePokemon.getName());
		if (blue.getNumPokemon() > 0)
		{
			chooseBluePokemon();
		}
	}
}

bool BattleArena::continueBattle()
{
	if (blue.getNumPokemon() > 0 && red.getNumPokemon() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
