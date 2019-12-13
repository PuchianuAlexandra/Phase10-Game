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
			Card card(Color::BLUE, Status::NINE, Place::HAND);

			Assert::IsTrue(Color::BLUE == card.GetColor());
			Assert::IsTrue(Status::NINE == card.GetStatus());
			Assert::IsTrue(Place::HAND == card.GetPlace());
		}

		TEST_METHOD(Print)
		{
			Card card(Color::BLUE, Status::NINE, Place::HAND);

			std::stringstream stream;
			stream << card;
			Assert::AreEqual(std::string("Blue 9 "), stream.str(), L"If you see this message, piece is not printed correctly");
		}
	};
}