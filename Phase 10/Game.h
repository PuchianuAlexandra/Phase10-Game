#pragma once
#include <queue>
#include "Deck.h"
#include "Player.h"
class Game
{
public: 
	void ReadPlayers();
	void Share10Cards();
	void StartGame();

private:
	std::queue <Player> players;
	Deck deck;
	int noPlayers;
};

