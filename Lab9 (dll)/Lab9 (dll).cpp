// Lab9 (dll).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab9 (dll).h"


extern "C" __declspec(dllexport) int fnc2(double p1, char p2)
{
    return p1 + p2;
}

