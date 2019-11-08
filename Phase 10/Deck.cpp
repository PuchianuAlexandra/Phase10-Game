#include "Deck.h"

Deck::Deck() 
{	
	for (int status = static_cast<int>(Status::ONE) ; status <= static_cast<int>(Status::WILD); status++)
	{
		for (int color = static_cast<int>(Color::Red) ; color <= static_cast<int>(Color::Blue) ; color++)
		{
			Card card(static_cast<Color>(color), static_cast<Status>(status), Place::Deck);
			m_deck.push_back(card);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	for (const Card card : deck.m_deck)
	{
		os << card << " ";
	}
	os << "\n";
	return os;
}
