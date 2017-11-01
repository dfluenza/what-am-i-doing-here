//Lab5.cpp: определяет точку входа для консольного приложения.
//"Функции и методы сообщений массивов в функции"

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>

/*функция — фрагмент кода, имеющий  собственное имя(идентификатор), а также интерфейс(входные и выходные параметры);
код оформляется в виде функции в случаях:
1)необходимости частого использования одного и того же фрагмента кода;
2)для упорядочивания больших массивов кода;*/


/*синтаксис:

void тип_выходного_параметра имя_функции (тип_параметра1,
тип_параметра2,
...) — функция без возвращения параметров;

void имя_функции () — нет входных и выходных данных;

!тип_выходного_параметра имя_функции (тип_параметра1,
тип_параметра2,
...) — (заголовок/объявление функции)
{
...выполняемые операторы (тело функции/определение функции)
return выходное_значение; (если функция void, то просто return;)
}!

!функция должна быть объявлена до момента её первого использования!,
т.к. компилятор обрабатывает текст программы всего один раз,
и если он встретит функцию где-то после, то назад с объявленной функцией он уже не вернётся;

переменные, объявленные внутри функции, видны только внутри функции;

то, что передается в параметры, передается в виде копий. их можно менять внутри функции (но зачем?? :^))
*/

//пример 1
int fnc1(double p1, //<значение параметра>...размерность [м]
	char p2, //<значение параметра>...размерность [см]
	int const p3) //<значение параметра>...размерность [км]

				  //передача параметров по значению;
{
	p1 = 2.5;
	//p3 = 10; //не даст изменить значение, так как в типе параметра прописана константа!
	return p1 + p2 / 100 + p3 * 1000; //типы приводятся автоматически
}

//пример 2 (объявление функции в начале отдельно от тела)
int fnc2(double p1, //<значение параметра>...размерность [м]
	char p2, //<значение параметра>...размерность [см]
	int p3); //<значение параметра>...размерность [км]

			 //пример 3
void fnc3(double &a, //входные параметры, переданные ПО ЗНАЧЕНИЮ
	double &b, //параметры переданные по ССЫЛКЕ, через них можно как передавать, так и выводить значения.
	double &c, double &d)
{
	c = a + b;
	d = a - b;
	return;
}

//функция работает аналогично
void fnc3_pointers(double  a, double b, double * c, /* * указатель */ double * d)
{
	*c = a + b; /* В версии с & компилятор сам "расставляет" * */
	*d = a - b;/* * — ничто иное как разыменование*/
	return;
}
//это значит, что в функцию передаются адреса (указатели) на некоторые внешние данные,
//а не копии самих данных. И по адресу (указателю) из функции можно изменить сам оригинал.

//передача массивов в функции
//первый способ передачи (и возвращения) массива в функции:
void fnc4_1(int matr[3][3])
/*передается не копия всего массива, а указатель на первый элемент несмотря на то, что передаем по значению*/
{/*раз передается указатель на оригинальный массив, следовательно меняется тоже исходный внешний оригинальный массив*/
	matr[1][1] = 10; /*какие-то действия с массивом и его элементами*/
	return;
}

//второй способ передачи (и возвращения) массива в функции:
void fnc4_2(int matr[][3])
/*пользователь должен самостоятельно следить за тем, чтобы индекс не превышал длину массива*/
{
	matr[1][1] = 10; /*какие-то действия с массивом и его элементами*/
	return;
}

//третий способ передачи (и возвращения) массива в функции:
void fnc4_3(int(&matr)[3][3])
{
	matr[1][1] = 10; /*какие-то действия с массивом и его элементами*/
	return;
}

//четвертый способ передачи (и возвращения) массива в функции:
void fnc4_4(int ** matr)
/*пользователь должен самостоятельно следить за тем, чтобы индекс не превышал длину массива*/
{
	matr[1][1] = 10;
	return;
}


int main()
{
	double d = 1.5;
	char ch = 1000;
	int ret_value = 0;

	fnc1(d, ch, 5);
	ret_value = fnc1(d, ch, 5);
	std::cout << "fnc1(d, ch, 5) = " << fnc1(d, ch, 5) << std::endl;

	getchar();
	return 0;
}

//пример 2 (определение функции в самом конце) — заголовок функции повторяется в точности!
int fnc2(double p1, //<значение параметра>...размерность [м]
	char p2, //<значение параметра>...размерность [см]
	int p3) //<значение параметра>...размерность [км]
{
	return p1 + p2 / 100 + p3 * 1000; /*типы приводятся автоматически */
}

