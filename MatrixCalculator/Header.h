/*!\mainpage MatrixCalculator
* ��������� �MatrixCalculator� ������������� ��� ��� ���������� ��������� �������� ��� ���������,\n
* (�������� - ADD, ��������� - SUB, ��������� - MUL)\n
*/

#pragma once
#define MAX_SIZE 20 //! ������������ ������ ������� 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//! ������� ����� �����
struct Matrix
{
	//! ��������
	int values[MAX_SIZE][MAX_SIZE];

	//! ������
	int width;

	//! ������
	int height;
};

/*! ������� �������, ���������� ������� �� ����� � ������
*	\param[in\out] matr - ��������� ��� ������ ������� �� �����
*	\param[in] file - ���� �� �������� ����� ����� �������
*	\param[in] path - ���� �� �����
*/
void getMatrixFromFile(Matrix* matr, ifstream& file, string path);

/*! �������, ���������� ����� �� ������
*	\param[in\out] matr - ��������� ��� ������ ������� �� �����
*	\param[in] strArr - ������ ����� �� �������� ����� �������� ����� 
*/
void getNumbersFromRow(Matrix* matr, vector<string> strArr);

/*! �������, ����������������� ������� �������� � ����� 
*	\param[in] value - ������ �������� ��� �������������� � ����� 
*	\return - ���������� �����
*/
int getValue(char* value);

/*! �������, ������������ ���-�� �������� � �������
*	\param[in] strArr - ������ �����, ������� �������� ������� 
*	\return ���-�� �������� � �������
*/
int getNumberOfColumns(vector<string> strArr);

/*! �������, ������� ������� ��������� ���-�� �������� � �������
*	\param[in] arr - ������ ���� ����� �������
*	\return - ��������� ���-�� �������� � �������
*/
int getMaxRowSize(vector<int> arr);

/*! �������, ����������� ������ ������ �� ����� �� �����������
*	\param[in] size - ������ ������
*/
void isSizeCorrect(int size);

/*! �������, ������� �������� ������� 
*	\param[in\out] matr - ������� ��� ���������
*/
void setZeroMatrix(Matrix* matr);

/*! �������, ������� ���������� ��� �������
* 	\param[in\out] result - �������������� �������
*	\param[in] matr1 - ������ �������
*	\param[in] matr2 - ������ �������
*/
void matrixAdd(Matrix* matr1, Matrix* matr2, Matrix* result);

/*! �������, ������� �������� �� ������ ������� ������
* 	\param[in\out] result - �������������� �������
*	\param[in] matr1 - ������ �������
*	\param[in] matr2 - ������ �������
*/
void matrixSub(Matrix* matr1, Matrix* matr2, Matrix* result);

/*! �������, ������� �������� ������ ������� �� ������
* 	\param[in\out] result - �������������� �������
*	\param[in] matr1 - ������ �������
*	\param[in] matr2 - ������ �������
*/
void matrixMul(Matrix* matr1, Matrix* matr2, Matrix* result);
