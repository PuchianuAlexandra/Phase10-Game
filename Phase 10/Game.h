#pragma once
#include <queue>
#include <stack>
#include "Deck.h"
#include "Player.h"
#include "Board.h"

class Game
{
public: 
	void ReadPlayers();
	void Share10Cards();
	void StartGame();
	void TestGame();
	void DecartCard(Player& player);
	Card PickCardFromDecartedStack();
	void PickCard(Player& player);
	void CountScore(Player& player);
	

private:
	std::queue <Player> players;
	std::stack<Card> decartedCards;
	Deck deck;
	std::vector<std::string> playersToSkip;
	int noPlayers;
};

