#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getNumberOfColumnsTest
{
	TEST_CLASS(getNumberOfColumnsTest)
	{
	public:
		//int getNumberOfColumns(vector<string> strArr);
		TEST_METHOD(typeTest)
		{
			vector<string> strArr = { "21,2,5", "12,5,67,787" };
			int exp = 4;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(differentSizesOfRows)
		{
			vector<string> strArr = { "21,2,5", "12,5,67,787", "21,2" };
			int exp = 4;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxLongRow)
		{
			vector<string> strArr = { "21,2,5,12,5,67,787,32,324,4567,1234,78509,-213,213,2,4,5,6,7,8"};
			int exp = 20;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(minLongRow)
		{
			vector<string> strArr = { "21" };
			int exp = 1;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(oneZeroRow)
		{
			vector<string> strArr = { "21,2,5,12,5,67", "", "21,2,5" };
			int exp = 6;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxRowInStart)
		{
			vector<string> strArr = { "21,2,5,12,5,67", "2,5,6", "21,2,5" };
			int exp = 6;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(maxRowInMiddle)
		{
			vector<string> strArr =  {"2,5,6","21,2,5,12,5,67", "21,2,5" };
			int exp = 6;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}


		TEST_METHOD(maxRowInEnd)
		{
			vector<string> strArr = { "2,5,6", "21,2,5", "21,2,5,12,5,67" };
			int exp = 6;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(onlyEmptyRow)
		{
			vector<string> strArr = {""};
			int exp = 0;
			int res = getNumberOfColumns(strArr);

			Assert::AreEqual(exp, res);
		}
	};
}
