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

	for (int index = 0; index < player.m_phase.size()-1; index++)
	{
		if (player.m_phase[index]&&!player.m_phase[index+1])
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
				return false;
			}
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

			player.m_phase[current] = 1;
			//return true;
		}
		return true;
		break;
	}
	//case 1 end
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
				return false;
			}
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
		if (!isPhase2(chosenCards1, chosenCards2, incorrect))
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
			//return true;
		}
		return true;
		break;
	}
	//case 2 end
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
				return false;
			}
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
		if (!isPhase3(chosenCards1, chosenCards2, incorrect))
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
			//return true;
		}
		return true;
		break;
	}
	//case3 end
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
					return false;
				}
			}
		}

		if (!isPhase4(chosenCards1))
		{
			return false;
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
			//return true;
		}
		return true;
		break;
	}
	//case4 end
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
					return false;
				}
			}
		}

		if (!isPhase5(chosenCards1))
		{
			return false;
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
			//return true;
		}
		return true;
		break;
	}
	//case5 end
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
					return false;
				}
			}
		}

		if (!isPhase6(chosenCards1))
		{
			return false;
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
			//return true;
		}
		return true;
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
			return false;
		}
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
	if (!isPhase7(chosenCards1, chosenCards2, incorrect))
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
		//return true;
	}
	return true;
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
					return false;
				}
			}
		}

		if (!isPhase8(chosenCards1))
		{
			return false;
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
			//return true;
		}
		return true;
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
				return false;
			}
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
		if (!isPhase9(chosenCards1, chosenCards2, incorrect))
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
			//return true;
		}
		return true;
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
				return false;
			}
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
		if (!isPhase10(chosenCards1, chosenCards2, incorrect))
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
		return true;
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
		std::cin >> option;
		options.push_back(option);
		chosenCards.push_back(player.m_handCards[--option]);
	}
}
//
//void Phase::ModifyHandCards2(Player & player, std::vector<int> options1, std::vector<int> options2)
//{
//	std::vector <Card> newHandCards;
//	for (int index = 0; index < player.m_handCards.size(); index++)
//	{
//		for (int index2 = 0; index2 < options1.size(); index2++)
//		{
//			if (index != (options1[index2] - 1) && index != (options2[index2] - 1))
//
//				newHandCards.push_back(player.m_handCards[index]);
//			
//
//		}
//		newHandCards.pop_back();
//		newHandCards.pop_back();
//	}
//
//	player.m_handCards = newHandCards;
//}

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



