#include "CppUnitTest.h"
#include "pch.h"
#include "../Phase 10/Game.h"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(GameTests)
	{
	public:

		TEST_METHOD(Share10Cards)
		{
			Game game;
			std::vector<Player> players;
			players.emplace_back("a", 1);
			game.SetPLayers(players);
			game.Share10Cards();
			players = game.GetPlayers();

			Assert::IsTrue(players[0].m_handCards.size() == 10);
		}

		TEST_METHOD(ShowPlayers)
		{
			Player player("Ana", 1);

			std::stringstream stream;
			stream << player;
			Assert::AreEqual(std::string("1) Ana -score: 0"), stream.str(), L"If you see this message, piece is not printed correctly");
		}

		TEST_METHOD(PickCardFromDecartedStack)
		{
			Game game;
			std::stack<Card> discardedCards;
			discardedCards.push(Card(Color::RED, Status::ONE, Place::HAND));
			discardedCards.push(Card(Color::YELLOW, Status::ONE, Place::HAND));
			discardedCards.push(Card(Color::RED, Status::ONE, Place::HAND));
			game.SetDiscardedCards(discardedCards);
			Card card = game.PickCardFromDecartedStack();
			Card card2 = discardedCards.top();

			Assert::IsTrue(card == card2);
		}
	};
}