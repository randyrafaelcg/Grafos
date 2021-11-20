#pragma once

#ifndef TRIPLA2_H
#define TRIPLA2_H

#include"Lista8.cpp"
class Tripla2
{
private:
	bool marca;
	int padre;
	int dist;
	Lista8<int> L8;
public:
	Tripla2();
	Tripla2(bool marca, int padre);
	~Tripla2();
	Lista8<int>& getLista8();
	bool getMarca();
	int getPadre();
	int getDist();
	void setMarca(bool marca);
	void setPadre(int padre);
	void setDist(int dist);
};
#endif
