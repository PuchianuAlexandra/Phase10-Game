#include "Player.h"

Player::Player(std::string name):
	m_name(name), m_score(0)
{
}

Player::~Player()
{

}

std::string Player::GetName() const
{
	return Player::m_name;
}

uint8_t Player::GetScore() const
{
	return m_score;
}

void Player::setScore(uint8_t score)
{
	m_score = score;
}

Card Player::DropCard()
{
	std::cout << "Choose a card to discard from your hand (from 1 to "<<m_handCards.size()<<") : ";
	int option;
	std::cin >> option;
	option--;

	int size = m_handCards.size();
	Card card = m_handCards[option];
	
	for (int index = option; index < size-1; index++)
	{
		m_handCards[index] = m_handCards[index + 1];
	}
	m_handCards.pop_back();
	return card;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name << " has " << player.m_score << " points.\n";
	out << player.m_name << "'s cards:\n ";
	for (int index = 0; index < player.m_handCards.size(); index++)
	{
		out << player.m_handCards[index] << " ";
	}
	out << std::endl;
	for (int index = 0; index < player.m_displayedCards.size(); index++)
	{
		for (int index2 = 0; index2 < player.m_displayedCards[index].size(); index2++)
		{
			out << player.m_displayedCards[index][index2] << " ";
		}
	}
	out << std::endl;

	return out;
}
