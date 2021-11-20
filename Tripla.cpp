#include "Tripla.h"

template<class T>
Tripla<T>::Tripla()
{

}

template<class T>
Tripla<T>::Tripla(T dato)
{
	this->dato = dato;
	sig = NULL;
	ant = NULL;
}

template<class T>
Tripla<T>::Tripla(T dato, int peso)
{
	this->dato = dato;
	this->peso = peso;
}

template<class T>
Tripla<T>::~Tripla()
{

}