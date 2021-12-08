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
			Des d = Des(1);
			Assert::AreEqual(1, d.getId());
			Assert::AreEqual(0, d.getValeur());
		}
		TEST_METHOD(TestDesJet)
		{
			Des d = Des();
			d.jet();
			Assert::AreNotEqual(0, d.getValeur());
		}
	};
}
