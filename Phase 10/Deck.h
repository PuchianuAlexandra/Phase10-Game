#pragma once
#include <cstdint>
#include <iostream>
#include <array>
#include "Color.h"
#include "Status.h"
#include "Place.h"
#include "Card.h"

class Deck
{
public:

	Deck(std::array<Card*, 108> deck);

private:

	std::array<Card,108> m_deck;
};

