#include "Card.h"

Card::Card(Color color, Status status, Place place, uint8_t value) :
	m_color(color), m_status(status), m_place(place), m_value(value)
{
}

Card::~Card()
{
}

Card::Color Card::GetColor() const
{
	return m_color;
}

Card::Status Card::GetStatus() const
{
	return m_status;
}

Card::Place Card::GetPlace() const
{
	return m_place;
}

uint8_t Card::GetValue() const
{
	return m_value;
}

void Card::SetPlace(Place place)
{
	m_place = place;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	switch (card.m_color)
	{
	case Card::Color::Red: out << "Red ";
		break;
	case Card::Color::Yellow: out << "Yellow ";
		break;
	case Card::Color::Green: out << "Green ";
		break;
	case Card::Color::Blue: out << "Blue ";
		break;
	default:
		break;
	}

	switch (card.m_status)
	{
	case Card::Status::Normal: out << "Normal ";
		break;
	case Card::Status::Skip: out << "Skip ";
		break;
	case Card::Status::Wild: out << "Wild ";
		break;
	default:
		break;
	}

	switch (card.m_place)
	{
	case Card::Place::Deck: out << "Deck ";
		break;
	case Card::Place::Decarted: out << "Decarted ";
		break;
	case Card::Place::Hand: out << "Hand ";
		break;
	case Card::Place::Displayed: out << "Displayed ";
		break;
	default:
		break;
	}
	if (card.m_status == Card::Status::Normal)
		out << card.m_value;
	
	return out;
	
}
