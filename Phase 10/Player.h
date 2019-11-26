#pragma once
#include<cstdint>
#include<string>
#include<vector>
#include <bitset>
#include"Card.h"

class Player
{
public:

	Player();
	Player(std::string name);
	~Player();
	Player(const Player& other);
	Player& operator = (const Player& other);
	Player& operator = (Player&& other);
	

	std::string GetName() const;
	uint16_t GetScore() const;
	void setScore(uint8_t score);
	friend std::ostream& operator<<(std::ostream& out, const Player& player);
	Card DropCard(int option);

public:
	//std::vector<bool>m_phase = { 0 };
	std::bitset<11> m_phase;
	std::vector<Card>m_handCards;
	std::vector<std::vector<Card>>m_displayedCards;

private:
	std::string m_name;
	uint16_t m_score;
};

