#pragma once
#include <cstdint>
#include <iostream>
#include <array>
#include "Color.h"
#include "Status.h"
#include "Place.h"
#include "Card.h"
#include <vector>

class Deck
{
public:
	Deck();

public:
	friend std::ostream& operator<< (std::ostream& os, const Deck& deck);

private:
	std::vector<Card> m_deck;
};

