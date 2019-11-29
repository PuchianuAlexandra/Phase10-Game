#pragma once
#include <queue>
#include <stack>
#include "Deck.h"
#include "Player.h"
#include "Board.h"

class Game
{
public:
	Game(uint8_t noPlayers);
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
	void AnnexCard(Player player, Card card);

private:
	std::vector<std::string> playersNames = { " " };
	uint8_t m_noPlayers;
	std::vector <Player> m_players;
	std::stack<Card> m_decartedCards;
	Deck m_deck;
	std::vector<std::string> m_playersToSkip;
};

