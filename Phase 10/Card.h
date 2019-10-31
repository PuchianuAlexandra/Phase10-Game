#pragma once
#include<cstdint>
#include <iostream>

class Card
{

public:
	enum class Color : uint8_t { Red, Green, Yellow, Blue };
	enum class Status :uint8_t { Normal, Skip, Wild };
	enum class Place : uint8_t { Deck, Decarted, Displayed, Hand };

	Card(Color color, Status status, Place place, uint8_t value);
	~Card();

	Color GetColor() const;
	Status GetStatus() const;
	Place GetPlace() const;
	uint8_t GetValue() const;

	void SetPlace(Place place);     //to change the place when it's the case

	friend std::ostream& operator<<(std::ostream& out, const Card& card);

private:
	Color m_color;
	Status m_status;
	Place m_place;
	uint8_t m_value;
};

