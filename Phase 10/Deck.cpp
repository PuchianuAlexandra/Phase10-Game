#include "Deck.h"

Deck::Deck(std::array<Card*, 108> deck) {
	
	int index = 0;
	for (int status = Status::ONE ; status != Status::WILD; status++)
	{
		for (int color = Color::Red ; color != Color::Blue ; color++)
		{
			deck[index] = new Card(static_cast<Color>(color), static_cast<Status>(status), Place::Deck);
			index++;
		}
	}
}
