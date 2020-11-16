#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4/Lab6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[10] = { 0,1,2,3,4,-5,6,-7,-8,-9 }, CreateIter = 0, PrintIter = 0, PrintZeroIter = 0, FindIndexFirstNegIter = 0, FindIndexLastNegIter = 0, SumNegativeIter = 0;

			SqueezedIter(a, 10);

			Assert::AreEqual(CreateIter, 0);
			Assert::AreEqual(PrintIter, 0);
			Assert::AreEqual(PrintZeroIter, 0);
			Assert::AreEqual(FindIndexFirstNegIter, 0);
			Assert::AreEqual(FindIndexLastNegIter, 0);
			Assert::AreEqual(SumNegativeIter, 0);
			Assert::AreEqual(a[0], 0);
			Assert::AreEqual(a[9], -9);
		}
	};
}
