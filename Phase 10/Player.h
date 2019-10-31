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

private:
	std::string m_name;
	uint8_t m_score=0;
	std::vector<bool>m_phase = { 0 };
	std::vector<Card>m_handCards;
	std::vector<std::vector<Card>>m_decartedCards;

};

