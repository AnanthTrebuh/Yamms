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
			/*int id = 1;
			Dice d(id);
			Assert::AreEqual(id, d.getId());
			Assert::AreEqual(0, d.getValeur());*/
		}
		TEST_METHOD(TestDesJet)
		{
			Dice d;
			d.jet();
			Assert::AreNotEqual(0, d.getValeur());
		}
	};
}
