#include "Card.h"

Card::Card(Color color, Status status, Place place) :
	m_color(color), m_status(status), m_place(place)
{
}

Card::Card()
{

}

Card::~Card()
{
}

Color Card::GetColor() const
{
	return m_color;
}

Status Card::GetStatus() const
{
	return m_status;
}

Place Card::GetPlace() const
{
	return m_place;
}

void Card::SetPlace(Place place)
{
	m_place = place;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	switch (card.m_color)
	{
	case Color::RED: out << "Red ";
		break;
	case Color::YELLOW: out << "Yellow ";
		break;
	case Color::GREEN: out << "Green ";
		break;
	case Color::BLUE: out << "Blue ";
		break;
	default:
		break;
	}

	switch (card.m_status)
	{
	case Status::ONE: out << "1 ";
		break;
	case Status::TWO: out << "2 ";
		break;
	case Status::THREE: out << "3 ";
		break;
	case Status::FOUR: out << "4 ";
		break;
	case Status::FIVE: out << "5 ";
		break;
	case Status::SIX: out << "6 ";
		break;
	case Status::SEVEN: out << "7 ";
		break;
	case Status::EIGHT: out << "8 ";
		break;
	case Status::NINE: out << "9 ";
		break;
	case Status::TEN: out << "10 ";
		break;
	case Status::ELEVEN: out << "11 ";
		break;
	case Status::TWELVE: out << "12 ";
		break;
	case Status::SKIP: out << "Skip ";
		break;
	case Status::WILD: out << "Wild ";
		break;
	default:
		break;
	}

	switch (card.m_place)
	{
	case Place::DECK: out << "Deck ";
		break;
	case Place::DECARTED: out << "Decarted ";
		break;
	case Place::HAND: out << "Hand ";
		break;
	case Place::DISPLAYED: out << "Displayed ";
		break;
	default:
		break;
	}	

	out << std::endl;
	return out;
	
}
