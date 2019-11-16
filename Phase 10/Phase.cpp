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

/*bool Phase::isPhase(Player & player)
{
	int current = 0;

	for (int index = 0; index < player.m_phase.size(); index++)
	{
		if (player.m_phase[index])
			current = index + 1;
	}

	std::vector<Card> chosenCards, chosenCards2;
	int index = 0;

	switch (current)
	{
	case 1:
	{
		std::cout << "Choose cards for a set of three: \n";
		
		index = 0;

		while (index < 3)
		{
			chosenCards.push_back(player.DropCard());
			index++;
		}


		std::cout << "Carti ramase: \n";
		for (Card card : player.m_handCards)
		{
			std::cout << card << "\n";
		}

		std::cout << "Choose cards for another set of three: \n";

		index = 0;
		while (index < 3)
		{
			chosenCards2.push_back(player.DropCard());
			index++;
		}

		int incorrect = 0;
		if (isPhase1(chosenCards, chosenCards2, incorrect))
		{
			
			return true;

		}
		else
		{
			for (int index = chosenCards.size() - 1; index >= 0; index--)
			{
				chosenCards[index].SetPlace(Place::HAND);
				player.m_handCards.push_back(chosenCards[index]);
				chosenCards.pop_back();
			}

			for (int index = chosenCards2.size() - 1; index >= 0; index--)
			{
				chosenCards2[index].SetPlace(Place::HAND);
				player.m_handCards.push_back(chosenCards2[index]);
				chosenCards2.pop_back();
			}

			return false;
		}
	}
	default:
		break;
	}
	
}
*/
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



