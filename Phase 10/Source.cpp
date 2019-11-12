#include<iostream>
#include"Card.h"
#include"Deck.h"
#include"Player.h"
#include "Game.h"

int main()
{
	Deck deck;
	Game game;
	//game.ReadPlayers();
	game.StartGame();

	system("pause");
	return 0;
}