#pragma once
#include <iostream>
using namespace std;

class weapon
{
public:
	weapon() //� ������������ ���������� ������������� ������ ������ � ������ ��������� ��������� ��������;
	{
		weight = 3.5;
		cartridges = capacity;
		cout << "weapon()" << endl;
	}
private: //� private �������� ��������������� ��������������, ������ � ������� ���������� ������������ ����� ������� ��������� ������ �������;
		 //������� � ������ ���������� � �������� �������� � ������� ��������� ������� ������, �������������� ���.��������;
	int cartridges; // ����� ���������� �������;
	int capacity; // ������� ��������;
public:
	double range = 1500;// ���������;
	double velocity; // ��������� ��������;
	double weight; // ���;
	bool optics;
	bool loaded;

	void load() // �����������;
	{
		cartridges = capacity;
	}
	void weapon::play_animation();
	weapon::~weapon();	
	void weapon::shot();
	

};

//void weapon::play_animation(); // �����, ������������ ��� ������, ���������� � ���_������::


class assault_rifle : public weapon
{
public:
	assault_rifle()
		: weapon()
	{
		return;
	}
};