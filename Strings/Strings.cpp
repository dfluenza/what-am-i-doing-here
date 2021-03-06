// Strings.cpp : Defines the entry point for the console application.
//"Строки и файлы"

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;

//строки старого С-типа представляют из себя массив символов, оканчивающийся на 0;

char cstr1[] = "C-style string";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '2', '\0' };

//функции для работы с С-строками
//вывод на печать printf(char[],,,)

//форматирование printf("базовая %s строка %f", параметр 1, параметр 2)
//с помощью printf можно не просто печатать строку, но и подставлять в неё другие переменные, попутно преобразовывая их
//в символьный вид и применяя форматирование;
//позиции, куда будут подставляться параметры, обозначаются в базовой строке символом %

//значение символов форматирования берется из таблицы-справки к функции http://cplusplus.com/reference/cstudio/printf/
//значения некоторых из них:
//%f — параметр подставляется на местро %f, оформленное в виде числа с правающей точкой;
//%s — параметр подствляется на место %s, как строка;
//%d — параметр подствляется на место %d, как целое число;
//%e — параметр подствляется на место %e в экспоненциальном виде;

//объединение строк strcat(*char, *char)
//копирование из одной строки в другую strcpy()
//сравнение двух строк strcmp()
//длина строки strlen()

//в стандартной библиотеке C++ массив символов инкапсулирован в класс, 
//в который так же собраны самые часто используемые методы обработки для которого перегружены операторы;

std::string cppstr1 = "C++ - style string 1";
std::string cppstr2 = "C++ - style string 2";

int main()
{
	printf(cstr1);
	printf("\n\n"); //в функцию передается массив (а имя массива является указателем на самый первый элемент)
					//char, либо указатель *char

	printf("Insert doule: %f \n" 
		"insert long long: %d \n"
		"insert string: %s \n" 
		"insert exponential: %e \n" //мантисса — дробное число между 1 и 2, умножаемое на 10^экспонента.
		"insert double with precision: %4.2f \n" //4.2 — 4 места перед запятой и 2 знака после запятой;
		"*ERROR insert long long as double: %f \n"  //неверное преобразование типов
		"*ERROR insert double as int: %010d \n",
		1000.15, 132456789, "string =", 1123456.1123456, 1123456.1123456, 10000);

	//копирование из одной строки в другую 
	char cstr3[255];
	strcpy_s(cstr3, 255, cstr1);
	printf_s("Result of strcpy(%s, %s) = ", cstr3, cstr2);
	cppstr2 == cppstr1;
	cout << "Istead of strcpy() use operator " << cppstr2 << endl;

	//сравнение двух строк 
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
	cout << "cppstr1 == cppstr2 = :\t" << (cppstr1 == cppstr2) << endl; //аналог сравнения на C++

	//длина строки 
	int lnght = strlen(cstr1);
	printf_s("Result of strlen(%s) = %d\n", cstr1, lnght);
	cout << "Istead of strlen() use std::string.length() :\t" << cppstr1.length() << endl;

	//объединение строк 
	strcat_s(cstr3, 255, cstr1);
	cout << "Result of strcat(cstr2, cstr1) = " << cstr3 << endl;
	cout << "Istead of strcat() use operator +:\t" << (cppstr1 + cppstr2) << endl;

	//"Работа с файлами"

	//std::fstream — универсальный класс для ввода (чтения из файла) и вывода (запись в файл)
	//std::ifstream — универсальный класс для ввода (чтения из файла)
	//std::ofstream — универсальный класс для вывода (запись в файл)
	//аналогично cout-потоку, предназначенному для вывода на консоль,
	//fstream является потом, предназначенным для ввода/вывода из/в файл;

	fstream fs;
	fs.open("Some text file.txt", //при открытии файла надо указать его имя
								  //а так же режим открытия (с перезаписью или без, для чтения/для записи/оба и т.д.)
		std::fstream::in //добавляется режим вывода из файла
		| std::fstream::out //добавляется режим записи в файл
		/*| std::fstream::app*///добавляется режим записи в конец файла
		| std::fstream::trunc); //trunc — truncate — режим с перезаписью всего файла;
	auto fstream_mode = std::fstream::in | std::fstream::out | std::fstream::app;
	cout << "std::fstream::in | std::fstream::out | std::fstream::app = " << bitset<8>(fstream_mode) << endl;

	fs << 1000.15 << endl << 132456789 << endl << "string =)" << endl << 1123456.1123456 << endl << 1.1123456 << endl << (long long)10000 << endl<< 10.5 << endl;
	fs.close();
	getchar();
    return 0;
}

