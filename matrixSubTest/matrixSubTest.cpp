#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixSubTest
{
	TEST_CLASS(matrixSubTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			Matrix matr1{ {{1,2,3,2},{1,5,12,5}} };
			Matrix matr2{ {{1,2,3,10},{1,5,12,16}} };

			int exp[2][4] = { {0,0,0,-8},{0,0,0,-11} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(negativeNumbers)
		{
			Matrix matr1{ {{-1,2,-3,2},{1,-5,-12,5}} };
			Matrix matr2{ {{1,2,3,10},{1,5,12,16}} };

			int exp[2][4] = { {-2,0,-6,-8},{0,-10,-24,-11} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxColNumbers)
		{
			Matrix matr1{ {{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21}} };
			Matrix matr2{ {{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23}} };

			int exp[1][20] =
			{ {0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxRowNumbers)
		{
			Matrix matr1{ {{1},{25},{1},{16},{54},{25},{38},{1},{25},{1},{16},{54},{25},{38},{15},{17},{213},{2135},{23},{12}} };
			Matrix matr2{ {{10},{5},{12},{1},{5},{225},{8},{15},{95},{145},{136},{54},{25},{38},{15},{17},{13},{5},{23},{12}} };

			int exp[20][20] =
			{ {-9},{20},{-11},{15},{49},{-200},{30},{-14},{-70},{-144},{-120},{0},{0},{0},{0},{0},{200},{2130},{0},{0} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(minRowNumbers)
		{
			Matrix matr1{ {{1}} };
			Matrix matr2{ {{10}} };

			int exp[20][20] =
			{ {-9} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxColAndRowNumbers)
		{
			Matrix matr1{ {{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21},
				{1,2,3,23,5,6,7,78,2,325,23,6,87,90,34,12,34,45,456,21}} };

			Matrix matr2{ {{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23},
				{1,2,3,10,5,60,7,66,12,12,33,56,1,234,54,6,7,89,12,23}} };

			int exp[20][20] =
			{ {0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2},
				{0,0,0,13,0,-54,0,12,-10,313,-10,-50,86,-144,-20,6,27,-44,444,-2} };

			Matrix res;
			matrixSub(&matr1, &matr2, &res);

			for (int i = 0; i < matr1.height; i++)
				for (int j = 0; j < matr1.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}
	};
}
