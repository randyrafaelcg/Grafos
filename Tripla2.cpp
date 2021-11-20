#include "Tripla2.h"

Tripla2::Tripla2()
{
	marca = false;
	padre = -1;
	dist = 999;
}

Tripla2::Tripla2(bool marca, int padre)
{
	this->marca = marca;
	this->padre = padre;
	dist = 999;
}

Tripla2::~Tripla2()
{
}

Lista8<int>& Tripla2::getLista8()
{
	return L8;
}

bool Tripla2::getMarca()
{
	return marca;
}

int Tripla2::getPadre()
{
	return padre;
}

int Tripla2::getDist()
{
	return dist;
}

void Tripla2::setMarca(bool marca)
{
	this->marca = marca;
}

void Tripla2::setPadre(int padre)
{
	this->padre = padre;
}

void Tripla2::setDist(int dist)
{
	this->dist = dist;
}
