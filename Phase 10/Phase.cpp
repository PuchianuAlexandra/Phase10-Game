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

bool Phase::isPhase1(std::vector<Card> cards1, std::vector<Card> cards2, int& inccorect)
{
	if (cards1.size() != 3)
	{
		inccorect = 1;
		return false;
	}
	else
		if (cards2.size() != 3)
		{
			inccorect = 2;
			return false;
		}

	if (!isSet(cards1))
	{
		inccorect = 1;
		return false;
	}

	if (!isSet(cards2))
	{
		inccorect = 2;
		return false;
	}

	return true;
}

bool Phase::isPhase2(std::vector<Card> cards1, std::vector<Card> cards2, int& inccorect)
{
	if (cards1.size() != 3)
	{
		inccorect = 1;
		return false;
	}
	else
		if (cards2.size() != 4)
		{
			inccorect = 2;
			return false;
		}

	if (!isSet(cards1))
	{
		inccorect = 1;
		return false;
	}

	if (!isRun(cards2))
	{
		inccorect = 2;
		return false;
	}

	return true;
}


