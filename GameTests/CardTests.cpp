#include "CppUnitTest.h"
#include "pch.h"
#include "../Phase 10/Card.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(CardTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Card card(Color::BLUE, Status::NINE);

			Assert::IsTrue(Color::BLUE == card.GetColor());
			Assert::IsTrue(Status::NINE == card.GetStatus());
		}

		TEST_METHOD(Print)
		{
			Card card(Color::BLUE, Status::NINE);

			std::stringstream stream;
			stream << card;
			Assert::AreEqual(std::string("Blue 9 \n"), stream.str(), L"If you see this message, piece is not printed correctly");
		}

		TEST_METHOD(Equal)
		{
			Card card1(Color::BLUE, Status::NINE);
			Card card2(Color::BLUE, Status::NINE);

			bool isEqual = false;

			if (card1 == card2)
			{
				isEqual = true;
			}

			Assert::IsTrue(true == isEqual);
		}

		TEST_METHOD(NotEqual)
		{
			Card card1(Color::BLUE, Status::NINE);
			Card card2(Color::RED, Status::FIVE);

			bool isNotEqual = false;

			if (card1 != card2)
			{
				isNotEqual = true;
			}

			Assert::IsTrue(true == isNotEqual);
		}
	};
}