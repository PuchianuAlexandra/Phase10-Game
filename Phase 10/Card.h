#pragma once
#include<cstdint>

class Card
{

public:
	enum class Color : uint8_t { Red, Green, Yellow, Blue };
	enum class Status :uint8_t { Normal, Skip, Wild };
	enum class Place : uint8_t { Deck, Decarted, Displayed, Hand };

	Card(Color color, Status status, Place place, uint8_t value);
	~Card();

private:
	Color m_color;
	Status m_status;
	Place m_place;
	uint8_t m_value;
};

