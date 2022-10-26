#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"


string path_fout; //Путь к выходному файлу с матрицей 
ofstream fout; //Объект для выходных данных 

int main()
{
    //русский язык
    setlocale(LC_ALL, "rus");

    string path_fin1; //Путь к первому файлу с матрицей 
    string path_fin2; //Путь ко воторому файлу с матрицей 
    string action; //Действие над матрицей  


    ifstream fin1; //Объект для входных данных из первого файла
    ifstream fin2; //Объект для входных данных из второго файла

    //Ввод данных из консоли 
    cin >> path_fin1;
    cin >> action;
    cin >> path_fin2;
    cin >> path_fout;

    //Проверка корректности выходного файла
    fout.open(path_fout);
    //Если при открытии файла возникла ошибка, то выдать ошибку выходного файла в консоль 
    if (!fout.is_open())
    {
        cout << "Неверно указан файл для выходных данных.  (\"" << path_fout << "\"). Возможно указанного расположения не существует.";
        return 0;
    }
    fout.close();

    //Проверка расширения выходного файла
    //Если последние 4 символа пути файла не равны ".csv", то выдать ошибку расширения выходного файла в консоль
    if (path_fout.rfind(".csv") != path_fout.size() - 4)
    {
        cout << "Неверно указано расширение выходного файла (\"" << path_fout << "\"). Файл должен иметь расширение .csv!";
        return 0;
    }

    //Проверка расширения входных файлов
    //Если последние 4 символа пути файла не равны ".csv", то выдать ошибку расширения входных файлов
    if (path_fin1.rfind(".csv") != path_fin1.size() - 4 || path_fin2.rfind(".csv") != path_fin2.size() - 4)
    {
        fout.open(path_fout);
        fout << "Неверно указано расширение файла. Проверьте расширение входных файлов (\"" << path_fin1 << "\",\"" << path_fin2 << "\"). Файл должен иметь расширение .csv!";
        fout.close();
        return 0;
    }

    //Проверка корректности первого входного файла
    fin1.open(path_fin1);
    //Если при открытии файла возникла ошибка, то выдать ошибку входного файла 
    if (!fin1.is_open())
    {
        fout.open(path_fout);
        fout << "Неверно указан файл с входными данными (\"" << path_fin1 << "\"). Возможно, файл не существует.";
        fout.close();
        return 0;
    }
    fin1.close();

    //Проверка корректности второго входного файла
    fin2.open(path_fin2);
    //Если при открытии файла возникла ошибка, то выдать ошибку входного файла 
    if (!fin2.is_open())
    {
        fout.open(path_fout);
        fout << "Неверно указан файл с входными данными (\"" << path_fin2 << "\"). Возможно, файл не существует.";
        fout.close();
        return 0;
    }
    fin2.close();

    //Создаем матрицы для входных данных
    Matrix matr1;
    Matrix matr2;
    //Создаем матрицу для выходных данных
    Matrix result;

    //Получаем матрицы из входных файлов 
    getMatrixFromFile(&matr1, fin1, path_fin1);
    getMatrixFromFile(&matr2, fin2, path_fin2);

    int endRow;//Ограничитель, чтобы в конце строки не было запятой 
    //Сложение матриц 
    if (action == "ADD")
    {
        //Сложить две матрицы 
        matrixAdd(&matr1, &matr2, &result);
        //Инициализируем ограничитель для вывода результата сложения  
        endRow = matr1.width - 1; 
    }
    //Вычитание матриц 
    else if (action == "SUB")
    {
        //Вычесть матрицы 
        matrixSub(&matr1, &matr2, &result);
        //Инициализируем ограничитель для вывода результата вычитания  
        endRow = matr1.width - 1; 
    }
    //Умножение матриц 
    else if (action == "MUL")
    {
        //Умножить матрицы
        matrixMul(&matr1, &matr2, &result);
        //Инициализируем ограничитель для вывода результата умножения  
        endRow = matr2.width - 1; 
    }
    //Иначе выводим ошибку неизвестного действия  
    else {
        fout.open(path_fout);
        fout << "Не опознан оператор: " << action;
        fout.close();
        return 0;
    }

    //Записываем результат в выходной файл
    fout.open(path_fout);
    //Для всех элементов результирующей матрицы 
    for (int i = 0; i < matr1.height; i++) {
        for (int j = 0; j < matr2.width; j++)
        {
            //Если элемент массива не равен ограничителю, то ставим после него запятую
            if (j != endRow)
                fout << result.values[i][j] << ',';
            //Иначе выводим только элемент массива
            else
                fout << result.values[i][j];
        }
        fout << endl;
    }
    fout.close();
    return 0;
}

//Записать матрицу из файла в массив 
void getMatrixFromFile(Matrix* matr, ifstream& file, string path)
{
    vector<string> strMatrix; //Вектор для строк из файла 

    file.open(path);
    //Пока не конец файла 
    while (!file.eof()) {
        string line; //Полученная строка из файла
        //Получаем строку из файла 
        getline(file, line);
        //Заносим полученную строку в вектор для хранения строк
        strMatrix.push_back(line);
    }
    file.close();

    //Получаем размеры матрицы 
    matr->height = strMatrix.size();
    matr->width = getNumberOfColumns(strMatrix);
    //Проверка ограничений размерности 
    isSizeCorrect(matr->height);
    isSizeCorrect(matr->width);

    //Обнуляем матрицу 
    setZeroMatrix(matr);

    //Заполним матрицу значениями из файла
    getNumbersFromRow(matr, strMatrix);
}

//Выделить числа из строки 
void getNumbersFromRow(Matrix* matr, vector<string> strArr) {
    //Для всех строк полученных из файла
    for (int i = 0; i < strArr.size(); i++)
    {
        //Перевести строку в массив символов
        char* char_matrix = &strArr[i][0];
        //Выделение первой части строки
        char* value = strtok(char_matrix, ",");

        int j = 0; //Итератор для столбцов
        //Получаем числовое значение из выделенной части строки 
        matr->values[i][j] = getValue(value);
        j++; //Увеличиваем итератор для столбцов

        //Выделение последующих частей строки
        while (value != NULL)
        {
            //Выделяем очередную часть 
            value = strtok(NULL, ",");

            //Если кол-во столбцов меньше ограничения
            if (j <= 20)
                //Получаем числовое значение из выделенной части строки 
                matr->values[i][j] = getValue(value);

            j++; //Увеличиваем итератор для столбцов
        }
    }
}

//Выделить число из части строки 
int getValue(char* value) {
    int num = 0; //Переменная с полученным числом 
    //Если часть строки не пустая 
    if (value != NULL) {
        //Для всех элементов массива выделенной части 
        for (int k = 0; k < strlen(value); k++) {
            //Если символ не является числом и отрицательным знаком
            if (!isdigit(value[k]) && value[k] != '-')
            {
                fout.open(path_fout);
                fout << "Некорректные входные данные. Матрицы должны содержать только целые числа!";
                fout.close();
                exit(0);
            }
        }
        //Переводим строку в число  
        num = atoi(value);
    }
    //Возвращаем полученное число 
    return num;
}

//Определить кол-во столбцов в матрице 
int getNumberOfColumns(vector<string> strArr) {
    int width = 0; //Счетчик столбцов 
    vector<int> widthSizes; //Вектор для хранения размеров строк 

    //Для всех строк матрицы 
    for (int i = 0; i < strArr.size(); i++)
    {
        width = 0; //Зануляем счетчик столбцов
        //Перевести строку в массив символов
        char* char_matrix = &strArr[i][0];
        //Выделение первой части строки
        char* pch = strtok(char_matrix, ",");

        //Выделение последующих частей строки
        while (pch != NULL)
        {
            //Выделяем очередную часть 
            pch = strtok(NULL, ",");
            //Увеличиваем счетчик столбцов
            width++;
        }
        //Присваиваем полученное значение столбцов в вектор для хранения всех размеров столбцов матрицы 
        widthSizes.push_back(width);
    }
    //Получаем максимальное число столбцов в матрице 
    width = getMaxRowSize(widthSizes);
    //Возвращаем число столбцов 
    return width;
}

//Найти наибольший размер столбцов матрицы 
int getMaxRowSize(vector<int> arr)
{
    int max = arr.at(0); //Пусть первый элемент будет наибольшим 
    //Для всех элементов массива 
    for (int i = 0; i < arr.size(); ++i) {
        //Если наибольший элемент больше очередного элемента
        if (arr[i] > max) {
            //Присваиваем этот элемент в наибольший 
            max = arr[i];
        }
    }
    //Возвращаем наибольшее значение столбцов матрицы
    return max;
}

//Обнулить матрицу
void setZeroMatrix(Matrix* matr) {
    //Для всех элементов матрицы 
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            //Присвоить 0
            matr->values[i][j] = 0;
}

//Проверить полученный размер на выход за ограничения 
void isSizeCorrect(int size)
{
    //Проверить, что полученные размеры лежат в диапазоне 0 < size <= 20
    if (!(size > 0 && size <= MAX_SIZE))
    {
        fout.open(path_fout);
        fout << "Размер матрицы не может быть меньше 1х1 и больше 20х20";
        fout.close();
        exit(0);
    }
}

//Сложение матриц 
void matrixAdd(Matrix* matr1, Matrix* matr2, Matrix* result) {
    //Если матрицы разных размеров - вывести ошибку 
    if (matr1->height != matr2->height || matr1->width != matr2->width)
    {
        fout.open(path_fout);
        fout << "Размеры матриц должны быть одинаковыми.";
        fout.close();
        exit(0);
    }
    else
    //Для всех элементов матрицы 
    for (int i = 0; i < matr1->height; i++)
        for (int j = 0; j < matr1->width; j++)
            //Сложить элемент первой матрицы с элементов второй матрицы 
            result->values[i][j] = matr1->values[i][j] + matr2->values[i][j];
}

//Вычитание матриц 
void matrixSub(Matrix* matr1, Matrix* matr2, Matrix* result) {
    //Если матрицы разных размеров - вывести ошибку 
    if (matr1->height != matr2->height || matr1->width != matr2->width)
    {
        fout.open(path_fout);
        fout << "Размеры матриц должны быть одинаковыми.";
        fout.close();
        exit(0);
    }
    else
        //Для всех элементов матрицы 
        for (int i = 0; i < matr1->height; i++)
            for (int j = 0; j < matr1->width; j++)
                //Сложить элемент первой матрицы с элементов второй матрицы 
                result->values[i][j] = matr1->values[i][j] - matr2->values[i][j];
}

//Умножение матриц 
void matrixMul(Matrix* matr1, Matrix* matr2, Matrix* result) {
    //Если число столбцов первой матрицы не совпадает с числом строк второй матрицы, то выводим ошибку умножения
    if (matr1->width != matr2->height)
    {
        fout.open(path_fout);
        fout << "Число столбцов матрицы A должно совпадать с числом строк матрицы B";
        fout.close();
        exit(0);
    }
    else{    
        //Для всех элементов матрицы 
        for (int i = 0; i < matr1->height; i++) {
            for (int j = 0; j < matr2->width; j++)
            {
                //Зануляем значение элемента результирующего массива 
                result->values[i][j] = 0;
                //Для всех элементов строки первой матрицы и столбца второй матрицы 
                for (int k = 0; k < matr2->height; k++)
                    //Прибавляем результат умножения элемента строки первой матрицы на элемент столбца второй матрицы 
                    result->values[i][j] += matr1->values[i][k] * matr2->values[k][j];
            }
        }
    }
}
