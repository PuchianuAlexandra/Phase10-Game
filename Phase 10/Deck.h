#pragma once
#include <cstdint>
#include <iostream>
#include <array>
#include "Color.h"
#include "Status.h"
#include "Place.h"
#include "Card.h"
#include <vector>
#include<algorithm>
#include<random>

class Deck
{
public:
	Deck();
	void ShuffleDeck();
public:
	//friend std::ostream& operator<< (std::ostream& os, const Deck& deck);

private:
	std::vector<Card> m_deck;
};

