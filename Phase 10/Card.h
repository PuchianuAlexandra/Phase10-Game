#pragma once

#include <iostream>

#include "Color.h"
#include "Status.h"

class Card
{

public:
	Card();
	Card(Color color, Status status);
	~Card();
	
	bool operator ==(Card card);
	bool operator !=(Card card);

public:
	Color GetColor() const;
	Status GetStatus() const;
	friend std::ostream& operator<<(std::ostream& out, const Card& card);

private:
	Color m_color;
	Status m_status;
};

