#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace setZeroMatrixTest
{
	TEST_CLASS(setZeroMatrixTest)
	{
	public:
		
		TEST_METHOD(typeTest)
		{
			Matrix matr;
			setZeroMatrix(&matr);

			for (int i = 0; i < matr.height; i++)
				for (int j = 0; j < matr.width; j++)
					Assert::AreEqual(0, matr.values[i][j]);
		}
	};
}
