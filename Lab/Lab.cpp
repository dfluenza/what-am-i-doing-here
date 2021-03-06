//Lab.cpp: определяет точку входа для консольного приложения.
//"Вводная лекция"

#include "stdafx.h"

//stdafx.h — просто текстовый файл кода с определениями и объявлениями.
//при компиляции берётся все содердимое файла заголовка и вставляется вместо соответствующего includ'a.
//.h — "header" —  заголовок.

#include <iostream>
#include <bitset>
#include <cmath>
int main() //точка входа (стандартная точка main) оформлена в виде функции;
		   //функция — фрагмент кода,имеющий собственное имя(идентификатор).
{
	std::cout << "Hello, world \n";

	//escape-последовательность - служебные непечатаемые символы (переносы, возврат строки и т.д.), 
	//включаются в строку через символ "\";
	//при обработке компилятор пропускает  \  и вместо следующей буквы вставляет соответствующий символ;

	std::cout << "Hello, world" << std::endl;

	// шаблон endl в конечном счете представляет тот же самый символ \n; 
	// в некоторый системах требуется писать '\r\n'  - r-return; -n- new line;

	std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

	//объект cout вместе с опретатором << позволяет выводить одновременно как строки,
	//так и переменные других типов, не заботясь о преобразовании их в строку.
	//иными словами, он автоматически выполняет приведение типов.

	std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
	std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
	std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
	std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
	std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
	std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
	std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
	std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;
	std::cout << "sizeof(true) = " << sizeof(true) << std::endl;
	std::cout << "sizeof(false) = " << sizeof(false) << std::endl;
	std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;

	//процессор не умеет работать с одиночными битами, байтами (и даже с одиночными char, и даже в одиночными short);
	//в процессоре есть 16 и 32-х разрядные ячейки памяти, и если мы загружаем char or bool,
	//незанятые разряды будут нулевые.
	//целые числа (беззнаковые) представлены в разрядах оперативной памяти,
	//в разряде регистра процессора в двоичном виде;


	int a = INT_MAX; //объявление переменной типа integer и инициализация;
	std::cout << "sizeof(a) = " << std::bitset<32>(a) << std::endl;
	getchar(); //ожидание ввода пользователем (один символ), используется как стоп-кран для консоли.
	return 0; //возврат из функции main — завершение программы.
}
