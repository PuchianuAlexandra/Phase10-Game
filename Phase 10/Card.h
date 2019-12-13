#pragma once

#include <cstdint>
#include <iostream>

#include "Color.h"
#include "Status.h"
#include "Place.h"

class Card
{

public:
	Card();
	Card(Color color, Status status, Place place);
	~Card();
	bool operator ==(Card card);
public:
	Color GetColor() const;
	Status GetStatus() const;
	Place GetPlace() const;
	void SetPlace(Place place);     //TODO to change the place when it's the case

public:
	friend std::ostream& operator<<(std::ostream& out, const Card& card);

private:
	Color m_color;
	Status m_status;
	Place m_place;
};

