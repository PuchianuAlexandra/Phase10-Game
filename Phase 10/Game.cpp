#include "Game.h"

void Game::ReadPlayers()
{
	std::cout << "Insert number of players: ";
	int noOfPlayers;
	std::cin >> noOfPlayers;

	for (int index = 0; index < noOfPlayers; index++)
	{
		std::cout << "Name for player nr " << index + 1 << " : ";
		std::string name;
		std::cin >> name;
		Player player(name);
		players.push(player);
	}

	for (int index = 0; index < noOfPlayers; index++)
	{
		Player player = players.front();
		players.pop();
		std::cout << player;
		players.push(player);
	}
}
