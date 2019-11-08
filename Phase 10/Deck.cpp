#include "Deck.h"

Deck::Deck() 
{	
	for (int status = static_cast<int>(Status::ONE) ; status <= static_cast<int>(Status::TWELVE); status++)
	{
		for (int color = static_cast<int>(Color::RED) ; color <= static_cast<int>(Color::BLUE) ; color++)
		{
			Card card(static_cast<Color>(color), static_cast<Status>(status), Place::DECK);
			m_deck.push_back(card);
			m_deck.push_back(card);
		}
	}

	Card skip(Color::BLACK, Status::SKIP, Place::DECK);
	for (int index = 0; index <= 3; index++)
	{
		m_deck.push_back(skip);
	}

	Card wild(Color::BLACK, Status::WILD, Place::DECK);
	for (int index = 0; index <= 7; index++)
	{
		m_deck.push_back(wild);
	}

	this->ShuffleDeck();

	for (Card card : m_deck)
	{
		std::cout << card << "\n";
	}
}

void Deck::ShuffleDeck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(m_deck), std::end(m_deck), rng);
}

/*std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	for (const Card card : deck.m_deck)
	{
		os << card << " ";
	}
	os << "\n";
	return os;
}*/
