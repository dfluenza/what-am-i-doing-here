// Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <iostream>

//STD — стандартная библиотека C++ 
//функции print_f, getchar, fopen, read —
//связующее звено между языком и ОС 
//[C++] --> [STD] --> [OC]

//STL — standart template library 
//это расширение библиотеки STD, содержащее структуры данных и функции по работе с ними
//именно из STL подключаются потоки (наши любимые) cout, cin, fstream, ifstrim, ofstream, 
//контейнеры array, vector, list, map,
//итераторы, 
//алгоритмы sort, copy и т.д.


//std::array
//инкапсулирует массивы постоянной (неизменной) длины, является шаблоном.

//std::vector
//инкапсулирует одномерный массив и предоставляет средства
//для изменения его длины

//std::list

//std::map

//std::tree


int main()
{
	std::array<double, 10> double_array1; //объект, построенный из шаблона std::array<>, инкапсулирующий массив.
	double_array1[5] = 10.5;
	double_array1.fill(0.0);
	int array_len = double_array1.size();
	//double_array.swap() — функция для обмена между содержимым двух массивов;
	std::sort(double_array1.begin(), double_array1.end());
	std::array<double, 10> double_array2;
	std::copy(double_array1.begin(), double_array1.end(), double_array2.begin());

	//для создания двухмерных массивов
	std::array<std::array<int, 3>, 3> mat33 = {0};
	mat33[1][1] = 100;
	//итератор — объект, ссылающийся на элемент массива, вектора или списка
	//"улучшенный" вариант переменной-счетчика;
	//нужен для связи шаблонов STL
	std::array<double, 10>::iterator array_iterator;

	//std::vector
	//инкапсулирует одномерный массив и предоставляет средства
	//для изменения его длины
	//очень близким к std::vector по функционалу является std::string

	//основной недостаток:
	//однако каждый раз при изменении длины (увеличении) vector запрашивает у ОС новую область памяти
	//и копирует туда старую; старая уничтожается (освобождается

	//основное преимущество:
	//а доступ к элементам осуществляется быстро и напрямую по адресу
	//[адрес_1 + i]

	//вывод: доступ быстрый, а вставка или увеличение — медленные.

	std::vector<long long> long_vector = {50, 15, 20};

	std::cout << "vector<> = ";
	for(long long value : long_vector)
	std::cout << '\t' << value;
	std::cout << std::endl;

	long_vector.push_back(25);
	long_vector.push_back(0);

	std::cout << "vector<> after push() = ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	//также у std::vector присутствует весь функционал std::array:
	//размер, сортировка, копирование, обмен, итераторы и т.д.

	std::sort(long_vector.begin(), long_vector.end());
	std::cout << "vector<> after sort() = ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	long_vector[2] = 11;

	//вставка в vector
	long_vector.insert(long_vector.begin() + 2, 100500);//с помощью шаблона можно вставить несколько значений
	std::cout << "vector<> after insert() = ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	//std::list
	//всё наоборот: вставка и увеличение списка идёт быстро, а доступ — медленнее,
	//причем, чем дальше от 1-ого элемента, тем медленнее.
	//так как для доступа к i-элементу (определения его адреса в ОП), необходимо пройти по цепочке от 1-ого элемента

	//в отличии от array и vector, не является компактным массивом,
	//элементы std::list представлены отдельными объектами, связанными друг с другом указателями,
	//которые они хранят.
	//[null|данные|указатель] --> [указатель|данные|указатель]
	//														/
	//													   /
	//													  /
	//													 /
	//													/						
	//											[указатель|данные|указатель] --> [указатель|данные|null]

	std::list<char> char_list = {'b'};
	char_list.push_front('a');//вставка перед первым элементом;
	char_list.push_back('a');//вставка после последнего элемента;
	for (char ch : char_list)
	{
		std::cout << ch << std::endl;
	}
	//если класс простой и не содержит динамических данных, то
	class sample_class
	{
		int a;
		double b;
	};
	//список можно создавать из объектов класса
	std::list<sample_class> obj_list1;
	//в противном случае — из указателей на объекты:
	std::list<sample_class*> obj_list2;

	//std::map
	//состоит из пар "ключ — значение", например: "Tu-154" — "5000", "Boing777" — "6000", "A320" — "6500"
	std::map<std::string, double> plane_and_range =
	{ {"Tu - 154", 5000}, {"Boeing777", 6000}, {"A320", 6500} };
	plane_and_range.insert({ "A380", 6400 });

	std::cout << "The range of Boing777 is " << plane_and_range["Boeing777"] << std::endl;
	std::cout << "The range of A380 is " << plane_and_range["A380"] << std::endl;

	//обработка исключений и ошибок
	double d_array[5] = { 1, 2, 3, 4, 5 };
	int i = 60000;
	try //в try помещается код, потенциально способный вызвать исключение:
		//функции, не получающие доступа к ресурсам, файлам, портам, устройствам и т.д.
		//функции, неправильно работающие с памятью
	{
		d_array[i] = 15;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error in \"d_array[i] = 15\"" << std::endl;
	}

	getchar();
    return 0;
}

//в курс не вошли темы, необходимые для штатной коммерческой разработки ПО
//такие как: 
//1. юнит-тестирование (на каждый модуль/проект создается проект, который его тестирует, сборка и запуск sln настраивается так,
//что в первую очередь собирается базовый проект, затем тестирующий и запускается)
//2. технологиии, процессы и шаблоны разработки: SCRUM, Waterfall, Agile и т.д.
//3. создание графических приложений
//4. многопоточные и ассинхронные приложения



