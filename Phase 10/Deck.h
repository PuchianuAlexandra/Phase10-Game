#pragma once

#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <vector>

#include "Color.h"
#include "Status.h"
#include "Place.h"
#include "Card.h"


class Deck
{
public:
	Deck();

public:
	void ShuffleDeck();
	Card PickCardFromDeck();
	void AddCard(Card card);
	bool IsEmpty() const;

private:
	std::vector<Card> m_deck;
};

