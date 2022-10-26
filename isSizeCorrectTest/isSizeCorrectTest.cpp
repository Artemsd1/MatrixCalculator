#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isSizeCorrectTest
{
	TEST_CLASS(isSizeCorrectTest)
	{
	public:
		
		//void isSizeCorrect(int size)
		TEST_METHOD(typeTest)
		{
			int N = 14;
			isSizeCorrect(N);
		}

		TEST_METHOD(maxSize)
		{
			int N = 20;
			isSizeCorrect(N);
		}

		TEST_METHOD(minSize)
		{
			int N = 1;
			isSizeCorrect(N);
		}
	};
}
