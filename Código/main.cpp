#include <cstdlib>				// exit
#include <iostream>				// cout, cin, endl, etc.
#include <string.h>
#include <stdlib.h>				// rand, srand
#include <time.h>				// time
#include <vector>				// vector

#include "battlearena.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemontrainer.h"

using namespace std;

void createTrainer(Pokedex pokedex, string &name, int &numPokemon, int &selection, vector<Pokemon> &pokemonTeam);					// Cria um trainador
void createRival(Pokedex pokedex, string &rivalName, const int &numPokemon, int &numRivalPokemon, vector<Pokemon> &rivalTeam);	    // Cria um treinador CPU
void randomPokemon(Pokedex pokedex, const int &numPokemon, vector<Pokemon> &pokemonRoster);											// selecina os pokemons aleatóriamente


int main(int argc, char *argv[])
{
	/*** VARIAVEIS ***/
	Pokedex pokedex;							// Objeto Pokedex
	PokemonTrainer Red;						    // Objeto Treinador, Usuário
	PokemonTrainer Blue;						// Objeto Treinador, CPU
	BattleArena battlearena;					// Obejto Arena	

	char decision;								// variavel de decisão

	string name;								// Nome do Treinador Pokemon
	int numPokemon;								// Numero de Pokemon no time
	int selection;								// Numero do Pokemon selecinado
	vector<Pokemon> pokemonTeam;				// Vetor dos Pokemon

	string rivalName;							// Nome do Rival
	int numRivalPokemon;						// Numero de Pokemon do Rival
	vector<Pokemon> rivalTeam;				    // Vetor dos Pokemon

	/*** INTRODUCAO ***/
	cout << "\n===========================" << endl;
	cout << "BEM VINDO AO MUNDO POKEMON!" << endl;
	cout << "===========================" << endl;

	cout << "\nAntes de comecar, voce precisa se inscrever:." << endl;

    createTrainer(pokedex, name, numPokemon, selection, pokemonTeam);

	Red = PokemonTrainer(name, pokemonTeam);											// Cria o Time do Treinador Usuario
	createRival(pokedex, rivalName, numPokemon, numRivalPokemon, rivalTeam);
	Blue = PokemonTrainer(rivalName, rivalTeam);										// Cria o Time do Treinador CPU


	/*** BATALHA ***/
	cout << "\nAgora voce esta pronto para batalhar!" << endl;
	battlearena = BattleArena(Blue, Red);
	battlearena.chooseRedPokemon();				// Seleciona o time do Usuário
	battlearena.chooseBluePokemon();			// Seleciona o time do adversário
	while (battlearena.continueBattle())		// A batalha continua ate que os dois lados tenham Pokemon
	{
		cout << "\n\n" << endl;
												// Exibe os estatus dos Pokemon ativos
		cout << battlearena.getRedPokemon().getName() << " [HP: " << battlearena.getRedPokemon().getHPRemaining() << "/" << battlearena.getRedPokemon().getHPTotal() << "]"
				  << " vs. "
				  << battlearena.getBluePokemon().getName() << " [HP: " << battlearena.getBluePokemon().getHPRemaining() << "/" << battlearena.getBluePokemon().getHPTotal() << "]"
				  << endl;

		/*** TURNO DO USUARIO ***/
		cout << "O que voce quer fazer? [A]tacar ou [T]rocar o Pokemon?" << endl;
		cin >> decision;
		decision = toupper(decision);
		while (cin.fail() || (decision != 'A' && decision != 'T'))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Escolha uma opcao valida!" << endl;
			cin >> decision;
			decision = toupper(decision);
		}

		if (decision == 'A')
		{
			battlearena.redAttack();		// Usuario escolhe atacar
		}
		else
		{
			battlearena.chooseRedPokemon();	// Usuario escolhe trocar
		}

		cout << "\n\n" << endl;

		/*** TURNO DA CPU ***/
		if (battlearena.getBluePokemonRemaining() > 0)
		{
			// Exibe os estatus dos Pokemon ativos
			cout << battlearena.getRedPokemon().getName() << " [HP: " << battlearena.getRedPokemon().getHPRemaining() << "/" << battlearena.getRedPokemon().getHPTotal() << "]"
					  << " vs. "
					  << battlearena.getBluePokemon().getName() << " [HP: " << battlearena.getBluePokemon().getHPRemaining() << "/" << battlearena.getBluePokemon().getHPTotal() << "]"
					  << endl;
			battlearena.blueAttack();
		}
	}

	/*** FIM DA BATALHA ***/
	if (battlearena.getBluePokemonRemaining() == 0)												// Se todos os Pokemon do Rival forme derrotados
	{
		cout << name << " derrotou " << rivalName << "!" << endl;								// Usuario vence
		cout << name << " recebeu $" << rand() % 1000 << " por ter vencido!\n\n" << endl;		// Usuario ganha um valor em dinheiro
	}
	else																						// Se todos os Pokemon do Usuario forem derrotados
	{
		cout << "\n\n" << rivalName << " defeated " << name << "!" << endl;						// CPU vence
		cout << name << " perdeu $" << rand() % 500 << " por ter perdido!\n\n" << endl;			// Usuario perde uma quantia de dinheiro
	}
}

/*** FUNCOES ***/

void createTrainer(Pokedex pokedex, string &name, int &numPokemon, int &selection, vector<Pokemon> &pokemonTeam)
{
	char choice;

	cout << "\nQual seu nome?" << endl;
	cin >> name;

	cout << "\nQuantos pokemon voce tem? (max 6)" << endl;
	cin >> numPokemon;
	while (cin.fail() || numPokemon > 6 || numPokemon < 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
        cout << "Essa nao era uma escolha valida. Digite um numero de 1 - 6:" << endl;
		cin >> numPokemon;
	}

	cout << "\n Voce quer escolher [E] os seus pokemon ou ter " << numPokemon << " escolido aleatoriamente [A] ? [E / A]" << endl;
	cin >> choice;
	choice = toupper(choice);

	while (cin.fail() || (choice != 'E' && choice != 'A'))
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Essa nao era uma escolha valida. Digite 'E' para escolher o seu pokemon ou 'A' para ele ser acolido aleatoriamente." << endl;
		cin >> choice;
		choice = toupper(choice);
	}

    // Escolha do Usuario
	if (choice == 'E')
	{
		cout << "\nEscolha " << numPokemon << " dos Pokemon a baixo:" << endl;
		pokedex.printFullPokedexNames();

		for (int i = 0; i < numPokemon; i++)
		{
			cout << "\nDigite o numero da pokedex do pokemon que voce deseja" << endl;
			cin >> selection;
			while (cin.fail() || pokedex.isInPokedex(selection) == false)
			{
				cout << "O numero da pokedex do seu poekemon nao foi encontrado." << endl;
				cout << "Digite um numero valido:" << endl;
				cin >> selection;
			}
			pokemonTeam.push_back(pokedex.findPokemon(selection));
		}
	}
	// Escolha aleatoria
	else
	{
		randomPokemon(pokedex, numPokemon, pokemonTeam);
	}
}

void createRival(Pokedex pokedex, std::string &rivalName, const int &numPokemon, int &numRivalPokemon, std::vector<Pokemon> &rivalTeam)
{
	rivalName = "Blue";							// Nome do Rival
	numRivalPokemon = numPokemon;				// Garante que o rival tem o mesmo numero de pokemon que o usuario
	randomPokemon(pokedex, numRivalPokemon, rivalTeam);
}


void randomPokemon(Pokedex pokedex, const int &numPokemon, std::vector<Pokemon> &pokemonTeam)
{
	srand (time(NULL));

	for (int i = 0; i < numPokemon; i++)
	{
		int selection = rand() % pokedex.getSize();
		pokemonTeam.push_back(pokedex.getPokemon(selection));
	}
}
