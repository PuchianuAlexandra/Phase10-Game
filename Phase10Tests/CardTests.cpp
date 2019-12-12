#include "CppUnitTest.h"
#include "stdafx.h"
#include "../Phase 10/Card.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Phase10Tests
{
	TEST_CLASS(CardTests)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Card card(Color::BLUE, Status::NINE, Place::HAND);

			Assert::IsTrue(Color::BLUE == card.GetColor());
			Assert::IsTrue(Status::NINE == card.GetStatus());
			Assert::IsTrue(Place::HAND == card.GetPlace());
		}
	};
}
