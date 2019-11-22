#include <cstdint>
#include "Game.h"
#include "Phase.h"

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

	/*for (int index = 0; index < noPlayers; index++)
	{
		Player player = players.front();
		players.pop();
		std::cout << player;
		players.push(player);
	}*/
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
	Player currentPlayer;
	Board board;
	Phase phase;
	bool option;
	int index = 0;

	while (index<noPlayers)
	{
		system("cls");
		board.ShowDisplayedCards(players);
		currentPlayer = players.front();
		std::cout << "\n"<<currentPlayer;

		players.pop();

		bool skipped = false;
		for (std::string name : playersToSkip)
		{
			if (name == currentPlayer.GetName())
			{
				skipped = true;
				name = "";
				break;
			}
		}

		if (skipped)
		{
			std::cout << "You are skiped!" << "\n";
			//players.push(currentPlayer);
		}

		else
		{
			PickCard(currentPlayer);
			if (currentPlayer.m_displayedCards.empty())
			{
				std::cout << "Do you want to display (choose 1 for yes and 0 for no)?\n";
				do
				{
					std::cin >> option;
					switch (option)
					{
					case 1: {
						phase.isPhase(currentPlayer);
						break;
					}

					case 0: {
						break;
					}

					default:
						break;
					}
				} while (option!=0);
			}

			DecartCard(currentPlayer);
			std::cout << "Cartile ramase in mana sunt: ";
			for (int index2 = 0; index2 < currentPlayer.m_handCards.size(); index2++)
			{
				std::cout << currentPlayer.m_handCards[index2];
				std::cout << "\n";
			}
		}

		players.push(currentPlayer);
		index++;
	}
	
}

void Game::TestGame()
{
	Phase phase;
	Board board;
	
	ReadPlayers();

	int index = 0;
	while (index < noPlayers)
	{
		Player player = players.front();
		players.pop();
		phase.isPhase(player);
		players.push(player);
		index++;
	}
	board.ShowDisplayedCards(players);

	//system("cls");



	//std::vector<Card> cards;
	//Card c1(Color::RED, Status::ONE, Place::HAND);
	//Card c2(Color::YELLOW, Status::ONE, Place::HAND);
	//Card c3(Color::RED, Status::ONE, Place::HAND);
	////Card c4(Color::BLUE, Status::ELEVEN, Place::HAND);
	//
	//cards.push_back(c1);
	//cards.push_back(c2);
	//cards.push_back(c3);
	////cards.push_back(c4);
	//
	//std::vector<Card> cards1;
	//Card c11(Color::RED, Status::ONE, Place::HAND);
	//Card c22(Color::YELLOW, Status::WILD, Place::HAND);
	//Card c33(Color::RED, Status::THREE, Place::HAND);
	//Card c44(Color::BLUE, Status::FOUR, Place::HAND);
	//
	//cards1.push_back(c11);
	//cards1.push_back(c22);
	//cards1.push_back(c33);
	//cards1.push_back(c44);
	//int inc = 0;

	/*players.front().m_phase[1] = true;
	players.front().m_phase[2] = true;
	players.front().m_phase[3] = true;
	players.front().m_phase[4] = true;
	players.front().m_phase[5] = true;
	players.front().m_phase[6] = true;
	players.front().m_phase[7] = true;
	players.front().m_phase[8] = true;
	players.front().m_phase[9] = true;
	

	if (phase.isPhase(players.front()))
	{
		std::cout << "Da <3";

		std::cout << "\n";
		std::cout << "Hand Cards \n";
		for (int index = 0; index < players.front().m_handCards.size(); index++)
		{

			std::cout << players.front().m_handCards[index] << "\n ";
		}
		std::cout << "Displayed Cards \n";
		for (int index = 0; index < 2; index++)
		{
			for (int index1 = 0; index1 < players.front().m_displayedCards[index].size(); index1++)
			{
				std::cout << players.front().m_displayedCards[index][index1] << "\n ";
			}
			std::cout << "*************************************\n";
		}
	}
	else
		std::cout << "BUZZ";*/


	/*Player player = players.front();
	CountScore(player);
	std::cout << player;*/

	/*std::vector<Card> cards;
	Card c1 (Color::RED, Status::ONE, Place::HAND);
	Card c2 (Color::YELLOW, Status::TEN, Place::HAND);
	Card c3 (Color::RED, Status::EIGHT, Place::HAND);
	Card c4(Color::BLUE, Status::ELEVEN, Place::HAND);
	Card c5(Color::BLUE, Status::TWELVE, Place::HAND);
	cards.push_back(c1);
	cards.push_back(c2);
	cards.push_back(c3);
	cards.push_back(c4);
	cards.push_back(c5);
	if (isColor(cards))
		std::cout << "Da. <3 ";
	else std::cout << "BUZZ";*/

	//test DropCard
	/*int index = 0;
	while (index<noPlayers)
	{
		Player player = players.front();
		players.pop();

		bool skipped = false;
		for (std::string name : playersToSkip)
		{
			if (name == player.GetName())
			{
				skipped = true;
				name = "";
			}
		}

		if (skipped)
		{
			std::cout << "You are skiped!" << "\n";
			players.push(player);
			index++;

		}

		else
		{
			PickCard(player);
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

	}*/

}

void Game::DecartCard(Player& player)
{
	std::cout << "Choose a card to discard from your hand (from 1 to " << player.m_handCards.size() << ") : ";
	int option;
	std::cin >> option;
	option--;
	Card decarted = player.DropCard(option);
	decarted.SetPlace(Place::DECARTED);
	decartedCards.push(decarted);

	if (decarted.GetStatus() == Status::SKIP)
	{
		std::cout << "Which player do u want to skip?"<<"\n";
		std::string name;
		std::cin >> name;
		playersToSkip.push_back(name);
	}

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

void Game::CountScore(Player & player)
{
	uint16_t score = player.GetScore();

	for (Card card : player.m_handCards)
	{
		if (card.GetStatus() < Status::TEN)
		{
			score += 5;
		}
		else if (card.GetStatus() > Status::NINE && card.GetStatus() < Status::WILD)
		{
			score += 10;
		}
		else
		{
			score += 20;
		}
	}

	player.setScore(score);
}
