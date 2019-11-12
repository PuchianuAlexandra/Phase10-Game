#include "Game.h"

void Game::ReadPlayers()
{
	std::cout << "Insert number of players: ";
	std::cin >> noPlayers;

	for (int index = 0; index < noPlayers; index++)
	{
		std::cout << "Name for player nr " << index + 1 << " : ";
		std::string name;
		std::cin >> name;
		Player player(name);
		players.push(player);
	}

	Share10Cards();

	for (int index = 0; index < noPlayers; index++)
	{
		Player player = players.front();
		players.pop();
		std::cout << player;
		players.push(player);
	}
}

void Game::Share10Cards()
{
	deck.ShuffleDeck();
	for (int index = 0; index < noPlayers; index++)
	{
		Player currentPlayer = players.front();
		players.pop();
		for (int index2 = 0; index2 < 10; index2++)
		{
			currentPlayer.m_handCards.push_back(deck.PickCard());
		}
		players.push(currentPlayer);
	}
}

void Game::StartGame()
{
	ReadPlayers();

	//test DropCard
	int index = 0;
	while (index<noPlayers)
	{
		Player player = players.front();
		players.pop();
		DecartCard(player);

		std::cout << "Cartile ramase in mana sunt: ";
		for (int index2 = 0; index2 < player.m_handCards.size(); index2++)
		{
			std::cout << player.m_handCards[index2];
			std::cout << "\n";
		}
		players.push(player);

		index++;
	}

	deck.TestDeck();


}

void Game::DecartCard(Player& player)
{
	Card decarted = player.DropCard();
	decarted.SetPlace(Place::DECARTED);
	decartedCards.push(decarted);

	//TEST

	std::cout << decartedCards.top();

}
