#pragma once
#include <cstdint>
#include <iostream>
#include <array>
#include "Color.h"
#include "Status.h"
#include "Place.h"
#include "Card.h"
#include<algorithm>
#include<random>
#include <vector>

class Deck
{
public:
	Deck();
	void ShuffleDeck();
	//friend std::ostream& operator<< (std::ostream& os, const Deck& deck);
	Card PickCardFromDeck();
	

private:
	std::vector<Card> m_deck;
};

