#pragma once

#ifndef TRIPLA_H
#define TRIPLA_H

#include <iostream>
#include<string>
#include <cstdio>
#include <string.h>
using namespace std;

template<class T>
class Tripla
{
public:
	Tripla* sig;
	Tripla* ant;
	T dato;
	int peso;
	//friend class Lista8;
public:
	Tripla();
	Tripla(T dato);
	Tripla(T dato, int peso);
	~Tripla();


};

#endif
