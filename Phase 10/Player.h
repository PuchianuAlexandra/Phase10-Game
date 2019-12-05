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
	Player(std::string name, uint16_t id);
	~Player();
	Player(const Player& other);
	Player& operator = (const Player& other);
	Player& operator = (Player&& other) noexcept;
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

public:

	std::string GetName() const;
	uint16_t GetScore() const;
	uint16_t GetId() const;
	void SetScore(uint16_t score);
	Card DropCard(int option);
	void RemakePlayer();

public:
	std::bitset<11> m_phase;
	std::vector<Card>m_handCards;
	std::vector<std::vector<Card>>m_displayedCards;

private:
	uint16_t m_id;
	std::string m_name;
	uint16_t m_score;
};

