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
		int current = 0;
		
		for (int index = 0; index < player.m_phase.size() - 1; index++)
		{
			if (player.m_phase[index] && !player.m_phase[index + 1])
			{
				current = index + 1;
				break;
			}
		}
		std::cout << player.GetName() << "'s current phase is " << current<<"\n";
		std::cout << player.GetName() << "'s displayed cards are:\n";
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
