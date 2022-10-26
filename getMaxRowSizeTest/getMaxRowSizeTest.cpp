#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getMaxRowSizeTest
{
	TEST_CLASS(getMaxRowSizeTest)
	{
	public:
		//int getMaxRowSize(vector<int> arr)
		TEST_METHOD(typeTest)
		{
			vector<int> arr = { 1,3,6,10,7 };
			int exp = 10;
			int res = getMaxRowSize(arr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxInStart)
		{
			vector<int> arr = { 19,3,6,10,7 };

			int exp = 19;
			int res = getMaxRowSize(arr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxInMiddle)
		{
			vector<int> arr = { 19,3,6,10,20,11,3,2,10 };

			int exp = 20;
			int res = getMaxRowSize(arr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxInEnd)
		{
			vector<int> arr = { 19,3,6,10,1,11,3,2,20 };

			int exp = 20;
			int res = getMaxRowSize(arr);

			Assert::AreEqual(exp, res);
		}
	};
}
