//Lab3.cpp: определяет точку входа для консольного приложения.
//"Операторы цикла и условного перехода"

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>

//'if' — оператор условного перехода;
//в скобках могут  находиться целые и дробные числа, логические переменные, логические выражения;

int main()
{
	int a = 10, b = 15, c = 15;
	if (a == b /*true*/)
		// == логические оператор сравнения, возвращает true только если оба операнда равны;
		// != логический оператор, проверяющий неравенство, возвращает true. только если операнды неравны;
	{
		std::cout << "a == b" << std::endl; /*а равно b;*/
	}
	else
	{
		std::cout << "a != b" << std::endl; /*а неравно b;*/
	}
	if (c == b /*true*/)
	{
		std::cout << "c == b" << std::endl; /*c равно b;*/
	}
	else
	{
		std::cout << "c != b" << std::endl; /*c не равно b;*/
	}

	int d = 0;
	if (d == 0)
	{
		std::cout << "d == 0" << '\n' << std::endl;
	}
	else if (d > 0)
	{
		std::cout << "d > 0" << std::endl;
	}
	else
	{
		std::cout << "d < 0" << '\n' << '\n' << std::endl;
	}

	//тернарный оператор (лог_усл) ? (операторы если true):(операторы если false);
	//также можно переносить запись на несколько строчек;
	(c == b) ?
		(std::cout << "c == b" << std::endl) : (std::cout << "c != b" << std::endl);
	(d == 0) ?
		(std::cout << "d == 0" << std::endl) : (d > 0) ?
		(std::cout << "d > 0" << std::endl) : (std::cout << "d < 0" << '\n' << '\n' << std::endl);

	//switch — оператор условного перехода с несколькими вариантами;
	//switch (выражение)
	//{case (выражение 1):
	//действия, выполняемые, если выражение == выражение 1
	//break;
	//case (выражение 2)
	//	{действия, выполняемые, если выражение == выражение 2
	//	 break;}
	//default:
	//	{действия, выполняемые, если ни одно выражение не подошло
	//	 break;}
	//}

	std::cout << std::endl;
	int page_number = 4;

	// 0 — стартовая страница;
	// 1 — страница сообщений;
	// 2 — страница новостей;
	// 3 — страница настроек;

	switch (page_number)
	{
	case (0):
		std::cout << "Start page" << std::endl;
		break;
	case (1):
	{std::cout << "Messages" << std::endl;
	break;
	}
	case (2):
	{std::cout << "Feed" << std::endl;
	break;
	}
	case (3):
	{std::cout << "Settings" << std::endl;
	break;
	}
	case (4):
	{std::cout << "Exit" << std::endl;
	}
	case (6):
	{std::cout << "Save button" << std::endl;
	}
	case (5):
	{std::cout << "Data save" << '\n' << '\n' << std::endl;
	break;
	}
	default:
	{std::cout << "Some another page" << std::endl;
	break;
	}
	}

	//switch целесообразно применять, если кол-во веток ограничено 5-7;
	//если вариантов больше, имеет смысл создать массив и проверять его на совпадения;

	//for — оператор цикла с отсчётом;
	//for (целочисл_перемнная; условие_продолжения; повторяемое_действие)
	//{
	//действия, выполняемые пока (условие продолжения == true);
	//}

	//типичный пример с for

	int arr[] = { 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };
	for (int i = 0; i < 10; i++ /*либо i+=1 либо i = i+1*/)
	{
		std::cout << "arr[i] = " << arr[i] << std::endl;/* действия, повторяемые, пока i<10;*/
	}
	std::cout << '\n' << '\n' << std::endl;

	//равносильный оператор с пустыми скобками и счетчиком за пределами цикла:

	int k = 0;
	for (;;)
	{
		if (k >= 10)
		{
			break;
		}
		std::cout << "arr[k] = " << arr[k] << std::endl;
		k++;
	}
	std::cout << '\n' << '\n' << std::endl;

	//также возможен вариант с несколькими операторами в скобках for:
	//если между несколькими операциями поставить запятую, то будет действовать логическое ИЛИ, а если && — И;


	for (int i = 0, j = 5; i + j < 10, j < 10; i++, j = j + 2, std::cout << "i = " << i << '\t' << "j = " << j << std::endl);
	std::cout << '\n' << '\n' << std::endl;

	//области видимости переменных:
	int m = 15;
	for (int i = 0; i < 10; i++)
	{
		int l = 20;
		std::cout << "i = " << i << std::endl;
		std::cout << "m = " << m << std::endl;
		std::cout << "l = " << l << std::endl;
		l++;
		m--;
	}

	//std::cout << "i = " << i << std::endl; //переменная из цикла за его пределами исчезнет;
	std::cout << "m = " << m << std::endl;
	//std::cout << "l = " << l << std::endl; //переменная из цикла за его пределами исчезнет;
	std::cout << '\n' << '\n' << std::endl;
	//переменные, объявленные в круглых/фигурных скобках, будут работать только внутри цикла;
	//как только цикл закрывается, переменная и её содержимое становятся недоступны;
	//кроме того, переменные, объявленные в фигурных скобках, перезаписываются каждую итерацию;

	//while (условие) — действие выполняется, пока условие == true, условие проверяется перед каждым заходом в цикл;
	//{
	//
	//}

	double rdn = 0.0;
	srand(100); //инициализация генератора случайных чисел;
				//RAND_MAX — константа, максимально возможное случайное число, возвращаемое rand ();
	while (rdn < RAND_MAX * 3 / 4)
	{
		rdn = rand(); //случайные числа, однородно распределенные от 0 до RAND;
		std::cout << "rdn = " << rdn << std::endl;
	}
	//while — цикл с предусловием, т.е. сначала проверяется условие, а потом выполняется действие;
	//do-while — цикл с постусловием;
	//do
	//{
	//}
	//while()

	int l = 0;
	while (l < 100)
	{
		if (l == 5)
		{
			l++; //если перед следующей итерацией счетчик не увеличить, то мы получим бесконечный цикл;
			continue; //переход на следующую итерацию;
		}
		if (l >= 10)
		{
			break; //выход из цикла;
		}
		std::cout << "l = " << l << std::endl;
		l++;
	}

	getchar();
	return 0;
}

