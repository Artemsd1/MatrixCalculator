#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getMatrixFromFileTest
{
	TEST_CLASS(getMatrixFromFileTest)
	{
	public:
		//void getMatrixFromFile(Matrix* matr, ifstream& file, string path)
		TEST_METHOD(typeTest)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/typeTest.csv";

			int exp[2][3] = { {21,2,5}, {11,23,4} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxRowCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/maxRowCount.csv";

			int exp[20][3] = { {21,2,5}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4},
							{11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4}, {11,23,4} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(minRowCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/minRowCount.csv";

			int exp[2][3] = { {21,2,5} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxColCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/maxColCount.csv";

			int exp[2][20] = { {21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(minColCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/minColCount.csv";

			int exp[2][1] = { {21},{12} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(maxRowAndColCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/maxRowAndColCount.csv";

			int exp[20][20] = { {21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
								{21,2,5,5,3,4,5,6,7,8,9,9,0,4,5,67,1,23,4,5},
			};
			int result[20][20];
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}

		TEST_METHOD(minRowAndColCount)
		{
			ifstream fin;
			string path = "../getMatrixFromFileTest/minRowAndColCount.csv";

			int exp[1][1] = { {21} };
			Matrix res;
			getMatrixFromFile(&res, fin, path);

			for (int i = 0; i < res.height; i++)
				for (int j = 0; j < res.width; j++)
					Assert::AreEqual(exp[i][j], res.values[i][j]);
		}
	};
}
