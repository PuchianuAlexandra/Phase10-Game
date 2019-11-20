#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::ShowDisplayedCards(std::queue<Player> players) const
{
	int no = players.size();
	while (no)
	{
		Player player = players.front();
		players.pop();
		std::cout << player.GetName() << "'s cards are:\n";
		for (int index = 0; index < player.m_displayedCards.size(); index++)
		{
			for (int index2 = 0; index2 < player.m_displayedCards[index].size(); index2++)
			{
				std::cout << player.m_displayedCards[index][index2];
			}
			std::cout << std::endl;
		}
		players.push(player);
		no--;
	}
}
