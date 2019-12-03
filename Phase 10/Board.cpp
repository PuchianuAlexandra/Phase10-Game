#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::ShowDisplayedCards(std::vector<Player> players) const
{
	for(int index=0; index<players.size();index++)
	{
		Player player = players[index];
		int currentPhase = 0;
		
		for (int index2 = 0; index2 < player.m_phase.size() - 1; index2++)
		{
			if (player.m_phase[index2] && !player.m_phase[index2 + 1])
			{
				currentPhase = index2 + 1;
				break;
			}
		}

		std::cout << player.GetName() << "'s current phase is " << currentPhase<<"\n";
		std::cout << player.GetName() << "'s displayed cards are:\n";

		for (int index2 = 0; index2 < player.m_displayedCards.size(); index2++)
		{
			for (int index3 = 0; index3 < player.m_displayedCards[index2].size(); index3++)
			{
				std::cout << player.m_displayedCards[index2][index3];
			}
			std::cout << std::endl;
		}
	}
}
