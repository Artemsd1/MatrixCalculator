/*!\mainpage MatrixCalculator
* Программа “MatrixCalculator” предназначена для для выполнения указанных операций над матрицами,\n
* (Сложение - ADD, Вычитание - SUB, Умножение - MUL)\n
*/

#pragma once
#define MAX_SIZE 20 //! Максимальный размер матрицы 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//! Матрица целых чисел
struct Matrix
{
	//! элементы
	int values[MAX_SIZE][MAX_SIZE];

	//! ширина
	int width;

	//! высота
	int height;
};

/*! Главная функция, выделяющая матрицу из файла в массив
*	\param[in\out] matr - структура для записи матрицы из файла
*	\param[in] file - файл из которого будем брать матрицу
*	\param[in] path - путь до файла
*/
void getMatrixFromFile(Matrix* matr, ifstream& file, string path);

/*! Функция, выделяющая числа из строки
*	\param[in\out] matr - структура для записи матрицы из файла
*	\param[in] strArr - массив строк из которого будем выделить числа 
*/
void getNumbersFromRow(Matrix* matr, vector<string> strArr);

/*! Функция, преобразовывающая массивы символов в число 
*	\param[in] value - массив символов для преобразования в число 
*	\return - полученное число
*/
int getValue(char* value);

/*! Функция, определяющая кол-во столбцов в матрцие
*	\param[in] strArr - массив строк, который содержит матрицу 
*	\return кол-во столбцов в матрице
*/
int getNumberOfColumns(vector<string> strArr);

/*! Функция, которая находит наибольше кол-во столбцов в матрице
*	\param[in] arr - массив длин строк матрицы
*	\return - наибольше кол-во столбцов в матрице
*/
int getMaxRowSize(vector<int> arr);

/*! Функция, проверяющая размер матриц на выход за ограничения
*	\param[in] size - размер матриц
*/
void isSizeCorrect(int size);

/*! Функция, которая обнуляет матрицу 
*	\param[in\out] matr - матрица для обнуления
*/
void setZeroMatrix(Matrix* matr);

/*! Функция, которая складывает две матрицы
* 	\param[in\out] result - результирующая матрица
*	\param[in] matr1 - первая матрица
*	\param[in] matr2 - вторая матрица
*/
void matrixAdd(Matrix* matr1, Matrix* matr2, Matrix* result);

/*! Функция, которая вычитает из первой матрицы вторую
* 	\param[in\out] result - результирующая матрица
*	\param[in] matr1 - первая матрица
*	\param[in] matr2 - вторая матрица
*/
void matrixSub(Matrix* matr1, Matrix* matr2, Matrix* result);

/*! Функция, которая умножает первую матрицу на вторую
* 	\param[in\out] result - результирующая матрица
*	\param[in] matr1 - первая матрица
*	\param[in] matr2 - вторая матрица
*/
void matrixMul(Matrix* matr1, Matrix* matr2, Matrix* result);
