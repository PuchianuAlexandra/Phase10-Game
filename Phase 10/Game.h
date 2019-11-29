#pragma once
#include <queue>
#include <stack>
#include "Deck.h"
#include "Player.h"
#include "Board.h"

class Game
{
public:
	Game(uint16_t noPlayers);
	Game();

	void ShowPlayers(std::vector<Player> players);
	void ReadPlayers();
	void Share10Cards();
	void StartGame();
	void TestGame();
	void DecartCard(Player& player);
	Card PickCardFromDecartedStack();
	void PickCard(Player& player);
	void CountScore(Player& player);
	Player SearchPlayer(std::vector<Player> players, std::string name) const;
	void AnnexCard(std::vector<Player>& players, int indexCard, int id);

private:
	std::vector<std::string> m_playersNames = { " " };
	uint16_t m_noPlayers;
	std::vector <Player> m_players;
	std::stack<Card> m_decartedCards;
	Deck m_deck;
	std::vector<std::string> m_playersToSkip;
};

