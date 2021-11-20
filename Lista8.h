#pragma once

#ifndef LISTA8_H
#define LISTA8_H

#include <iostream>
#include<string>
#include <cstdio>
#include <string.h>
#include <set>
#include <sstream>
#include<fstream>
#include<conio.h>
using namespace std;
#include "Tripla.cpp"

template <class T>
class Lista8
{
private:
	Tripla<T>* ultimo;
	Tripla<T>* primero;
	//Lista8 copia;
public:
	Lista8();
	~Lista8();
	void insertar_principio(T dato);
	void insertar_final(T dato);
	void insertar_final_con_peso(T dato, int peso);
	void eliminar_principio();
	void eliminar_final();
	void busquedaSec(T dato);
	void busquedaSecRec(T dato);
	void mostrar();
	void menor();
	void busqueda(int pos);
	T getElemPos(int pos);
	void ordenar();
	void leerdearchivo();
	T getprimero();
	T getultimo();

};

#endif