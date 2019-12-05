#include "Player.h"

Player::Player()
{
	m_name = "";
	m_id = 0;
}

Player::Player(std::string name, uint16_t id):
	m_name(name), m_score(0), m_id(id)
{
	m_phase[0] = 1;
}

Player::~Player()
{

}

Player::Player(const Player& other)
{
	*this = other;
}

Player& Player::operator=(const Player& other)
{
	m_name = other.m_name;
	m_displayedCards = other.m_displayedCards;
	m_handCards = other.m_handCards;
	m_phase = other.m_phase;
	m_score = other.m_score;
	m_id = other.m_id;
	return *this;
}

Player & Player::operator=(Player && other) noexcept
{
	m_name = other.m_name;
	m_displayedCards = other.m_displayedCards;
	m_handCards = other.m_handCards;
	m_phase = other.m_phase;
	m_score = other.m_score;
	m_id = other.m_id;

	new (&other) Player;

	return *this;
}

std::string Player::GetName() const
{
	return Player::m_name;
}

uint16_t Player::GetScore() const
{
	return m_score;
}

uint16_t Player::GetId() const
{
	return m_id;
}

void Player::SetScore(uint16_t score)
{
	m_score = score;
}

void Player::CountScore()
{
	uint16_t score = this->GetScore();

	for (Card card : this->m_handCards)
	{
		if (card.GetStatus() < Status::TEN)
		{
			score += 5;
		}
		else if (card.GetStatus() > Status::NINE&& card.GetStatus() < Status::WILD)
		{
			score += 10;
		}
		else
		{
			score += 20;
		}
	}

	this->SetScore(score);
}

Card Player::DropCard(int option)
{
	int size = m_handCards.size();
	Card card = m_handCards[option];
	
	for (int index = option; index < size-1; index++)
	{
		m_handCards[index] = m_handCards[index + 1];
	}
	m_handCards.pop_back();
	return card;
}

void Player::RemakePlayer()
{
	m_handCards.clear();
	m_displayedCards.clear();
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
	/*for (int index = 0; index < player.m_displayedCards.size(); index++)
	{
		for (int index2 = 0; index2 < player.m_displayedCards[index].size(); index2++)
		{
			out << player.m_displayedCards[index][index2] << " ";
		}
	}
	out << std::endl;*/

	return out;
}
