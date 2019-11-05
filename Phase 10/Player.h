#pragma once
#include<cstdint>
#include<string>
#include<vector>
#include"Card.h"

class Player
{
public:

	Player(std::string name);
	~Player();
	std::string GetName() const;
	uint8_t GetScore() const;
	void setScore(uint8_t score);
	friend std::ostream& operator<<(std::ostream& out, const Player& player);


public:
	std::vector<bool>m_phase = { 0 };
	std::vector<Card>m_handCards;
	std::vector<std::vector<Card>>m_displayedCards;

private:
	std::string m_name;
	uint8_t m_score=0;
};

