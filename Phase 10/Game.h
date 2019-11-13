#pragma once
#include <queue>
#include <stack>
#include "Deck.h"
#include "Player.h"
class Game
{
public: 
	void ReadPlayers();
	void Share10Cards();
	void StartGame();
	void DecartCard(Player& player);
	Card PickCardFromDecartedStack();
	void PickCard(Player& player);
	void CountScore(Player& player);
	bool IsSet(int noOfCards, std::vector<Card> cards);
	bool isRun(int noOfCards, std::vector<Card> cards);
	bool isColor(int noOfCards, std::vector<Card> cards);

private:
	std::queue <Player> players;
	std::stack<Card> decartedCards;
	Deck deck;
	std::vector<std::string> playersToSkip;
	int noPlayers;
};

