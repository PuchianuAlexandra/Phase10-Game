#pragma once
#include <vector>
#include "Player.h"

class Card;

class Phase
{
public:
	bool isSet(std::vector<Card> cards);
	bool isRun(std::vector<Card> cards);
	bool isColor(std::vector<Card> cards);
	bool isPhase(Player& player);

private:
	void ChoseCards(int no, Player player, std::vector<int>& options, std::vector<Card>& chosenCards);
   // void ModifyHandCards2(Player& player, std::vector<int> options1, std::vector<int> options2);


	bool isPhase1(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect );
	bool isPhase2(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect);
	bool isPhase3(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect); 
	bool isPhase4(std::vector<Card> cards); 
	bool isPhase5(std::vector<Card> cards);
	bool isPhase6(std::vector<Card> cards);
	bool isPhase7(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect);
	bool isPhase8(std::vector<Card> cards);
	bool isPhase9(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect); 
	bool isPhase10(std::vector<Card> cards1, std::vector<Card> cards2, int& incorrect); 

};

