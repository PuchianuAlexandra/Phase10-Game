#include "CppUnitTest.h"
#include "pch.h"
#include "../Phase 10/Deck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(PickCardFromDeck)
		{
			Deck deck;
			Card c1(Color::RED, Status::ONE, Place::HAND);
			Card c2(Color::YELLOW, Status::TEN, Place::HAND);
			Card c3(Color::RED, Status::ELEVEN, Place::HAND);
			deck.AddCard(c1);
			deck.AddCard(c2);
			deck.AddCard(c3);

			Assert::IsTrue(c3== deck.PickCardFromDeck());
		}

	};
}