#include <cstdint>
#include "Game.h"
#include "Phase.h"
#include <sstream>

Game::Game(uint16_t noPlayers) :m_noPlayers(noPlayers)
{
}

Game::Game()
{
}

void Game::ShowPlayers(std::vector<Player> players)
{
	for (int indexPlayer = 0; indexPlayer < m_noPlayers; indexPlayer++)
	{
		std::cout << players[indexPlayer].GetId() << ") " << players[indexPlayer].GetName() << " -score: " << players[indexPlayer].GetScore() << "\n";
	}
	std::cout << "\n";
}

void Game::ReadPlayers()
{

	std::string auxNumber;
	bool ok = true;
	std::cin.exceptions(std::istream::failbit);


	do {
		try
		{
			std::cout << "Insert number of players: ";
			std::cin >> auxNumber;
			if (auxNumber.size() == 1) {
				std::stringstream intNumber(auxNumber);
				int x;
				intNumber >> x;
				if (x <= 8 && x >= 2)
				{
					m_noPlayers = x;
					ok = true;
				}

				else {
					throw std::runtime_error("\nYou have to insert a digit between 2 and 8!\n");
				}
			}
			else {
				throw std::runtime_error("\nYou have to insert a digit between 2 and 8!\n");
			}
		}

		catch (std::runtime_error& e)
		{
			ok = false;
			std::cout << "\nYou have to insert a digit between 2 and 8!\n";
			std::cin.clear();
			std::string tmp;
			getline(std::cin, tmp);
		}

	} while (ok == false);




	for (int index = 0; index < m_noPlayers; index++)
	{
		bool ok = false;
		while (!ok) {
			std::cout << "Name for player nr " << index + 1 << " : ";
			std::string name;
			std::cin >> name;
			if (std::find(m_playersNames.begin(), m_playersNames.end(), name) != m_playersNames.end()) {
				std::cout << "\nName already exists!\n";
			}
			else {
				m_playersNames.push_back(name);
				Player player(name, index + 1);
				m_players.push_back(player);
				ok = true;
			}
		}
	}

	Share10Cards();

}

void Game::Share10Cards()
{
	m_deck.ShuffleDeck();
	for (int index = 0; index < m_noPlayers; index++)
	{
		//Player currentPlayer = m_players[index];
		for (int index2 = 0; index2 < 10; index2++)
		{
			m_players[index].m_handCards.push_back(m_deck.PickCardFromDeck());
		}
	}
}

void Game::StartGame()
{
	ReadPlayers();
	Player currentPlayer;
	Board board;
	Phase phase;


	//TODO while nu a castigat nimeni 
	for (int indexPlayer = 0; indexPlayer < m_noPlayers; indexPlayer++)
	{
		system("cls");
		board.ShowDisplayedCards(m_players);
		currentPlayer = m_players[indexPlayer];
		std::cout << "\n" << currentPlayer;

		bool skipped = false;
		for (std::string name : m_playersToSkip)
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
			system("pause");
		}

		else
		{
			PickCard(currentPlayer);

			for (int index = 0; index < currentPlayer.m_handCards.size(); index++)
			{
				std::cout << index + 1 << ". " << currentPlayer.m_handCards[index];
			}

			if (currentPlayer.m_displayedCards.empty())
			{
				std::string auxOption;
				int option;
				bool ok = true;
				do {
					try
					{
						std::cout << "\nDo you want to display (choose 1 for yes and 2 for no)?\n";
						std::cin >> auxOption;
						if (auxOption.size() == 1) {

							std::stringstream intNumber(auxOption);
							int x = -1;
							intNumber >> x;
							if (x == 2 || x == 1)
							{
								option = x;
								ok = true;
							}

							else {
								throw std::runtime_error("\nYou have to insert a valid option!\n");
							}
						}
						else {
							throw std::runtime_error("\nYou have to insert a valid option!\n");
						}
					}

					catch (std::runtime_error& e)
					{
						ok = false;
						std::cout << "\nYou have to insert a valid option!\n";
						std::cin.clear();
						std::string tmp;
						getline(std::cin, tmp);
					}

				} while (ok == false);

				switch (option)
				{
				case 1: {
					phase.IsPhase(currentPlayer);
					if (!currentPlayer.m_displayedCards.empty())
						option = 0;
					break;
				}

				case 2: {
					break;
				}

				default:
					break;
				}
			}

			std::cout << "\nRemaining cards are:\n";
			for (int index2 = 0; index2 < currentPlayer.m_handCards.size(); index2++)
			{
				std::cout << index2 + 1 << ". " << currentPlayer.m_handCards[index2];
			}

			std::cout << "\nMy displayed cards are:\n";
			for (int index = 0; index < currentPlayer.m_displayedCards.size(); index++)
			{
				for (int index2 = 0; index2 < currentPlayer.m_displayedCards[index].size(); index2++)
				{
					std::cout << currentPlayer.m_displayedCards[index][index2];
				}
				std::cout << std::endl;
			}

			if (!currentPlayer.m_displayedCards.empty())
			{
				m_players[indexPlayer] = currentPlayer;
				int option;
				std::string auxOption;
				bool ok = true;

				do {
					try
					{
						std::cout << "\nDo you want to annex a card (choose 1 for yes and 2 for no)? \n";
						std::cin >> auxOption;
						if (auxOption.size() == 1) {

							std::stringstream intNumber(auxOption);
							int x = -1;
							intNumber >> x;
							if (x == 2 || x == 1)
							{
								option = x;
								ok = true;
							}

							else {
								throw std::runtime_error("\nYou have to insert a valid option!\n");
							}
						}
						else {
							throw std::runtime_error("\nYou have to insert a valid option!\n");
						}
					}

					catch (std::runtime_error& e)
					{
						ok = false;
						std::cout << "\nYou have to insert a valid option!\n";
						std::cin.clear();
						std::string tmp;
						getline(std::cin, tmp);
					}

				} while (ok == false);

				switch (option)
				{
				case 1: {
					int indexCard;
					Card cardToAnnex;

					//TODO try catch for which card
					std::cout << "\nWhich card?\n";
					std::cin >> indexCard;
					cardToAnnex = currentPlayer.m_handCards[indexCard - 1];
					ShowPlayers(m_players);

					std::string auxNumber;
					bool ok = true;
					std::cin.exceptions(std::istream::failbit);
					int option;

					do
					{
						try
						{
							std::cout << "\nPlayer (choose id):\n";
							std::cin >> auxNumber;
							if (auxNumber.size() == 1) {
								std::stringstream intNumber(auxNumber);
								int x;
								intNumber >> x;
								if (x <= m_noPlayers - 1 && x >= 1)
								{
									option = x;
									option--;
									AnnexCard(m_players, indexCard - 1, option);
									ok = true;
								}

								else {
									throw std::runtime_error("\nYou have to insert a valid option \n");
								}
							}
							else {
								throw std::runtime_error("\nYou have to insert a valid option \n");
							}
						}

						catch (std::runtime_error& e)
						{
							ok = false;
							std::cout << "\nYou have to insert a digit between 1 and " << m_noPlayers << std::endl;
							std::cin.clear();
							std::string tmp;
							getline(std::cin, tmp);
						}

					} while (ok == false);

					break;
				}

				case 0: {
					break;
				}

				default:
					break;
				}
			}

			DecartCard(currentPlayer);
		}
	}

}

void Game::TestGame()
{
	/*Phase phase;
	Board board;

	ReadPlayers();

	int index = 0;
	while (index < m_noPlayers)
	{
		Player player = m_players.front();
		m_players.pop();
		phase.isPhase(player);
		m_players.push(player);
		index++;
	}
	board.ShowDisplayedCards(m_players);*/

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
	std::string auxNumber;
	bool ok = true;
	std::cin.exceptions(std::istream::failbit);

	int option;
	do
	{
		try
		{
			std::cout << "Choose a card to discard from your hand (from 1 to " << player.m_handCards.size() << ") : ";

			std::cin >> auxNumber;
			if (auxNumber.size() == 1) {
				std::stringstream intNumber(auxNumber);
				int x;
				intNumber >> x;
				if (x <= player.m_handCards.size() - 1 && x >= 1)
				{
					option = x;
					option--;
					ok = true;
				}

				else {
					throw std::runtime_error("\nYou have to insert a valid option \n");
				}
			}
			else {
				throw std::runtime_error("\nYou have to insert a valid option \n");
			}
		}

		catch (std::runtime_error& e)
		{
			ok = false;
			std::cout << "\nYou have to insert a digit between 1 and " << player.m_handCards.size() << std::endl;
			std::cin.clear();
			std::string tmp;
			getline(std::cin, tmp);
		}

	} while (ok == false);

	Card decarted = player.DropCard(option);
	decarted.SetPlace(Place::DECARTED);
	m_decartedCards.push(decarted);

	if (decarted.GetStatus() == Status::SKIP)
	{
		ShowPlayers(m_players);
		
		std::string auxNumber;
		bool ok = true;
		std::cin.exceptions(std::istream::failbit);
		int option;

		do
		{
			try
			{
				std::cout << "Which player do you want to skip? (choose id)" << "\n";

				std::cin >> auxNumber;
				if (auxNumber.size() == 1) {
					std::stringstream intNumber(auxNumber);
					int x;
					intNumber >> x;
					if (x <= m_noPlayers - 1 && x >= 1)
					{
						option = x;
						option--;
						m_playersToSkip.push_back(m_players[option].GetName());
						ok = true;
					}

					else {
						throw std::runtime_error("\nYou have to insert a valid option \n");
					}
				}
				else {
					throw std::runtime_error("\nYou have to insert a valid option \n");
				}
			}

			catch (std::runtime_error& e)
			{
				ok = false;
				std::cout << "\nYou have to insert a digit between 1 and " << m_noPlayers << std::endl;
				std::cin.clear();
				std::string tmp;
				getline(std::cin, tmp);
			}

		} while (ok == false);
	}

}

Card Game::PickCardFromDecartedStack()
{
	Card card = m_decartedCards.top();
	card.SetPlace(Place::HAND);
	m_decartedCards.pop();
	return card;
}

void Game::PickCard(Player& player)
{
	if (m_decartedCards.empty())
	{
		Card card = m_deck.PickCardFromDeck();
		player.m_handCards.push_back(card);
	}
	else
	{
		int option;
		do {
			std::string auxOption;
			bool ok = true;
			do {

				try
				{
					std::cout << "From where do you want to pick a card?\n";
					std::cout << "1.Deck\n";
					std::cout << "2.Decarted Cards: " << m_decartedCards.top() << "\n";

					std::cin >> auxOption;
					if (auxOption.size() == 1) {

						std::stringstream intNumber(auxOption);
						int x = -1;
						intNumber >> x;
						if (x == 2 || x == 1)
						{
							option = x;
							ok = true;
						}

						else {
							throw std::runtime_error("\nYou have to insert a valid option!\n");
						}
					}
					else {
						throw std::runtime_error("\nYou have to insert a valid option!\n");
					}
				}

				catch (std::runtime_error& e)
				{
					ok = false;
					std::cout << "\nYou have to insert a valid option!\n";
					std::cin.clear();
					std::string tmp;
					getline(std::cin, tmp);
				}

			} while (ok == false);


			switch (option)
			{
			case 1:
			{
				Card card = m_deck.PickCardFromDeck();
				player.m_handCards.push_back(card);
				break;
			}
			case 2:
			{
				if (m_decartedCards.top().GetStatus() == Status::SKIP)
				{
					std::cout << "You can't pick that card.\nYou received a card from deck.\n";
					Card card = PickCardFromDecartedStack();
					player.m_handCards.push_back(card);
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

		} while (option != 1 && option != 2);
	}

}

void Game::CountScore(Player& player)
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

//TODO cred ca nu ne mai trebuie ca nu mai cautam numele
Player Game::SearchPlayer(std::vector<Player> players, std::string name) const
{
	Player returnedPlayer;
	for(int indexPlayer=0; indexPlayer<m_noPlayers;indexPlayer++)
	{
		Player player = players[indexPlayer];
		if (player.GetName() == name && !player.m_displayedCards.empty())
		{
			returnedPlayer = player;
		}
	}
	return returnedPlayer;

}

//TODO Annex Card
void Game::AnnexCard(std::vector<Player>& players, int indexCard, int indexId)
{
	/*for (int indexPlayer = 0; indexPlayer < players.size(); indexPlayer++)
	{*/	//std::vector<std::vector<Card>> auxDisplayedCard = players[indexPlayer].m_displayedCards;
			bool ok = false;
			std::vector<Card>vector;
			Phase phase;
			Card card = players[indexId].m_handCards[indexCard];

			for (int index = 0; index < players[indexId].m_displayedCards.size(); index++)
			{
				vector = players[indexId].m_displayedCards[index];
				vector.push_back(card);
				if (phase.IsColor(vector) || phase.IsRun(vector) || phase.IsSet(vector))
				{
					players[indexId].m_displayedCards[index] = vector;
					//std::cout << "Yeeeee1";
					ok = true;

					for (int index2 = indexCard; index2 < players[indexId].m_handCards.size() - 1; index2++)
					{
						players[indexId].m_handCards[index2] = players[indexId].m_handCards[index2 + 1];
					}

					players[indexId].m_handCards.pop_back();
					break;
				}
				else
				{
					vector.pop_back();
					int size = vector.size();
					size++;
					vector.resize(size);
					for (int index = vector.size() - 1; index >= 0; index--)
					{
						vector[index] = vector[index - 1];
					}
					vector[0] = card;

					if (phase.IsColor(vector) || phase.IsRun(vector) || phase.IsSet(vector))
					{
						players[indexId].m_displayedCards[index] = vector;
						//std::cout << "Yeeeee2";
						ok = true;
						
						for (int index2 = indexCard; index2 < players[indexId].m_handCards.size() - 1; index2++)
						{
							players[indexId].m_handCards[index2] = players[indexId].m_handCards[index2 + 1];
						}

						players[indexId].m_handCards.pop_back();
						break;
					}
				}

			}
				if (ok)
					std::cout << "Annexed the card.\n";
				else
					std::cout << "Could not annex.\n";

				for (int index = 0; index < players[indexId].m_handCards.size(); index++)
				{
					std::cout << index + 1 <<" "<< players[indexId].m_handCards[index];
			    }
				std::cout << "\n";
		
	//}
}


