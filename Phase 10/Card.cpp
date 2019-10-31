#include "Card.h"



Card::Card(Color color, Status status, Place place, uint8_t value) :
	m_color(color), m_status(status), m_place(place), m_value(value)
{
}

Card::~Card()
{
}
