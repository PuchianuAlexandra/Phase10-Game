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
			currentPlayer.m_handCards.push_back(deck.PickCardFromDeck());
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
		PickCard(player);
		std::cout << "Cartile ramase in mana sunt: ";
		for (int index2 = 0; index2 < player.m_handCards.size(); index2++)
		{
			std::cout << player.m_handCards[index2];
			std::cout << "\n";
		}
		players.push(player);

		index++;
	}




}

void Game::DecartCard(Player& player)
{
	Card decarted = player.DropCard();
	decarted.SetPlace(Place::DECARTED);
	decartedCards.push(decarted);

	std::cout << decartedCards.top();

}

Card Game::PickCardFromDecartedStack()
{
	Card card = decartedCards.top();
	card.SetPlace(Place::HAND);
	decartedCards.pop();
	return card;
}

void Game::PickCard(Player& player)
{
	if (decartedCards.empty())
	{
		Card card = deck.PickCardFromDeck();
		player.m_handCards.push_back(card);
	}
	else
	{
		int option=0;
		std::cout << "From where do you want to pick a card?\n";
		std::cout << "1.Deck\n";
		std::cout << "2.Decarted Cards: "<<decartedCards.top()<<"\n";
		while (option != 1 && option != 2) {
		std::cin >> option;
			switch (option)
			{
			case 1:
			{
				Card card = deck.PickCardFromDeck();
				player.m_handCards.push_back(card);
				break;
			}
			case 2:
			{
				if (decartedCards.top().GetStatus() == Status::SKIP)
				{
					std::cout << "You can't pick that card.\n";
				}
				else {
					Card card = PickCardFromDecartedStack();
					player.m_handCards.push_back(card);
				}
				break;
			}

			default:
			{
				std::cout << "Insert a valid option!";
				break;
			}
			}
		} 
	}
}
