#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getValueTest
{
	TEST_CLASS(getValueTest)
	{
	public:
		//int getValue(char* value)

		TEST_METHOD(TestMethod1)
		{
			string line = "2";
			char* number = &line[0];
			int exp = 2;
			int res = getValue(number);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(negativeNumber)
		{
			string line = "-12";
			char* number = &line[0];
			int exp = -12;
			int res = getValue(number);

			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(longNumber)
		{
			string line = "21312432";
			char* number = &line[0];
			int exp = 21312432;
			int res = getValue(number);

			Assert::AreEqual(exp, res);
		}
	};
}
