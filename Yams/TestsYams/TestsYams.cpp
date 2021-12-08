#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsYams
{
	TEST_CLASS(TestsYams)
	{
	public:
		
		TEST_METHOD(TestDesConst)
		{
			Dice d = Dice(1);
			Assert::AreEqual(1, d.getId());
			Assert::AreEqual(0, d.getValeur());
		}
		TEST_METHOD(TestDesJet)
		{
			Dice d = Dice();
			d.jet();
			Assert::AreNotEqual(0, d.getValeur());
		}
	};
}
