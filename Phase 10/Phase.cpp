#include <sstream>
#include "Phase.h"
#include"Card.h"


bool Phase::IsSet(std::vector<Card> cards)
{
	Status value = Status::WILD;
	for (Card card : cards)
	{
		if (card.GetStatus() == Status::SKIP)
		{
			return false;
		}
		else
			if (card.GetStatus() <= Status::TWELVE)
			{
				value = card.GetStatus();
				break;
			}
	}
	if (value != Status::WILD)
	{
		for (Card card : cards)
		{
			if (value != card.GetStatus() && card.GetStatus() != Status::WILD)
			{
			
				return false;
			}
		}
	}
	return true;

}

bool Phase::IsRun(std::vector<Card> cards)
{
	int no = 0;
	int countWild = 0;
	for (auto it = 0; it <= cards.size() - 1; it++)
	{
		if (cards[it].GetStatus() == Status::SKIP)
		{
			return false;
		}
		else
		{
			if (cards[it].GetStatus() == Status::WILD)
			{
				countWild++;
			}
			else
			{
				if (no == 0)
				{
					if (static_cast<int>(cards[it].GetStatus()) < it + 1 || cards.size() - it > 13 - static_cast<int>(cards[it].GetStatus()))  //wild-uri si carte
					{
						return false;
					}
					else
					{
						no = static_cast<int>(cards[it].GetStatus());
						countWild = 0;
					}
				}
				else
				{
					if (countWild != 0)
					{
						if (static_cast<int>(cards[it].GetStatus()) - no != countWild + 1)
							return false;
					}
					else
					{
						if (static_cast<int>(cards[it].GetStatus()) - no != 1)
							return false;
					}
					countWild = 0;
				}
				no = static_cast<int>(cards[it].GetStatus());
			}
		}
	}
	return true;
}

bool Phase::IsColor(std::vector<Card> cards)
{
	Color value = Color::BLACK;
	for (Card card : cards)
	{
		if (card.GetStatus() == Status::SKIP)
		{
			return false;
		}
		else
			if (card.GetColor() <= Color::BLUE)
			{
				value = card.GetColor();
				break;
			}
	}
	if (value != Color::BLACK)
	{
		for (Card card : cards)
		{
			if (value != card.GetColor() && card.GetColor() != Color::BLACK)
			{
				return false;
			}
		}
	}
	return true;
}

void Phase::IsPhase(Player & player)
{
	int current = 0;

	for (int index = 0; index < player.m_phase.size()-1; index++)
	{
		if (player.m_phase[index] && !player.m_phase[index + 1])
		{
			current = index + 1;
			break;
		}
	}

	std::vector<Card> chosenCards1, chosenCards2;
	int index = 0;

	switch (current)
	{
	case 1:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of three:\n";
		ChoseCards(3, player, options1, chosenCards1);
		
		std::cout << "Choose cards for a set of three:\n";
		ChoseCards(3, player, options2, chosenCards2);

		std::vector<int>::iterator it;
		for (int index = 0; index < options2.size(); index++)
		{
			it = std::find(options1.begin(), options1.end(), options2[index]);
			if (it != options1.end())
			{
				std::cout << "You can't choose the same card twice.\n";
				return;
			}
		}
		
		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}
		
		int incorrect = 0;
		if (!IsPhase1(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2=0; index2 < 3; index2++)
				{
					if (index != (options1[index2]-1) && index != (options2[index2]-1))
						 
						newHandCards.push_back(player.m_handCards[index]);
					   
				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}

			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);
			player.m_displayedCards.push_back(chosenCards2);

			player.m_phase[current] = 1;
		}
		break;
	}

	case 2:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of three:\n";
		ChoseCards(3, player, options1, chosenCards1);

		std::cout << "Choose cards for a run of four:\n";
		ChoseCards(4, player, options2, chosenCards2);

		std::vector<int>::iterator it;
		for (int index = 0; index < options2.size(); index++)
		{
			it = std::find(options1.begin(), options1.end(), options2[index]);
			if (it != options1.end())
			{
				std::cout << "You can't choose the same card twice.\n";
				return;
			}
		}

		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		int incorrect = 0;
		if (!IsPhase2(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options1.size(); index2++)
				{
					if (index != (options1[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				for (int index2 = 0; index2 < options2.size(); index2++)
				{
					if (index != (options2[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);
			player.m_displayedCards.push_back(chosenCards2);

			player.m_phase[current] = 1;
		}
		break;
	}
	
	case 3:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of four:\n";
		ChoseCards(4, player, options1, chosenCards1);

		std::cout << "Choose cards for a run of four:\n";
		ChoseCards(4, player, options2, chosenCards2);

		std::vector<int>::iterator it;
		for (int index = 0; index < options2.size(); index++)
		{
			it = std::find(options1.begin(), options1.end(), options2[index]);
			if (it != options1.end())
			{
				std::cout << "You can't choose the same card twice.\n";
				return;
			}
		}

		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		int incorrect = 0;
		if (!IsPhase3(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options1.size(); index2++)
				{
					if (index != (options1[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				for (int index2 = 0; index2 < options2.size(); index2++)
				{
					if (index != (options2[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);
			player.m_displayedCards.push_back(chosenCards2);

			player.m_phase[current] = 1;
		}
		break;
	}
	
	case 4:
	{
		std::vector<int> options;
		std::cout << "Choose cards for a run of seven:\n";
		ChoseCards(7, player, options, chosenCards1);

		for (int index = 0; index < options.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options.size(); index2++)
			{
				if (options[index] == options[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		if (!IsPhase4(chosenCards1))
		{
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options.size(); index2++)
				{
					if (index != (options[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);

			player.m_phase[current] = 1;
		}
		break;
	}
	
	case 5:
	{
		std::vector<int> options;
		std::cout << "Choose cards for a run of eight:\n";
		ChoseCards(8, player, options, chosenCards1);

		for (int index = 0; index < options.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options.size(); index2++)
			{
				if (options[index] == options[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		if (!IsPhase5(chosenCards1))
		{
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options.size(); index2++)
				{
					if (index != (options[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);

			player.m_phase[current] = 1;
		}
		break;
	}

	case 6:
	{
		std::vector<int> options;
		std::cout << "Choose cards for a run of nine:\n";
		ChoseCards(9, player, options, chosenCards1);

		for (int index = 0; index < options.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options.size(); index2++)
			{
				if (options[index] == options[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		if (!IsPhase6(chosenCards1))
		{
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options.size(); index2++)
				{
					if (index != (options[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);

			player.m_phase[current] = 1;
		}
		break;
	}

	case 7:
	{
	std::vector<int> options1, options2;
	std::cout << "Choose cards for a set of four:\n";
	ChoseCards(4, player, options1, chosenCards1);

	std::cout << "Choose cards for a set of four:\n";
	ChoseCards(4, player, options2, chosenCards2);

	std::vector<int>::iterator it;
	for (int index = 0; index < options2.size(); index++)
	{
		it = std::find(options1.begin(), options1.end(), options2[index]);
		if (it != options1.end())
		{
			std::cout << "You can't choose the same card twice.\n";
			return;
		}
	}

	for (int index = 0; index < options1.size() - 1; index++)
	{
		for (int index2 = index + 1; index2 < options1.size(); index2++)
		{
			if (options1[index] == options1[index2] || options2[index] == options2[index2])
			{
				std::cout << "You can't insert the same card twice.\n";
				return;
			}
		}
	}

	int incorrect = 0;
	if (!IsPhase7(chosenCards1, chosenCards2, incorrect))
	{
		if (incorrect == 1)
			std::cout << "The first set is incorrect!\n";
		if (incorrect == 2)
			std::cout << "The second set is incorrect!\n";
		return;
	}
	else {
		std::vector <Card> newHandCards;
		for (int index = 0; index < player.m_handCards.size(); index++)
		{
			for (int index2 = 0; index2 < 4; index2++)
			{
				if (index != (options1[index2] - 1) && index != (options2[index2] - 1))

					newHandCards.push_back(player.m_handCards[index]);

			}
			newHandCards.pop_back();
			newHandCards.pop_back();
		}

		player.m_handCards = newHandCards;
		player.m_displayedCards.push_back(chosenCards1);
		player.m_displayedCards.push_back(chosenCards2);

		player.m_phase[current] = 1;
	}
	break;
	}

	case 8:
	{
		std::vector<int> options;
		std::cout << "Choose seven cards with the same color:\n";
		ChoseCards(7, player, options, chosenCards1);

		for (int index = 0; index < options.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options.size(); index2++)
			{
				if (options[index] == options[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		if (!IsPhase8(chosenCards1))
		{
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options.size(); index2++)
				{
					if (index != (options[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}


			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);

			player.m_phase[current] = 1;
		}
		break;
	}

	case 9:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of five:\n";
		ChoseCards(5, player, options1, chosenCards1);

		std::cout << "Choose cards for a set of two:\n";
		ChoseCards(2, player, options2, chosenCards2);

		std::vector<int>::iterator it;
		for (int index = 0; index < options2.size(); index++)
		{
			it = std::find(options1.begin(), options1.end(), options2[index]);
			if (it != options1.end())
			{
				std::cout << "You can't choose the same card twice.\n";
				return;
			}
		}

		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		int incorrect = 0;
		if (!IsPhase9(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options1.size(); index2++)
				{
					if (index != (options1[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				for (int index2 = 0; index2 < options2.size(); index2++)
				{
					if (index != (options2[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}

			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);
			player.m_displayedCards.push_back(chosenCards2);

			player.m_phase[current] = 1;
		}
		break;
	}

	case 10:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of five:\n";
		ChoseCards(5, player, options1, chosenCards1);

		std::cout << "Choose cards for a set of three:\n";
		ChoseCards(3, player, options2, chosenCards2);

		std::vector<int>::iterator it;
		for (int index = 0; index < options2.size(); index++)
		{
			it = std::find(options1.begin(), options1.end(), options2[index]);
			if (it != options1.end())
			{
				std::cout << "You can't choose the same card twice.\n";
				return;
			}
		}

		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return;
				}
			}
		}

		int incorrect = 0;
		if (!IsPhase10(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return;
		}
		else {
			std::vector <Card> newHandCards;
			for (int index = 0; index < player.m_handCards.size(); index++)
			{
				for (int index2 = 0; index2 < options1.size(); index2++)
				{
					if (index != (options1[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				for (int index2 = 0; index2 < options2.size(); index2++)
				{
					if (index != (options2[index2] - 1))

						newHandCards.push_back(player.m_handCards[index]);

				}
				newHandCards.pop_back();
				newHandCards.pop_back();
			}

			player.m_handCards = newHandCards;
			player.m_displayedCards.push_back(chosenCards1);
			player.m_displayedCards.push_back(chosenCards2);

			player.m_phase[current] = 1;
		}
		break;
	}
	default:
		break;
	}	
}

void Phase::ChoseCards(int no, Player player, std::vector<int>& options, std::vector<Card>& chosenCards)
{
	for (int index = 0; index < no; index++)
	{
		int option;
		std::string auxOption;
		bool ok = true;
		do {
			try
			{
				std::cin >> auxOption;
				if (auxOption.size() <= 2) {

					std::stringstream intNumber(auxOption);
					int x = -1;
					intNumber >> x;
					if (x <= player.m_handCards.size() && x >= 1)
					{
						option = x;
						options.push_back(option);
						chosenCards.push_back(player.m_handCards[--option]);
						ok = true;
					}

					else {
						throw std::runtime_error("\nYou have to insert a valid option!\n");
						options.clear();
						chosenCards.clear();
						index =0;
					}
				}
				else {
					options.clear();
					chosenCards.clear();
					index = 0;
					throw std::runtime_error("\nYou have to insert a valid option!\n");
				}
			}

			catch (std::runtime_error & e)
			{
				ok = false;
				std::cout << "\nYou have to insert a valid option!\n";
				std::cin.clear();
				std::string tmp;
				getline(std::cin, tmp);
			}

		} while (ok == false);
		
		
	}
}


bool Phase::IsPhase1(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
{
	if (cards1.size() != 3)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 3)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::IsPhase2(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
{
	if (cards1.size() != 3)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 4)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsRun(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::IsPhase3(std::vector<Card> cards1, std::vector<Card> cards2, int & incorrect)
{
	if (cards1.size() != 4)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 4)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsRun(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::IsPhase4(std::vector<Card> cards)
{
	if (cards.size() != 7)
		return false;
	
	if (!IsRun(cards))
		return false;

	return true;
}

bool Phase::IsPhase5(std::vector<Card> cards)
{
	if (cards.size() != 8)
		return false;

	if (!IsRun(cards))
		return false;

	return true;
}

bool Phase::IsPhase6(std::vector<Card> cards)
{
	if (cards.size() != 9)
		return false;

	if (!IsRun(cards))
		return false;

	return true;
}

bool Phase::IsPhase7(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
{
	if (cards1.size() != 4)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 4)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::IsPhase8(std::vector<Card> cards)
{
	if (cards.size() != 7)
		return false;

	if (!IsColor(cards))
		return false;

	return true;
}

bool Phase::IsPhase9(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
{
	if (cards1.size() != 5)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 2)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::IsPhase10(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
{
	if (cards1.size() != 5)
	{
		incorrect = 1;
		return false;
	}
	else
		if (cards2.size() != 3)
		{
			incorrect = 2;
			return false;
		}

	if (!IsSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!IsSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}
