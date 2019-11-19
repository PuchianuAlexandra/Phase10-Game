#include "Phase.h"
#include"Card.h"


bool Phase::isSet(std::vector<Card> cards)
{
	Status value = Status::WILD;
	for (Card card : cards)
	{
		if (card.GetStatus() == Status::SKIP)
		{
			//std::cout << "You picked a Skip card!";
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
				//std::cout << "Your set is not valid!";
				return false;
			}
		}
	}
	return true;

}

bool Phase::isRun(std::vector<Card> cards)
{
	int no = 0;
	int countWild = 0;
	for (auto it = 0; it <= cards.size() - 1; it++)
	{
		if (cards[it].GetStatus() == Status::SKIP)
		{
			//std::cout << "You picked a Skip card!";
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

bool Phase::isColor(std::vector<Card> cards)
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

bool Phase::isPhase(Player & player)
{
	int current = 0;

	for (int index = 0; index < player.m_phase.size(); index++)
	{
		if (player.m_phase[index])
			current = index + 1;
	}

	std::vector<Card> chosenCards1, chosenCards2;
	int index = 0;

	switch (current)
	{
	case 1:
	{
		std::vector<int> options1, options2;
		std::cout << "Choose cards for a set of three:\n";
		for (int index=0; index<3;index++)
		{
			int option;
			std::cin >> option;
			options1.push_back(option);
			chosenCards1.push_back(player.m_handCards[--option]);
		}
		std::cout << "Choose cards for a set of three:\n";
		for (int index = 0; index < 3; index++)
		{
			int option;
			std::cin >> option;
			options2.push_back(option);
			chosenCards2.push_back(player.m_handCards[--option]);
			
		}

		for (int index = 0; index < options1.size() - 1; index++)
		{
			for (int index2 = index + 1; index2 < options1.size(); index2++)
			{
				if (options1[index] == options1[index2] || options2[index] == options2[index2])
				{
					std::cout << "You can't insert the same card twice.\n";
					return false;
				}
			}
		}
		
		int incorrect = 0;
		if (!isPhase1(chosenCards1, chosenCards2, incorrect))
		{
			if (incorrect == 1)
				std::cout << "The first set is incorrect!\n";
			if (incorrect == 2)
				std::cout << "The second set is incorrect!\n";
			return false;
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

		}

	}
case2:
	{
	std::vector<int> options1, options2;
	std::cout << "Choose cards for a set of three:\n";
	for (int index = 0; index < 3; index++)
	{
		int option;
		std::cin >> option;
		options1.push_back(option);
		chosenCards1.push_back(player.m_handCards[--option]);
	}
	std::cout << "Choose cards for a run of four:\n";
	for (int index = 0; index < 4; index++)
	{
		int option;
		std::cin >> option;
		options2.push_back(option);
		chosenCards2.push_back(player.m_handCards[--option]);

	}

	for (int index = 0; index < options1.size() - 1; index++)
	{
		for (int index2 = index + 1; index2 < options1.size(); index2++)
		{
			if (options1[index] == options1[index2] || options2[index] == options2[index2])
			{
				std::cout << "You can't insert the same card twice.\n";
				return false;
			}

			if (options1[index] == options1[index2] || options2[index] == options2[index2])
			{
				std::cout << "You can't insert the same card twice.\n";
				return false;
			}
		}
	}


	int incorrect = 0;
	if (!isPhase1(chosenCards1, chosenCards2, incorrect))
	{
		if (incorrect == 1)
			std::cout << "The first set is incorrect!\n";
		if (incorrect == 2)
			std::cout << "The second set is incorrect!\n";
		return false;
	}
	else {
		std::vector <Card> newHandCards;
		for (int index = 0; index < player.m_handCards.size(); index++)
		{
			for (int index2 = 0; index2 < 3; index2++)
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

	}
	}
	default:
		break;
	}	
}

bool Phase::isPhase1(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase2(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isRun(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase3(std::vector<Card> cards1, std::vector<Card> cards2, int & incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isRun(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase4(std::vector<Card> cards)
{
	if (cards.size() != 7)
		return false;
	
	if (!isRun(cards))
		return false;

	return true;
}

bool Phase::isPhase5(std::vector<Card> cards)
{
	if (cards.size() != 8)
		return false;

	if (!isRun(cards))
		return false;

	return true;
}

bool Phase::isPhase6(std::vector<Card> cards)
{
	if (cards.size() != 9)
		return false;

	if (!isRun(cards))
		return false;

	return true;
}

bool Phase::isPhase7(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase8(std::vector<Card> cards)
{
	if (cards.size() != 7)
		return false;

	if (!isColor(cards))
		return false;

	return true;
}

bool Phase::isPhase9(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase10(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect)
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

	if (!isSet(cards1))
	{
		incorrect = 1;
		return false;
	}

	if (!isSet(cards2))
	{
		incorrect = 2;
		return false;
	}

	return true;
}



