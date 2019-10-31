#include "Player.h"

Player::Player(std::string name):
	m_name(name)
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

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name << " have " << player.m_score << " points.\n";
	out << player.m_name << "'s cards: ";
	for (auto obj : player.m_handCards)
	{
		out << obj.GetValue() << " ";
		//out << obj.Card::GetColor() << "\n";
	}

	//out << "Discaded cards: \n";
	//for (auto obj : player.m_decartedCards)
	//{
	//	out << obj. << " ";
	//	//out << obj.Card::GetColor() << "\n";
	//}

	return out;
}
